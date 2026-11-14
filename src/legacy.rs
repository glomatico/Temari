//! Version-specific backend for the pinned 3.6.0-beta x86-64 capture profile.
//! Uses the locally generated, checked C lift; no Apple ELF is loaded here.
use crate::rounds::{R1Entry, Template, ST_SIZE};
use std::collections::HashMap;

pub const PROFILE: &str = "apple-music-3.6.0.1109-x86_64-research-v1";
#[derive(Clone)]
pub struct LegacyTemplate {
    state: [u8; 0x800],
    bl: u8,
    r9b: u8,
}
#[repr(C)]
struct Region {
    base: u64,
    size: u64,
    data: *mut u8,
    writable: u32,
}
#[repr(C)]
struct Memory {
    regions: *mut Region,
    count: usize,
    error: u32,
    fault: u64,
}
extern "C" {
    fn legacy_block(regs: *mut u64, memory: *mut Memory) -> u32;
}

pub fn from_fields(map: &HashMap<String, String>) -> Result<Template, String> {
    if map.get("profile").map(String::as_str) != Some(PROFILE) {
        return Err("unsupported template profile".into());
    }
    let ctx = crate::template::base64_decode(map.get("ctx").ok_or("no ctx")?);
    let raw = crate::template::base64_decode(map.get("state").ok_or("no state")?);
    if ctx.len() != 0x8000 || raw.len() != 0x800 {
        return Err("legacy context/state size mismatch".into());
    }
    let byte = |name: &str| -> Result<u8, String> {
        map.get(name)
            .ok_or_else(|| format!("missing {name}"))?
            .parse::<u8>()
            .map_err(|_| format!("invalid {name}"))
    };
    let mut state = [0; 0x800];
    state.copy_from_slice(&raw);
    let legacy = LegacyTemplate {
        state,
        bl: byte("bl")?,
        r9b: byte("r9b")?,
    };
    let mut tmpl = Template::new(
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
    tmpl.legacy = Some(legacy);
    Ok(tmpl)
}

pub fn decrypt_aligned(tmpl: &Template, input: &[u8], output: &mut [u8]) {
    let t = tmpl.legacy.as_ref().expect("legacy profile");
    assert!(input.len() < 0x10000000 && input.len() % 16 == 0 && output.len() >= input.len());
    let mut state = t.state;
    const RBP: u64 = 0x30010000;
    const CTX: u64 = 0x20000000;
    const INPUT: u64 = 0x40000000;
    const OUTPUT: u64 = 0x50000000;
    for (off, value) in [
        (0x90, CTX),
        (0x140, INPUT),
        (0x788, OUTPUT),
        (0x370, input.len() as u64),
    ] {
        state[0x800 - off..0x808 - off].copy_from_slice(&value.to_le_bytes());
    }
    let mut regs = [0u64; 16];
    regs[1] = t.bl.into();
    regs[5] = 0x06c4f3f6;
    regs[6] = RBP;
    regs[7] = RBP - 0x1000;
    regs[9] = t.r9b.into();
    regs[13] = 8578;
    let mut regions = [
        Region {
            base: RBP - 0x800,
            size: 0x800,
            data: state.as_mut_ptr(),
            writable: 1,
        },
        Region {
            base: CTX,
            size: tmpl.ctx.len() as u64,
            data: tmpl.ctx.as_ptr() as *mut u8,
            writable: 0,
        },
        Region {
            base: INPUT,
            size: input.len() as u64,
            data: input.as_ptr() as *mut u8,
            writable: 0,
        },
        Region {
            base: OUTPUT,
            size: input.len() as u64,
            data: output.as_mut_ptr(),
            writable: 1,
        },
    ];
    let mut memory = Memory {
        regions: regions.as_mut_ptr(),
        count: regions.len(),
        error: 0,
        fault: 0,
    };
    for block in 0..input.len() / 16 {
        // The C lift bounds-checks every emulated memory access and refuses
        // writes to context/input. All host pointers remain owned by this call.
        let error = unsafe { legacy_block(regs.as_mut_ptr(), &mut memory) };
        assert_eq!(error, 0, "invalid legacy memory contract");
        assert_eq!(
            regs[0],
            if block + 1 == input.len() / 16 {
                0x10ac19
            } else {
                0x107070
            },
            "invalid legacy dispatch"
        );
    }
}
