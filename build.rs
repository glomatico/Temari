// Compile the self-contained, source-ported legacy round engine into Temari.
// No Apple native libraries, APK files or network services are needed at build
// time. cc selects the target-appropriate C compiler for Cargo's platform.
fn main() {
    println!("cargo:rerun-if-changed=src/legacy/legacy_backend.c");
    cc::Build::new()
        .file("src/legacy/legacy_backend.c")
        .flag_if_supported("-std=c11")
        .warnings(true)
        .compile("temari_legacy");
}
