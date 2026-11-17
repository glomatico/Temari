//! Pinned Apple Music 3.6.0.1109 ARM64 block transform.
//! Pure Rust with checked virtual memory; never loads an Apple library.
use crate::rounds::{R1Entry, Template, ST_SIZE};
use std::collections::HashMap;
mod block;

pub const PROFILE: &str = "apple-music-3.6.0.1109-arm64-v8a-research-v1";
const SP: u64 = 0x30000000;
const CTX: u64 = 0x20000000;
const INPUT: u64 = 0x40000000;
const OUTPUT: u64 = 0x50000000;
const STATE_SIZE: usize = 0x900;
const TABLE_SIZE: usize = 0x2520;
const POINTERS: &[(usize, u64)] = &[
    (0x26e0, 0),
    (0x2680, 0x110),
    (0x2678, 0x530),
    (0x2670, 0xa70),
    (0x2668, 0xe90),
    (0x2660, 0x13b0),
    (0x2650, 0x17c0),
    (0x2648, 0x1be0),
    (0x2640, 0x2010),
    (0x2368, 0x12a0),
    (0x2360, 0x2420),
    (0x2358, 0xa0d),
];

#[derive(Clone)]
pub struct Arm64Template {
    state: [u8; STATE_SIZE],
}

pub fn from_fields(map: &HashMap<String, String>) -> Result<Template, String> {
    if map.get("profile").map(String::as_str) != Some(PROFILE) {
        return Err("unsupported template profile".into());
    }
    let ctx = crate::template::base64_decode(map.get("ctx").ok_or("no ctx")?);
    let state = crate::template::base64_decode(map.get("state").ok_or("no state")?);
    if ctx.len() != TABLE_SIZE || state.len() != STATE_SIZE {
        return Err("ARM64 context/state size mismatch".into());
    }
    let mut snapshot = [0u8; STATE_SIZE];
    snapshot.copy_from_slice(&state);
    let word = |offset: usize| {
        u64::from_le_bytes(
            snapshot[offset - 0x1e00..offset - 0x1df8]
                .try_into()
                .unwrap(),
        )
    };
    if POINTERS
        .iter()
        .any(|&(slot, offset)| word(slot) != CTX + offset)
        || word(0x1e28) != INPUT
        || word(0x1e30) != OUTPUT
        || u32::from_le_bytes(snapshot[0x888..0x88c].try_into().unwrap()) != 8360
    {
        return Err("invalid ARM64 context relocation/dispatch".into());
    }
    let mut template = Template::new(
        ctx,
        [0; ST_SIZE],
        R1Entry {
            rdx: 0,
            rcx: 0,
            rax: 0,
            r9: 0,
            rbp: 0,
        },
    );
    template.arm64 = Some(Arm64Template { state: snapshot });
    Ok(template)
}

struct Memory<'a> {
    state: [u8; STATE_SIZE],
    tables: &'a [u8],
    input: &'a [u8],
    output: &'a mut [u8],
}
fn offset(address: u64, base: u64, size: usize, n: usize) -> Option<usize> {
    let off = address.checked_sub(base)?;
    if off > size as u64 || n > size - off as usize {
        None
    } else {
        Some(off as usize)
    }
}
impl Memory<'_> {
    fn load(&self, address: u64, n: usize) -> u64 {
        // Only the two validated loop dispatch entries are exposed.
        if n == 4 && address == 0x2770 + 8360 * 4 {
            return 0;
        }
        if n == 4 && address == 0x2770 + 8361 * 4 {
            return 0x444c;
        }
        for (base, bytes) in [
            (SP + 0x1e00, self.state.as_slice()),
            (CTX, self.tables),
            (INPUT, self.input),
        ] {
            if let Some(off) = offset(address, base, bytes.len(), n) {
                let mut value = [0u8; 8];
                value[..n].copy_from_slice(&bytes[off..off + n]);
                return u64::from_le_bytes(value);
            }
        }
        panic!("invalid ARM64 context memory read");
    }
    fn store(&mut self, address: u64, n: usize, value: u64) {
        for (base, bytes) in [
            (SP + 0x1e00, self.state.as_mut_slice()),
            (OUTPUT, &mut *self.output),
        ] {
            if let Some(off) = offset(address, base, bytes.len(), n) {
                bytes[off..off + n].copy_from_slice(&value.to_le_bytes()[..n]);
                return;
            }
        }
        panic!("invalid ARM64 context memory write");
    }
}
impl Drop for Memory<'_> {
    fn drop(&mut self) {
        // Do not retain the per-sample key state in reusable stack slots.
        for byte in &mut self.state {
            unsafe { std::ptr::write_volatile(byte, 0) }
        }
    }
}
pub fn decrypt_aligned(template: &Template, input: &[u8], output: &mut [u8]) {
    assert!(input.len() < 0x10000000 && input.len() % 16 == 0 && output.len() >= input.len());
    let mut memory = Memory {
        state: template.arm64.as_ref().expect("ARM64 profile").state,
        tables: &template.ctx,
        input,
        output,
    };
    memory.state[0x3d0..0x3d4].copy_from_slice(&(input.len() as u32).to_le_bytes());
    let mut registers = [0u64; 31];
    registers[21] = 0x6dc490;
    for index in 0..input.len() / 16 {
        let next = block::block(&mut registers, &mut memory);
        assert_eq!(
            next,
            if index + 1 == input.len() / 16 {
                0x109d74
            } else {
                0x105928
            },
            "invalid ARM64 dispatch"
        );
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn virtual_memory_boundaries() {
        assert_eq!(offset(CTX - 1, CTX, 16, 1), None);
        assert_eq!(offset(CTX + 15, CTX, 16, 1), Some(15));
        assert_eq!(offset(CTX + 15, CTX, 16, 2), None);
        assert_eq!(offset(u64::MAX, CTX, 16, 1), None);
        let mut output = [0u8; 16];
        let mut m = Memory {
            state: [0; STATE_SIZE],
            tables: &[7; TABLE_SIZE],
            input: &[9; 16],
            output: &mut output,
        };
        assert_eq!(m.load(CTX, 1), 7);
        assert_eq!(m.load(INPUT, 1), 9);
        m.store(SP + 0x1e00, 4, 0x12345678);
        assert_eq!(m.load(SP + 0x1e00, 4), 0x12345678);
        assert!(
            std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| m.store(CTX, 1, 0))).is_err()
        );
    }
}
