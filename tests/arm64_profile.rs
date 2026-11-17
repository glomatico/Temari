//! Entirely fabricated tables/state. Expected vectors were computed by an
//! independent Unicorn execution of the pinned block, never by this backend.
use temari::{decrypt, decrypt_par, template_from_json};

fn b64(bytes: &[u8]) -> String {
    const A: &[u8] = b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    let mut result = String::new();
    for chunk in bytes.chunks(3) {
        let a = chunk[0] as usize;
        let b = *chunk.get(1).unwrap_or(&0) as usize;
        let c = *chunk.get(2).unwrap_or(&0) as usize;
        result.push(A[a >> 2] as char);
        result.push(A[((a & 3) << 4) | (b >> 4)] as char);
        result.push(if chunk.len() > 1 {
            A[((b & 15) << 2) | (c >> 6)] as char
        } else {
            '='
        });
        result.push(if chunk.len() > 2 {
            A[c & 63] as char
        } else {
            '='
        });
    }
    result
}
fn fixture() -> String {
    let mut state = [0u8; 0x900];
    for (slot, off) in [
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
    ] {
        state[slot - 0x1e00..slot - 0x1df8].copy_from_slice(&(0x20000000u64 + off).to_le_bytes());
    }
    state[0x28..0x30].copy_from_slice(&0x40000000u64.to_le_bytes());
    state[0x30..0x38].copy_from_slice(&0x50000000u64.to_le_bytes());
    state[0x888..0x88c].copy_from_slice(&8360u32.to_le_bytes());
    state[0x240..0x244].copy_from_slice(&0xdb8920u32.to_le_bytes());
    let tables: Vec<u8> = (0..0x2520).map(|i| (i * 73 + 19) as u8).collect();
    format!(
        r#"{{"profile":"apple-music-1109-arm64-v8a","ctx":"{}","state":"{}"}}"#,
        b64(&tables),
        b64(&state)
    )
}
fn unhex(s: &str) -> Vec<u8> {
    s.as_bytes()
        .chunks_exact(2)
        .map(|v| u8::from_str_radix(std::str::from_utf8(v).unwrap(), 16).unwrap())
        .collect()
}
#[test]
fn independent_synthetic_vectors_and_reset() {
    let template = template_from_json(&fixture()).unwrap();
    assert!(template.arm64.is_some());
    assert!(template.legacy.is_none());
    let input: Vec<u8> = (0..32).map(|i| (i * 17 + 3) as u8).collect();
    let expected = unhex("5f790a813ecbb805e4674e35e7c152a9d1f4c2be50e6ac6666460eaa45a096da");
    assert_eq!(decrypt(&template, &input), expected);
    assert_eq!(decrypt(&template, &input[..16]), expected[..16]);
    assert_eq!(
        decrypt_par(&template, &[&input, &[], &input[..16], &input]),
        vec![
            expected.clone(),
            vec![],
            expected[..16].to_vec(),
            expected.clone()
        ]
    );
    for tail in 0..16 {
        let sample = &input[..16 + tail];
        let mut want = expected[..16].to_vec();
        want.extend_from_slice(&input[16..16 + tail]);
        assert_eq!(decrypt(&template, sample), want);
    }
}
#[test]
fn explicit_profile_and_relocation_validation() {
    let json = fixture();
    assert!(
        template_from_json(&json.replace("apple-music-1109-arm64-v8a", "apple-music-1109-unknown"))
            .is_err()
    );
    assert!(template_from_json(&json.replace("arm64-v8a", "x86_64")).is_err());
    let wrong = format!(
        r#"{{"profile":"apple-music-1109-arm64-v8a","ctx":"{}","state":"{}"}}"#,
        b64(&vec![0; 0x2520]),
        b64(&vec![0; 0x900])
    );
    assert!(template_from_json(&wrong).is_err());
    assert!(template_from_json(
        r#"{"profile":"apple-music-1109-arm64-v8a","ctx":"","state":""}"#
    )
    .is_err());
}
