//! Fabricated contexts only. Expected bytes come from running the pinned
//! CoreLSKD block with Unicorn, not from this crate's C implementation.
//! No Apple APK, decrypted media, account or license data is included.
use temari::{decrypt, decrypt_par, template_from_json};

const SYNTHETIC_LEGACY: &str = include_str!("fixtures/legacy-v1109-synthetic.json");

fn unhex(s: &str) -> Vec<u8> {
    s.as_bytes()
        .chunks_exact(2)
        .map(|chunk| {
            u8::from_str_radix(std::str::from_utf8(chunk).unwrap(), 16).unwrap()
        })
        .collect()
}

#[test]
fn legacy_native_rust_api_matches_independent_emulator() {
    let template = template_from_json(SYNTHETIC_LEGACY).expect("synthetic legacy template");
    assert!(template.legacy.is_some());
    let ct16 = unhex("d5746c88472bbe9d016a662e3f25c22b");
    let pt16 = unhex("dac451baf17e2fe7b97650bebedd6eda");
    let ct64 = unhex(concat!(
        "d5746c88472bbe9d016a662e3f25c22bd2929f087a3f8d452ad9d20c1eebf7a",
        "55e148823d9004dbbf53d1491b022c41d613701fe8c9f8b365fe5aac56cb393b1"
    ));
    let pt64 = unhex(concat!(
        "dac451baf17e2fe7b97650bebedd6edacdc2b38cec5a39914927370d78af46bd",
        "9422c25d3f93d09b8713cc15a82436c9582f7c3bf39d4d1eb385bd43de3a837e"
    ));
    assert_eq!(decrypt(&template, &ct16), pt16);
    assert_eq!(decrypt(&template, &ct64), pt64);
    assert_eq!(
        decrypt_par(&template, &[&ct16, &ct64, &[], &ct16]),
        vec![pt16.clone(), pt64.clone(), vec![], pt16.clone()],
    );

    // SAMPLE-AES only decrypts the aligned prefix, preserving its tail.
    let mut unaligned = ct64;
    unaligned.extend_from_slice(&[0x15, 0x23, 0x42]);
    let mut expected = pt64;
    expected.extend_from_slice(&[0x15, 0x23, 0x42]);
    assert_eq!(decrypt(&template, &unaligned), expected);
}

#[test]
fn unknown_explicit_profile_fails_closed() {
    let unknown = SYNTHETIC_LEGACY.replace(
        "apple-music-1109-x86_64",
        "unsupported-legacy-version",
    );
    assert!(template_from_json(&unknown).is_err());
}

#[test]
fn upstream_templates_still_take_the_original_engine() {
    // This is a public-format synthetic template, not a real captured key.
    // Empty base64 values are rejected; zeros of the correct lengths are not.
    fn b64_zeros(n: usize) -> String {
        // Base64 encoding of zero bytes, with correct padding.
        let full = "A".repeat(n / 3 * 4);
        match n % 3 {
            0 => full,
            1 => full + "AA==",
            _ => full + "AAA=",
        }
    }
    let untagged = format!(
        r#"{{"ctx":"{}","state":"{}","rax":"0x0","rcx":"0x0","rdx":"0x0","r9":"0x0","rbp":"0x0"}}"#,
        b64_zeros(0x8000),
        b64_zeros(0x2100),
    );
    let tmpl = template_from_json(&untagged).expect("upstream template");
    assert!(tmpl.legacy.is_none());
    assert_eq!(decrypt(&tmpl, &[]), Vec::<u8>::new());
}
