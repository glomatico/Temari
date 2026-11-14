/* Generated locally from the pinned ELF; see scripts/lift_legacy.py. */
#include <stdint.h>
#include <stddef.h>
typedef struct { uint64_t base, size; uint8_t *data; uint32_t writable; } Region;
typedef struct { Region *regions; size_t count; uint32_t error; uint64_t fault; } Memory;
static uint64_t load(Memory *m, uint64_t p, unsigned n) {
    if (p == 0x7fa0 + 8578*4 && n == 4) return 0;
    if (p == 0x7fa0 + 8579*4 && n == 4) return 0x3ba9;
    for (size_t i=0; i<m->count; ++i) {
        Region *r=&m->regions[i];
        if (p>=r->base && n<=r->size && p-r->base<=r->size-n) {
            uint64_t v=0;
            for (unsigned j=0; j<n; ++j) v|=(uint64_t)r->data[p-r->base+j]<<(8*j);
            return v;
        }
    }
    m->error=1; m->fault=p; return 0;
}
static void save(Memory *m, uint64_t p, unsigned n, uint64_t v) {
    for (size_t i=0; i<m->count; ++i) {
        Region *r=&m->regions[i];
        if (r->writable && p>=r->base && n<=r->size && p-r->base<=r->size-n) {
            for (unsigned j=0; j<n; ++j) r->data[p-r->base+j]=(uint8_t)(v>>(8*j));
            return;
        }
    }
    m->error=1; m->fault=p;
}
uint32_t legacy_block(uint64_t *r, Memory *m) {
    uint64_t a, b; unsigned eq=0;

    /* 0x107070: mov byte ptr [rbp - 0x288], r9b */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd78)), 1, ((r[9] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x107077: mov qword ptr [rbp - 0x2c0], r13 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd40)), 8, ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10707e: mov byte ptr [rbp - 0x1e8], bl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe18)), 1, ((r[1] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x107084: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107086: or eax, 6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x6))) & UINT64_C(0xffffffff);
    /* 0x107089: xor eax, 0x6c4f3f0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c4f3f0))) & UINT64_C(0xffffffff);
    /* 0x10708e: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107091: and ecx, 0xc7711d92 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xc7711d92))) & UINT64_C(0xffffffff);
    /* 0x107097: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107099: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10709b: add eax, 0x63b88ec9 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x63b88ec9))) & UINT64_C(0xffffffff);
    /* 0x1070a0: mov qword ptr [rbp - 0x68], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff98)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1070a4: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1070a6: or eax, 3 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x3))) & UINT64_C(0xffffffff);
    /* 0x1070a9: xor eax, 0x6c4f3f4 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c4f3f4))) & UINT64_C(0xffffffff);
    /* 0x1070ae: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1070b1: and ecx, 0xee26ef50 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xee26ef50))) & UINT64_C(0xffffffff);
    /* 0x1070b7: xor ecx, 0xfffffffd */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xfffffffd))) & UINT64_C(0xffffffff);
    /* 0x1070ba: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1070bc: add eax, 0x771377aa */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x771377aa))) & UINT64_C(0xffffffff);
    /* 0x1070c1: mov qword ptr [rbp - 0x98], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff68)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1070c8: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1070ca: or eax, 0xe */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0xe))) & UINT64_C(0xffffffff);
    /* 0x1070cd: xor eax, 0x6c4f3f0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c4f3f0))) & UINT64_C(0xffffffff);
    /* 0x1070d2: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1070d5: and ecx, 0xf1c3280 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xf1c3280))) & UINT64_C(0xffffffff);
    /* 0x1070db: xor ecx, 0xfffffff7 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xfffffff7))) & UINT64_C(0xffffffff);
    /* 0x1070de: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1070e0: add eax, 0x78e1945 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x78e1945))) & UINT64_C(0xffffffff);
    /* 0x1070e5: mov qword ptr [rbp - 0x48], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffb8)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1070e9: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1070eb: or eax, 5 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x5))) & UINT64_C(0xffffffff);
    /* 0x1070ee: xor eax, 0x6c4f3f2 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c4f3f2))) & UINT64_C(0xffffffff);
    /* 0x1070f3: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1070f6: and ecx, 0x805bbef0 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x805bbef0))) & UINT64_C(0xffffffff);
    /* 0x1070fc: xor ecx, 0xfffffff7 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xfffffff7))) & UINT64_C(0xffffffff);
    /* 0x1070ff: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107101: add eax, 0x402ddf7d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x402ddf7d))) & UINT64_C(0xffffffff);
    /* 0x107106: mov qword ptr [rbp - 0x78], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff88)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10710a: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10710c: or eax, 0xd */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0xd))) & UINT64_C(0xffffffff);
    /* 0x10710f: xor eax, 0x6c4f3f2 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c4f3f2))) & UINT64_C(0xffffffff);
    /* 0x107114: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107117: and ecx, 0xa46c9144 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa46c9144))) & UINT64_C(0xffffffff);
    /* 0x10711d: xor ecx, 0xfffffff5 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xfffffff5))) & UINT64_C(0xffffffff);
    /* 0x107120: lea r11d, [rax + rcx] */
    r[11] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107124: add r11d, 0x523648a8 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x523648a8))) & UINT64_C(0xffffffff);
    /* 0x10712b: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10712d: or eax, 0xf */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0xf))) & UINT64_C(0xffffffff);
    /* 0x107130: xor eax, 0x6c4f3f0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c4f3f0))) & UINT64_C(0xffffffff);
    /* 0x107135: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107138: and ecx, 0xcd63ede0 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xcd63ede0))) & UINT64_C(0xffffffff);
    /* 0x10713e: xor ecx, 0xffffffef */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xffffffef))) & UINT64_C(0xffffffff);
    /* 0x107141: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107143: add eax, 0x66b1f6f9 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x66b1f6f9))) & UINT64_C(0xffffffff);
    /* 0x107148: mov qword ptr [rbp - 0x40], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffc0)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10714c: mov r15, qword ptr [rbp - 0x90] */
    r[15] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff70)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107153: mov rax, qword ptr [rbp - 0x310] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffcf0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10715a: movzx r12d, byte ptr [r15 + rax + 0x2ee0] */
    r[12] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107163: xor r12d, 0x4c */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107167: lea eax, [r12 + r12] */
    r[0] = ((((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10716b: and eax, 0x110 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x110))) & UINT64_C(0xffffffff);
    /* 0x107170: sub r12d, eax */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107173: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107175: or eax, 0xc */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0xc))) & UINT64_C(0xffffffff);
    /* 0x107178: xor rax, 0x6c4f3f2 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f2))) & UINT64_C(0xffffffffffffffff);
    /* 0x10717e: mov qword ptr [rbp - 0x1a8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe58)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107185: mov rcx, qword ptr [rbp - 0x140] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffec0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10718c: movzx eax, byte ptr [rcx + rax] */
    r[0] = (load(m, (((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107190: movzx edx, byte ptr [r15 + 0x38ed] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0x38ed)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107198: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1071a1: xor al, dl */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[3] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x1071a3: mov byte ptr [rbp - 0x1f8], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe08)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x1071a9: movzx r8d, al */
    r[8] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1071ad: lea eax, [r8 + r8] */
    r[0] = ((((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1071b1: and eax, 0xffffffd6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffd6))) & UINT64_C(0xffffffff);
    /* 0x1071b4: sub r8d, eax */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1071b7: mov rax, qword ptr [rbp - 0x670] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff990)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1071be: mov r13, rdi */
    r[13] = (((r[5] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x1071c1: movzx r9d, byte ptr [r15 + rax + 0x2ee0] */
    r[9] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1071ca: xor r9d, 0x4c */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1071ce: lea eax, [r9 + r9] */
    r[0] = ((((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1071d2: and eax, 0x5e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5e))) & UINT64_C(0xffffffff);
    /* 0x1071d5: sub r9d, eax */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1071d8: mov eax, r13d */
    r[0] = (((r[13] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1071db: xor rax, 0x6c4f3f6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f6))) & UINT64_C(0xffffffffffffffff);
    /* 0x1071e1: mov qword ptr [rbp - 0xd0], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff30)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1071e8: movzx eax, byte ptr [rcx + rax] */
    r[0] = (load(m, (((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1071ec: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1071f5: mov edi, edx */
    r[5] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1071f7: xor al, dl */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[3] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x1071f9: mov byte ptr [rbp - 0x1a0], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe60)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x1071ff: movzx esi, al */
    r[4] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107202: lea eax, [rsi + rsi] */
    r[0] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107205: and eax, 0xffffffb8 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffb8))) & UINT64_C(0xffffffff);
    /* 0x107208: sub esi, eax */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10720a: mov rax, qword ptr [rbp - 0x398] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc68)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107211: movzx ebx, byte ptr [r15 + rax + 0x2ee0] */
    r[1] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10721a: xor ebx, 0x4c */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10721d: lea eax, [rbx + rbx] */
    r[0] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107220: and eax, 0xffffffe6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffe6))) & UINT64_C(0xffffffff);
    /* 0x107223: sub ebx, eax */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107225: mov rax, qword ptr [rbp - 0x6a0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff960)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10722c: movzx edx, byte ptr [r15 + rax + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107235: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107238: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10723b: and eax, 0x14c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x14c))) & UINT64_C(0xffffffff);
    /* 0x107240: sub edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107242: mov eax, r13d */
    r[0] = (((r[13] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107245: or eax, 1 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x1))) & UINT64_C(0xffffffff);
    /* 0x107248: xor rax, 0x6c4f3f6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f6))) & UINT64_C(0xffffffffffffffff);
    /* 0x10724e: mov qword ptr [rbp - 0x250], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdb0)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107255: movzx eax, byte ptr [rcx + rax] */
    r[0] = (load(m, (((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107259: mov r14, rcx */
    r[14] = (((r[2] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x10725c: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107265: xor al, dil */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[5] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x107268: mov r10d, edi */
    r[10] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10726b: mov byte ptr [rbp - 0x550], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffab0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x107271: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107274: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107277: and ecx, 0x68 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x68))) & UINT64_C(0xffffffff);
    /* 0x10727a: sub eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10727c: shl ebx, 0x10 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10727f: add ebx, 0xbdf30000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xbdf30000))) & UINT64_C(0xffffffff);
    /* 0x107285: xor ebx, 0xbdf30000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbdf30000))) & UINT64_C(0xffffffff);
    /* 0x10728b: lea ecx, [rbx + rbx] */
    r[2] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10728e: and ecx, 0xbc700000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xbc700000))) & UINT64_C(0xffffffff);
    /* 0x107294: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107296: add ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107298: add ecx, 0x5e38250f */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5e38250f))) & UINT64_C(0xffffffff);
    /* 0x10729e: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x1072a1: add edx, 0xcf73a600 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xcf73a600))) & UINT64_C(0xffffffff);
    /* 0x1072a7: xor edx, 0xcf73a600 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xcf73a600))) & UINT64_C(0xffffffff);
    /* 0x1072ad: lea edi, [rdx + rdx] */
    r[5] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1072b0: and edi, 0xa194000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa194000))) & UINT64_C(0xffffffff);
    /* 0x1072b6: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1072b8: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1072ba: add edx, 0x50ca041 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x50ca041))) & UINT64_C(0xffffffff);
    /* 0x1072c0: xor ecx, 0x5e38250f */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5e38250f))) & UINT64_C(0xffffffff);
    /* 0x1072c6: xor edx, 0x50ca041 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x50ca041))) & UINT64_C(0xffffffff);
    /* 0x1072cc: or edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1072ce: lea ecx, [rdx + rdx] */
    r[2] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1072d1: and ecx, 0x6b3067d6 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x6b3067d6))) & UINT64_C(0xffffffff);
    /* 0x1072d7: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1072d9: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1072db: add ecx, 0x359833eb */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x359833eb))) & UINT64_C(0xffffffff);
    /* 0x1072e1: mov rdx, qword ptr [rbp - 0x4d8] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb28)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1072e8: movzx edx, byte ptr [r15 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1072f1: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1072f4: lea edi, [rdx + rdx] */
    r[5] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1072f7: and edi, 0x72 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x72))) & UINT64_C(0xffffffff);
    /* 0x1072fa: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1072fc: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1072fe: add edx, 0x656d539 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x656d539))) & UINT64_C(0xffffffff);
    /* 0x107304: xor edx, 0x656d539 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x656d539))) & UINT64_C(0xffffffff);
    /* 0x10730a: xor ecx, 0x359833eb */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x359833eb))) & UINT64_C(0xffffffff);
    /* 0x107310: or edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107312: xor r11, 0x523648a7 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x523648a7))) & UINT64_C(0xffffffffffffffff);
    /* 0x107319: mov qword ptr [rbp - 0x280], r11 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd80)), 8, ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107320: movzx ecx, byte ptr [r14 + r11] */
    r[2] = (load(m, (((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107325: movzx ecx, byte ptr [r15 + rcx + 0x4180] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10732e: xor cl, r10b */
    r[2] = (r[2] & UINT64_C(0xffffffffffffff00)) | ((((((r[2] >> 0) & UINT64_C(0xff)) ^ ((r[10] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x107331: mov byte ptr [rbp - 0x2a0], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd60)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x107337: movzx ebx, cl */
    r[1] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10733a: lea ecx, [rbx + rbx] */
    r[2] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10733d: and ecx, 0xffffff9c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff9c))) & UINT64_C(0xffffffff);
    /* 0x107340: sub ebx, ecx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107342: shl esi, 0x10 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107345: add esi, 0x12dc0000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x12dc0000))) & UINT64_C(0xffffffff);
    /* 0x10734b: xor esi, 0x12dc0000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x12dc0000))) & UINT64_C(0xffffffff);
    /* 0x107351: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107354: and ecx, 0x82240000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x82240000))) & UINT64_C(0xffffffff);
    /* 0x10735a: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10735c: lea edi, [rsi + rcx] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10735f: add edi, 0x411252a1 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x411252a1))) & UINT64_C(0xffffffff);
    /* 0x107365: shl eax, 8 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107368: add eax, 0xdc73400 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xdc73400))) & UINT64_C(0xffffffff);
    /* 0x10736d: xor eax, 0xdc73400 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xdc73400))) & UINT64_C(0xffffffff);
    /* 0x107372: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107375: and ecx, 0xb05ebe00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xb05ebe00))) & UINT64_C(0xffffffff);
    /* 0x10737b: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10737d: lea r11d, [rax + rcx] */
    r[11] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107381: add r11d, 0x582f5f18 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x582f5f18))) & UINT64_C(0xffffffff);
    /* 0x107388: mov eax, r13d */
    r[0] = (((r[13] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10738b: mov qword ptr [rbp - 0x70], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff90)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10738f: mov qword ptr [rbp - 0x50], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffb0)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107393: mov qword ptr [rbp - 0x58], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffa8)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107397: mov qword ptr [rbp - 0xc0], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff40)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10739e: mov qword ptr [rbp - 0xa0], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff60)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1073a5: mov qword ptr [rbp - 0x60], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffa0)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1073a9: or r13d, 2 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x2))) & UINT64_C(0xffffffff);
    /* 0x1073ad: xor r13, 0x6c4f3f4 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f4))) & UINT64_C(0xffffffffffffffff);
    /* 0x1073b4: mov qword ptr [rbp - 0x248], r13 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdb8)), 8, ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1073bb: movzx eax, byte ptr [r14 + r13] */
    r[0] = (load(m, (((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1073c0: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1073c9: xor al, r10b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[10] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x1073cc: mov r13d, r10d */
    r[13] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1073cf: mov byte ptr [rbp - 0x278], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd88)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x1073d5: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1073d8: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1073db: and esi, 0xffffff9a */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff9a))) & UINT64_C(0xffffffff);
    /* 0x1073de: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1073e0: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1073e2: add eax, 0x6599b7cd */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6599b7cd))) & UINT64_C(0xffffffff);
    /* 0x1073e7: mov qword ptr [rbp - 0xa8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1073ee: xor edi, 0x411252a1 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x411252a1))) & UINT64_C(0xffffffff);
    /* 0x1073f4: xor r11d, 0x582f5f18 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x582f5f18))) & UINT64_C(0xffffffff);
    /* 0x1073fb: or r11d, edi */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) | ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1073fe: shl r8d, 0x10 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107402: add r8d, 0xf9eb0000 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xf9eb0000))) & UINT64_C(0xffffffff);
    /* 0x107409: xor r8d, 0xf9eb0000 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf9eb0000))) & UINT64_C(0xffffffff);
    /* 0x107410: lea eax, [r8 + r8] */
    r[0] = ((((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107414: and eax, 0xfc9c0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfc9c0000))) & UINT64_C(0xffffffff);
    /* 0x107419: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10741b: add eax, r8d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10741e: add eax, 0x7e4e052a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7e4e052a))) & UINT64_C(0xffffffff);
    /* 0x107423: shl r12d, 0x10 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107427: add r12d, 0x88880000 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x88880000))) & UINT64_C(0xffffffff);
    /* 0x10742e: mov ecx, r12d */
    r[2] = (((r[12] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107431: xor ecx, 0x88880000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x88880000))) & UINT64_C(0xffffffff);
    /* 0x107437: and r12d, 0x170000 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x170000))) & UINT64_C(0xffffffff);
    /* 0x10743e: mov edi, ecx */
    r[5] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107440: and edi, 0x5fdf0000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5fdf0000))) & UINT64_C(0xffffffff);
    /* 0x107446: xor edi, r12d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ ((r[12] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107449: mov rsi, rdx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x10744c: add edx, edx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10744e: and edx, 0x79de7c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x79de7c))) & UINT64_C(0xffffffff);
    /* 0x107454: sub esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107456: mov qword ptr [rbp - 0xc8], rsi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8, ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10745d: add edi, edi */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10745f: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107461: add ecx, edi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107463: add ecx, 0x1fc8cde9 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1fc8cde9))) & UINT64_C(0xffffffff);
    /* 0x107469: shl r9d, 8 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10746d: add r9d, 0xbb3f2f00 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xbb3f2f00))) & UINT64_C(0xffffffff);
    /* 0x107474: xor r9d, 0xbb3f2f00 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbb3f2f00))) & UINT64_C(0xffffffff);
    /* 0x10747b: lea edx, [r9 + r9] */
    r[3] = ((((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10747f: and edx, 0xc31b7000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xc31b7000))) & UINT64_C(0xffffffff);
    /* 0x107485: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107487: add edx, r9d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10748a: add edx, 0x618db81a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x618db81a))) & UINT64_C(0xffffffff);
    /* 0x107490: xor edx, 0x618db81a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x618db81a))) & UINT64_C(0xffffffff);
    /* 0x107496: xor ecx, 0x1fc8cde9 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1fc8cde9))) & UINT64_C(0xffffffff);
    /* 0x10749c: or edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10749e: lea ecx, [rdx + rdx] */
    r[2] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1074a1: and ecx, 0xb61671c0 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xb61671c0))) & UINT64_C(0xffffffff);
    /* 0x1074a7: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1074a9: add edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1074ab: add edx, 0x5b0b38e0 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5b0b38e0))) & UINT64_C(0xffffffff);
    /* 0x1074b1: shl ebx, 8 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x1074b4: add ebx, 0xd4e9ce00 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd4e9ce00))) & UINT64_C(0xffffffff);
    /* 0x1074ba: xor ebx, 0xd4e9ce00 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd4e9ce00))) & UINT64_C(0xffffffff);
    /* 0x1074c0: lea ecx, [rbx + rbx] */
    r[2] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1074c3: and ecx, 0xcb987200 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xcb987200))) & UINT64_C(0xffffffff);
    /* 0x1074c9: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1074cb: lea r9d, [rbx + rcx] */
    r[9] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1074cf: add r9d, 0x65cc396a */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x65cc396a))) & UINT64_C(0xffffffff);
    /* 0x1074d6: lea ecx, [r11 + r11] */
    r[2] = ((((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1074da: and ecx, 0xa8b339fe */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa8b339fe))) & UINT64_C(0xffffffff);
    /* 0x1074e0: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1074e2: add ecx, r11d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1074e5: add ecx, 0x54599cff */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x54599cff))) & UINT64_C(0xffffffff);
    /* 0x1074eb: mov dword ptr [rbp - 0x270], ecx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 4, ((r[2] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1074f1: mov rcx, qword ptr [rbp - 0x3f0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc10)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1074f8: movzx ecx, byte ptr [r15 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107501: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107504: lea ebx, [rcx + rcx] */
    r[1] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107507: and ebx, 0x154 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x154))) & UINT64_C(0xffffffff);
    /* 0x10750d: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10750f: lea r11d, [rcx + rbx] */
    r[11] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107513: add r11d, 0x370d85aa */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x370d85aa))) & UINT64_C(0xffffffff);
    /* 0x10751a: xor r11d, 0x370d85aa */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x370d85aa))) & UINT64_C(0xffffffff);
    /* 0x107521: xor edx, 0x5b0b38e0 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5b0b38e0))) & UINT64_C(0xffffffff);
    /* 0x107527: or r11d, edx */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10752a: xor eax, 0x7e4e052a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7e4e052a))) & UINT64_C(0xffffffff);
    /* 0x10752f: xor r9d, 0x65cc396a */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x65cc396a))) & UINT64_C(0xffffffff);
    /* 0x107536: or r9d, eax */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107539: mov r10, qword ptr [rbp - 0x70] */
    r[10] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10753d: or r10d, 8 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x8))) & UINT64_C(0xffffffff);
    /* 0x107541: xor r10, 0x6c4f3f6 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f6))) & UINT64_C(0xffffffffffffffff);
    /* 0x107548: mov qword ptr [rbp - 0x70], r10 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff90)), 8, ((r[10] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10754c: mov r8, qword ptr [rbp - 0x50] */
    r[8] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffb0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107550: or r8d, 0xa */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0xa))) & UINT64_C(0xffffffff);
    /* 0x107554: xor r8, 0x6c4f3f4 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f4))) & UINT64_C(0xffffffffffffffff);
    /* 0x10755b: mov qword ptr [rbp - 0x50], r8 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffb0)), 8, ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10755f: mov rcx, qword ptr [rbp - 0x58] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffa8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107563: or ecx, 0xb */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0xb))) & UINT64_C(0xffffffff);
    /* 0x107566: xor rcx, 0x6c4f3f4 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f4))) & UINT64_C(0xffffffffffffffff);
    /* 0x10756d: mov qword ptr [rbp - 0x58], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffa8)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107571: mov r14, qword ptr [rbp - 0xc0] */
    r[14] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff40)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107578: or r14d, 4 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x4))) & UINT64_C(0xffffffff);
    /* 0x10757c: mov rbx, qword ptr [rbp - 0x98] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff68)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107583: xor rbx, 0x771377a9 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x771377a9))) & UINT64_C(0xffffffffffffffff);
    /* 0x10758a: mov qword ptr [rbp - 0x98], rbx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff68)), 8, ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107591: xor r14, 0x6c4f3f2 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f2))) & UINT64_C(0xffffffffffffffff);
    /* 0x107598: mov qword ptr [rbp - 0xc0], r14 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff40)), 8, ((r[14] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10759f: mov rax, qword ptr [rbp - 0xa0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff60)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1075a6: or eax, 7 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x7))) & UINT64_C(0xffffffff);
    /* 0x1075a9: xor rax, 0x6c4f3f0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f0))) & UINT64_C(0xffffffffffffffff);
    /* 0x1075af: mov rdi, rax */
    r[5] = (((r[0] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x1075b2: mov qword ptr [rbp - 0xa0], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff60)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1075b9: mov rdx, qword ptr [rbp - 0x68] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff98)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1075bd: xor rdx, 0x63b88ec9 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x63b88ec9))) & UINT64_C(0xffffffffffffffff);
    /* 0x1075c4: mov qword ptr [rbp - 0x68], rdx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff98)), 8, ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1075c8: mov r12, qword ptr [rbp - 0x60] */
    r[12] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffa0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1075cc: or r12d, 9 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) | UINT64_C(0x9))) & UINT64_C(0xffffffff);
    /* 0x1075d0: xor r12, 0x6c4f3f6 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x6c4f3f6))) & UINT64_C(0xffffffffffffffff);
    /* 0x1075d7: mov qword ptr [rbp - 0x60], r12 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffa0)), 8, ((r[12] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1075db: mov rsi, qword ptr [rbp - 0x140] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffec0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1075e2: movzx eax, byte ptr [rsi + rcx] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1075e6: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1075ef: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x1075f2: mov byte ptr [rbp - 0x108], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffef8)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x1075f8: mov rcx, qword ptr [rbp - 0x48] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffb8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1075fc: xor rcx, 0x78e1944 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x78e1944))) & UINT64_C(0xffffffffffffffff);
    /* 0x107603: mov qword ptr [rbp - 0x48], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffb8)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107607: movzx eax, byte ptr [rsi + rdi] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10760b: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107614: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x107617: mov byte ptr [rbp - 0xf8], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff08)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10761d: movzx eax, byte ptr [rsi + rdx] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107621: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10762a: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x10762d: mov byte ptr [rbp - 0xe0], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff20)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x107633: mov rdi, qword ptr [rbp - 0x78] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff88)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107637: xor rdi, 0x402ddf7c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x402ddf7c))) & UINT64_C(0xffffffffffffffff);
    /* 0x10763e: mov qword ptr [rbp - 0x78], rdi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff88)), 8, ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107642: mov rdx, qword ptr [rbp - 0x40] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffc0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107646: xor rdx, 0x66b1f6f8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) ^ UINT64_C(0x66b1f6f8))) & UINT64_C(0xffffffffffffffff);
    /* 0x10764d: mov qword ptr [rbp - 0x40], rdx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffc0)), 8, ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107651: movzx eax, byte ptr [rsi + r8] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107656: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10765f: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x107662: mov byte ptr [rbp - 0xb8], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff48)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x107668: movzx eax, byte ptr [rsi + rbx] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10766c: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107675: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x107678: mov byte ptr [rbp - 0xd8], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff28)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10767e: movzx eax, byte ptr [rsi + r10] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107683: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10768c: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x10768f: mov byte ptr [rbp - 0x100], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff00)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x107695: movzx eax, byte ptr [rsi + r14] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10769a: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1076a3: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x1076a6: mov byte ptr [rbp - 0xe8], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff18)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x1076ac: movzx eax, byte ptr [rsi + r12] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1076b1: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1076ba: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x1076bd: mov byte ptr [rbp - 0x128], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffed8)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x1076c3: movzx eax, byte ptr [rsi + rcx] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1076c7: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1076d0: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x1076d3: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1076d5: mov byte ptr [rbp - 0x228], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdd8)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x1076db: movzx eax, byte ptr [rsi + rdi] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1076df: movzx eax, byte ptr [r15 + rax + 0x4180] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1076e8: xor al, r13b */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ ((r[13] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x1076eb: mov byte ptr [rbp - 0x300], al */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd00)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x1076f1: movzx eax, byte ptr [rsi + rdx] */
    r[0] = (load(m, (((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1076f5: xor r13b, byte ptr [r15 + rax + 0x4180] */
    r[13] = (r[13] & UINT64_C(0xffffffffffffff00)) | ((((((r[13] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x4180)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x1076fd: mov byte ptr [rbp - 0x240], r13b */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc0)), 1, ((r[13] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x107704: lea eax, [r11 + r11] */
    r[0] = ((((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107708: and eax, 0xabe2f4 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xabe2f4))) & UINT64_C(0xffffffff);
    /* 0x10770d: sub r11d, eax */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107710: mov eax, dword ptr [rbp - 0x270] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107716: xor eax, 0x54599cff */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x54599cff))) & UINT64_C(0xffffffff);
    /* 0x10771b: mov r8, qword ptr [rbp - 0xa8] */
    r[8] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107722: xor r8d, 0x6599b7cd */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6599b7cd))) & UINT64_C(0xffffffff);
    /* 0x107729: or r8d, eax */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10772c: movzx eax, cl */
    r[0] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10772f: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107732: and edx, 0x78 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x78))) & UINT64_C(0xffffffff);
    /* 0x107735: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107737: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107739: add eax, 0x16346f3c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x16346f3c))) & UINT64_C(0xffffffff);
    /* 0x10773e: lea edx, [r8 + r8] */
    r[3] = ((((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107742: and edx, 0xff2cee */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xff2cee))) & UINT64_C(0xffffffff);
    /* 0x107748: sub r8d, edx */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10774b: lea edx, [r9 + r9] */
    r[3] = ((((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10774f: and edx, 0x564ee6bc */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x564ee6bc))) & UINT64_C(0xffffffff);
    /* 0x107755: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107757: add edx, r9d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10775a: add edx, 0x2b27735e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2b27735e))) & UINT64_C(0xffffffff);
    /* 0x107760: xor edx, 0x2b27735e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2b27735e))) & UINT64_C(0xffffffff);
    /* 0x107766: xor eax, 0x16346f3c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x16346f3c))) & UINT64_C(0xffffffff);
    /* 0x10776b: or eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10776d: shl r11d, 8 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107771: add r11d, 0xd5f17a00 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd5f17a00))) & UINT64_C(0xffffffff);
    /* 0x107778: xor r11d, 0xd5f17a00 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd5f17a00))) & UINT64_C(0xffffffff);
    /* 0x10777f: lea edx, [r11 + r11] */
    r[3] = ((((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107783: and edx, 0xe4794800 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe4794800))) & UINT64_C(0xffffffff);
    /* 0x107789: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10778b: lea ecx, [r11 + rdx] */
    r[2] = ((((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10778f: add ecx, 0x723ca424 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x723ca424))) & UINT64_C(0xffffffff);
    /* 0x107795: mov rsi, qword ptr [rbp - 0xc8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10779c: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10779f: add esi, 0x3cef3e00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3cef3e00))) & UINT64_C(0xffffffff);
    /* 0x1077a5: xor esi, 0x3cef3e00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3cef3e00))) & UINT64_C(0xffffffff);
    /* 0x1077ab: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1077ae: and edx, 0xd3d3a000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xd3d3a000))) & UINT64_C(0xffffffff);
    /* 0x1077b4: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1077b6: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1077b8: add edx, 0x69e9d07e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x69e9d07e))) & UINT64_C(0xffffffff);
    /* 0x1077be: lea edi, [rax + rax] */
    r[5] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1077c1: and edi, 0x47461a */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x47461a))) & UINT64_C(0xffffffff);
    /* 0x1077c7: sub eax, edi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1077c9: mov rdi, qword ptr [rbp - 0x520] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffae0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1077d0: movzx esi, byte ptr [r15 + rdi + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1077d9: mov dword ptr [rbp - 0xa8], esi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 4, ((r[4] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1077df: mov edi, esi */
    r[5] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1077e1: xor edi, 0x4c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1077e4: lea ebx, [rdi + rdi] */
    r[1] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1077e7: and ebx, 0x24 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x24))) & UINT64_C(0xffffffff);
    /* 0x1077ea: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1077ec: add edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1077ee: add edi, 0x37fdd112 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x37fdd112))) & UINT64_C(0xffffffff);
    /* 0x1077f4: xor edi, 0x37fdd112 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x37fdd112))) & UINT64_C(0xffffffff);
    /* 0x1077fa: xor edx, 0x69e9d07e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x69e9d07e))) & UINT64_C(0xffffffff);
    /* 0x107800: or edi, edx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107802: mov rsi, r8 */
    r[4] = (((r[8] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x107805: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107808: add esi, 0x7f967700 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7f967700))) & UINT64_C(0xffffffff);
    /* 0x10780e: xor esi, 0x7f967700 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7f967700))) & UINT64_C(0xffffffff);
    /* 0x107814: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107817: and edx, 0x549c5200 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x549c5200))) & UINT64_C(0xffffffff);
    /* 0x10781d: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10781f: add esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107821: add esi, 0x2a4e294b */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2a4e294b))) & UINT64_C(0xffffffff);
    /* 0x107827: movzx r11d, byte ptr [rbp - 0xd8] */
    r[11] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff28)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10782f: lea edx, [r11 + r11] */
    r[3] = ((((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107833: and edx, 0x7c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7c))) & UINT64_C(0xffffffff);
    /* 0x107836: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107838: add edx, r11d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10783b: add edx, 0x6402453e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6402453e))) & UINT64_C(0xffffffff);
    /* 0x107841: xor esi, 0x2a4e294b */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2a4e294b))) & UINT64_C(0xffffffff);
    /* 0x107847: xor edx, 0x6402453e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6402453e))) & UINT64_C(0xffffffff);
    /* 0x10784d: or edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10784f: mov rsi, qword ptr [rbp - 0x530] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffad0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107856: movzx esi, byte ptr [r15 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10785f: mov dword ptr [rbp - 0x270], esi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 4, ((r[4] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x107865: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107868: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10786b: and ebx, 0x120 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x120))) & UINT64_C(0xffffffff);
    /* 0x107871: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107873: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107875: add esi, 0x3e1b9690 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3e1b9690))) & UINT64_C(0xffffffff);
    /* 0x10787b: xor esi, 0x3e1b9690 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3e1b9690))) & UINT64_C(0xffffffff);
    /* 0x107881: xor ecx, 0x723ca424 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x723ca424))) & UINT64_C(0xffffffff);
    /* 0x107887: or esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107889: shl eax, 8 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10788c: add eax, 0xa3a30d00 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xa3a30d00))) & UINT64_C(0xffffffff);
    /* 0x107891: xor eax, 0xa3a30d00 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xa3a30d00))) & UINT64_C(0xffffffff);
    /* 0x107896: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107899: and ecx, 0xb9d88e00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xb9d88e00))) & UINT64_C(0xffffffff);
    /* 0x10789f: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078a1: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078a3: add eax, 0x5cec4703 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5cec4703))) & UINT64_C(0xffffffff);
    /* 0x1078a8: lea ecx, [rdx + rdx] */
    r[2] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1078ab: and ecx, 0x1f24be3a */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1f24be3a))) & UINT64_C(0xffffffff);
    /* 0x1078b1: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078b3: add edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078b5: add edx, 0xf925f1d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xf925f1d))) & UINT64_C(0xffffffff);
    /* 0x1078bb: movzx r10d, r13b */
    r[10] = (((r[13] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1078bf: lea ecx, [r10 + r10] */
    r[2] = ((((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1078c3: and ecx, 0xffffffe6 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffe6))) & UINT64_C(0xffffffff);
    /* 0x1078c6: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078c8: add ecx, r10d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[10] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078cb: add ecx, 0x4f578ef3 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4f578ef3))) & UINT64_C(0xffffffff);
    /* 0x1078d1: xor eax, 0x5cec4703 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5cec4703))) & UINT64_C(0xffffffff);
    /* 0x1078d6: xor ecx, 0x4f578ef3 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4f578ef3))) & UINT64_C(0xffffffff);
    /* 0x1078dc: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078de: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1078e1: and eax, 0x35a3cc98 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x35a3cc98))) & UINT64_C(0xffffffff);
    /* 0x1078e6: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078e8: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078ea: add eax, 0x1ad1e64c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1ad1e64c))) & UINT64_C(0xffffffff);
    /* 0x1078ef: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1078f2: and ecx, 0xcd4a7e82 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xcd4a7e82))) & UINT64_C(0xffffffff);
    /* 0x1078f8: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1078fa: lea r13d, [rsi + rcx] */
    r[13] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1078fe: add r13d, 0x66a53f41 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x66a53f41))) & UINT64_C(0xffffffff);
    /* 0x107905: xor r13d, eax */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107908: movzx ebx, byte ptr [rbp - 0xf8] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff08)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10790f: mov eax, ebx */
    r[0] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107911: and eax, 0x50 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x50))) & UINT64_C(0xffffffff);
    /* 0x107914: add eax, eax */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107916: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107918: lea r12d, [rbx + rax] */
    r[12] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10791c: add r12d, 0x3785df50 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3785df50))) & UINT64_C(0xffffffff);
    /* 0x107923: mov eax, r13d */
    r[0] = (((r[13] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107926: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107929: movzx ecx, al */
    r[2] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10792c: mov rax, qword ptr [rbp - 0x450] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbb0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107933: movzx r14d, byte ptr [r15 + rax + 0x2ee0] */
    r[14] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10793c: xor bl, r14b */
    r[1] = (r[1] & UINT64_C(0xffffffffffffff00)) | ((((((r[1] >> 0) & UINT64_C(0xff)) ^ ((r[14] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x10793f: xor bl, 0x4c */
    r[1] = (r[1] & UINT64_C(0xffffffffffffff00)) | ((((((r[1] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x4c))) & UINT64_C(0xff)) << 0);
    /* 0x107942: xor ecx, 0x74 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x74))) & UINT64_C(0xffffffff);
    /* 0x107945: movzx eax, bl */
    r[0] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107948: mov r8d, dword ptr [r15 + rax*4 + 0x3950] */
    r[8] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107950: xor r8d, dword ptr [r15 + rcx*4 + 0x2ff0] */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107958: lea eax, [rdi + rdi] */
    r[0] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10795b: and eax, 0x33f568d6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x33f568d6))) & UINT64_C(0xffffffff);
    /* 0x107960: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107962: lea ecx, [rdi + rax] */
    r[2] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107965: add ecx, 0x19fab46b */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x19fab46b))) & UINT64_C(0xffffffff);
    /* 0x10796b: xor ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10796d: mov eax, ecx */
    r[0] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10796f: movzx edx, ch */
    r[3] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107972: mov qword ptr [rbp - 0x2b0], rdx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 8, ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107979: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10797c: xor ecx, 0x16 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x16))) & UINT64_C(0xffffffff);
    /* 0x10797f: xor r8d, dword ptr [r15 + rcx*4 + 0x4ac0] */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107987: mov rcx, qword ptr [rbp - 0x358] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffca8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10798e: movzx ecx, byte ptr [r15 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107997: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10799a: lea esi, [rcx + rcx] */
    r[4] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10799d: and esi, 0xffffffc0 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffc0))) & UINT64_C(0xffffffff);
    /* 0x1079a0: sub ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1079a2: mov rdx, qword ptr [rbp - 0x6c0] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff940)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1079a9: movzx esi, byte ptr [r15 + rdx + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1079b2: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1079b5: mov edi, esi */
    r[5] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1079b7: and edi, 0x5c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5c))) & UINT64_C(0xffffffff);
    /* 0x1079ba: add edi, edi */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1079bc: sub esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1079be: movzx edi, byte ptr [rbp - 0xe8] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff18)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1079c5: lea edx, [rdi + rdi] */
    r[3] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1079c8: and edx, 0x7c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7c))) & UINT64_C(0xffffffff);
    /* 0x1079cb: sub edi, edx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1079cd: movzx edx, byte ptr [rbp - 0x300] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd00)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1079d4: mov ebx, edx */
    r[1] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1079d6: and ebx, 0x76 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x76))) & UINT64_C(0xffffffff);
    /* 0x1079d9: add ebx, ebx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1079db: sub edx, ebx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1079dd: shl ecx, 0x10 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1079e0: add ecx, 0xe8e00000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xe8e00000))) & UINT64_C(0xffffffff);
    /* 0x1079e6: xor ecx, 0xe8e00000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe8e00000))) & UINT64_C(0xffffffff);
    /* 0x1079ec: lea ebx, [rcx + rcx] */
    r[1] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1079ef: and ebx, 0xec40000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xec40000))) & UINT64_C(0xffffffff);
    /* 0x1079f5: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1079f7: add ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1079f9: add ecx, 0x76252af */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x76252af))) & UINT64_C(0xffffffff);
    /* 0x1079ff: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107a02: add esi, 0x82705c00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x82705c00))) & UINT64_C(0xffffffff);
    /* 0x107a08: xor esi, 0x82705c00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x82705c00))) & UINT64_C(0xffffffff);
    /* 0x107a0e: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107a11: and ebx, 0xc5140800 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xc5140800))) & UINT64_C(0xffffffff);
    /* 0x107a17: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a19: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a1b: add esi, 0x628a0420 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x628a0420))) & UINT64_C(0xffffffff);
    /* 0x107a21: xor ecx, 0x76252af */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x76252af))) & UINT64_C(0xffffffff);
    /* 0x107a27: xor esi, 0x628a0420 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x628a0420))) & UINT64_C(0xffffffff);
    /* 0x107a2d: or esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a2f: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107a32: and ecx, 0xc6ff4830 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xc6ff4830))) & UINT64_C(0xffffffff);
    /* 0x107a38: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a3a: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a3c: add ecx, 0x637fa418 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x637fa418))) & UINT64_C(0xffffffff);
    /* 0x107a42: shl edi, 0x10 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107a45: add edi, 0x643e0000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x643e0000))) & UINT64_C(0xffffffff);
    /* 0x107a4b: xor edi, 0x643e0000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x643e0000))) & UINT64_C(0xffffffff);
    /* 0x107a51: lea esi, [rdi + rdi] */
    r[4] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107a54: and esi, 0x954a0000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x954a0000))) & UINT64_C(0xffffffff);
    /* 0x107a5a: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a5c: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a5e: add esi, 0x4aa50b11 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4aa50b11))) & UINT64_C(0xffffffff);
    /* 0x107a64: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107a67: add edx, 0x2ff17600 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2ff17600))) & UINT64_C(0xffffffff);
    /* 0x107a6d: xor edx, 0x2ff17600 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2ff17600))) & UINT64_C(0xffffffff);
    /* 0x107a73: lea edi, [rdx + rdx] */
    r[5] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107a76: and edi, 0x58688800 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x58688800))) & UINT64_C(0xffffffff);
    /* 0x107a7c: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a7e: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a80: add edx, 0x2c344418 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2c344418))) & UINT64_C(0xffffffff);
    /* 0x107a86: xor esi, 0x4aa50b11 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4aa50b11))) & UINT64_C(0xffffffff);
    /* 0x107a8c: xor edx, 0x2c344418 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2c344418))) & UINT64_C(0xffffffff);
    /* 0x107a92: or edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a94: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107a97: and esi, 0xb1901c72 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xb1901c72))) & UINT64_C(0xffffffff);
    /* 0x107a9d: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107a9f: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107aa1: add edx, 0x58c80e39 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x58c80e39))) & UINT64_C(0xffffffff);
    /* 0x107aa7: movzx esi, byte ptr [rbp - 0xe0] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff20)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107aae: lea edi, [rsi + rsi] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107ab1: and edi, 0xffffffb8 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffb8))) & UINT64_C(0xffffffff);
    /* 0x107ab4: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107ab6: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107ab8: add esi, 0x558645dc */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x558645dc))) & UINT64_C(0xffffffff);
    /* 0x107abe: xor edx, 0x58c80e39 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x58c80e39))) & UINT64_C(0xffffffff);
    /* 0x107ac4: xor esi, 0x558645dc */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x558645dc))) & UINT64_C(0xffffffff);
    /* 0x107aca: or esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107acc: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107acf: and edx, 0x7de48e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7de48e))) & UINT64_C(0xffffffff);
    /* 0x107ad5: sub esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107ad7: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107ada: add esi, 0xbef24700 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xbef24700))) & UINT64_C(0xffffffff);
    /* 0x107ae0: xor esi, 0xbef24700 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbef24700))) & UINT64_C(0xffffffff);
    /* 0x107ae6: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107ae9: and edx, 0x366de000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x366de000))) & UINT64_C(0xffffffff);
    /* 0x107aef: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107af1: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107af3: add edx, 0x1b36f06f */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1b36f06f))) & UINT64_C(0xffffffff);
    /* 0x107af9: mov rsi, qword ptr [rbp - 0x448] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbb8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107b00: movzx esi, byte ptr [r15 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107b09: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107b0c: lea edi, [rsi + rsi] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107b0f: and edi, 0x2a */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2a))) & UINT64_C(0xffffffff);
    /* 0x107b12: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b14: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b16: add esi, 0x35fddf15 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x35fddf15))) & UINT64_C(0xffffffff);
    /* 0x107b1c: xor esi, 0x35fddf15 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x35fddf15))) & UINT64_C(0xffffffff);
    /* 0x107b22: xor ecx, 0x637fa418 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x637fa418))) & UINT64_C(0xffffffff);
    /* 0x107b28: or esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b2a: xor edx, 0x1b36f06f */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1b36f06f))) & UINT64_C(0xffffffff);
    /* 0x107b30: xor r12d, 0x3785df50 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3785df50))) & UINT64_C(0xffffffff);
    /* 0x107b37: or r12d, edx */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b3a: lea ecx, [r12 + r12] */
    r[2] = ((((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107b3e: and ecx, 0xfca9643e */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfca9643e))) & UINT64_C(0xffffffff);
    /* 0x107b44: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b46: add ecx, r12d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[12] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b49: add ecx, 0x7e54b21f */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7e54b21f))) & UINT64_C(0xffffffff);
    /* 0x107b4f: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107b52: and edx, 0x15ba30 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x15ba30))) & UINT64_C(0xffffffff);
    /* 0x107b58: sub esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b5a: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107b5d: add esi, 0xadd1800 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xadd1800))) & UINT64_C(0xffffffff);
    /* 0x107b63: xor esi, 0xadd1800 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xadd1800))) & UINT64_C(0xffffffff);
    /* 0x107b69: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107b6c: and edx, 0x17f38800 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x17f38800))) & UINT64_C(0xffffffff);
    /* 0x107b72: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b74: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b76: add edx, 0xbf9c49a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xbf9c49a))) & UINT64_C(0xffffffff);
    /* 0x107b7c: mov esi, r14d */
    r[4] = (((r[14] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107b7f: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107b82: lea edi, [rsi + rsi] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107b85: and edi, 0x30 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x30))) & UINT64_C(0xffffffff);
    /* 0x107b88: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b8a: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107b8c: add esi, 0x213ffc18 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x213ffc18))) & UINT64_C(0xffffffff);
    /* 0x107b92: xor edx, 0xbf9c49a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbf9c49a))) & UINT64_C(0xffffffff);
    /* 0x107b98: xor esi, 0x213ffc18 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x213ffc18))) & UINT64_C(0xffffffff);
    /* 0x107b9e: or esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107ba0: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107ba3: and edx, 0xad996696 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xad996696))) & UINT64_C(0xffffffff);
    /* 0x107ba9: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107bab: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107bad: add edx, 0x56ccb34b */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x56ccb34b))) & UINT64_C(0xffffffff);
    /* 0x107bb3: xor edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107bb5: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107bb8: mov ecx, edx */
    r[2] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107bba: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x107bbd: movzx esi, al */
    r[4] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107bc0: xor esi, 0x68 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x68))) & UINT64_C(0xffffffff);
    /* 0x107bc3: xor ecx, 0x28 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x28))) & UINT64_C(0xffffffff);
    /* 0x107bc6: mov eax, dword ptr [r15 + rcx*4 + 0x4ac0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107bce: xor eax, dword ptr [rbp - 0x5b0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa50)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107bd4: xor eax, dword ptr [r15 + rsi*4 + 0x2ff0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107bdc: mov ecx, r13d */
    r[2] = (((r[13] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107bdf: mov r12d, r13d */
    r[12] = (((r[13] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107be2: movzx ecx, ch */
    r[2] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107be5: xor ecx, 0xd9 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd9))) & UINT64_C(0xffffffff);
    /* 0x107beb: xor eax, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107bf3: mov r13d, edx */
    r[13] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107bf6: movzx ecx, dh */
    r[2] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107bf9: mov qword ptr [rbp - 0x220], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107c00: mov rcx, qword ptr [rbp - 0x2c8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107c07: movzx edx, byte ptr [r15 + rcx + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c10: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107c13: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c16: and esi, 0x64 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x64))) & UINT64_C(0xffffffff);
    /* 0x107c19: sub edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107c1b: mov rcx, qword ptr [rbp - 0x678] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff988)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107c22: movzx esi, byte ptr [r15 + rcx + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c2b: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107c2e: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c31: and ebx, 0x114 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x114))) & UINT64_C(0xffffffff);
    /* 0x107c37: sub esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107c39: movzx ebx, byte ptr [rbp - 0x100] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff00)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c40: lea edi, [rbx + rbx] */
    r[5] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c43: and edi, 0xffffff86 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff86))) & UINT64_C(0xffffffff);
    /* 0x107c46: sub ebx, edi */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107c48: shl edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107c4b: add edx, 0x25320000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x25320000))) & UINT64_C(0xffffffff);
    /* 0x107c51: xor edx, 0x25320000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x25320000))) & UINT64_C(0xffffffff);
    /* 0x107c57: lea edi, [rdx + rdx] */
    r[5] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c5a: and edi, 0x16020000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x16020000))) & UINT64_C(0xffffffff);
    /* 0x107c60: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107c62: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107c64: add edx, 0xb013773 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xb013773))) & UINT64_C(0xffffffff);
    /* 0x107c6a: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107c6d: add esi, 0x2c348a00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2c348a00))) & UINT64_C(0xffffffff);
    /* 0x107c73: xor esi, 0x2c348a00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2c348a00))) & UINT64_C(0xffffffff);
    /* 0x107c79: lea edi, [rsi + rsi] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c7c: and edi, 0x9a867400 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x9a867400))) & UINT64_C(0xffffffff);
    /* 0x107c82: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107c84: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107c86: add esi, 0x4d433af3 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4d433af3))) & UINT64_C(0xffffffff);
    /* 0x107c8c: movzx edi, byte ptr [rbp - 0x128] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffed8)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c93: lea ecx, [rdi + rdi] */
    r[2] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107c96: and ecx, 0x4a */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x4a))) & UINT64_C(0xffffffff);
    /* 0x107c99: sub edi, ecx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107c9b: xor edx, 0xb013773 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb013773))) & UINT64_C(0xffffffff);
    /* 0x107ca1: xor esi, 0x4d433af3 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4d433af3))) & UINT64_C(0xffffffff);
    /* 0x107ca7: or esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107ca9: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107cac: and ecx, 0x8a3a822e */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x8a3a822e))) & UINT64_C(0xffffffff);
    /* 0x107cb2: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107cb4: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107cb6: add ecx, 0x451d4117 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x451d4117))) & UINT64_C(0xffffffff);
    /* 0x107cbc: shl ebx, 0x10 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107cbf: add ebx, 0x84c30000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x84c30000))) & UINT64_C(0xffffffff);
    /* 0x107cc5: xor ebx, 0x84c30000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x84c30000))) & UINT64_C(0xffffffff);
    /* 0x107ccb: lea edx, [rbx + rbx] */
    r[3] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107cce: and edx, 0xa6920000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa6920000))) & UINT64_C(0xffffffff);
    /* 0x107cd4: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107cd6: add edx, ebx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107cd8: add edx, 0x53490311 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x53490311))) & UINT64_C(0xffffffff);
    /* 0x107cde: shl edi, 8 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107ce1: add edi, 0x1d492500 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1d492500))) & UINT64_C(0xffffffff);
    /* 0x107ce7: xor edi, 0x1d492500 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1d492500))) & UINT64_C(0xffffffff);
    /* 0x107ced: lea esi, [rdi + rdi] */
    r[4] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107cf0: and esi, 0x5f678a00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5f678a00))) & UINT64_C(0xffffffff);
    /* 0x107cf6: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107cf8: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107cfa: add esi, 0x2fb3c59b */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2fb3c59b))) & UINT64_C(0xffffffff);
    /* 0x107d00: xor edx, 0x53490311 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x53490311))) & UINT64_C(0xffffffff);
    /* 0x107d06: xor esi, 0x2fb3c59b */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2fb3c59b))) & UINT64_C(0xffffffff);
    /* 0x107d0c: or esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d0e: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107d11: and edx, 0x7eaa25e2 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7eaa25e2))) & UINT64_C(0xffffffff);
    /* 0x107d17: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d19: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d1b: add edx, 0x3f5512f1 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3f5512f1))) & UINT64_C(0xffffffff);
    /* 0x107d21: movzx esi, byte ptr [rbp - 0xb8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff48)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107d28: lea edi, [rsi + rsi] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107d2b: and edi, 0x104 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x104))) & UINT64_C(0xffffffff);
    /* 0x107d31: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d33: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d35: add esi, 0x68548082 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x68548082))) & UINT64_C(0xffffffff);
    /* 0x107d3b: xor esi, 0x68548082 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x68548082))) & UINT64_C(0xffffffff);
    /* 0x107d41: xor edx, 0x3f5512f1 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3f5512f1))) & UINT64_C(0xffffffff);
    /* 0x107d47: or esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d49: mov rdx, qword ptr [rbp - 0x4a8] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107d50: movzx edx, byte ptr [r15 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107d59: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107d5c: lea edi, [rdx + rdx] */
    r[5] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107d5f: and edi, 0xffffff90 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff90))) & UINT64_C(0xffffffff);
    /* 0x107d62: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d64: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d66: add edx, 0x1a7b3dc8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1a7b3dc8))) & UINT64_C(0xffffffff);
    /* 0x107d6c: xor ecx, 0x451d4117 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x451d4117))) & UINT64_C(0xffffffff);
    /* 0x107d72: xor edx, 0x1a7b3dc8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1a7b3dc8))) & UINT64_C(0xffffffff);
    /* 0x107d78: or edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d7a: lea ecx, [rdx + rdx] */
    r[2] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107d7d: and ecx, 0x3628e0 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x3628e0))) & UINT64_C(0xffffffff);
    /* 0x107d83: sub edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d85: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107d88: and ecx, 0x192262 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x192262))) & UINT64_C(0xffffffff);
    /* 0x107d8e: sub esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107d90: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107d93: add edx, 0x1b147000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1b147000))) & UINT64_C(0xffffffff);
    /* 0x107d99: xor edx, 0x1b147000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1b147000))) & UINT64_C(0xffffffff);
    /* 0x107d9f: lea ecx, [rdx + rdx] */
    r[2] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107da2: and ecx, 0x33ea0e00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x33ea0e00))) & UINT64_C(0xffffffff);
    /* 0x107da8: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107daa: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107dac: add ecx, 0x19f50749 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x19f50749))) & UINT64_C(0xffffffff);
    /* 0x107db2: mov rdx, qword ptr [rbp - 0x488] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb78)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107db9: movzx r14d, byte ptr [r15 + rdx + 0x2ee0] */
    r[14] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107dc2: mov edx, r14d */
    r[3] = (((r[14] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107dc5: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107dc8: lea ebx, [rdx + rdx] */
    r[1] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107dcb: and ebx, 0xffffffb0 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffb0))) & UINT64_C(0xffffffff);
    /* 0x107dce: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107dd0: add edx, ebx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107dd2: add edx, 0x6e176ed8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6e176ed8))) & UINT64_C(0xffffffff);
    /* 0x107dd8: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107ddb: add esi, 0x8c913100 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x8c913100))) & UINT64_C(0xffffffff);
    /* 0x107de1: xor esi, 0x8c913100 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x8c913100))) & UINT64_C(0xffffffff);
    /* 0x107de7: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107dea: and ebx, 0x7ce50000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7ce50000))) & UINT64_C(0xffffffff);
    /* 0x107df0: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107df2: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107df4: add esi, 0x3e728023 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3e728023))) & UINT64_C(0xffffffff);
    /* 0x107dfa: movzx ebx, byte ptr [rbp - 0x108] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffef8)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107e01: lea edi, [rbx + rbx] */
    r[5] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107e04: and edi, 0xa */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa))) & UINT64_C(0xffffffff);
    /* 0x107e07: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e09: add edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e0b: add edi, 0x4417ec05 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4417ec05))) & UINT64_C(0xffffffff);
    /* 0x107e11: xor esi, 0x3e728023 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3e728023))) & UINT64_C(0xffffffff);
    /* 0x107e17: xor edi, 0x4417ec05 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4417ec05))) & UINT64_C(0xffffffff);
    /* 0x107e1d: or edi, esi */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) | ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e1f: lea esi, [rdi + rdi] */
    r[4] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107e22: and esi, 0xca668612 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xca668612))) & UINT64_C(0xffffffff);
    /* 0x107e28: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e2a: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e2c: add esi, 0x65334309 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x65334309))) & UINT64_C(0xffffffff);
    /* 0x107e32: xor ecx, 0x19f50749 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x19f50749))) & UINT64_C(0xffffffff);
    /* 0x107e38: xor edx, 0x6e176ed8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6e176ed8))) & UINT64_C(0xffffffff);
    /* 0x107e3e: or edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e40: lea ecx, [rdx + rdx] */
    r[2] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107e43: and ecx, 0x31411af2 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x31411af2))) & UINT64_C(0xffffffff);
    /* 0x107e49: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e4b: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e4d: add ecx, 0x18a08d79 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x18a08d79))) & UINT64_C(0xffffffff);
    /* 0x107e53: xor ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107e55: mov edx, ecx */
    r[3] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107e57: movzx esi, ch */
    r[4] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107e5a: xor bl, r14b */
    r[1] = (r[1] & UINT64_C(0xffffffffffffff00)) | ((((((r[1] >> 0) & UINT64_C(0xff)) ^ ((r[14] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x107e5d: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x107e60: xor ecx, 0x7d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7d))) & UINT64_C(0xffffffff);
    /* 0x107e63: shr r13d, 0x10 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107e67: movzx edi, r13b */
    r[5] = (((r[13] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107e6b: xor edi, 0x98 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x98))) & UINT64_C(0xffffffff);
    /* 0x107e71: mov ecx, dword ptr [r15 + rcx*4 + 0x4ac0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107e79: xor ecx, dword ptr [rbp - 0x620] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff9e0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107e7f: xor ecx, dword ptr [r15 + rdi*4 + 0x2ff0] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107e87: xor bl, 0x4c */
    r[1] = (r[1] & UINT64_C(0xffffffffffffff00)) | ((((((r[1] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x4c))) & UINT64_C(0xff)) << 0);
    /* 0x107e8a: movzx edi, bl */
    r[5] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107e8d: xor eax, dword ptr [r15 + rdi*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107e95: mov r14d, eax */
    r[14] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107e98: movzx edi, al */
    r[5] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107e9b: mov qword ptr [rbp - 0xc8], rdi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8, ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107ea2: mov r13d, eax */
    r[13] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107ea5: movzx eax, ah */
    r[0] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107ea8: mov r9, rax */
    r[9] = (((r[0] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x107eab: mov rax, qword ptr [rbp - 0x2b0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107eb2: xor eax, 0xeb */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xeb))) & UINT64_C(0xffffffff);
    /* 0x107eb7: xor ecx, dword ptr [r15 + rax*4 + 0x46a0] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107ebf: xor r10b, byte ptr [rbp - 0x270] */
    r[10] = (r[10] & UINT64_C(0xffffffffffffff00)) | ((((((r[10] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x107ec6: xor r11b, byte ptr [rbp - 0xa8] */
    r[11] = (r[11] & UINT64_C(0xffffffffffffff00)) | ((((((r[11] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x107ecd: xor r10b, 0x4c */
    r[10] = (r[10] & UINT64_C(0xffffffffffffff00)) | ((((((r[10] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x4c))) & UINT64_C(0xff)) << 0);
    /* 0x107ed1: movzx eax, r10b */
    r[0] = (((r[10] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107ed5: xor ecx, dword ptr [r15 + rax*4 + 0x3950] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107edd: shr r12d, 0x18 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x107ee1: xor r12d, 0x7c */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7c))) & UINT64_C(0xffffffff);
    /* 0x107ee5: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107ee8: movzx eax, dl */
    r[0] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107eeb: xor eax, 0x93 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x93))) & UINT64_C(0xffffffff);
    /* 0x107ef0: mov edx, dword ptr [r15 + rax*4 + 0x2ff0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107ef8: xor edx, dword ptr [rbp - 0x640] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff9c0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107efe: xor edx, dword ptr [r15 + r12*4 + 0x4ac0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107f06: xor r11b, 0x4c */
    r[11] = (r[11] & UINT64_C(0xffffffffffffff00)) | ((((((r[11] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x4c))) & UINT64_C(0xff)) << 0);
    /* 0x107f0a: movzx eax, r11b */
    r[0] = (((r[11] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107f0e: xor edx, dword ptr [r15 + rax*4 + 0x3950] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107f16: mov r12d, ecx */
    r[12] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107f19: movzx eax, cl */
    r[0] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107f1c: mov qword ptr [rbp - 0xa8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107f23: mov eax, ecx */
    r[0] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107f25: movzx ecx, ch */
    r[2] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107f28: mov qword ptr [rbp - 0x270], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107f2f: mov rcx, qword ptr [rbp - 0x220] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107f36: xor ecx, 1 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1))) & UINT64_C(0xffffffff);
    /* 0x107f39: xor edx, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107f41: xor esi, 0xce */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xce))) & UINT64_C(0xffffffff);
    /* 0x107f47: xor r8d, dword ptr [r15 + rsi*4 + 0x46a0] */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107f4f: mov edi, edx */
    r[5] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107f51: movzx ecx, dl */
    r[2] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107f54: movzx esi, dh */
    r[4] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x107f57: mov qword ptr [rbp - 0x220], rsi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8, ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x107f5e: mov dword ptr [rbp - 0x208], edx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 4, ((r[3] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x107f64: mov rdx, qword ptr [rbp - 0x340] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffcc0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107f6b: movzx edx, byte ptr [r15 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107f74: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107f77: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107f7a: and esi, 0x152 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x152))) & UINT64_C(0xffffffff);
    /* 0x107f80: sub edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107f82: mov rsi, qword ptr [rbp - 0x6c8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff938)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x107f89: movzx esi, byte ptr [r15 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107f92: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x107f95: mov ebx, esi */
    r[1] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x107f97: and ebx, 0x45 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x45))) & UINT64_C(0xffffffff);
    /* 0x107f9a: add ebx, ebx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107f9c: sub esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107f9e: shl edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x107fa1: add edx, 0xeaa90000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xeaa90000))) & UINT64_C(0xffffffff);
    /* 0x107fa7: xor edx, 0xeaa90000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xeaa90000))) & UINT64_C(0xffffffff);
    /* 0x107fad: lea ebx, [rdx + rdx] */
    r[1] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107fb0: and ebx, 0x44d60000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x44d60000))) & UINT64_C(0xffffffff);
    /* 0x107fb6: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107fb8: add edx, ebx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107fba: add edx, 0x226bc666 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x226bc666))) & UINT64_C(0xffffffff);
    /* 0x107fc0: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x107fc3: add esi, 0xeb624500 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xeb624500))) & UINT64_C(0xffffffff);
    /* 0x107fc9: xor esi, 0xeb624500 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xeb624500))) & UINT64_C(0xffffffff);
    /* 0x107fcf: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107fd2: and ebx, 0x90a8e00 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x90a8e00))) & UINT64_C(0xffffffff);
    /* 0x107fd8: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107fda: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107fdc: add esi, 0x48547d5 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x48547d5))) & UINT64_C(0xffffffff);
    /* 0x107fe2: xor edx, 0x226bc666 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x226bc666))) & UINT64_C(0xffffffff);
    /* 0x107fe8: xor esi, 0x48547d5 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x48547d5))) & UINT64_C(0xffffffff);
    /* 0x107fee: or esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107ff0: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x107ff3: and edx, 0xabf7a06 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xabf7a06))) & UINT64_C(0xffffffff);
    /* 0x107ff9: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107ffb: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x107ffd: add edx, 0x55fbd03 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x55fbd03))) & UINT64_C(0xffffffff);
    /* 0x108003: mov rsi, qword ptr [rbp - 0x480] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb80)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10800a: movzx esi, byte ptr [r15 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108013: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108016: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108019: and ebx, 0xffffffd0 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffd0))) & UINT64_C(0xffffffff);
    /* 0x10801c: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10801e: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108020: add esi, 0x129236e8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x129236e8))) & UINT64_C(0xffffffff);
    /* 0x108026: xor esi, 0x129236e8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x129236e8))) & UINT64_C(0xffffffff);
    /* 0x10802c: xor edx, 0x55fbd03 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x55fbd03))) & UINT64_C(0xffffffff);
    /* 0x108032: or esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108034: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108037: and edx, 0xad2f7e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xad2f7e))) & UINT64_C(0xffffffff);
    /* 0x10803d: sub esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10803f: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x108042: add esi, 0xd697bf00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd697bf00))) & UINT64_C(0xffffffff);
    /* 0x108048: xor esi, 0xd697bf00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd697bf00))) & UINT64_C(0xffffffff);
    /* 0x10804e: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108051: and edx, 0x762d6a00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x762d6a00))) & UINT64_C(0xffffffff);
    /* 0x108057: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108059: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10805b: add edx, 0x3b16b5be */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3b16b5be))) & UINT64_C(0xffffffff);
    /* 0x108061: mov rsi, qword ptr [rbp - 0x420] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbe0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108068: movzx esi, byte ptr [r15 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108071: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108074: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108077: and ebx, 0xffffffce */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffce))) & UINT64_C(0xffffffff);
    /* 0x10807a: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10807c: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10807e: add esi, 0x69e4ffe7 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x69e4ffe7))) & UINT64_C(0xffffffff);
    /* 0x108084: xor edx, 0x3b16b5be */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3b16b5be))) & UINT64_C(0xffffffff);
    /* 0x10808a: xor esi, 0x69e4ffe7 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x69e4ffe7))) & UINT64_C(0xffffffff);
    /* 0x108090: or esi, edx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108092: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108095: and edx, 0xe921418e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe921418e))) & UINT64_C(0xffffffff);
    /* 0x10809b: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10809d: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10809f: add edx, 0x7490a0c7 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7490a0c7))) & UINT64_C(0xffffffff);
    /* 0x1080a5: mov ebx, r8d */
    r[1] = (((r[8] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1080a8: xor ebx, edx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1080aa: mov edx, ebx */
    r[3] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1080ac: movzx r11d, bl */
    r[11] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1080b0: movzx esi, bh */
    r[4] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1080b3: mov r8d, ebx */
    r[8] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1080b6: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1080b9: xor eax, 0x11 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x11))) & UINT64_C(0xffffffff);
    /* 0x1080bc: xor ecx, 0x6b */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6b))) & UINT64_C(0xffffffff);
    /* 0x1080bf: mov eax, dword ptr [r15 + rax*4 + 0x4ac0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1080c7: xor eax, dword ptr [rbp - 0x668] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff998)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1080cd: xor eax, dword ptr [r15 + rcx*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1080d5: shr r14d, 0x10 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1080d9: movzx ecx, r14b */
    r[2] = (((r[14] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1080dd: xor ecx, 0x3b */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3b))) & UINT64_C(0xffffffff);
    /* 0x1080e0: xor eax, dword ptr [r15 + rcx*4 + 0x2ff0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1080e8: xor esi, 0x52 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x52))) & UINT64_C(0xffffffff);
    /* 0x1080eb: xor eax, dword ptr [r15 + rsi*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1080f3: shr r12d, 0x10 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1080f7: movzx ecx, r12b */
    r[2] = (((r[12] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1080fb: xor ecx, 0xf1 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf1))) & UINT64_C(0xffffffff);
    /* 0x108101: shr edi, 0x18 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108104: xor edi, 0x47 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x47))) & UINT64_C(0xffffffff);
    /* 0x108107: mov ecx, dword ptr [r15 + rcx*4 + 0x2ff0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10810f: xor ecx, dword ptr [rbp - 0x638] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff9c8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108115: xor ecx, dword ptr [r15 + rdi*4 + 0x4ac0] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10811d: xor r9d, 0x6d */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6d))) & UINT64_C(0xffffffff);
    /* 0x108121: xor ecx, dword ptr [r15 + r9*4 + 0x46a0] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108129: shr r13d, 0x18 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10812d: xor r13d, 0x10 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x10))) & UINT64_C(0xffffffff);
    /* 0x108131: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108134: movzx esi, dl */
    r[4] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108137: mov edx, dword ptr [r15 + r13*4 + 0x4ac0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10813f: xor edx, dword ptr [rbp - 0x680] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff980)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108145: xor esi, 1 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1))) & UINT64_C(0xffffffff);
    /* 0x108148: xor edx, dword ptr [r15 + rsi*4 + 0x2ff0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108150: mov r12d, eax */
    r[12] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108153: movzx esi, al */
    r[4] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108156: mov qword ptr [rbp - 0x2b0], rsi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 8, ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10815d: movzx esi, ah */
    r[4] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108160: mov qword ptr [rbp - 0x188], rsi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8, ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108167: mov r14d, eax */
    r[14] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10816a: mov rax, qword ptr [rbp - 0x220] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108171: xor eax, 7 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7))) & UINT64_C(0xffffffff);
    /* 0x108174: xor edx, dword ptr [r15 + rax*4 + 0x46a0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10817c: xor r11d, 0x77 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x77))) & UINT64_C(0xffffffff);
    /* 0x108180: xor ecx, dword ptr [r15 + r11*4 + 0x3950] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108188: mov r13d, ecx */
    r[13] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10818b: movzx r11d, cl */
    r[11] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10818f: movzx eax, ch */
    r[0] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108192: mov qword ptr [rbp - 0x238], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108199: mov edi, ecx */
    r[5] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10819b: mov rax, qword ptr [rbp - 0x350] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffcb0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1081a2: movzx eax, byte ptr [r15 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1081ab: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1081ae: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1081b1: and ecx, 0x52 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x52))) & UINT64_C(0xffffffff);
    /* 0x1081b4: sub eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1081b6: mov rcx, qword ptr [rbp - 0x6b8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff948)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1081bd: movzx ecx, byte ptr [r15 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1081c6: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1081c9: mov ebx, ecx */
    r[1] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1081cb: and ebx, 0x5f */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5f))) & UINT64_C(0xffffffff);
    /* 0x1081ce: add ebx, ebx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1081d0: sub ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1081d2: shl eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1081d5: add eax, 0x51290000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x51290000))) & UINT64_C(0xffffffff);
    /* 0x1081da: xor eax, 0x51290000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x51290000))) & UINT64_C(0xffffffff);
    /* 0x1081df: lea ebx, [rax + rax] */
    r[1] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1081e2: and ebx, 0xdd180000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xdd180000))) & UINT64_C(0xffffffff);
    /* 0x1081e8: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1081ea: add eax, ebx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1081ec: add eax, 0x6e8c8af3 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6e8c8af3))) & UINT64_C(0xffffffff);
    /* 0x1081f1: shl ecx, 8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x1081f4: add ecx, 0x86f45f00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x86f45f00))) & UINT64_C(0xffffffff);
    /* 0x1081fa: xor ecx, 0x86f45f00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x86f45f00))) & UINT64_C(0xffffffff);
    /* 0x108200: lea ebx, [rcx + rcx] */
    r[1] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108203: and ebx, 0xcde1ea00 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xcde1ea00))) & UINT64_C(0xffffffff);
    /* 0x108209: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10820b: add ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10820d: add ecx, 0x66f0f526 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x66f0f526))) & UINT64_C(0xffffffff);
    /* 0x108213: xor eax, 0x6e8c8af3 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6e8c8af3))) & UINT64_C(0xffffffff);
    /* 0x108218: xor ecx, 0x66f0f526 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x66f0f526))) & UINT64_C(0xffffffff);
    /* 0x10821e: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108220: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108223: and eax, 0x1c54f172 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1c54f172))) & UINT64_C(0xffffffff);
    /* 0x108228: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10822a: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10822c: add eax, 0xe2a78b9 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xe2a78b9))) & UINT64_C(0xffffffff);
    /* 0x108231: mov rcx, qword ptr [rbp - 0x498] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb68)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108238: movzx ecx, byte ptr [r15 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108241: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108244: mov ebx, ecx */
    r[1] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108246: and ebx, 0x4d */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x4d))) & UINT64_C(0xffffffff);
    /* 0x108249: add ebx, ebx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10824b: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10824d: add ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10824f: add ecx, 0x4948e14d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4948e14d))) & UINT64_C(0xffffffff);
    /* 0x108255: xor ecx, 0x4948e14d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4948e14d))) & UINT64_C(0xffffffff);
    /* 0x10825b: xor eax, 0xe2a78b9 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe2a78b9))) & UINT64_C(0xffffffff);
    /* 0x108260: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108262: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108265: and eax, 0xa33940 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa33940))) & UINT64_C(0xffffffff);
    /* 0x10826a: sub ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10826c: shl ecx, 8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10826f: add ecx, 0xd19ca000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd19ca000))) & UINT64_C(0xffffffff);
    /* 0x108275: xor ecx, 0xd19ca000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd19ca000))) & UINT64_C(0xffffffff);
    /* 0x10827b: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10827e: and eax, 0x7e3b0200 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7e3b0200))) & UINT64_C(0xffffffff);
    /* 0x108283: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108285: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108287: add eax, 0x3f1d8126 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3f1d8126))) & UINT64_C(0xffffffff);
    /* 0x10828c: mov rcx, qword ptr [rbp - 0x460] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffba0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108293: movzx ecx, byte ptr [r15 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10829c: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10829f: mov ebx, ecx */
    r[1] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1082a1: and ebx, 0x42 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x42))) & UINT64_C(0xffffffff);
    /* 0x1082a4: add ebx, ebx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1082a6: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1082a8: add ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1082aa: add ecx, 0x23663c42 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x23663c42))) & UINT64_C(0xffffffff);
    /* 0x1082b0: xor eax, 0x3f1d8126 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3f1d8126))) & UINT64_C(0xffffffff);
    /* 0x1082b5: xor ecx, 0x23663c42 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x23663c42))) & UINT64_C(0xffffffff);
    /* 0x1082bb: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1082bd: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1082c0: and eax, 0x2f3bf3e2 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2f3bf3e2))) & UINT64_C(0xffffffff);
    /* 0x1082c5: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1082c7: mov rsi, qword ptr [rbp - 0xc8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1082ce: xor esi, 0x83 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x83))) & UINT64_C(0xffffffff);
    /* 0x1082d4: lea ebx, [rcx + rax] */
    r[1] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1082d7: add ebx, 0x179df9f1 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x179df9f1))) & UINT64_C(0xffffffff);
    /* 0x1082dd: xor ebx, dword ptr [r15 + rsi*4 + 0x3950] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1082e5: mov rax, qword ptr [rbp - 0x270] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1082ec: xor eax, 0x7d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7d))) & UINT64_C(0xffffffff);
    /* 0x1082ef: xor ebx, dword ptr [r15 + rax*4 + 0x46a0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1082f7: shr r8d, 0x18 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1082fb: xor r8d, 0x4e */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4e))) & UINT64_C(0xffffffff);
    /* 0x1082ff: xor ebx, dword ptr [r15 + r8*4 + 0x4ac0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108307: mov eax, dword ptr [rbp - 0x208] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10830d: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108310: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108313: xor eax, 0xb5 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb5))) & UINT64_C(0xffffffff);
    /* 0x108318: xor ebx, dword ptr [r15 + rax*4 + 0x2ff0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108320: mov eax, ebx */
    r[0] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108322: movzx r9d, bl */
    r[9] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108326: movzx ecx, bh */
    r[2] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108329: mov qword ptr [rbp - 0x220], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108330: mov dword ptr [rbp - 0x270], ebx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 4, ((r[1] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x108336: mov rcx, qword ptr [rbp - 0x468] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb98)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10833d: movzx ebx, byte ptr [r15 + rcx + 0x2ee0] */
    r[1] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108346: xor ebx, 0x4c */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108349: lea ecx, [rbx + rbx] */
    r[2] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10834c: and ecx, 0xffffffd6 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffd6))) & UINT64_C(0xffffffff);
    /* 0x10834f: sub ebx, ecx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108351: mov rcx, qword ptr [rbp - 0x6d0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff930)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108358: movzx ecx, byte ptr [r15 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108361: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108364: lea esi, [rcx + rcx] */
    r[4] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108367: and esi, 0xffffffc8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffc8))) & UINT64_C(0xffffffff);
    /* 0x10836a: sub ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10836c: shl ebx, 0x10 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10836f: add ebx, 0x6feb0000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6feb0000))) & UINT64_C(0xffffffff);
    /* 0x108375: xor ebx, 0x6feb0000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6feb0000))) & UINT64_C(0xffffffff);
    /* 0x10837b: lea esi, [rbx + rbx] */
    r[4] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10837e: and esi, 0x1fe20000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1fe20000))) & UINT64_C(0xffffffff);
    /* 0x108384: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108386: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108388: add esi, 0xff1fea2 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xff1fea2))) & UINT64_C(0xffffffff);
    /* 0x10838e: shl ecx, 8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x108391: add ecx, 0xac55e400 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xac55e400))) & UINT64_C(0xffffffff);
    /* 0x108397: xor ecx, 0xac55e400 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xac55e400))) & UINT64_C(0xffffffff);
    /* 0x10839d: lea ebx, [rcx + rcx] */
    r[1] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1083a0: and ebx, 0x3f334400 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x3f334400))) & UINT64_C(0xffffffff);
    /* 0x1083a6: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1083a8: add ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1083aa: add ecx, 0x1f99a2ab */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1f99a2ab))) & UINT64_C(0xffffffff);
    /* 0x1083b0: xor esi, 0xff1fea2 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xff1fea2))) & UINT64_C(0xffffffff);
    /* 0x1083b6: xor ecx, 0x1f99a2ab */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1f99a2ab))) & UINT64_C(0xffffffff);
    /* 0x1083bc: or ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1083be: lea esi, [rcx + rcx] */
    r[4] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1083c1: and esi, 0xa4882ab2 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa4882ab2))) & UINT64_C(0xffffffff);
    /* 0x1083c7: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1083c9: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1083cb: add ecx, 0x52441559 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x52441559))) & UINT64_C(0xffffffff);
    /* 0x1083d1: mov rsi, qword ptr [rbp - 0x440] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbc0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1083d8: movzx esi, byte ptr [r15 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1083e1: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1083e4: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1083e7: and ebx, 0x56 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x56))) & UINT64_C(0xffffffff);
    /* 0x1083ea: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1083ec: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1083ee: add esi, 0x560b492b */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x560b492b))) & UINT64_C(0xffffffff);
    /* 0x1083f4: xor esi, 0x560b492b */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x560b492b))) & UINT64_C(0xffffffff);
    /* 0x1083fa: xor ecx, 0x52441559 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x52441559))) & UINT64_C(0xffffffff);
    /* 0x108400: or esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108402: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108405: and ecx, 0x873492 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x873492))) & UINT64_C(0xffffffff);
    /* 0x10840b: sub esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10840d: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x108410: add esi, 0x439a4900 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x439a4900))) & UINT64_C(0xffffffff);
    /* 0x108416: xor esi, 0x439a4900 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x439a4900))) & UINT64_C(0xffffffff);
    /* 0x10841c: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10841f: and ecx, 0xb018d800 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xb018d800))) & UINT64_C(0xffffffff);
    /* 0x108425: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108427: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108429: add ecx, 0x580c6c62 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x580c6c62))) & UINT64_C(0xffffffff);
    /* 0x10842f: mov rsi, qword ptr [rbp - 0x4f8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb08)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108436: movzx esi, byte ptr [r15 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10843f: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108442: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108445: and ebx, 0x14e */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x14e))) & UINT64_C(0xffffffff);
    /* 0x10844b: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10844d: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10844f: add esi, 0x748365a7 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x748365a7))) & UINT64_C(0xffffffff);
    /* 0x108455: mov rbx, qword ptr [rbp - 0xa8] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10845c: xor ebx, 0x9a */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9a))) & UINT64_C(0xffffffff);
    /* 0x108462: xor edx, dword ptr [r15 + rbx*4 + 0x3950] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10846a: xor ecx, 0x580c6c62 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x580c6c62))) & UINT64_C(0xffffffff);
    /* 0x108470: xor esi, 0x748365a7 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x748365a7))) & UINT64_C(0xffffffff);
    /* 0x108476: or esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108478: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10847b: and ecx, 0x18cfe052 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x18cfe052))) & UINT64_C(0xffffffff);
    /* 0x108481: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108483: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108485: add ecx, 0xc67f029 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xc67f029))) & UINT64_C(0xffffffff);
    /* 0x10848b: movzx esi, dl */
    r[4] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10848e: xor esi, 0xea */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xea))) & UINT64_C(0xffffffff);
    /* 0x108494: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108497: and ebx, 0x12 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x12))) & UINT64_C(0xffffffff);
    /* 0x10849a: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10849c: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10849e: add esi, 0x58a59809 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x58a59809))) & UINT64_C(0xffffffff);
    /* 0x1084a4: xor esi, 0x18bc8a29 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x18bc8a29))) & UINT64_C(0xffffffff);
    /* 0x1084aa: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1084ad: and ebx, 0x2202c2 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2202c2))) & UINT64_C(0xffffffff);
    /* 0x1084b3: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1084b5: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1084b7: add esi, 0x3675a161 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3675a161))) & UINT64_C(0xffffffff);
    /* 0x1084bd: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1084c0: xor eax, 0x2d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2d))) & UINT64_C(0xffffffff);
    /* 0x1084c3: xor esi, 0x766cb36d */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x766cb36d))) & UINT64_C(0xffffffff);
    /* 0x1084c9: mov ebx, dword ptr [r15 + rsi*4 + 0x3950] */
    r[1] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1084d1: xor ebx, dword ptr [r15 + rax*4 + 0x4ac0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1084d9: xor ebx, ecx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1084db: shr r13d, 0x10 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1084df: movzx eax, r13b */
    r[0] = (((r[13] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1084e3: xor eax, 0xc */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc))) & UINT64_C(0xffffffff);
    /* 0x1084e6: xor ebx, dword ptr [r15 + rax*4 + 0x2ff0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1084ee: mov eax, edx */
    r[0] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1084f0: movzx ecx, dh */
    r[2] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1084f3: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1084f6: movzx r8d, dl */
    r[8] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1084fa: mov rdx, qword ptr [rbp - 0x188] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108501: xor edx, 0x7a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7a))) & UINT64_C(0xffffffff);
    /* 0x108504: xor ebx, dword ptr [r15 + rdx*4 + 0x46a0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10850c: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10850f: xor eax, 0x21 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x21))) & UINT64_C(0xffffffff);
    /* 0x108512: mov rdx, qword ptr [rbp - 0x238] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108519: xor edx, 0x54 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x54))) & UINT64_C(0xffffffff);
    /* 0x10851c: mov r10d, dword ptr [r15 + rax*4 + 0x4ac0] */
    r[10] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108524: xor r10d, dword ptr [rbp - 0x608] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff9f8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10852b: xor r10d, dword ptr [r15 + rdx*4 + 0x46a0] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108533: xor ecx, 0x52 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x52))) & UINT64_C(0xffffffff);
    /* 0x108536: shr edi, 0x18 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108539: xor edi, 0x62 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x62))) & UINT64_C(0xffffffff);
    /* 0x10853c: mov edx, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108544: xor edx, dword ptr [rbp - 0x628] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff9d8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10854a: xor edx, dword ptr [r15 + rdi*4 + 0x4ac0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108552: shr r14d, 0x10 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108556: movzx eax, r14b */
    r[0] = (((r[14] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10855a: xor eax, 0xc7 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc7))) & UINT64_C(0xffffffff);
    /* 0x10855f: xor edx, dword ptr [r15 + rax*4 + 0x2ff0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108567: mov r13d, ebx */
    r[13] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10856a: movzx eax, bl */
    r[0] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10856d: mov qword ptr [rbp - 0x188], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108574: movzx eax, bh */
    r[0] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108577: mov qword ptr [rbp - 0xc8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10857e: mov dword ptr [rbp - 0x238], ebx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 4, ((r[1] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x108584: xor r9d, 0x41 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x41))) & UINT64_C(0xffffffff);
    /* 0x108588: xor edx, dword ptr [r15 + r9*4 + 0x3950] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108590: xor r8d, 0x34 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x34))) & UINT64_C(0xffffffff);
    /* 0x108594: shr r12d, 0x18 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108598: xor r12d, 0x20 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x20))) & UINT64_C(0xffffffff);
    /* 0x10859c: mov eax, dword ptr [r15 + r8*4 + 0x2ff0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1085a4: xor eax, dword ptr [rbp - 0x5d0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa30)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1085aa: xor eax, dword ptr [r15 + r12*4 + 0x4ac0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1085b2: mov edi, edx */
    r[5] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1085b4: movzx ecx, dl */
    r[2] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1085b7: mov qword ptr [rbp - 0x258], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffda8)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1085be: movzx ebx, dh */
    r[1] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1085c1: mov r12d, edx */
    r[12] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1085c4: mov rcx, qword ptr [rbp - 0x220] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1085cb: xor ecx, 0xb */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb))) & UINT64_C(0xffffffff);
    /* 0x1085ce: xor eax, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1085d6: xor r11d, 0x88 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x88))) & UINT64_C(0xffffffff);
    /* 0x1085dd: xor eax, dword ptr [r15 + r11*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1085e5: mov r8d, eax */
    r[8] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1085e8: movzx r9d, al */
    r[9] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1085ec: movzx ecx, ah */
    r[2] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1085ef: mov r11d, eax */
    r[11] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1085f2: mov rax, qword ptr [rbp - 0x3b0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc50)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1085f9: movzx eax, byte ptr [r15 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108602: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108605: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108608: and edx, 0x18 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x18))) & UINT64_C(0xffffffff);
    /* 0x10860b: sub eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10860d: mov rdx, qword ptr [rbp - 0x738] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff8c8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108614: movzx edx, byte ptr [r15 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10861d: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108620: lea r14d, [rdx + rdx] */
    r[14] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108624: and r14d, 0x13e */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x13e))) & UINT64_C(0xffffffff);
    /* 0x10862b: sub edx, r14d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[14] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10862e: shl eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108631: add eax, 0x740c0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x740c0000))) & UINT64_C(0xffffffff);
    /* 0x108636: xor eax, 0x740c0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x740c0000))) & UINT64_C(0xffffffff);
    /* 0x10863b: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10863e: and esi, 0x33b80000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x33b80000))) & UINT64_C(0xffffffff);
    /* 0x108644: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108646: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108648: add eax, 0x19dc4923 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x19dc4923))) & UINT64_C(0xffffffff);
    /* 0x10864d: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x108650: add edx, 0xe0ac9f00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xe0ac9f00))) & UINT64_C(0xffffffff);
    /* 0x108656: xor edx, 0xe0ac9f00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe0ac9f00))) & UINT64_C(0xffffffff);
    /* 0x10865c: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10865f: and esi, 0x69f03200 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x69f03200))) & UINT64_C(0xffffffff);
    /* 0x108665: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108667: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108669: add edx, 0x34f819bc */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x34f819bc))) & UINT64_C(0xffffffff);
    /* 0x10866f: xor eax, 0x19dc4923 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x19dc4923))) & UINT64_C(0xffffffff);
    /* 0x108674: xor edx, 0x34f819bc */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x34f819bc))) & UINT64_C(0xffffffff);
    /* 0x10867a: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10867c: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10867f: and eax, 0x79d693a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x79d693a))) & UINT64_C(0xffffffff);
    /* 0x108684: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108686: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108688: add eax, 0x3ceb49d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3ceb49d))) & UINT64_C(0xffffffff);
    /* 0x10868d: mov rdx, qword ptr [rbp - 0x458] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffba8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108694: movzx edx, byte ptr [r15 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10869d: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1086a0: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1086a3: and esi, 0x10e */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x10e))) & UINT64_C(0xffffffff);
    /* 0x1086a9: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1086ab: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1086ad: add edx, 0x46657887 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x46657887))) & UINT64_C(0xffffffff);
    /* 0x1086b3: xor edx, 0x46657887 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x46657887))) & UINT64_C(0xffffffff);
    /* 0x1086b9: xor eax, 0x3ceb49d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3ceb49d))) & UINT64_C(0xffffffff);
    /* 0x1086be: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1086c0: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1086c3: and eax, 0x9cbfce */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x9cbfce))) & UINT64_C(0xffffffff);
    /* 0x1086c8: sub edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1086ca: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x1086cd: add edx, 0xce5fe700 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xce5fe700))) & UINT64_C(0xffffffff);
    /* 0x1086d3: xor edx, 0xce5fe700 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xce5fe700))) & UINT64_C(0xffffffff);
    /* 0x1086d9: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1086dc: and eax, 0xa0728000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa0728000))) & UINT64_C(0xffffffff);
    /* 0x1086e1: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1086e3: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1086e5: add eax, 0x5039408c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5039408c))) & UINT64_C(0xffffffff);
    /* 0x1086ea: mov edx, dword ptr [rbp - 0x270] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1086f0: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1086f3: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1086f6: xor edx, 0xc */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc))) & UINT64_C(0xffffffff);
    /* 0x1086f9: xor r10d, dword ptr [r15 + rdx*4 + 0x2ff0] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108701: mov rdx, qword ptr [rbp - 0x518] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffae8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108708: movzx edx, byte ptr [r15 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108711: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108714: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108716: and esi, 0x5b */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5b))) & UINT64_C(0xffffffff);
    /* 0x108719: add esi, esi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10871b: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10871d: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10871f: add edx, 0xe85f85b */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xe85f85b))) & UINT64_C(0xffffffff);
    /* 0x108725: xor edx, 0xe85f85b */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe85f85b))) & UINT64_C(0xffffffff);
    /* 0x10872b: xor eax, 0x5039408c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5039408c))) & UINT64_C(0xffffffff);
    /* 0x108730: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108732: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108735: and eax, 0xba5456d8 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xba5456d8))) & UINT64_C(0xffffffff);
    /* 0x10873a: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10873c: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10873e: add eax, 0x5d2a2b6c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5d2a2b6c))) & UINT64_C(0xffffffff);
    /* 0x108743: mov rdx, qword ptr [rbp - 0x2b0] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10874a: xor edx, 0xb1 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb1))) & UINT64_C(0xffffffff);
    /* 0x108750: xor r10d, dword ptr [r15 + rdx*4 + 0x3950] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108758: shr r13d, 0x18 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10875c: shr edi, 0x10 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10875f: movzx edx, dil */
    r[3] = (((r[5] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108763: xor r13d, 0x36 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x36))) & UINT64_C(0xffffffff);
    /* 0x108767: xor edx, 0x6c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c))) & UINT64_C(0xffffffff);
    /* 0x10876a: mov edx, dword ptr [r15 + rdx*4 + 0x2ff0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108772: xor edx, dword ptr [r15 + r13*4 + 0x4ac0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10877a: movzx esi, r10b */
    r[4] = (((r[10] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10877e: xor esi, 0x41 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x41))) & UINT64_C(0xffffffff);
    /* 0x108781: xor edx, dword ptr [r15 + rsi*4 + 0x3950] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108789: xor edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10878b: xor ecx, 3 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3))) & UINT64_C(0xffffffff);
    /* 0x10878e: xor edx, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108796: mov dword ptr [rbp - 0x208], edx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 4, ((r[3] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x10879c: movzx eax, dl */
    r[0] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10879f: mov qword ptr [rbp - 0x220], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1087a6: movzx eax, dh */
    r[0] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1087a9: mov qword ptr [rbp - 0x270], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1087b0: mov eax, edx */
    r[0] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1087b2: mov qword ptr [rbp - 0xa8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1087b9: shr r12d, 0x18 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1087bd: xor r12d, 0xb */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb))) & UINT64_C(0xffffffff);
    /* 0x1087c1: shr r8d, 0x10 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1087c5: movzx ecx, r8b */
    r[2] = (((r[8] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1087c9: xor ecx, 0x38 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x38))) & UINT64_C(0xffffffff);
    /* 0x1087cc: mov eax, dword ptr [r15 + r12*4 + 0x4ac0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1087d4: xor eax, dword ptr [rbp - 0x690] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff970)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1087da: xor eax, dword ptr [r15 + rcx*4 + 0x2ff0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1087e2: mov edx, r10d */
    r[3] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1087e5: movzx ecx, dh */
    r[2] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1087e8: xor ecx, 0x27 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x27))) & UINT64_C(0xffffffff);
    /* 0x1087eb: xor eax, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1087f3: mov ecx, dword ptr [rbp - 0x238] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1087f9: shr ecx, 0x10 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1087fc: movzx ecx, cl */
    r[2] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1087ff: mov esi, r10d */
    r[4] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108802: mov edi, r10d */
    r[5] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108805: shr esi, 0x18 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108808: xor esi, 0x12 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x12))) & UINT64_C(0xffffffff);
    /* 0x10880b: xor ecx, 0xf6 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf6))) & UINT64_C(0xffffffff);
    /* 0x108811: mov edx, dword ptr [r15 + rcx*4 + 0x2ff0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108819: xor edx, dword ptr [rbp - 0x618] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff9e8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10881f: xor edx, dword ptr [r15 + rsi*4 + 0x4ac0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108827: xor ebx, 0xb3 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb3))) & UINT64_C(0xffffffff);
    /* 0x10882d: xor edx, dword ptr [r15 + rbx*4 + 0x46a0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108835: shr edi, 0x10 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108838: movzx ecx, dil */
    r[2] = (((r[5] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10883c: mov rsi, qword ptr [rbp - 0x188] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108843: xor esi, 0x99 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x99))) & UINT64_C(0xffffffff);
    /* 0x108849: xor eax, dword ptr [r15 + rsi*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108851: mov rsi, qword ptr [rbp - 0xc8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108858: xor esi, 2 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2))) & UINT64_C(0xffffffff);
    /* 0x10885b: shr r11d, 0x18 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10885f: xor r11d, 0x67 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x67))) & UINT64_C(0xffffffff);
    /* 0x108863: mov ebx, dword ptr [r15 + rsi*4 + 0x46a0] */
    r[1] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10886b: xor ebx, dword ptr [rbp - 0x698] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff968)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108871: xor ebx, dword ptr [r15 + r11*4 + 0x4ac0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108879: mov r13d, eax */
    r[13] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10887c: movzx esi, al */
    r[4] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10887f: mov qword ptr [rbp - 0x238], rsi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8, ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108886: movzx esi, ah */
    r[4] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108889: mov qword ptr [rbp - 0x218], rsi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde8)), 8, ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108890: mov qword ptr [rbp - 0xc8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108897: mov rax, qword ptr [rbp - 0x258] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffda8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10889e: xor eax, 0x82 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x82))) & UINT64_C(0xffffffff);
    /* 0x1088a3: xor ebx, dword ptr [r15 + rax*4 + 0x3950] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1088ab: xor ecx, 0xc5 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc5))) & UINT64_C(0xffffffff);
    /* 0x1088b1: xor ebx, dword ptr [r15 + rcx*4 + 0x2ff0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1088b9: mov r8d, ebx */
    r[8] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1088bc: movzx eax, bl */
    r[0] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1088bf: mov qword ptr [rbp - 0x230], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdd0)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1088c6: movzx eax, bh */
    r[0] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1088c9: mov qword ptr [rbp - 0x258], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffda8)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1088d0: mov r12d, ebx */
    r[12] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1088d3: xor r9d, 0xad */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xad))) & UINT64_C(0xffffffff);
    /* 0x1088da: xor edx, dword ptr [r15 + r9*4 + 0x3950] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1088e2: mov r14d, edx */
    r[14] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1088e5: movzx eax, dl */
    r[0] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1088e8: mov qword ptr [rbp - 0x298], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd68)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1088ef: movzx eax, dh */
    r[0] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1088f2: mov qword ptr [rbp - 0x2b8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd48)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1088f9: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1088fb: mov rax, qword ptr [rbp - 0x2e8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd18)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108902: movzx edx, byte ptr [r15 + rax + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10890b: mov r9d, edx */
    r[9] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10890e: xor r9b, 0x4c */
    r[9] = (r[9] & UINT64_C(0xffffffffffffff00)) | ((((((r[9] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x4c))) & UINT64_C(0xff)) << 0);
    /* 0x108912: shr dl, 7 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) >> (UINT64_C(0x7) & 31))) & UINT64_C(0xff)) << 0);
    /* 0x108915: add r9b, r9b */
    r[9] = (r[9] & UINT64_C(0xffffffffffffff00)) | ((((((r[9] >> 0) & UINT64_C(0xff)) + ((r[9] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x108918: or r9b, dl */
    r[9] = (r[9] & UINT64_C(0xffffffffffffff00)) | ((((((r[9] >> 0) & UINT64_C(0xff)) | ((r[3] >> 0) & UINT64_C(0xff)))) & UINT64_C(0xff)) << 0);
    /* 0x10891b: mov rax, qword ptr [rbp - 0x378] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc88)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108922: movzx edx, byte ptr [r15 + rax + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10892b: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10892e: lea ebx, [rdx + rdx] */
    r[1] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108931: and ebx, 0xfffffff6 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfffffff6))) & UINT64_C(0xffffffff);
    /* 0x108934: sub edx, ebx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108936: mov rax, qword ptr [rbp - 0x758] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff8a8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10893d: movzx ebx, byte ptr [r15 + rax + 0x2ee0] */
    r[1] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108946: xor ebx, 0x4c */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108949: mov edi, ebx */
    r[5] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10894b: and edi, 0x4b */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x4b))) & UINT64_C(0xffffffff);
    /* 0x10894e: add edi, edi */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108950: sub ebx, edi */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108952: shl edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108955: add edx, 0x61fb0000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x61fb0000))) & UINT64_C(0xffffffff);
    /* 0x10895b: xor edx, 0x61fb0000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x61fb0000))) & UINT64_C(0xffffffff);
    /* 0x108961: lea edi, [rdx + rdx] */
    r[5] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108964: and edi, 0xf1760000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xf1760000))) & UINT64_C(0xffffffff);
    /* 0x10896a: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10896c: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10896e: add edx, 0x78bb4379 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x78bb4379))) & UINT64_C(0xffffffff);
    /* 0x108974: shl ebx, 8 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x108977: add ebx, 0x9c524b00 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x9c524b00))) & UINT64_C(0xffffffff);
    /* 0x10897d: xor ebx, 0x9c524b00 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9c524b00))) & UINT64_C(0xffffffff);
    /* 0x108983: lea edi, [rbx + rbx] */
    r[5] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108986: and edi, 0xae58cc00 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xae58cc00))) & UINT64_C(0xffffffff);
    /* 0x10898c: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10898e: add edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108990: add edi, 0x572c6602 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x572c6602))) & UINT64_C(0xffffffff);
    /* 0x108996: xor edx, 0x78bb4379 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x78bb4379))) & UINT64_C(0xffffffff);
    /* 0x10899c: xor edi, 0x572c6602 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x572c6602))) & UINT64_C(0xffffffff);
    /* 0x1089a2: or edi, edx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1089a4: lea edx, [rdi + rdi] */
    r[3] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1089a7: and edx, 0x176e7b14 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x176e7b14))) & UINT64_C(0xffffffff);
    /* 0x1089ad: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1089af: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1089b1: add edx, 0xbb73d8a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xbb73d8a))) & UINT64_C(0xffffffff);
    /* 0x1089b7: mov rax, qword ptr [rbp - 0x328] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffcd8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1089be: movzx ecx, byte ptr [r15 + rax + 0x2ee0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1089c7: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1089ca: lea edi, [rcx + rcx] */
    r[5] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1089cd: and edi, 0x72 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x72))) & UINT64_C(0xffffffff);
    /* 0x1089d0: sub ecx, edi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1089d2: mov rax, qword ptr [rbp - 0x388] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc78)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1089d9: movzx edi, byte ptr [r15 + rax + 0x2ee0] */
    r[5] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1089e2: xor edi, 0x4c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1089e5: lea ebx, [rdi + rdi] */
    r[1] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1089e8: and ebx, 0x58 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x58))) & UINT64_C(0xffffffff);
    /* 0x1089eb: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1089ed: add edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1089ef: add edi, 0x63ea492c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x63ea492c))) & UINT64_C(0xffffffff);
    /* 0x1089f5: xor edx, 0xbb73d8a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbb73d8a))) & UINT64_C(0xffffffff);
    /* 0x1089fb: xor edi, 0x63ea492c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x63ea492c))) & UINT64_C(0xffffffff);
    /* 0x108a01: or edi, edx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108a03: lea edx, [rdi + rdi] */
    r[3] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108a06: and edx, 0xbcf35e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xbcf35e))) & UINT64_C(0xffffffff);
    /* 0x108a0c: sub edi, edx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108a0e: mov rax, qword ptr [rbp - 0x3d8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc28)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108a15: movzx edx, byte ptr [r15 + rax + 0x2ee0] */
    r[3] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108a1e: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108a21: lea ebx, [rdx + rdx] */
    r[1] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108a24: and ebx, 0xffffff86 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff86))) & UINT64_C(0xffffffff);
    /* 0x108a27: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108a29: lea r11d, [rdx + rbx] */
    r[11] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108a2d: add r11d, 0x4354e9c3 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4354e9c3))) & UINT64_C(0xffffffff);
    /* 0x108a34: shl edi, 8 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x108a37: add edi, 0xde79af00 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xde79af00))) & UINT64_C(0xffffffff);
    /* 0x108a3d: xor edi, 0xde79af00 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xde79af00))) & UINT64_C(0xffffffff);
    /* 0x108a43: lea ebx, [rdi + rdi] */
    r[1] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108a46: and ebx, 0xd7aafc00 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xd7aafc00))) & UINT64_C(0xffffffff);
    /* 0x108a4c: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108a4e: add edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108a50: add edi, 0x6bd57e22 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6bd57e22))) & UINT64_C(0xffffffff);
    /* 0x108a56: xor edi, 0x6bd57e22 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6bd57e22))) & UINT64_C(0xffffffff);
    /* 0x108a5c: xor r11d, 0x4354e9c3 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4354e9c3))) & UINT64_C(0xffffffff);
    /* 0x108a63: or r11d, edi */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) | ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108a66: shr esi, 0x10 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108a69: movzx esi, sil */
    r[4] = (((r[4] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108a6d: xor esi, 0xfc */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xfc))) & UINT64_C(0xffffffff);
    /* 0x108a73: mov esi, dword ptr [r15 + rsi*4 + 0x2ff0] */
    r[4] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108a7b: mov edi, esi */
    r[5] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108a7d: and edi, 1 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1))) & UINT64_C(0xffffffff);
    /* 0x108a80: lea ebx, [rdi + rdi] */
    r[1] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108a83: xor ebx, 2 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2))) & UINT64_C(0xffffffff);
    /* 0x108a86: mov r10d, 0x5c48a396 */
    r[10] = (UINT64_C(0x5c48a396)) & UINT64_C(0xffffffff);
    /* 0x108a8c: lea edx, [rbx + rdi] */
    r[3] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108a8f: add edx, 0x37fff1fa */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x37fff1fa))) & UINT64_C(0xffffffff);
    /* 0x108a95: sub r10d, edx */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108a98: ror r9b, 1 */
    a = ((r[9] >> 0) & UINT64_C(0xff)); r[9] = (r[9] & UINT64_C(0xffffffffffffff00)) | (((((a >> 1) | (a << 7))) & UINT64_C(0xff)) << 0);
    /* 0x108a9b: mov byte ptr [rbp - 0x2b0], r9b */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 1, ((r[9] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x108aa2: and esi, 0xfffffffe */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfffffffe))) & UINT64_C(0xffffffff);
    /* 0x108aa5: xor esi, 0x3ff660e0 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3ff660e0))) & UINT64_C(0xffffffff);
    /* 0x108aab: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108aae: and edx, 0x2f8e4f98 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2f8e4f98))) & UINT64_C(0xffffffff);
    /* 0x108ab4: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108ab6: lea r9d, [rsi + rdx] */
    r[9] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108aba: add r9d, 0x17c727cc */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x17c727cc))) & UINT64_C(0xffffffff);
    /* 0x108ac1: mov rax, qword ptr [rbp - 0xa8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108ac8: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108acb: shl ecx, 0x10 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108ace: mov qword ptr [rbp - 0x188], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108ad5: xor eax, 0x67 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x67))) & UINT64_C(0xffffffff);
    /* 0x108ad8: mov qword ptr [rbp - 0xa8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108adf: mov eax, dword ptr [rbp - 0x208] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108ae5: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108ae8: mov rcx, qword ptr [rbp - 0xc8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108aef: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108af2: xor ecx, 0x7f */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7f))) & UINT64_C(0xffffffff);
    /* 0x108af5: mov qword ptr [rbp - 0xc8], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108afc: mov rcx, qword ptr [rbp - 0x270] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108b03: xor ecx, 0xd9 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd9))) & UINT64_C(0xffffffff);
    /* 0x108b09: mov qword ptr [rbp - 0x270], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108b10: shr r12d, 0x10 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108b14: movzx ecx, r12b */
    r[2] = (((r[12] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108b18: shr r8d, 0x18 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108b1c: xor r8d, 0x74 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x74))) & UINT64_C(0xffffffff);
    /* 0x108b20: shr r13d, 0x10 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108b24: movzx edx, r13b */
    r[3] = (((r[13] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108b28: xor edx, 0xbb */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbb))) & UINT64_C(0xffffffff);
    /* 0x108b2e: mov qword ptr [rbp - 0x2e0], rdx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd20)), 8, ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108b35: lea r12d, [r11 + r11] */
    r[12] = ((((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108b39: mov r13, r11 */
    r[13] = (((r[11] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x108b3c: and r12d, 0xed9b2ec8 */
    r[12] = ((((r[12] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xed9b2ec8))) & UINT64_C(0xffffffff);
    /* 0x108b43: neg r12d */
    r[12] = ((UINT64_C(0) - ((r[12] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108b46: movzx r11d, al */
    r[11] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108b4a: xor ecx, 0x44 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x44))) & UINT64_C(0xffffffff);
    /* 0x108b4d: mov qword ptr [rbp - 0x2d0], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd30)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108b54: xor r11d, 0xbb */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbb))) & UINT64_C(0xffffffff);
    /* 0x108b5b: shr r14d, 0x18 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108b5f: xor r14d, 0xd */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd))) & UINT64_C(0xffffffff);
    /* 0x108b63: xor r9d, 0xf8523c6 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf8523c6))) & UINT64_C(0xffffffff);
    /* 0x108b6a: mov r8d, dword ptr [r15 + r8*4 + 0x4ac0] */
    r[8] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108b72: xor r8d, dword ptr [rbp - 0x600] */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa00)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108b79: lea ecx, [r9 + r9] */
    r[2] = ((((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108b7d: and ecx, 0xb8d886d8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xb8d886d8))) & UINT64_C(0xffffffff);
    /* 0x108b83: xor r8d, 0x48438bfc */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x48438bfc))) & UINT64_C(0xffffffff);
    /* 0x108b8a: lea eax, [rbx + rdi] */
    r[0] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108b8d: add eax, -1 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffff);
    /* 0x108b90: and eax, r8d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & ((r[8] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108b93: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108b95: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108b98: and edx, 0x83f18a4 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x83f18a4))) & UINT64_C(0xffffffff);
    /* 0x108b9e: mov rsi, qword ptr [rbp - 0x238] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108ba5: xor esi, 0xdf */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xdf))) & UINT64_C(0xffffffff);
    /* 0x108bab: cmp eax, edx */
    eq = (((r[0] >> 0) & UINT64_C(0xffffffff)) == (((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffff)));
    /* 0x108bad: lea eax, [rbx + rdi + 0x2448b19a] */
    r[0] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2448b19a))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108bb4: cmovne eax, r10d */
    if (!eq) { r[0] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff); }
    /* 0x108bb8: mov ebx, dword ptr [r15 + rsi*4 + 0x3950] */
    r[1] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108bc0: mov rdx, qword ptr [rbp - 0x270] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108bc7: xor ebx, dword ptr [r15 + rdx*4 + 0x46a0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108bcf: add ecx, r9d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108bd2: add ecx, 0x5c6c436d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5c6c436d))) & UINT64_C(0xffffffff);
    /* 0x108bd8: lea edx, [r8 + rax] */
    r[3] = ((((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108bdc: add eax, r8d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108bdf: add eax, 0xdbb74e65 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xdbb74e65))) & UINT64_C(0xffffffff);
    /* 0x108be4: add edx, edx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108be6: add edx, 0xb76e9cca */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xb76e9cca))) & UINT64_C(0xffffffff);
    /* 0x108bec: and edx, 0xfed7e506 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfed7e506))) & UINT64_C(0xffffffff);
    /* 0x108bf2: sub eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108bf4: xor ebx, ecx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108bf6: add eax, 0x7f6bf283 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7f6bf283))) & UINT64_C(0xffffffff);
    /* 0x108bfb: xor ebx, eax */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108bfd: mov eax, dword ptr [r15 + r11*4 + 0x2ff0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108c05: xor eax, dword ptr [rbp - 0x5f8] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa08)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108c0b: xor eax, dword ptr [r15 + r14*4 + 0x4ac0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108c13: mov dword ptr [rbp - 0x2a8], ebx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd58)), 4, ((r[1] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x108c19: movzx edx, bl */
    r[3] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108c1c: movzx ecx, bh */
    r[2] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108c1f: mov qword ptr [rbp - 0x238], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108c26: mov ecx, ebx */
    r[2] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108c28: mov qword ptr [rbp - 0x208], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108c2f: mov rcx, qword ptr [rbp - 0x218] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108c36: xor ecx, 0xab */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xab))) & UINT64_C(0xffffffff);
    /* 0x108c3c: xor eax, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108c44: mov rcx, qword ptr [rbp - 0x230] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdd0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108c4b: xor ecx, 0xbe */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbe))) & UINT64_C(0xffffffff);
    /* 0x108c51: xor eax, dword ptr [r15 + rcx*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108c59: mov rcx, qword ptr [rbp - 0xc8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108c60: mov ecx, dword ptr [r15 + rcx*4 + 0x4ac0] */
    r[2] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108c68: xor ecx, dword ptr [rbp - 0x5c8] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa38)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108c6e: mov rsi, qword ptr [rbp - 0x2d0] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd30)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108c75: xor ecx, dword ptr [r15 + rsi*4 + 0x2ff0] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108c7d: movzx esi, al */
    r[4] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108c80: mov qword ptr [rbp - 0xc8], rsi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8, ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108c87: mov dword ptr [rbp - 0x218], eax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde8)), 4, ((r[0] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x108c8d: movzx esi, ah */
    r[4] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108c90: mov qword ptr [rbp - 0x270], rsi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8, ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108c97: mov esi, eax */
    r[4] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108c99: mov rax, qword ptr [rbp - 0x220] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108ca0: xor eax, 0xdc */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xdc))) & UINT64_C(0xffffffff);
    /* 0x108ca5: xor ecx, dword ptr [r15 + rax*4 + 0x3950] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108cad: mov rax, qword ptr [rbp - 0x2b8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd48)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108cb4: xor eax, 0xce */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xce))) & UINT64_C(0xffffffff);
    /* 0x108cb9: xor ecx, dword ptr [r15 + rax*4 + 0x46a0] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108cc1: lea r8d, [r12 + r13] */
    r[8] = ((((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108cc5: add r8d, 0x76cd9764 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x76cd9764))) & UINT64_C(0xffffffff);
    /* 0x108ccc: mov rax, qword ptr [rbp - 0x2e0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd20)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108cd3: mov eax, dword ptr [r15 + rax*4 + 0x2ff0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108cdb: mov rdi, qword ptr [rbp - 0xa8] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108ce2: xor eax, dword ptr [r15 + rdi*4 + 0x4ac0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108cea: xor eax, r8d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[8] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108ced: mov rdi, qword ptr [rbp - 0x298] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd68)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108cf4: xor edi, 0xd8 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd8))) & UINT64_C(0xffffffff);
    /* 0x108cfa: xor eax, dword ptr [r15 + rdi*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108d02: mov r14d, ecx */
    r[14] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108d05: movzx r11d, cl */
    r[11] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108d09: movzx edi, ch */
    r[5] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108d0c: mov r10d, ecx */
    r[10] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108d0f: mov rcx, qword ptr [rbp - 0x258] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffda8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108d16: xor ecx, 0xf5 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf5))) & UINT64_C(0xffffffff);
    /* 0x108d1c: xor eax, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108d24: mov r12, r15 */
    r[12] = (((r[15] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x108d27: shr esi, 0x18 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108d2a: xor esi, 0x2a */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2a))) & UINT64_C(0xffffffff);
    /* 0x108d2d: mov ebx, dword ptr [r15 + rsi*4 + 0x4ac0] */
    r[1] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108d35: xor ebx, dword ptr [rbp - 0x5e8] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa18)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108d3b: xor edi, 0xd8 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd8))) & UINT64_C(0xffffffff);
    /* 0x108d41: xor ebx, dword ptr [r15 + rdi*4 + 0x46a0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108d49: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108d4b: shr ecx, 0x10 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108d4e: movzx ecx, cl */
    r[2] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108d51: xor ecx, 0x5c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5c))) & UINT64_C(0xffffffff);
    /* 0x108d54: xor ebx, dword ptr [r15 + rcx*4 + 0x2ff0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108d5c: xor edx, 0xea */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xea))) & UINT64_C(0xffffffff);
    /* 0x108d62: xor ebx, dword ptr [r15 + rdx*4 + 0x3950] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108d6a: movzx r9d, al */
    r[9] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108d6e: movzx esi, ah */
    r[4] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108d71: mov r8d, eax */
    r[8] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108d74: mov dword ptr [rbp - 0x3a0], ebx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc60)), 4, ((r[1] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x108d7a: movzx edx, bl */
    r[3] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108d7d: movzx eax, bh */
    r[0] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108d80: mov r13, rax */
    r[13] = (((r[0] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x108d83: mov eax, ebx */
    r[0] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108d85: mov qword ptr [rbp - 0xa8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108d8c: mov eax, dword ptr [rbp - 0x2a8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd58)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108d92: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108d95: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108d98: shr r10d, 0x18 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108d9c: xor r10d, 0x37 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x37))) & UINT64_C(0xffffffff);
    /* 0x108da0: xor eax, 0xea */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xea))) & UINT64_C(0xffffffff);
    /* 0x108da5: mov eax, dword ptr [r15 + rax*4 + 0x2ff0] */
    r[0] = (load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108dad: xor eax, dword ptr [rbp - 0x578] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa88)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108db3: xor eax, dword ptr [r15 + r10*4 + 0x4ac0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108dbb: mov rcx, qword ptr [rbp - 0x270] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108dc2: xor ecx, 0x66 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x66))) & UINT64_C(0xffffffff);
    /* 0x108dc5: xor eax, dword ptr [r15 + rcx*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108dcd: xor r9d, 0xd4 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd4))) & UINT64_C(0xffffffff);
    /* 0x108dd4: xor eax, dword ptr [r15 + r9*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108ddc: movzx ecx, al */
    r[2] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108ddf: mov qword ptr [rbp - 0x270], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108de6: mov r15d, eax */
    r[15] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108de9: movzx ecx, ah */
    r[2] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108dec: mov qword ptr [rbp - 0x220], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108df3: mov edi, eax */
    r[5] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108df5: mov eax, dword ptr [rbp - 0x218] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde8)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108dfb: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108dfe: xor r11d, 0x21 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x21))) & UINT64_C(0xffffffff);
    /* 0x108e02: movzx ebx, al */
    r[1] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108e05: xor ebx, 0xd9 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd9))) & UINT64_C(0xffffffff);
    /* 0x108e0b: mov eax, dword ptr [r12 + r11*4 + 0x3950] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108e13: xor eax, dword ptr [rbp - 0x630] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff9d0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108e19: xor eax, dword ptr [r12 + rbx*4 + 0x2ff0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108e21: xor esi, 0x65 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x65))) & UINT64_C(0xffffffff);
    /* 0x108e24: xor eax, dword ptr [r12 + rsi*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108e2c: mov rcx, qword ptr [rbp - 0x658] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff9a8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108e33: movzx esi, byte ptr [r12 + rcx + 0x2ee0] */
    r[4] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108e3c: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108e3f: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108e42: and ebx, 6 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x6))) & UINT64_C(0xffffffff);
    /* 0x108e45: sub esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108e47: mov rcx, qword ptr [rbp - 0x188] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108e4e: add ecx, 0xc0390000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xc0390000))) & UINT64_C(0xffffffff);
    /* 0x108e54: xor ecx, 0xc0390000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc0390000))) & UINT64_C(0xffffffff);
    /* 0x108e5a: lea ebx, [rcx + rcx] */
    r[1] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108e5d: and ebx, 0xf92e0000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xf92e0000))) & UINT64_C(0xffffffff);
    /* 0x108e63: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108e65: add ebx, ecx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108e67: add ebx, 0x7c97ad88 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7c97ad88))) & UINT64_C(0xffffffff);
    /* 0x108e6d: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x108e70: add esi, 0x1cab0300 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1cab0300))) & UINT64_C(0xffffffff);
    /* 0x108e76: xor esi, 0x1cab0300 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1cab0300))) & UINT64_C(0xffffffff);
    /* 0x108e7c: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108e7f: and ecx, 0x959c6800 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x959c6800))) & UINT64_C(0xffffffff);
    /* 0x108e85: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108e87: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108e89: add ecx, 0x4ace34d0 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4ace34d0))) & UINT64_C(0xffffffff);
    /* 0x108e8f: xor ebx, 0x7c97ad88 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7c97ad88))) & UINT64_C(0xffffffff);
    /* 0x108e95: xor ecx, 0x4ace34d0 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4ace34d0))) & UINT64_C(0xffffffff);
    /* 0x108e9b: or ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108e9d: lea esi, [rcx + rcx] */
    r[4] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108ea0: and esi, 0x8eaf528e */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x8eaf528e))) & UINT64_C(0xffffffff);
    /* 0x108ea6: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108ea8: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108eaa: add ecx, 0x4757a947 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4757a947))) & UINT64_C(0xffffffff);
    /* 0x108eb0: mov rsi, qword ptr [rbp - 0x3d0] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc30)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108eb7: movzx esi, byte ptr [r12 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108ec0: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108ec3: lea ebx, [rsi + rsi] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108ec6: and ebx, 0x13c */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x13c))) & UINT64_C(0xffffffff);
    /* 0x108ecc: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108ece: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108ed0: add esi, 0x1d86ad9e */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1d86ad9e))) & UINT64_C(0xffffffff);
    /* 0x108ed6: xor esi, 0x1d86ad9e */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1d86ad9e))) & UINT64_C(0xffffffff);
    /* 0x108edc: xor ecx, 0x4757a947 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4757a947))) & UINT64_C(0xffffffff);
    /* 0x108ee2: or esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108ee4: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108ee7: and ecx, 0xd921c4 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xd921c4))) & UINT64_C(0xffffffff);
    /* 0x108eed: sub esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108eef: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x108ef2: add esi, 0xec90e200 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xec90e200))) & UINT64_C(0xffffffff);
    /* 0x108ef8: xor esi, 0xec90e200 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xec90e200))) & UINT64_C(0xffffffff);
    /* 0x108efe: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108f01: and ecx, 0x1a61dc00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1a61dc00))) & UINT64_C(0xffffffff);
    /* 0x108f07: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108f09: lea r9d, [rsi + rcx] */
    r[9] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108f0d: add r9d, 0xd30ee0b */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd30ee0b))) & UINT64_C(0xffffffff);
    /* 0x108f14: mov rsi, qword ptr [rbp - 0x3a8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108f1b: movzx ebx, byte ptr [r12 + rsi + 0x2ee0] */
    r[1] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108f24: xor ebx, 0x4c */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108f27: mov esi, ebx */
    r[4] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108f29: and esi, 0x79 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x79))) & UINT64_C(0xffffffff);
    /* 0x108f2c: add esi, esi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108f2e: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108f30: add esi, ebx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108f32: add esi, 0x3004d179 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3004d179))) & UINT64_C(0xffffffff);
    /* 0x108f38: mov rcx, qword ptr [rbp - 0xc8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108f3f: xor ecx, 0xb */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb))) & UINT64_C(0xffffffff);
    /* 0x108f42: mov rbx, qword ptr [rbp - 0x238] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108f49: xor ebx, 0xef */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xef))) & UINT64_C(0xffffffff);
    /* 0x108f4f: mov ebx, dword ptr [r12 + rbx*4 + 0x46a0] */
    r[1] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108f57: xor ebx, dword ptr [r12 + rcx*4 + 0x3950] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108f5f: shr r8d, 0x18 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108f63: xor r8d, 0x4c */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x108f67: xor ebx, dword ptr [r12 + r8*4 + 0x4ac0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108f6f: xor esi, 0x3004d179 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3004d179))) & UINT64_C(0xffffffff);
    /* 0x108f75: xor r9d, 0xd30ee0b */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd30ee0b))) & UINT64_C(0xffffffff);
    /* 0x108f7c: or esi, r9d */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108f7f: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108f82: and ecx, 0xf989e330 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xf989e330))) & UINT64_C(0xffffffff);
    /* 0x108f88: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108f8a: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108f8c: add ecx, 0x7cc4f198 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7cc4f198))) & UINT64_C(0xffffffff);
    /* 0x108f92: shr r14d, 0x10 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x108f96: movzx esi, r14b */
    r[4] = (((r[14] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108f9a: xor esi, 0x53 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x53))) & UINT64_C(0xffffffff);
    /* 0x108f9d: xor ebx, dword ptr [r12 + rsi*4 + 0x2ff0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108fa5: xor ebx, ecx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x108fa7: mov rcx, qword ptr [rbp - 0x208] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x108fae: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108fb1: xor ecx, 0x4f */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4f))) & UINT64_C(0xffffffff);
    /* 0x108fb4: xor eax, dword ptr [r12 + rcx*4 + 0x4ac0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108fbc: mov r14d, ebx */
    r[14] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108fbf: movzx r10d, bl */
    r[10] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108fc3: movzx ecx, bh */
    r[2] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108fc6: mov qword ptr [rbp - 0x238], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x108fcd: mov esi, ebx */
    r[4] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108fcf: shr esi, 0x18 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x108fd2: xor edx, 0x63 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x63))) & UINT64_C(0xffffffff);
    /* 0x108fd5: xor esi, 0x46 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x46))) & UINT64_C(0xffffffff);
    /* 0x108fd8: mov ebx, dword ptr [r12 + rdx*4 + 0x3950] */
    r[1] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108fe0: xor ebx, dword ptr [r12 + rsi*4 + 0x4ac0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x108fe8: movzx r9d, al */
    r[9] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108fec: mov r11d, eax */
    r[11] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108fef: movzx ecx, ah */
    r[2] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x108ff2: mov r8d, eax */
    r[8] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x108ff5: xor ecx, 0x16 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x16))) & UINT64_C(0xffffffff);
    /* 0x108ff8: xor ebx, dword ptr [r12 + rcx*4 + 0x46a0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109000: mov rax, qword ptr [rbp - 0x320] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffce0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109007: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109010: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109013: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109016: and ecx, 0xffffffe6 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffe6))) & UINT64_C(0xffffffff);
    /* 0x109019: sub eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10901b: mov rcx, qword ptr [rbp - 0x780] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff880)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109022: movzx ecx, byte ptr [r12 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10902b: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10902e: mov edx, ecx */
    r[3] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109030: and edx, 0x44 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x44))) & UINT64_C(0xffffffff);
    /* 0x109033: add edx, edx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109035: sub ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109037: shl eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10903a: add eax, 0x1ef30000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1ef30000))) & UINT64_C(0xffffffff);
    /* 0x10903f: xor eax, 0x1ef30000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1ef30000))) & UINT64_C(0xffffffff);
    /* 0x109044: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109047: and edx, 0x47480000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x47480000))) & UINT64_C(0xffffffff);
    /* 0x10904d: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10904f: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109051: add eax, 0x23a43bea */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x23a43bea))) & UINT64_C(0xffffffff);
    /* 0x109056: shl ecx, 8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x109059: add ecx, 0xe62b4400 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xe62b4400))) & UINT64_C(0xffffffff);
    /* 0x10905f: xor ecx, 0xe62b4400 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe62b4400))) & UINT64_C(0xffffffff);
    /* 0x109065: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109068: and edx, 0x52355200 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x52355200))) & UINT64_C(0xffffffff);
    /* 0x10906e: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109070: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109072: add ecx, 0x291aa9dd */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x291aa9dd))) & UINT64_C(0xffffffff);
    /* 0x109078: xor eax, 0x23a43bea */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x23a43bea))) & UINT64_C(0xffffffff);
    /* 0x10907d: xor ecx, 0x291aa9dd */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x291aa9dd))) & UINT64_C(0xffffffff);
    /* 0x109083: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109085: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109088: and eax, 0xa752afe0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa752afe0))) & UINT64_C(0xffffffff);
    /* 0x10908d: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10908f: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109091: add eax, 0x53a957f0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x53a957f0))) & UINT64_C(0xffffffff);
    /* 0x109096: mov rcx, qword ptr [rbp - 0x438] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbc8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10909d: movzx ecx, byte ptr [r12 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1090a6: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1090a9: mov edx, ecx */
    r[3] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1090ab: and edx, 0x66 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x66))) & UINT64_C(0xffffffff);
    /* 0x1090ae: add edx, edx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1090b0: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1090b2: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1090b4: add ecx, 0x2ce7ed66 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2ce7ed66))) & UINT64_C(0xffffffff);
    /* 0x1090ba: xor eax, 0x53a957f0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x53a957f0))) & UINT64_C(0xffffffff);
    /* 0x1090bf: xor ecx, 0x2ce7ed66 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2ce7ed66))) & UINT64_C(0xffffffff);
    /* 0x1090c5: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1090c7: shr edi, 0x18 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1090ca: xor edi, 0x6f */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6f))) & UINT64_C(0xffffffff);
    /* 0x1090cd: xor r13d, 0x5a */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5a))) & UINT64_C(0xffffffff);
    /* 0x1090d1: mov eax, dword ptr [r12 + r13*4 + 0x46a0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1090d9: xor eax, dword ptr [r12 + rdi*4 + 0x4ac0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1090e1: mov esi, eax */
    r[4] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1090e3: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1090e6: and eax, 0x5b986a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5b986a))) & UINT64_C(0xffffffff);
    /* 0x1090eb: sub ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1090ed: shl ecx, 8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x1090f0: add ecx, 0xadcc3500 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xadcc3500))) & UINT64_C(0xffffffff);
    /* 0x1090f6: xor ecx, 0xadcc3500 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xadcc3500))) & UINT64_C(0xffffffff);
    /* 0x1090fc: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1090ff: and eax, 0xbbdef200 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xbbdef200))) & UINT64_C(0xffffffff);
    /* 0x109104: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109106: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109108: add eax, 0x5def79b5 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5def79b5))) & UINT64_C(0xffffffff);
    /* 0x10910d: mov rcx, qword ptr [rbp - 0x338] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffcc8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109114: movzx ecx, byte ptr [r12 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10911d: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109120: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109123: and edx, 0x15e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x15e))) & UINT64_C(0xffffffff);
    /* 0x109129: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10912b: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10912d: add ecx, 0x121a76af */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x121a76af))) & UINT64_C(0xffffffff);
    /* 0x109133: xor ecx, 0x121a76af */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x121a76af))) & UINT64_C(0xffffffff);
    /* 0x109139: xor eax, 0x5def79b5 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5def79b5))) & UINT64_C(0xffffffff);
    /* 0x10913e: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109140: shr r15d, 0x10 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109144: movzx eax, r15b */
    r[0] = (((r[15] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109148: xor eax, 4 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4))) & UINT64_C(0xffffffff);
    /* 0x10914b: xor ebx, dword ptr [r12 + rax*4 + 0x2ff0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109153: mov dword ptr [rbp - 0x258], ebx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffda8)), 4, ((r[1] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x109159: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10915c: and eax, 0x6d893d60 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x6d893d60))) & UINT64_C(0xffffffff);
    /* 0x109161: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109163: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109165: add eax, 0x36c49eb0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x36c49eb0))) & UINT64_C(0xffffffff);
    /* 0x10916a: xor eax, ebx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10916c: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10916e: mov qword ptr [rbp - 0x230], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdd0)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109175: movzx ecx, al */
    r[2] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109178: mov qword ptr [rbp - 0x2b8], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd48)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10917f: movzx ecx, ah */
    r[2] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109182: mov qword ptr [rbp - 0x2d0], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd30)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109189: mov dword ptr [rbp - 0xc8], eax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 4, ((r[0] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x10918f: xor r10d, 0x28 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x28))) & UINT64_C(0xffffffff);
    /* 0x109193: xor esi, dword ptr [r12 + r10*4 + 0x3950] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10919b: mov dword ptr [rbp - 0x2a8], esi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd58)), 4, ((r[4] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1091a1: mov rcx, qword ptr [rbp - 0xa8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1091a8: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1091ab: xor ecx, 0x6d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6d))) & UINT64_C(0xffffffff);
    /* 0x1091ae: xor r9d, 0x3c */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3c))) & UINT64_C(0xffffffff);
    /* 0x1091b2: mov eax, dword ptr [r12 + r9*4 + 0x3950] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1091ba: xor eax, dword ptr [r12 + rcx*4 + 0x4ac0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1091c2: shr r14d, 0x10 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1091c6: movzx ecx, r14b */
    r[2] = (((r[14] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1091ca: xor ecx, 0x55 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x55))) & UINT64_C(0xffffffff);
    /* 0x1091cd: xor eax, dword ptr [r12 + rcx*4 + 0x2ff0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1091d5: mov rcx, qword ptr [rbp - 0x220] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1091dc: xor ecx, 0xbe */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbe))) & UINT64_C(0xffffffff);
    /* 0x1091e2: mov ebx, dword ptr [r12 + rcx*4 + 0x46a0] */
    r[1] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1091ea: mov r15d, eax */
    r[15] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1091ed: xor eax, dword ptr [rbp - 0x5e0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa20)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1091f3: xor eax, ebx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1091f5: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1091f7: mov qword ptr [rbp - 0x208], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1091fe: movzx ecx, al */
    r[2] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109201: mov qword ptr [rbp - 0x220], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109208: movzx ecx, ah */
    r[2] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10920b: mov qword ptr [rbp - 0x188], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109212: mov dword ptr [rbp - 0x2e0], eax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd20)), 4, ((r[0] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x109218: shr r8d, 0x10 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10921c: movzx eax, r8b */
    r[0] = (((r[8] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109220: xor eax, 0x99 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x99))) & UINT64_C(0xffffffff);
    /* 0x109225: mov ecx, dword ptr [r12 + rax*4 + 0x2ff0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10922d: mov dword ptr [rbp - 0x418], ecx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbe8)), 4, ((r[2] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x109233: mov eax, esi */
    r[0] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109235: xor eax, dword ptr [rbp - 0x568] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa98)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10923b: xor eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10923d: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10923f: mov qword ptr [rbp - 0xa8], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109246: movzx ecx, al */
    r[2] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109249: mov qword ptr [rbp - 0x298], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd68)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109250: mov r10d, eax */
    r[10] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109253: movzx eax, ah */
    r[0] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109256: mov qword ptr [rbp - 0x360], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffca0)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10925d: mov rax, qword ptr [rbp - 0x238] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109264: xor eax, 3 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3))) & UINT64_C(0xffffffff);
    /* 0x109267: mov r9d, dword ptr [r12 + rax*4 + 0x46a0] */
    r[9] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10926f: mov eax, dword ptr [rbp - 0x3a0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc60)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109275: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109278: shr r11d, 0x18 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10927c: xor r11d, 0x28 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x28))) & UINT64_C(0xffffffff);
    /* 0x109280: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109283: xor eax, 0x69 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x69))) & UINT64_C(0xffffffff);
    /* 0x109286: mov r8d, dword ptr [r12 + rax*4 + 0x2ff0] */
    r[8] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10928e: xor r8d, dword ptr [r12 + r11*4 + 0x4ac0] */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109296: mov rax, qword ptr [rbp - 0x270] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10929d: xor eax, 0x8b */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x8b))) & UINT64_C(0xffffffff);
    /* 0x1092a2: mov ecx, dword ptr [r12 + rax*4 + 0x3950] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1092aa: mov dword ptr [rbp - 0x3c0], ecx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc40)), 4, ((r[2] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1092b0: mov eax, r8d */
    r[0] = (((r[8] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1092b3: xor eax, dword ptr [rbp - 0x598] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa68)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1092b9: xor eax, r9d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1092bc: xor eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1092be: movzx ecx, al */
    r[2] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1092c1: mov qword ptr [rbp - 0x410], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbf0)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1092c8: mov dword ptr [rbp - 0x218], eax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde8)), 4, ((r[0] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1092ce: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1092d0: mov qword ptr [rbp - 0x3b8], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc48)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1092d7: movzx eax, ah */
    r[0] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1092da: mov qword ptr [rbp - 0x238], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1092e1: movzx eax, byte ptr [rbp - 0x2b0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1092e8: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1092eb: and esi, 0x14e */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x14e))) & UINT64_C(0xffffffff);
    /* 0x1092f1: sub eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1092f3: mov rcx, qword ptr [rbp - 0x778] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff888)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1092fa: movzx esi, byte ptr [r12 + rcx + 0x2ee0] */
    r[4] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109303: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109306: lea edi, [rsi + rsi] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109309: and edi, 0x14a */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x14a))) & UINT64_C(0xffffffff);
    /* 0x10930f: sub esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109311: shl eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109314: add eax, 0xa5a70000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xa5a70000))) & UINT64_C(0xffffffff);
    /* 0x109319: mov edi, eax */
    r[5] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10931b: xor edi, 0xa5a70000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xa5a70000))) & UINT64_C(0xffffffff);
    /* 0x109321: and eax, 0x2100000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2100000))) & UINT64_C(0xffffffff);
    /* 0x109326: mov ecx, edi */
    r[2] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109328: and ecx, 0x1fbb0000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1fbb0000))) & UINT64_C(0xffffffff);
    /* 0x10932e: xor eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109330: add eax, eax */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109332: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109334: lea ecx, [rdi + rax] */
    r[2] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109337: add ecx, 0x1dab3a2d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1dab3a2d))) & UINT64_C(0xffffffff);
    /* 0x10933d: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x109340: add esi, 0x77fa500 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x77fa500))) & UINT64_C(0xffffffff);
    /* 0x109346: xor esi, 0x77fa500 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x77fa500))) & UINT64_C(0xffffffff);
    /* 0x10934c: lea eax, [rsi + rsi] */
    r[0] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10934f: and eax, 0x25190000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x25190000))) & UINT64_C(0xffffffff);
    /* 0x109354: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109356: add esi, eax */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109358: add esi, 0x128c80e8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x128c80e8))) & UINT64_C(0xffffffff);
    /* 0x10935e: mov rax, qword ptr [rbp - 0x348] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffcb8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109365: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10936e: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109371: lea edi, [rax + rax] */
    r[5] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109374: and edi, 0x6c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x6c))) & UINT64_C(0xffffffff);
    /* 0x109377: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109379: lea edx, [rax + rdi] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10937c: add edx, 0x7825b236 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7825b236))) & UINT64_C(0xffffffff);
    /* 0x109382: xor ecx, 0x1dab3a2d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1dab3a2d))) & UINT64_C(0xffffffff);
    /* 0x109388: xor esi, 0x128c80e8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x128c80e8))) & UINT64_C(0xffffffff);
    /* 0x10938e: or esi, ecx */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109390: lea ecx, [rsi + rsi] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109393: and ecx, 0xb691b724 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xb691b724))) & UINT64_C(0xffffffff);
    /* 0x109399: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10939b: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10939d: add ecx, 0x5b48db92 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5b48db92))) & UINT64_C(0xffffffff);
    /* 0x1093a3: mov rax, qword ptr [rbp - 0x318] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffce8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1093aa: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1093b3: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1093b6: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1093b9: and esi, 0xffffff94 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff94))) & UINT64_C(0xffffffff);
    /* 0x1093bc: sub eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1093be: mov r14, rax */
    r[14] = (((r[0] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x1093c1: xor ecx, 0x5b48db92 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5b48db92))) & UINT64_C(0xffffffff);
    /* 0x1093c7: xor edx, 0x7825b236 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7825b236))) & UINT64_C(0xffffffff);
    /* 0x1093cd: or edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1093cf: mov rax, qword ptr [rbp - 0x3f8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc08)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1093d6: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1093df: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1093e2: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1093e5: and ecx, 0x12e */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x12e))) & UINT64_C(0xffffffff);
    /* 0x1093eb: sub eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1093ed: lea ecx, [rdx + rdx] */
    r[2] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1093f0: and ecx, 0x34071a */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x34071a))) & UINT64_C(0xffffffff);
    /* 0x1093f6: sub edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1093f8: xor r15d, dword ptr [rbp - 0x5f0] */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa10)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1093ff: xor r15d, ebx */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) ^ ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109402: mov ecx, r9d */
    r[2] = (((r[9] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109405: and ecx, 0xfbffffff */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfbffffff))) & UINT64_C(0xffffffff);
    /* 0x10940b: xor ecx, 0x8a09246f */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x8a09246f))) & UINT64_C(0xffffffff);
    /* 0x109411: lea esi, [rcx + rcx] */
    r[4] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109414: and esi, 0xa08f8b76 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa08f8b76))) & UINT64_C(0xffffffff);
    /* 0x10941a: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10941c: lea r13d, [rcx + rsi] */
    r[13] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109420: add r13d, 0x5447c5bb */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5447c5bb))) & UINT64_C(0xffffffff);
    /* 0x109427: and r9d, 0x4000000 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x4000000))) & UINT64_C(0xffffffff);
    /* 0x10942e: mov esi, r9d */
    r[4] = (((r[9] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109431: xor esi, 0x3fff6bbb */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3fff6bbb))) & UINT64_C(0xffffffff);
    /* 0x109437: mov r11d, 0x69facf4c */
    r[11] = (UINT64_C(0x69facf4c)) & UINT64_C(0xffffffff);
    /* 0x10943d: lea ebx, [rsi + r9*2] */
    r[1] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109441: sub r11d, ebx */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109444: xor r8d, dword ptr [rbp - 0x580] */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa80)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10944b: mov ebx, r8d */
    r[1] = (((r[8] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10944e: xor ebx, 0x20000000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x20000000))) & UINT64_C(0xffffffff);
    /* 0x109454: lea ecx, [rsi + r9*2] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109458: add ecx, 0xc0009445 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xc0009445))) & UINT64_C(0xffffffff);
    /* 0x10945e: and ebx, ecx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109460: shl r14d, 0x10 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109464: mov qword ptr [rbp - 0x270], r14 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8, ((r[14] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10946b: shl eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10946e: mov qword ptr [rbp - 0x400], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc00)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109475: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x109478: shr r10d, 0x10 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10947c: add edx, 0x9a038d00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x9a038d00))) & UINT64_C(0xffffffff);
    /* 0x109482: xor edx, 0x9a038d00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9a038d00))) & UINT64_C(0xffffffff);
    /* 0x109488: lea r14d, [rdx + rdx] */
    r[14] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10948c: and r14d, 0x54da0000 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x54da0000))) & UINT64_C(0xffffffff);
    /* 0x109493: neg r14d */
    r[14] = ((UINT64_C(0) - ((r[14] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109496: mov rax, qword ptr [rbp - 0xa8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10949d: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1094a0: xor eax, 0x29 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x29))) & UINT64_C(0xffffffff);
    /* 0x1094a3: mov qword ptr [rbp - 0xa8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1094aa: mov eax, r15d */
    r[0] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1094ad: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1094b0: xor eax, 0x76 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x76))) & UINT64_C(0xffffffff);
    /* 0x1094b3: mov qword ptr [rbp - 0x3c8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc38)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1094ba: shr dword ptr [rbp - 0xc8], 0x10 */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 4, (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 4) >> (UINT64_C(0x10) & 31)));
    if (m->error) return m->error;
    /* 0x1094c1: xor r13d, 0x25c54519 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x25c54519))) & UINT64_C(0xffffffff);
    /* 0x1094c8: movzx r10d, r10b */
    r[10] = (((r[10] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1094cc: xor r10d, 0x23 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x23))) & UINT64_C(0xffffffff);
    /* 0x1094d0: lea eax, [r13 + r13] */
    r[0] = ((((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1094d5: and eax, 0x8544e03a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x8544e03a))) & UINT64_C(0xffffffff);
    /* 0x1094da: lea ecx, [rbx + rbx] */
    r[2] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1094dd: and ecx, 0x70000000 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x70000000))) & UINT64_C(0xffffffff);
    /* 0x1094e3: mov edi, r15d */
    r[5] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1094e6: shr edi, 0x10 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1094e9: mov dword ptr [rbp - 0x3a0], edi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc60)), 4, ((r[5] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1094ef: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1094f1: cmp ebx, ecx */
    eq = (((r[1] >> 0) & UINT64_C(0xffffffff)) == (((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffff)));
    /* 0x1094f3: lea ecx, [rsi + r9*2 - 0x1604082a] */
    r[2] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0xffffffffe9fbf7d6))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1094fb: cmovne ecx, r11d */
    if (!eq) { r[2] = (((r[11] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff); }
    /* 0x1094ff: xor r8d, 0x20ed2ba9 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x20ed2ba9))) & UINT64_C(0xffffffff);
    /* 0x109506: lea esi, [r8 + rcx] */
    r[4] = ((((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10950a: add ecx, r8d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10950d: add ecx, 0xd6049c6f */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd6049c6f))) & UINT64_C(0xffffffff);
    /* 0x109513: add eax, r13d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109516: add eax, 0xc2a2701d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xc2a2701d))) & UINT64_C(0xffffffff);
    /* 0x10951b: xor eax, dword ptr [rbp - 0x3c0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc40)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109521: add esi, esi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109523: add esi, 0xac0938de */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xac0938de))) & UINT64_C(0xffffffff);
    /* 0x109529: and esi, 0xb65d3470 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xb65d3470))) & UINT64_C(0xffffffff);
    /* 0x10952f: sub ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109531: add ecx, 0x5b2e9a38 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5b2e9a38))) & UINT64_C(0xffffffff);
    /* 0x109537: xor eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109539: mov ebx, r15d */
    r[1] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10953c: movzx ecx, bl */
    r[2] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10953f: xor ecx, 0x9e */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9e))) & UINT64_C(0xffffffff);
    /* 0x109545: mov esi, dword ptr [r12 + rcx*4 + 0x3950] */
    r[4] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10954d: xor esi, dword ptr [r12 + r10*4 + 0x2ff0] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109555: mov rcx, qword ptr [rbp - 0x230] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdd0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10955c: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10955f: xor ecx, 0xc */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc))) & UINT64_C(0xffffffff);
    /* 0x109562: xor esi, dword ptr [r12 + rcx*4 + 0x4ac0] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10956a: mov edi, eax */
    r[5] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10956c: movzx r11d, al */
    r[11] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109570: movzx ecx, ah */
    r[2] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109573: mov r8d, eax */
    r[8] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109576: xor ecx, 0xb0 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb0))) & UINT64_C(0xffffffff);
    /* 0x10957c: xor esi, dword ptr [r12 + rcx*4 + 0x46a0] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109584: mov r10d, esi */
    r[10] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109587: movzx ebx, bh */
    r[1] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10958a: lea eax, [rdx + r14] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10958e: add eax, 0x2a6d0004 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2a6d0004))) & UINT64_C(0xffffffff);
    /* 0x109593: mov rcx, qword ptr [rbp - 0x308] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffcf8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10959a: movzx ecx, byte ptr [r12 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1095a3: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1095a6: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1095a9: and edx, 0x16 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x16))) & UINT64_C(0xffffffff);
    /* 0x1095ac: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1095ae: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1095b0: add ecx, 0x267a830b */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x267a830b))) & UINT64_C(0xffffffff);
    /* 0x1095b6: xor eax, 0x2a6d0004 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2a6d0004))) & UINT64_C(0xffffffff);
    /* 0x1095bb: xor ecx, 0x267a830b */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x267a830b))) & UINT64_C(0xffffffff);
    /* 0x1095c1: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1095c3: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1095c6: and eax, 0xfd5a54b6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfd5a54b6))) & UINT64_C(0xffffffff);
    /* 0x1095cb: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1095cd: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1095cf: add eax, 0x7ead2a5b */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7ead2a5b))) & UINT64_C(0xffffffff);
    /* 0x1095d4: xor eax, dword ptr [rbp - 0x258] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffda8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1095da: mov dword ptr [rbp - 0x230], eax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdd0)), 4, ((r[0] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1095e0: movzx ecx, al */
    r[2] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1095e3: mov qword ptr [rbp - 0x2b0], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x1095ea: mov r9d, eax */
    r[9] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1095ed: movzx esi, ah */
    r[4] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1095f0: mov rax, qword ptr [rbp - 0x3c8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1095f7: mov eax, dword ptr [r12 + rax*4 + 0x4ac0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1095ff: xor eax, dword ptr [rbp - 0x5a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa60)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109605: mov rcx, qword ptr [rbp - 0x360] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffca0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10960c: xor ecx, 0x42 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x42))) & UINT64_C(0xffffffff);
    /* 0x10960f: xor eax, dword ptr [r12 + rcx*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109617: mov r14d, eax */
    r[14] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10961a: mov rax, qword ptr [rbp - 0xa8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109621: mov eax, dword ptr [r12 + rax*4 + 0x4ac0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109629: xor eax, dword ptr [rbp - 0x538] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffac8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10962f: shr edi, 0x10 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109632: movzx ecx, dil */
    r[2] = (((r[5] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109636: xor ecx, 0xde */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xde))) & UINT64_C(0xffffffff);
    /* 0x10963c: xor eax, dword ptr [r12 + rcx*4 + 0x2ff0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109644: mov rcx, qword ptr [rbp - 0x2b8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd48)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10964b: xor eax, dword ptr [r12 + rcx*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109653: xor ebx, 0x6b */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6b))) & UINT64_C(0xffffffff);
    /* 0x109656: xor eax, dword ptr [r12 + rbx*4 + 0x46a0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10965e: mov edx, dword ptr [rbp - 0x2a8] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd58)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109664: xor edx, dword ptr [rbp - 0x5d8] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa28)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10966a: xor edx, dword ptr [rbp - 0x418] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbe8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109670: mov r13d, edx */
    r[13] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109673: movzx edi, dl */
    r[5] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109676: movzx ecx, dh */
    r[2] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109679: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10967c: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10967f: mov qword ptr [rbp - 0x2b8], rdx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd48)), 8, ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109686: mov rdx, qword ptr [rbp - 0x410] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbf0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10968d: xor edx, 0xd0 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd0))) & UINT64_C(0xffffffff);
    /* 0x109693: xor ecx, 0x7a */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7a))) & UINT64_C(0xffffffff);
    /* 0x109696: mov edx, dword ptr [r12 + rdx*4 + 0x3950] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10969e: xor edx, dword ptr [rbp - 0x560] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffaa0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1096a4: xor edx, dword ptr [r12 + rcx*4 + 0x46a0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1096ac: mov dword ptr [rbp - 0x2a8], edx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd58)), 4, ((r[3] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1096b2: mov rcx, qword ptr [rbp - 0x3b8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc48)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1096b9: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1096bc: xor ecx, 4 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4))) & UINT64_C(0xffffffff);
    /* 0x1096bf: xor edi, 0x9f */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9f))) & UINT64_C(0xffffffff);
    /* 0x1096c5: mov edx, dword ptr [r12 + rdi*4 + 0x3950] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1096cd: xor edx, dword ptr [rbp - 0x588] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa78)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1096d3: xor edx, dword ptr [r12 + rcx*4 + 0x4ac0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1096db: mov ecx, dword ptr [rbp - 0x2e0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd20)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1096e1: shr ecx, 0x10 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1096e4: movzx ecx, cl */
    r[2] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1096e7: xor ecx, 0x49 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x49))) & UINT64_C(0xffffffff);
    /* 0x1096ea: xor edx, dword ptr [r12 + rcx*4 + 0x2ff0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1096f2: xor esi, 0xd8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd8))) & UINT64_C(0xffffffff);
    /* 0x1096f8: xor edx, dword ptr [r12 + rsi*4 + 0x46a0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109700: mov dword ptr [rbp - 0xa8], edx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 4, ((r[3] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x109706: mov rcx, qword ptr [rbp - 0x750] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff8b0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10970d: movzx ecx, byte ptr [r12 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109716: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109719: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10971c: and edx, 0x114 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x114))) & UINT64_C(0xffffffff);
    /* 0x109722: sub ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109724: mov rsi, qword ptr [rbp - 0x400] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc00)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10972b: add esi, 0x42970000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x42970000))) & UINT64_C(0xffffffff);
    /* 0x109731: xor esi, 0x42970000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x42970000))) & UINT64_C(0xffffffff);
    /* 0x109737: lea edx, [rsi + rsi] */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10973a: and edx, 0xe5800000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe5800000))) & UINT64_C(0xffffffff);
    /* 0x109740: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109742: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109744: add edx, 0x72c0a5d5 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x72c0a5d5))) & UINT64_C(0xffffffff);
    /* 0x10974a: shl ecx, 8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10974d: add ecx, 0x939d8a00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x939d8a00))) & UINT64_C(0xffffffff);
    /* 0x109753: xor ecx, 0x939d8a00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x939d8a00))) & UINT64_C(0xffffffff);
    /* 0x109759: lea esi, [rcx + rcx] */
    r[4] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10975c: and esi, 0x8eface00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x8eface00))) & UINT64_C(0xffffffff);
    /* 0x109762: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109764: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109766: add ecx, 0x477d678c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x477d678c))) & UINT64_C(0xffffffff);
    /* 0x10976c: xor edx, 0x72c0a5d5 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x72c0a5d5))) & UINT64_C(0xffffffff);
    /* 0x109772: xor ecx, 0x477d678c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x477d678c))) & UINT64_C(0xffffffff);
    /* 0x109778: or ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10977a: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10977d: and edx, 0x22e54a0 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x22e54a0))) & UINT64_C(0xffffffff);
    /* 0x109783: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109785: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109787: add ecx, 0x1172a50 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1172a50))) & UINT64_C(0xffffffff);
    /* 0x10978d: mov rdx, qword ptr [rbp - 0x430] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbd0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109794: movzx edx, byte ptr [r12 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10979d: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1097a0: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1097a2: and esi, 0x79 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x79))) & UINT64_C(0xffffffff);
    /* 0x1097a5: add esi, esi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1097a7: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1097a9: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1097ab: add edx, 0x27615879 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x27615879))) & UINT64_C(0xffffffff);
    /* 0x1097b1: xor ecx, 0x1172a50 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1172a50))) & UINT64_C(0xffffffff);
    /* 0x1097b7: xor edx, 0x27615879 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x27615879))) & UINT64_C(0xffffffff);
    /* 0x1097bd: or edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1097bf: lea ecx, [rdx + rdx] */
    r[2] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1097c2: and ecx, 0x147d44 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x147d44))) & UINT64_C(0xffffffff);
    /* 0x1097c8: sub edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1097ca: mov rcx, qword ptr [rbp - 0x428] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffbd8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x1097d1: movzx ecx, byte ptr [r12 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1097da: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1097dd: lea esi, [rcx + rcx] */
    r[4] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1097e0: and esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x1097e3: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1097e5: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1097e7: add ecx, 0x778b6526 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x778b6526))) & UINT64_C(0xffffffff);
    /* 0x1097ed: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x1097f0: add edx, 0xa3ea200 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xa3ea200))) & UINT64_C(0xffffffff);
    /* 0x1097f6: xor edx, 0xa3ea200 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xa3ea200))) & UINT64_C(0xffffffff);
    /* 0x1097fc: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1097ff: and esi, 0x9d6da000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x9d6da000))) & UINT64_C(0xffffffff);
    /* 0x109805: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109807: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109809: add edx, 0x4eb6d084 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4eb6d084))) & UINT64_C(0xffffffff);
    /* 0x10980f: xor edx, 0x4eb6d084 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4eb6d084))) & UINT64_C(0xffffffff);
    /* 0x109815: xor ecx, 0x778b6526 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x778b6526))) & UINT64_C(0xffffffff);
    /* 0x10981b: or ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10981d: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109820: and edx, 0x2094ac80 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2094ac80))) & UINT64_C(0xffffffff);
    /* 0x109826: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109828: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10982a: add ecx, 0x104a5640 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x104a5640))) & UINT64_C(0xffffffff);
    /* 0x109830: xor r10d, ecx */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109833: mov rdx, qword ptr [rbp - 0x2d0] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd30)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10983a: xor edx, 0x6c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c))) & UINT64_C(0xffffffff);
    /* 0x10983d: movzx ecx, byte ptr [rbp - 0x3a0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc60)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109844: xor ecx, 0x7e */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7e))) & UINT64_C(0xffffffff);
    /* 0x109847: mov edx, dword ptr [r12 + rdx*4 + 0x46a0] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10984f: xor edx, dword ptr [rbp - 0x5a8] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa58)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109855: xor edx, dword ptr [r12 + rcx*4 + 0x2ff0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10985d: shr r8d, 0x18 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109861: xor r8d, 0xe */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe))) & UINT64_C(0xffffffff);
    /* 0x109865: xor edx, dword ptr [r12 + r8*4 + 0x4ac0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10986d: mov edi, edx */
    r[5] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10986f: mov ecx, r10d */
    r[2] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109872: mov qword ptr [rbp - 0x258], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffda8)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109879: movzx esi, r10b */
    r[4] = (((r[10] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10987d: mov dword ptr [rbp - 0x3a0], r10d */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc60)), 4, ((r[10] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x109884: movzx ecx, ch */
    r[2] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109887: mov rdx, qword ptr [rbp - 0x298] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd68)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10988e: xor edx, 0xd5 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd5))) & UINT64_C(0xffffffff);
    /* 0x109894: xor edi, dword ptr [r12 + rdx*4 + 0x3950] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10989c: xor r11d, 0xec */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xec))) & UINT64_C(0xffffffff);
    /* 0x1098a3: mov r10d, r14d */
    r[10] = (((r[14] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1098a6: xor r10d, dword ptr [r12 + r11*4 + 0x3950] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1098ae: movzx edx, byte ptr [rbp - 0xc8] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1098b5: xor edx, 0x55 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x55))) & UINT64_C(0xffffffff);
    /* 0x1098b8: xor r10d, dword ptr [r12 + rdx*4 + 0x2ff0] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1098c0: mov edx, edi */
    r[3] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1098c2: mov ebx, edi */
    r[1] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1098c4: mov dword ptr [rbp - 0x3b8], edi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc48)), 4, ((r[5] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x1098ca: shr edx, 0x18 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x1098cd: xor edx, 0x4b */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4b))) & UINT64_C(0xffffffff);
    /* 0x1098d0: mov edi, r10d */
    r[5] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1098d3: mov r15d, r10d */
    r[15] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x1098d6: shr edi, 0x10 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1098d9: movzx edi, dil */
    r[5] = (((r[5] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x1098dd: xor edi, 0x4d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4d))) & UINT64_C(0xffffffff);
    /* 0x1098e0: mov r11d, dword ptr [r12 + rdx*4 + 0x4ac0] */
    r[11] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1098e8: xor r11d, dword ptr [rbp - 0x138] */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffec8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1098ef: xor r11d, dword ptr [r12 + rdi*4 + 0x2ff0] */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1098f7: xor ecx, 0xa4 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xa4))) & UINT64_C(0xffffffff);
    /* 0x1098fd: xor r11d, dword ptr [r12 + rcx*4 + 0x46a0] */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109905: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109907: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10990a: mov edx, ebx */
    r[3] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10990c: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10990f: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109912: xor edx, 0xcc */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xcc))) & UINT64_C(0xffffffff);
    /* 0x109918: xor ecx, 0x23 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x23))) & UINT64_C(0xffffffff);
    /* 0x10991b: mov r10d, dword ptr [r12 + rdx*4 + 0x2ff0] */
    r[10] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109923: mov r14d, dword ptr [rbp - 0x5b8] */
    r[14] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa48)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10992a: xor r10d, r14d */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ ((r[14] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10992d: xor r10d, dword ptr [r12 + rcx*4 + 0x4ac0] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109935: xor esi, 0xf0 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf0))) & UINT64_C(0xffffffff);
    /* 0x10993b: xor r10d, dword ptr [r12 + rsi*4 + 0x3950] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109943: mov ecx, r15d */
    r[2] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109946: movzx ecx, ch */
    r[2] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109949: xor ecx, 0xe */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe))) & UINT64_C(0xffffffff);
    /* 0x10994c: xor r10d, dword ptr [r12 + rcx*4 + 0x46a0] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109954: mov dword ptr [rbp - 0x298], eax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd68)), 4, ((r[0] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x10995a: movzx ecx, al */
    r[2] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10995d: mov qword ptr [rbp - 0x2d0], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd30)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109964: movzx eax, ah */
    r[0] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109967: mov qword ptr [rbp - 0x2e0], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd20)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10996e: mov rax, qword ptr [rbp - 0x380] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc80)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109975: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10997e: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109981: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109984: and edx, 0xffffffb6 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffb6))) & UINT64_C(0xffffffff);
    /* 0x109987: sub eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109989: mov rcx, qword ptr [rbp - 0x790] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff870)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109990: movzx edx, byte ptr [r12 + rcx + 0x2ee0] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109999: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10999c: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10999e: and esi, 0x5a */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5a))) & UINT64_C(0xffffffff);
    /* 0x1099a1: add esi, esi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099a3: sub edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099a5: shl eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x1099a8: add eax, 0xf2db0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xf2db0000))) & UINT64_C(0xffffffff);
    /* 0x1099ad: xor eax, 0xf2db0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf2db0000))) & UINT64_C(0xffffffff);
    /* 0x1099b2: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1099b5: and esi, 0xe18a0000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe18a0000))) & UINT64_C(0xffffffff);
    /* 0x1099bb: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099bd: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099bf: add eax, 0x70c5adbf */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x70c5adbf))) & UINT64_C(0xffffffff);
    /* 0x1099c4: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x1099c7: add edx, 0x55ff5a00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x55ff5a00))) & UINT64_C(0xffffffff);
    /* 0x1099cd: xor edx, 0x55ff5a00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x55ff5a00))) & UINT64_C(0xffffffff);
    /* 0x1099d3: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1099d6: and esi, 0x377c4000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x377c4000))) & UINT64_C(0xffffffff);
    /* 0x1099dc: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099de: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099e0: add edx, 0x1bbe2063 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1bbe2063))) & UINT64_C(0xffffffff);
    /* 0x1099e6: xor eax, 0x70c5adbf */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x70c5adbf))) & UINT64_C(0xffffffff);
    /* 0x1099eb: xor edx, 0x1bbe2063 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1bbe2063))) & UINT64_C(0xffffffff);
    /* 0x1099f1: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099f3: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x1099f6: and eax, 0x899404d4 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x899404d4))) & UINT64_C(0xffffffff);
    /* 0x1099fb: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099fd: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x1099ff: add eax, 0x44ca026a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x44ca026a))) & UINT64_C(0xffffffff);
    /* 0x109a04: mov rcx, qword ptr [rbp - 0x4a0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb60)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109a0b: movzx edx, byte ptr [r12 + rcx + 0x2ee0] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109a14: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109a17: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109a19: and esi, 0x56 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x56))) & UINT64_C(0xffffffff);
    /* 0x109a1c: add esi, esi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109a1e: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109a20: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109a22: add edx, 0x2b903b56 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2b903b56))) & UINT64_C(0xffffffff);
    /* 0x109a28: xor edx, 0x2b903b56 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2b903b56))) & UINT64_C(0xffffffff);
    /* 0x109a2e: xor eax, 0x44ca026a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x44ca026a))) & UINT64_C(0xffffffff);
    /* 0x109a33: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109a35: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109a38: and eax, 0x3103b2 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x3103b2))) & UINT64_C(0xffffffff);
    /* 0x109a3d: sub edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109a3f: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x109a42: lea eax, [rdx + 0x3220e100] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0x3220e100))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109a48: add edx, 0x9881d900 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x9881d900))) & UINT64_C(0xffffffff);
    /* 0x109a4e: xor edx, 0x9881d900 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9881d900))) & UINT64_C(0xffffffff);
    /* 0x109a54: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109a56: and esi, 0x7ffd3b00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7ffd3b00))) & UINT64_C(0xffffffff);
    /* 0x109a5c: and eax, 0x200 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x200))) & UINT64_C(0xffffffff);
    /* 0x109a61: xor eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109a63: add eax, eax */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109a65: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109a67: lea esi, [rdx + rax] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109a6a: add esi, 0x7ffd3995 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7ffd3995))) & UINT64_C(0xffffffff);
    /* 0x109a70: mov rax, qword ptr [rbp - 0x208] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109a77: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109a7a: xor eax, 9 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9))) & UINT64_C(0xffffffff);
    /* 0x109a7d: mov ebx, dword ptr [rbp - 0x2a8] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd58)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109a83: xor ebx, dword ptr [r12 + rax*4 + 0x4ac0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109a8b: mov eax, dword ptr [rbp - 0x230] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdd0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109a91: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109a94: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109a97: xor eax, 0x3c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3c))) & UINT64_C(0xffffffff);
    /* 0x109a9a: xor ebx, dword ptr [r12 + rax*4 + 0x2ff0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109aa2: mov rax, qword ptr [rbp - 0x188] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109aa9: xor eax, 0x89 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x89))) & UINT64_C(0xffffffff);
    /* 0x109aae: shr r13d, 0x18 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109ab2: xor r13d, 0x12 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x12))) & UINT64_C(0xffffffff);
    /* 0x109ab6: mov edx, dword ptr [r12 + rax*4 + 0x46a0] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109abe: xor edx, dword ptr [rbp - 0x6a8] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff958)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ac4: xor edx, dword ptr [r12 + r13*4 + 0x4ac0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109acc: mov eax, dword ptr [rbp - 0x218] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde8)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ad2: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109ad5: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109ad8: xor eax, 0x70 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x70))) & UINT64_C(0xffffffff);
    /* 0x109adb: xor edx, dword ptr [r12 + rax*4 + 0x2ff0] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ae3: mov rax, qword ptr [rbp - 0x2b0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109aea: xor eax, 0xeb */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xeb))) & UINT64_C(0xffffffff);
    /* 0x109aef: xor edx, dword ptr [r12 + rax*4 + 0x3950] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109af7: mov rcx, qword ptr [rbp - 0x220] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109afe: xor ecx, 0xe2 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe2))) & UINT64_C(0xffffffff);
    /* 0x109b04: mov rax, qword ptr [rbp - 0x238] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109b0b: xor eax, 0xdf */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xdf))) & UINT64_C(0xffffffff);
    /* 0x109b10: mov eax, dword ptr [r12 + rax*4 + 0x46a0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109b18: xor eax, dword ptr [r12 + rcx*4 + 0x3950] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109b20: shr r9d, 0x18 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109b24: xor r9d, 0x44 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x44))) & UINT64_C(0xffffffff);
    /* 0x109b28: xor eax, dword ptr [r12 + r9*4 + 0x4ac0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109b30: mov rcx, qword ptr [rbp - 0x470] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109b37: movzx edi, byte ptr [r12 + rcx + 0x2ee0] */
    r[5] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109b40: xor edi, 0x4c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109b43: lea ecx, [rdi + rdi] */
    r[2] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109b46: and ecx, 0x10a */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x10a))) & UINT64_C(0xffffffff);
    /* 0x109b4c: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109b4e: add ecx, edi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109b50: add ecx, 0x66209d85 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x66209d85))) & UINT64_C(0xffffffff);
    /* 0x109b56: xor esi, 0x7ffd3995 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7ffd3995))) & UINT64_C(0xffffffff);
    /* 0x109b5c: xor ecx, 0x66209d85 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x66209d85))) & UINT64_C(0xffffffff);
    /* 0x109b62: or ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109b64: lea esi, [rcx + rcx] */
    r[4] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109b67: and esi, 0xe4696836 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe4696836))) & UINT64_C(0xffffffff);
    /* 0x109b6d: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109b6f: add ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109b71: add ecx, 0x7234b41b */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7234b41b))) & UINT64_C(0xffffffff);
    /* 0x109b77: mov rsi, qword ptr [rbp - 0x2b8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd48)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109b7e: xor esi, 0xb2 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb2))) & UINT64_C(0xffffffff);
    /* 0x109b84: xor eax, dword ptr [r12 + rsi*4 + 0x2ff0] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109b8c: xor eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109b8e: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109b90: shr esi, 0x18 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109b93: xor esi, 0x67 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x67))) & UINT64_C(0xffffffff);
    /* 0x109b96: movzx r9d, al */
    r[9] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109b9a: xor r9d, 0xab */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xab))) & UINT64_C(0xffffffff);
    /* 0x109ba1: mov edi, dword ptr [r12 + rsi*4 + 0x4ac0] */
    r[5] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ba9: xor edi, r14d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ ((r[14] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109bac: xor edi, dword ptr [r12 + r9*4 + 0x3950] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109bb4: mov ecx, r15d */
    r[2] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109bb7: movzx r13d, cl */
    r[13] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109bbb: mov esi, dword ptr [rbp - 0xa8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109bc1: shr esi, 0x10 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109bc4: movzx esi, sil */
    r[4] = (((r[4] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109bc8: xor esi, 0xd9 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd9))) & UINT64_C(0xffffffff);
    /* 0x109bce: xor edi, dword ptr [r12 + rsi*4 + 0x2ff0] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109bd6: movzx esi, bh */
    r[4] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109bd9: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109bdc: xor edi, dword ptr [r12 + rsi*4 + 0x46a0] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109be4: mov dword ptr [rbp - 0xc8], edi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 4, ((r[5] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x109bea: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109bed: mov esi, dword ptr [rbp - 0x3a0] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc60)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109bf3: shr esi, 0x10 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109bf6: xor ecx, 0xb */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb))) & UINT64_C(0xffffffff);
    /* 0x109bf9: movzx esi, sil */
    r[4] = (((r[4] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109bfd: xor esi, 0xdb */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xdb))) & UINT64_C(0xffffffff);
    /* 0x109c03: mov esi, dword ptr [r12 + rsi*4 + 0x2ff0] */
    r[4] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c0b: mov r9d, dword ptr [rbp - 0x590] */
    r[9] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffa70)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c12: xor esi, r9d */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109c15: xor esi, dword ptr [r12 + rcx*4 + 0x4ac0] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c1d: mov r8d, edx */
    r[8] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109c20: movzx ecx, dh */
    r[2] = (((r[3] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109c23: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109c26: mov rdi, qword ptr [rbp - 0x2e0] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd20)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109c2d: xor edi, 0xf9 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf9))) & UINT64_C(0xffffffff);
    /* 0x109c33: xor esi, dword ptr [r12 + rdi*4 + 0x46a0] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c3b: movzx edi, ah */
    r[5] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109c3e: xor edi, 0x46 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x46))) & UINT64_C(0xffffffff);
    /* 0x109c41: xor edx, 0x9d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9d))) & UINT64_C(0xffffffff);
    /* 0x109c47: mov r14d, dword ptr [r12 + rdx*4 + 0x3950] */
    r[14] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c4f: xor r14d, dword ptr [r12 + rdi*4 + 0x46a0] */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c57: mov edx, ebx */
    r[3] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109c59: mov r15d, ebx */
    r[15] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109c5c: shr edx, 0x18 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109c5f: xor edx, 0x31 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x31))) & UINT64_C(0xffffffff);
    /* 0x109c62: mov edi, eax */
    r[5] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109c64: shr edi, 0x10 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109c67: movzx edi, dil */
    r[5] = (((r[5] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109c6b: xor edi, 0xa5 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xa5))) & UINT64_C(0xffffffff);
    /* 0x109c71: mov edi, dword ptr [r12 + rdi*4 + 0x2ff0] */
    r[5] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c79: xor edi, r9d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109c7c: xor edi, dword ptr [r12 + rdx*4 + 0x4ac0] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c84: mov ebx, dword ptr [rbp - 0x3b8] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc48)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109c8a: movzx edx, bh */
    r[3] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109c8d: movzx ebx, bl */
    r[1] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109c90: mov qword ptr [rbp - 0x220], rbx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8, ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x109c97: xor ecx, 0x3e */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3e))) & UINT64_C(0xffffffff);
    /* 0x109c9a: xor edi, dword ptr [r12 + rcx*4 + 0x46a0] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ca2: mov dword ptr [rbp - 0x2b0], edi */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 4, ((r[5] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x109ca8: mov ecx, r15d */
    r[2] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109cab: mov r9d, r15d */
    r[9] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109cae: movzx r15d, cl */
    r[15] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109cb2: mov rcx, qword ptr [rbp - 0x798] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff868)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109cb9: movzx ecx, byte ptr [r12 + rcx + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109cc2: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109cc5: lea edi, [rcx + rcx] */
    r[5] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109cc8: and edi, 0x5e */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5e))) & UINT64_C(0xffffffff);
    /* 0x109ccb: sub ecx, edi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109ccd: mov rbx, qword ptr [rbp - 0x270] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109cd4: add ebx, 0xf8ca0000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xf8ca0000))) & UINT64_C(0xffffffff);
    /* 0x109cda: xor ebx, 0xf8ca0000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf8ca0000))) & UINT64_C(0xffffffff);
    /* 0x109ce0: lea edi, [rbx + rbx] */
    r[5] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ce3: and edi, 0xd7640000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xd7640000))) & UINT64_C(0xffffffff);
    /* 0x109ce9: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109ceb: add edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109ced: add edi, 0x6bb2675d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6bb2675d))) & UINT64_C(0xffffffff);
    /* 0x109cf3: shl ecx, 8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x109cf6: add ecx, 0xc9cd2f00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xc9cd2f00))) & UINT64_C(0xffffffff);
    /* 0x109cfc: xor ecx, 0xc9cd2f00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc9cd2f00))) & UINT64_C(0xffffffff);
    /* 0x109d02: lea ebx, [rcx + rcx] */
    r[1] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109d05: and ebx, 0xbfd72000 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xbfd72000))) & UINT64_C(0xffffffff);
    /* 0x109d0b: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d0d: add ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d0f: add ecx, 0x5feb90e9 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5feb90e9))) & UINT64_C(0xffffffff);
    /* 0x109d15: xor edi, 0x6bb2675d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6bb2675d))) & UINT64_C(0xffffffff);
    /* 0x109d1b: xor ecx, 0x5feb90e9 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5feb90e9))) & UINT64_C(0xffffffff);
    /* 0x109d21: or ecx, edi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d23: mov rdi, qword ptr [rbp - 0x3e8] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc18)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109d2a: movzx edi, byte ptr [r12 + rdi + 0x2ee0] */
    r[5] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109d33: xor edi, 0x4c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109d36: lea ebx, [rdi + rdi] */
    r[1] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109d39: and ebx, 0x14a */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x14a))) & UINT64_C(0xffffffff);
    /* 0x109d3f: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d41: add edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d43: add edi, 0x4c93ada5 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4c93ada5))) & UINT64_C(0xffffffff);
    /* 0x109d49: lea ebx, [rcx + rcx] */
    r[1] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109d4c: and ebx, 0xe1e747ba */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe1e747ba))) & UINT64_C(0xffffffff);
    /* 0x109d52: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d54: add ecx, ebx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d56: add ecx, 0x70f3a3dd */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x70f3a3dd))) & UINT64_C(0xffffffff);
    /* 0x109d5c: xor ecx, 0x70f3a3dd */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x70f3a3dd))) & UINT64_C(0xffffffff);
    /* 0x109d62: xor edi, 0x4c93ada5 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c93ada5))) & UINT64_C(0xffffffff);
    /* 0x109d68: or edi, ecx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d6a: lea ecx, [rdi + rdi] */
    r[2] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109d6d: and ecx, 0x49d68 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x49d68))) & UINT64_C(0xffffffff);
    /* 0x109d73: sub edi, ecx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d75: shl edi, 8 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x109d78: add edi, 0x24eb400 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x24eb400))) & UINT64_C(0xffffffff);
    /* 0x109d7e: mov ecx, edi */
    r[2] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109d80: xor ecx, 0x24eb400 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x24eb400))) & UINT64_C(0xffffffff);
    /* 0x109d86: mov ebx, ecx */
    r[1] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109d88: and ebx, 0x7fbbb700 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7fbbb700))) & UINT64_C(0xffffffff);
    /* 0x109d8e: and edi, 0x3d110200 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x3d110200))) & UINT64_C(0xffffffff);
    /* 0x109d94: xor edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d96: add edi, edi */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d98: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d9a: add ecx, edi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109d9c: add ecx, 0x42aab5c3 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x42aab5c3))) & UINT64_C(0xffffffff);
    /* 0x109da2: mov rdi, qword ptr [rbp - 0x330] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffcd0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109da9: movzx edi, byte ptr [r12 + rdi + 0x2ee0] */
    r[5] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109db2: xor edi, 0x4c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x109db5: lea ebx, [rdi + rdi] */
    r[1] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109db8: and ebx, 0xffffff90 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff90))) & UINT64_C(0xffffffff);
    /* 0x109dbb: neg ebx */
    r[1] = ((UINT64_C(0) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109dbd: add edi, ebx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109dbf: add edi, 0x9ff8cc8 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x9ff8cc8))) & UINT64_C(0xffffffff);
    /* 0x109dc5: xor ecx, 0x42aab5c3 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x42aab5c3))) & UINT64_C(0xffffffff);
    /* 0x109dcb: xor edi, 0x9ff8cc8 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9ff8cc8))) & UINT64_C(0xffffffff);
    /* 0x109dd1: or edi, ecx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109dd3: lea ecx, [rdi + rdi] */
    r[2] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109dd6: and ecx, 0x2ce6c7fa */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2ce6c7fa))) & UINT64_C(0xffffffff);
    /* 0x109ddc: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109dde: add edi, ecx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109de0: add edi, 0x167363fd */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x167363fd))) & UINT64_C(0xffffffff);
    /* 0x109de6: mov rcx, qword ptr [rbp - 0x258] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffda8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109ded: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109df0: xor ecx, 0x2a */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2a))) & UINT64_C(0xffffffff);
    /* 0x109df3: xor r13d, 0xf2 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf2))) & UINT64_C(0xffffffff);
    /* 0x109dfa: mov ecx, dword ptr [r12 + rcx*4 + 0x4ac0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e02: xor ecx, dword ptr [r12 + r13*4 + 0x3950] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e0a: xor edx, 0x9f */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9f))) & UINT64_C(0xffffffff);
    /* 0x109e10: xor ecx, edi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109e12: xor ecx, dword ptr [r12 + rdx*4 + 0x46a0] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e1a: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109e1d: xor eax, 0x48 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x48))) & UINT64_C(0xffffffff);
    /* 0x109e20: xor edi, dword ptr [r12 + rax*4 + 0x4ac0] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e28: shr r8d, 0x10 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109e2c: movzx eax, r8b */
    r[0] = (((r[8] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109e30: xor eax, 0x8c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x8c))) & UINT64_C(0xffffffff);
    /* 0x109e35: xor edi, dword ptr [r12 + rax*4 + 0x2ff0] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e3d: mov r13d, edi */
    r[13] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109e40: mov eax, dword ptr [rbp - 0xa8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e46: movzx r8d, al */
    r[8] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109e4a: movzx edx, ah */
    r[3] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109e4d: mov edi, eax */
    r[5] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109e4f: xor edx, 0x94 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x94))) & UINT64_C(0xffffffff);
    /* 0x109e55: xor r13d, dword ptr [r12 + rdx*4 + 0x46a0] */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x46a0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e5d: shr edi, 0x18 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x109e60: xor edi, 0x1d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1d))) & UINT64_C(0xffffffff);
    /* 0x109e63: shr r9d, 0x10 */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109e67: movzx edx, r9b */
    r[3] = (((r[9] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109e6b: xor edx, 0x32 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x32))) & UINT64_C(0xffffffff);
    /* 0x109e6e: mov edi, dword ptr [r12 + rdi*4 + 0x4ac0] */
    r[5] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ac0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e76: xor edi, dword ptr [rbp - 0x138] */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffec8)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e7c: xor edi, 0x5f562780 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5f562780))) & UINT64_C(0xffffffff);
    /* 0x109e82: mov edx, dword ptr [r12 + rdx*4 + 0x2ff0] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e8a: mov eax, 0x2780c4eb */
    r[0] = (UINT64_C(0x2780c4eb)) & UINT64_C(0xffffffff);
    /* 0x109e8f: xor edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109e91: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109e93: and eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109e95: lea ebx, [rax + rax] */
    r[1] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109e98: and ebx, 0x39f6bc70 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x39f6bc70))) & UINT64_C(0xffffffff);
    /* 0x109e9e: sub eax, ebx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[1] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109ea0: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109ea2: mov edi, edx */
    r[5] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109ea4: xor edi, 0x36b7ea3f */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x36b7ea3f))) & UINT64_C(0xffffffff);
    /* 0x109eaa: and edx, 0x36b7ea3f */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x36b7ea3f))) & UINT64_C(0xffffffff);
    /* 0x109eb0: lea edx, [rdi + rdx*2] */
    r[3] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109eb3: add eax, eax */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109eb5: add eax, 0xb9f6bc70 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xb9f6bc70))) & UINT64_C(0xffffffff);
    /* 0x109eba: xor eax, 0x4609438e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4609438e))) & UINT64_C(0xffffffff);
    /* 0x109ebf: add eax, 2 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2))) & UINT64_C(0xffffffff);
    /* 0x109ec2: mov edi, eax */
    r[5] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109ec4: xor edi, 0x35bded57 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x35bded57))) & UINT64_C(0xffffffff);
    /* 0x109eca: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109ecc: and eax, 0x35bded56 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x35bded56))) & UINT64_C(0xffffffff);
    /* 0x109ed1: lea eax, [rdx + rax*2] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ed4: mov rdx, qword ptr [rbp - 0x2d0] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd30)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109edb: xor r11d, dword ptr [r12 + rdx*4 + 0x3950] */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ee3: mov rdx, qword ptr [rbp - 0x220] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x109eea: xor edx, 0x9a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9a))) & UINT64_C(0xffffffff);
    /* 0x109ef0: xor esi, dword ptr [r12 + rdx*4 + 0x3950] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109ef8: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109efb: add edx, 0x271450d4 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x271450d4))) & UINT64_C(0xffffffff);
    /* 0x109f01: and edx, 0x45f4dc8a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x45f4dc8a))) & UINT64_C(0xffffffff);
    /* 0x109f07: sub eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109f09: xor r8d, 4 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4))) & UINT64_C(0xffffffff);
    /* 0x109f0d: mov r9d, dword ptr [rbp - 0x2b0] */
    r[9] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109f14: xor r9d, dword ptr [r12 + r8*4 + 0x3950] */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109f1c: add eax, 0xb68496af */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xb68496af))) & UINT64_C(0xffffffff);
    /* 0x109f21: xor r14d, eax */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109f24: mov eax, dword ptr [rbp - 0x298] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd68)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109f2a: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x109f2d: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x109f30: xor eax, 0x24 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x24))) & UINT64_C(0xffffffff);
    /* 0x109f33: xor ecx, dword ptr [r12 + rax*4 + 0x2ff0] */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x2ff0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109f3b: xor r15d, 0xc8 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc8))) & UINT64_C(0xffffffff);
    /* 0x109f42: xor r13d, dword ptr [r12 + r15*4 + 0x3950] */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3950)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109f4a: mov edi, dword ptr [rbp - 0xc8] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109f50: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109f52: xor eax, 0x66033a0d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x66033a0d))) & UINT64_C(0xffffffff);
    /* 0x109f57: mov edx, r10d */
    r[3] = (((r[10] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109f5a: xor edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109f5c: xor edx, 0x31d443c4 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x31d443c4))) & UINT64_C(0xffffffff);
    /* 0x109f62: add edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109f64: xor r10d, 0x99fcc5f2 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x99fcc5f2))) & UINT64_C(0xffffffff);
    /* 0x109f6b: mov eax, edx */
    r[0] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109f6d: xor eax, 0x1bff37f6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1bff37f6))) & UINT64_C(0xffffffff);
    /* 0x109f72: add r10d, eax */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109f75: and edx, 0x1bff37f6 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1bff37f6))) & UINT64_C(0xffffffff);
    /* 0x109f7b: lea eax, [r10 + rdx*2] */
    r[0] = ((((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109f7f: add eax, 0xe400c80b */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xe400c80b))) & UINT64_C(0xffffffff);
    /* 0x109f84: mov edx, eax */
    r[3] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109f86: xor edx, 0xfbdf9f5d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xfbdf9f5d))) & UINT64_C(0xffffffff);
    /* 0x109f8c: and eax, 0xfbdf9f5d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfbdf9f5d))) & UINT64_C(0xffffffff);
    /* 0x109f91: lea eax, [rdx + rax*2] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109f94: mov edi, r11d */
    r[5] = (((r[11] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109f97: xor edi, r14d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ ((r[14] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109f9a: xor edi, 0xaf62afda */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xaf62afda))) & UINT64_C(0xffffffff);
    /* 0x109fa0: mov edx, r14d */
    r[3] = (((r[14] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109fa3: mov r15, r14 */
    r[15] = (((r[14] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x109fa6: xor edx, 0x4e239041 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4e239041))) & UINT64_C(0xffffffff);
    /* 0x109fac: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109fae: xor r11d, 0xebf0e290 */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xebf0e290))) & UINT64_C(0xffffffff);
    /* 0x109fb5: mov edi, edx */
    r[5] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109fb7: xor edi, 0x1cf73fd7 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1cf73fd7))) & UINT64_C(0xffffffff);
    /* 0x109fbd: add r11d, edi */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109fc0: and edx, 0x1cf73fd7 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1cf73fd7))) & UINT64_C(0xffffffff);
    /* 0x109fc6: lea edx, [r11 + rdx*2] */
    r[3] = ((((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109fca: add edx, 0xe308c02a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xe308c02a))) & UINT64_C(0xffffffff);
    /* 0x109fd0: mov edi, edx */
    r[5] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109fd2: xor edi, 0x6f57fce7 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6f57fce7))) & UINT64_C(0xffffffff);
    /* 0x109fd8: and edx, 0xef57fce7 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xef57fce7))) & UINT64_C(0xffffffff);
    /* 0x109fde: lea r8d, [rdi + rdx*2] */
    r[8] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x109fe2: mov edx, r13d */
    r[3] = (((r[13] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109fe5: xor edx, 0x2ce2914d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2ce2914d))) & UINT64_C(0xffffffff);
    /* 0x109feb: mov ebx, ecx */
    r[1] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x109fed: xor ebx, r13d */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ ((r[13] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109ff0: xor ebx, 0x482d8ca3 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x482d8ca3))) & UINT64_C(0xffffffff);
    /* 0x109ff6: add ebx, edx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x109ff8: xor ecx, 0xd31d6eb2 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd31d6eb2))) & UINT64_C(0xffffffff);
    /* 0x109ffe: mov edx, ebx */
    r[3] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a000: xor edx, 0xf7ff6fd6 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf7ff6fd6))) & UINT64_C(0xffffffff);
    /* 0x10a006: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a008: and ebx, 0xf7ff6fd6 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xf7ff6fd6))) & UINT64_C(0xffffffff);
    /* 0x10a00e: lea edx, [rcx + rbx*2] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a011: add edx, 0x800902b */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x800902b))) & UINT64_C(0xffffffff);
    /* 0x10a017: mov ecx, r9d */
    r[2] = (((r[9] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a01a: xor ecx, esi */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a01c: xor ecx, 0x686d45ae */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x686d45ae))) & UINT64_C(0xffffffff);
    /* 0x10a022: mov ebx, r9d */
    r[1] = (((r[9] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a025: mov r10d, r9d */
    r[10] = (((r[9] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a028: xor ebx, 0x421c8175 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x421c8175))) & UINT64_C(0xffffffff);
    /* 0x10a02e: add ebx, ecx */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a030: imul ecx, eax, 0xaf45a39f */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) * UINT64_C(0xaf45a39f))) & UINT64_C(0xffffffff);
    /* 0x10a036: imul eax, eax, 0x5e8b473e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) * UINT64_C(0x5e8b473e))) & UINT64_C(0xffffffff);
    /* 0x10a03c: add eax, 0x4d259c7a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4d259c7a))) & UINT64_C(0xffffffff);
    /* 0x10a041: and eax, 0xa154813c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa154813c))) & UINT64_C(0xffffffff);
    /* 0x10a046: sub ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a048: mov eax, ebx */
    r[0] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a04a: xor eax, 0x2eebefb7 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2eebefb7))) & UINT64_C(0xffffffff);
    /* 0x10a04f: xor esi, 0xbde37e8a */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbde37e8a))) & UINT64_C(0xffffffff);
    /* 0x10a055: add esi, eax */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a057: and ebx, 0x2eebefb7 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2eebefb7))) & UINT64_C(0xffffffff);
    /* 0x10a05d: lea eax, [rsi + rbx*2] */
    r[0] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a060: add eax, 0xd114104a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd114104a))) & UINT64_C(0xffffffff);
    /* 0x10a065: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a067: xor esi, 0xfa7ffd3f */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xfa7ffd3f))) & UINT64_C(0xffffffff);
    /* 0x10a06d: and edx, 0xfa7ffd3f */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfa7ffd3f))) & UINT64_C(0xffffffff);
    /* 0x10a073: lea esi, [rsi + rdx*2] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a076: mov edx, eax */
    r[3] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a078: xor edx, 0x7dfffaff */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7dfffaff))) & UINT64_C(0xffffffff);
    /* 0x10a07e: and eax, 0xfdfffaff */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfdfffaff))) & UINT64_C(0xffffffff);
    /* 0x10a083: lea edx, [rdx + rax*2] */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a086: imul eax, edx, 0xa371574d */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) * UINT64_C(0xa371574d))) & UINT64_C(0xffffffff);
    /* 0x10a08c: imul edx, edx, 0x46e2ae9a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) * UINT64_C(0x46e2ae9a))) & UINT64_C(0xffffffff);
    /* 0x10a092: add edx, 0x84bb09a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x84bb09a))) & UINT64_C(0xffffffff);
    /* 0x10a098: and edx, 0x1e81d682 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1e81d682))) & UINT64_C(0xffffffff);
    /* 0x10a09e: sub eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a0a0: imul edx, esi, 0xc6da4f7b */
    r[3] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) * UINT64_C(0xc6da4f7b))) & UINT64_C(0xffffffff);
    /* 0x10a0a6: imul esi, esi, 0x8db49ef6 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) * UINT64_C(0x8db49ef6))) & UINT64_C(0xffffffff);
    /* 0x10a0ac: add esi, 0x769c376 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x769c376))) & UINT64_C(0xffffffff);
    /* 0x10a0b2: and esi, 0x308edbd2 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x308edbd2))) & UINT64_C(0xffffffff);
    /* 0x10a0b8: sub edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a0ba: add ecx, 0xf73d0edb */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xf73d0edb))) & UINT64_C(0xffffffff);
    /* 0x10a0c0: imul esi, r8d, 0xdddb4679 */
    r[4] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) * UINT64_C(0xdddb4679))) & UINT64_C(0xffffffff);
    /* 0x10a0c7: mov edi, ecx */
    r[5] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a0c9: xor edi, 0xaf55bf61 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xaf55bf61))) & UINT64_C(0xffffffff);
    /* 0x10a0cf: add edi, esi */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a0d1: add edi, 0x8ba54cd2 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x8ba54cd2))) & UINT64_C(0xffffffff);
    /* 0x10a0d7: mov ebx, edi */
    r[1] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a0d9: xor ebx, 0x75f7fdf */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x75f7fdf))) & UINT64_C(0xffffffff);
    /* 0x10a0df: and edi, 0x75f7fdf */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x75f7fdf))) & UINT64_C(0xffffffff);
    /* 0x10a0e5: lea edi, [rbx + rdi*2] */
    r[5] = ((((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a0e8: add eax, 0x366c38e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x366c38e))) & UINT64_C(0xffffffff);
    /* 0x10a0ed: add edx, 0xdbfc4fa4 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xdbfc4fa4))) & UINT64_C(0xffffffff);
    /* 0x10a0f3: xor edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a0f5: xor eax, 0xf40eb41 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf40eb41))) & UINT64_C(0xffffffff);
    /* 0x10a0fa: sub eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a0fc: add eax, 0x745ab32f */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x745ab32f))) & UINT64_C(0xffffffff);
    /* 0x10a101: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a104: and esi, 0x1075d4c6 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1075d4c6))) & UINT64_C(0xffffffff);
    /* 0x10a10a: sub eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a10c: xor ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a10e: xor edx, 0x170786a8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x170786a8))) & UINT64_C(0xffffffff);
    /* 0x10a114: sub edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a116: add edx, 0x75f7fdf */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x75f7fdf))) & UINT64_C(0xffffffff);
    /* 0x10a11c: mov esi, edx */
    r[4] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a11e: xor esi, 0xf77ef6a */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf77ef6a))) & UINT64_C(0xffffffff);
    /* 0x10a124: and edx, 0xf77ef6a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xf77ef6a))) & UINT64_C(0xffffffff);
    /* 0x10a12a: lea r8d, [rsi + rdx*2] */
    r[8] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a12e: add eax, 0x83aea63 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x83aea63))) & UINT64_C(0xffffffff);
    /* 0x10a133: xor eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a135: xor ecx, 0x47adc636 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x47adc636))) & UINT64_C(0xffffffff);
    /* 0x10a13b: xor eax, 0x4f972c55 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4f972c55))) & UINT64_C(0xffffffff);
    /* 0x10a140: add ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a142: mov edx, ecx */
    r[3] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a144: xor edx, 0x9fb3e22f */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9fb3e22f))) & UINT64_C(0xffffffff);
    /* 0x10a14a: and ecx, 0x1fb3e22f */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1fb3e22f))) & UINT64_C(0xffffffff);
    /* 0x10a150: lea r9d, [rdx + rcx*2] */
    r[9] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 2 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a154: mov ecx, r8d */
    r[2] = (((r[8] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a157: sub ecx, r9d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a15a: add ecx, 0x903bf2c5 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x903bf2c5))) & UINT64_C(0xffffffff);
    /* 0x10a160: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a163: and edx, 0x5c8417ca */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5c8417ca))) & UINT64_C(0xffffffff);
    /* 0x10a169: sub ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a16b: add ecx, 0x2e420be5 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2e420be5))) & UINT64_C(0xffffffff);
    /* 0x10a171: mov edx, ecx */
    r[3] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a173: xor ecx, r13d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ ((r[13] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a176: mov esi, ecx */
    r[4] = (((r[2] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a178: movzx ebx, cl */
    r[1] = (((r[2] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a17b: mov qword ptr [rbp - 0xa8], rbx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8, ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10a182: movzx ebx, ch */
    r[1] = (((r[2] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a185: mov qword ptr [rbp - 0x188], rbx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8, ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10a18c: mov dword ptr [rbp - 0x270], ecx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 4, ((r[2] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x10a192: xor edx, 0xd1bdf41a */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd1bdf41a))) & UINT64_C(0xffffffff);
    /* 0x10a198: lea ecx, [rax + rdx] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a19b: add ecx, ecx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a19d: add ecx, 2 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2))) & UINT64_C(0xffffffff);
    /* 0x10a1a0: and ecx, 0xd6e584e0 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xd6e584e0))) & UINT64_C(0xffffffff);
    /* 0x10a1a6: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a1a8: add eax, 1 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1))) & UINT64_C(0xffffffff);
    /* 0x10a1ab: sub eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a1ad: add eax, 0x6b72c270 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6b72c270))) & UINT64_C(0xffffffff);
    /* 0x10a1b2: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a1b4: xor eax, r10d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ ((r[10] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a1b7: mov r10d, eax */
    r[10] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a1ba: movzx r11d, al */
    r[11] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a1be: movzx edx, ah */
    r[3] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a1c1: mov qword ptr [rbp - 0x208], rdx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 8, ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10a1c8: mov r14d, eax */
    r[14] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a1cb: sub edi, r8d */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) - ((r[8] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a1ce: xor ecx, 0x6b72c270 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6b72c270))) & UINT64_C(0xffffffff);
    /* 0x10a1d4: lea eax, [rdi + rcx] */
    r[0] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a1d7: lea r8d, [rax + rax] */
    r[8] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a1db: add r8d, 0x1030df16 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1030df16))) & UINT64_C(0xffffffff);
    /* 0x10a1e2: and r8d, 0x3c7d9278 */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x3c7d9278))) & UINT64_C(0xffffffff);
    /* 0x10a1e9: lea eax, [rdi + rcx] */
    r[0] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a1ec: add eax, 0x8186f8b */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x8186f8b))) & UINT64_C(0xffffffff);
    /* 0x10a1f1: sub eax, r8d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[8] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a1f4: add eax, 0x1e3ec93c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1e3ec93c))) & UINT64_C(0xffffffff);
    /* 0x10a1f9: xor r15d, eax */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a1fc: xor eax, 0xe1c136c3 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xe1c136c3))) & UINT64_C(0xffffffff);
    /* 0x10a201: add eax, r9d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[9] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a204: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a207: add ecx, 0x983ba4 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x983ba4))) & UINT64_C(0xffffffff);
    /* 0x10a20d: and ecx, 0x391e0a7e */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x391e0a7e))) & UINT64_C(0xffffffff);
    /* 0x10a213: sub eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a215: add eax, 0x7cdb2311 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7cdb2311))) & UINT64_C(0xffffffff);
    /* 0x10a21a: xor eax, dword ptr [rbp - 0xc8] */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a220: mov ecx, eax */
    r[2] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a222: movzx edx, al */
    r[3] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a225: mov qword ptr [rbp - 0xc8], rdx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8, ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10a22c: movzx edx, ah */
    r[3] = (((r[0] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a22f: mov qword ptr [rbp - 0x220], rdx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8, ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10a236: mov edx, eax */
    r[3] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a238: mov rbx, r15 */
    r[1] = (((r[15] >> 0) & UINT64_C(0xffffffffffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x10a23b: mov eax, ebx */
    r[0] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a23d: mov dword ptr [rbp - 0x2b0], ebx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 4, ((r[1] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x10a243: movzx r8d, bl */
    r[8] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a247: movzx eax, bh */
    r[0] = (((r[1] >> 8) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a24a: shr ebx, 0x18 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a24d: xor ebx, 0x49 */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x49))) & UINT64_C(0xffffffff);
    /* 0x10a250: mov r9d, dword ptr [r12 + rbx*4 + 0x3410] */
    r[9] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[1] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3410)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a258: shr esi, 0x18 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a25b: xor esi, 0x41 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x41))) & UINT64_C(0xffffffff);
    /* 0x10a25e: xor eax, 0xd2 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd2))) & UINT64_C(0xffffffff);
    /* 0x10a263: mov ebx, dword ptr [r12 + rsi*4 + 0x3410] */
    r[1] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3410)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a26b: xor ebx, dword ptr [r12 + rax*4 + 0x4ef0] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ef0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a273: mov rax, qword ptr [rbp - 0x3e0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc20)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a27a: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a283: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a286: lea r15d, [rax + rax] */
    r[15] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a28a: and r15d, 0x156 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x156))) & UINT64_C(0xffffffff);
    /* 0x10a291: sub eax, r15d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[15] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a294: mov rsi, qword ptr [rbp - 0x6f8] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff908)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a29b: movzx r15d, byte ptr [r12 + rsi + 0x2ee0] */
    r[15] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a2a4: xor r15d, 0x4c */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a2a8: mov r13d, r15d */
    r[13] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a2ab: and r13d, 0x53 */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x53))) & UINT64_C(0xffffffff);
    /* 0x10a2af: add r13d, r13d */
    r[13] = ((((r[13] >> 0) & UINT64_C(0xffffffff)) + ((r[13] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a2b2: sub r15d, r13d */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) - ((r[13] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a2b5: shl eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a2b8: add eax, 0xcbab0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xcbab0000))) & UINT64_C(0xffffffff);
    /* 0x10a2bd: xor eax, 0xcbab0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xcbab0000))) & UINT64_C(0xffffffff);
    /* 0x10a2c2: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a2c5: and esi, 0x58a80000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x58a80000))) & UINT64_C(0xffffffff);
    /* 0x10a2cb: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a2cd: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a2cf: add eax, 0x2c54037a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2c54037a))) & UINT64_C(0xffffffff);
    /* 0x10a2d4: shl r15d, 8 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a2d8: add r15d, 0xf5f15300 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xf5f15300))) & UINT64_C(0xffffffff);
    /* 0x10a2df: xor r15d, 0xf5f15300 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf5f15300))) & UINT64_C(0xffffffff);
    /* 0x10a2e6: lea esi, [r15 + r15] */
    r[4] = ((((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a2ea: and esi, 0x729d9e00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x729d9e00))) & UINT64_C(0xffffffff);
    /* 0x10a2f0: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a2f2: add esi, r15d */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[15] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a2f5: add esi, 0x394ecfa5 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x394ecfa5))) & UINT64_C(0xffffffff);
    /* 0x10a2fb: xor eax, 0x2c54037a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2c54037a))) & UINT64_C(0xffffffff);
    /* 0x10a300: xor esi, 0x394ecfa5 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x394ecfa5))) & UINT64_C(0xffffffff);
    /* 0x10a306: or esi, eax */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a308: lea eax, [rsi + rsi] */
    r[0] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a30b: and eax, 0xe4982e00 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe4982e00))) & UINT64_C(0xffffffff);
    /* 0x10a310: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a312: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a314: add eax, 0x724c1700 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x724c1700))) & UINT64_C(0xffffffff);
    /* 0x10a319: mov rsi, qword ptr [rbp - 0x558] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffaa8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a320: movzx esi, byte ptr [r12 + rsi + 0x2ee0] */
    r[4] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a329: xor esi, 0x4c */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a32c: lea edi, [rsi + rsi] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a32f: and edi, 0x2e */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x2e))) & UINT64_C(0xffffffff);
    /* 0x10a332: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a334: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a336: add esi, 0x50e7c417 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x50e7c417))) & UINT64_C(0xffffffff);
    /* 0x10a33c: xor eax, 0x724c1700 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x724c1700))) & UINT64_C(0xffffffff);
    /* 0x10a341: xor esi, 0x50e7c417 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x50e7c417))) & UINT64_C(0xffffffff);
    /* 0x10a347: or esi, eax */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a349: lea eax, [rsi + rsi] */
    r[0] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a34c: and eax, 0x1a0b2a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1a0b2a))) & UINT64_C(0xffffffff);
    /* 0x10a351: sub esi, eax */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a353: mov rax, qword ptr [rbp - 0x510] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffaf0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a35a: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a363: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a366: lea edi, [rax + rax] */
    r[5] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a369: and edi, 0xffffff80 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff80))) & UINT64_C(0xffffffff);
    /* 0x10a36c: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a36e: add eax, edi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a370: add eax, 0x3e8e96c0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3e8e96c0))) & UINT64_C(0xffffffff);
    /* 0x10a375: shl esi, 8 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a378: add esi, 0xd059500 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd059500))) & UINT64_C(0xffffffff);
    /* 0x10a37e: xor esi, 0xd059500 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd059500))) & UINT64_C(0xffffffff);
    /* 0x10a384: lea edi, [rsi + rsi] */
    r[5] = ((((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a387: and edi, 0x1377f800 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x1377f800))) & UINT64_C(0xffffffff);
    /* 0x10a38d: neg edi */
    r[5] = ((UINT64_C(0) - ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a38f: add esi, edi */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a391: add esi, 0x9bbfca5 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x9bbfca5))) & UINT64_C(0xffffffff);
    /* 0x10a397: xor esi, 0x9bbfca5 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9bbfca5))) & UINT64_C(0xffffffff);
    /* 0x10a39d: xor eax, 0x3e8e96c0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3e8e96c0))) & UINT64_C(0xffffffff);
    /* 0x10a3a2: or eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a3a4: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a3a7: and esi, 0x8794ff30 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x8794ff30))) & UINT64_C(0xffffffff);
    /* 0x10a3ad: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a3af: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a3b1: add eax, 0x43ca7f98 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x43ca7f98))) & UINT64_C(0xffffffff);
    /* 0x10a3b6: xor ebx, eax */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a3b8: xor r11d, 0xbb */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbb))) & UINT64_C(0xffffffff);
    /* 0x10a3bf: xor ebx, dword ptr [r12 + r11*4 + 0x4290] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4290)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a3c7: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a3ca: movzx eax, dl */
    r[0] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a3cd: xor eax, 0x35 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x35))) & UINT64_C(0xffffffff);
    /* 0x10a3d0: xor ebx, dword ptr [r12 + rax*4 + 0x3d70] */
    r[1] = ((((r[1] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3d70)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a3d8: mov edi, ebx */
    r[5] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a3da: shr edi, 0x18 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a3dd: xor dil, byte ptr [rbp - 0x190] */
    r[5] = (r[5] & UINT64_C(0xffffffffffffff00)) | ((((((r[5] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe70)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a3e4: shr r10d, 0x10 */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a3e8: movzx eax, r10b */
    r[0] = (((r[10] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a3ec: xor eax, 0x89 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x89))) & UINT64_C(0xffffffff);
    /* 0x10a3f1: xor r9d, dword ptr [r12 + rax*4 + 0x3d70] */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3d70)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a3f9: mov rax, qword ptr [rbp - 0x208] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdf8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a400: xor eax, 0xdd */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xdd))) & UINT64_C(0xffffffff);
    /* 0x10a405: mov r10d, dword ptr [r12 + rax*4 + 0x4ef0] */
    r[10] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ef0)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a40d: mov rax, qword ptr [rbp - 0x188] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe78)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a414: xor eax, 0xcb */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xcb))) & UINT64_C(0xffffffff);
    /* 0x10a419: xor r9d, dword ptr [r12 + rax*4 + 0x4ef0] */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ef0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a421: mov rax, qword ptr [rbp - 0x390] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc70)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a428: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a431: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a434: mov edx, eax */
    r[3] = (((r[0] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a436: and edx, 0x6c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x6c))) & UINT64_C(0xffffffff);
    /* 0x10a439: add edx, edx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a43b: sub eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a43d: mov rdx, qword ptr [rbp - 0x768] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff898)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a444: movzx edx, byte ptr [r12 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a44d: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a450: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a453: and esi, 0x72 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x72))) & UINT64_C(0xffffffff);
    /* 0x10a456: sub edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a458: shl eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a45b: add eax, 0x5a6c0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5a6c0000))) & UINT64_C(0xffffffff);
    /* 0x10a460: xor eax, 0x5a6c0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5a6c0000))) & UINT64_C(0xffffffff);
    /* 0x10a465: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a468: and esi, 0x5d660000 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x5d660000))) & UINT64_C(0xffffffff);
    /* 0x10a46e: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a470: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a472: add eax, 0x2eb3d4f5 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x2eb3d4f5))) & UINT64_C(0xffffffff);
    /* 0x10a477: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a47a: add edx, 0x5fa63900 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5fa63900))) & UINT64_C(0xffffffff);
    /* 0x10a480: xor edx, 0x5fa63900 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5fa63900))) & UINT64_C(0xffffffff);
    /* 0x10a486: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a489: and esi, 0xa2cb0c00 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xa2cb0c00))) & UINT64_C(0xffffffff);
    /* 0x10a48f: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a491: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a493: add edx, 0x516586ef */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x516586ef))) & UINT64_C(0xffffffff);
    /* 0x10a499: xor eax, 0x2eb3d4f5 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x2eb3d4f5))) & UINT64_C(0xffffffff);
    /* 0x10a49e: xor edx, 0x516586ef */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x516586ef))) & UINT64_C(0xffffffff);
    /* 0x10a4a4: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a4a6: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a4a9: and eax, 0x98d3dadc */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x98d3dadc))) & UINT64_C(0xffffffff);
    /* 0x10a4ae: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a4b0: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a4b2: add eax, 0x4c69ed6e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x4c69ed6e))) & UINT64_C(0xffffffff);
    /* 0x10a4b7: mov rdx, qword ptr [rbp - 0x490] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb70)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a4be: movzx edx, byte ptr [r12 + rdx + 0x2ee0] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a4c7: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a4ca: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a4cd: and esi, 0xffffffd4 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffd4))) & UINT64_C(0xffffffff);
    /* 0x10a4d0: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a4d2: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a4d4: add edx, 0x5eaab8ea */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x5eaab8ea))) & UINT64_C(0xffffffff);
    /* 0x10a4da: xor eax, 0x4c69ed6e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c69ed6e))) & UINT64_C(0xffffffff);
    /* 0x10a4df: xor edx, 0x5eaab8ea */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x5eaab8ea))) & UINT64_C(0xffffffff);
    /* 0x10a4e5: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a4e7: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a4ea: and eax, 0x34cc62 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x34cc62))) & UINT64_C(0xffffffff);
    /* 0x10a4ef: sub edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a4f1: mov rax, qword ptr [rbp - 0x508] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffaf8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a4f8: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a501: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a504: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a507: and esi, 0x12e */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x12e))) & UINT64_C(0xffffffff);
    /* 0x10a50d: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a50f: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a511: add eax, 0x3f2c5297 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3f2c5297))) & UINT64_C(0xffffffff);
    /* 0x10a516: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a519: add edx, 0x9a663100 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x9a663100))) & UINT64_C(0xffffffff);
    /* 0x10a51f: xor edx, 0x9a663100 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9a663100))) & UINT64_C(0xffffffff);
    /* 0x10a525: lea esi, [rdx + rdx] */
    r[4] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a528: and esi, 0x4a747400 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x4a747400))) & UINT64_C(0xffffffff);
    /* 0x10a52e: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a530: add edx, esi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a532: add edx, 0x253a3afc */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x253a3afc))) & UINT64_C(0xffffffff);
    /* 0x10a538: shr r14d, 0x18 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a53c: xor r14d, 0xb7 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb7))) & UINT64_C(0xffffffff);
    /* 0x10a543: mov esi, dword ptr [r12 + r14*4 + 0x3410] */
    r[4] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3410)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a54b: xor r8d, 0x9a */
    r[8] = ((((r[8] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x9a))) & UINT64_C(0xffffffff);
    /* 0x10a552: xor esi, dword ptr [r12 + r8*4 + 0x4290] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4290)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a55a: xor eax, 0x3f2c5297 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3f2c5297))) & UINT64_C(0xffffffff);
    /* 0x10a55f: xor edx, 0x253a3afc */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x253a3afc))) & UINT64_C(0xffffffff);
    /* 0x10a565: or eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a567: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a56a: and edx, 0xe8e4a31e */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe8e4a31e))) & UINT64_C(0xffffffff);
    /* 0x10a570: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a572: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a574: add eax, 0x7472518f */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7472518f))) & UINT64_C(0xffffffff);
    /* 0x10a579: mov edx, dword ptr [rbp - 0x270] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a57f: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a582: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a585: xor edx, 0x1c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1c))) & UINT64_C(0xffffffff);
    /* 0x10a588: xor esi, dword ptr [r12 + rdx*4 + 0x3d70] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3d70)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a590: xor esi, eax */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a592: mov rax, qword ptr [rbp - 0x220] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffde0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a599: xor eax, 0xb0 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xb0))) & UINT64_C(0xffffffff);
    /* 0x10a59e: xor esi, dword ptr [r12 + rax*4 + 0x4ef0] */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4ef0)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a5a6: shr ecx, 0x18 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a5a9: xor ecx, 0xd2 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd2))) & UINT64_C(0xffffffff);
    /* 0x10a5af: xor r10d, dword ptr [r12 + rcx*4 + 0x3410] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3410)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a5b7: mov eax, dword ptr [rbp - 0x2b0] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd50)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a5bd: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a5c0: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a5c3: xor eax, 0x70 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x70))) & UINT64_C(0xffffffff);
    /* 0x10a5c6: xor r10d, dword ptr [r12 + rax*4 + 0x3d70] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x3d70)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a5ce: mov edx, ebx */
    r[3] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a5d0: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a5d3: xor dl, byte ptr [rbp - 0x1f0] */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe10)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a5d9: mov rax, qword ptr [rbp - 0xa8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a5e0: xor eax, 0x53 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x53))) & UINT64_C(0xffffffff);
    /* 0x10a5e3: xor r10d, dword ptr [r12 + rax*4 + 0x4290] */
    r[10] = ((((r[10] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4290)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a5eb: mov dword ptr [rbp - 0xa8], r10d */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 4, ((r[10] >> 0) & UINT64_C(0xffffffff)));
    if (m->error) return m->error;
    /* 0x10a5f2: mov rax, qword ptr [rbp - 0xc8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a5f9: xor eax, 0xbf */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbf))) & UINT64_C(0xffffffff);
    /* 0x10a5fe: xor r9d, dword ptr [r12 + rax*4 + 0x4290] */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x4290)), 4))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a606: xor dil, 0x32 */
    r[5] = (r[5] & UINT64_C(0xffffffffffffff00)) | ((((((r[5] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x32))) & UINT64_C(0xff)) << 0);
    /* 0x10a60a: movzx eax, dil */
    r[0] = (((r[5] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a60e: movzx r13d, byte ptr [r12 + rax + 0x5300] */
    r[13] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a617: xor r13b, 0x33 */
    r[13] = (r[13] & UINT64_C(0xffffffffffffff00)) | ((((((r[13] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a61b: mov rax, qword ptr [rbp - 0x478] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb88)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a622: movzx r15d, byte ptr [r12 + rax + 0x2ee0] */
    r[15] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a62b: mov rax, qword ptr [rbp - 0x528] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffad8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a632: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a63b: mov qword ptr [rbp - 0xc8], rax */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8, ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10a642: mov rax, qword ptr [rbp - 0x688] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff978)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a649: movzx r14d, byte ptr [r12 + rax + 0x2ee0] */
    r[14] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a652: mov rax, qword ptr [rbp - 0x6d8] */
    r[0] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff928)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a659: movzx eax, byte ptr [r12 + rax + 0x2ee0] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a662: mov rdi, qword ptr [rbp - 0x6e0] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff920)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a669: movzx r11d, byte ptr [r12 + rdi + 0x2ee0] */
    r[11] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a672: mov rdi, qword ptr [rbp - 0x500] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffb00)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a679: movzx ecx, byte ptr [r12 + rdi + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a682: mov qword ptr [rbp - 0x270], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10a689: mov rdi, qword ptr [rbp - 0x748] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff8b8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a690: movzx ecx, byte ptr [r12 + rdi + 0x2ee0] */
    r[2] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a699: mov qword ptr [rbp - 0x1f0], rcx */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe10)), 8, ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)));
    if (m->error) return m->error;
    /* 0x10a6a0: mov rdi, qword ptr [rbp - 0x368] */
    r[5] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc98)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a6a7: movzx edi, byte ptr [r12 + rdi + 0x2ee0] */
    r[5] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x2ee0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a6b0: mov r8, qword ptr [rbp - 0x788] */
    r[8] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffff878)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a6b7: mov r10, qword ptr [rbp - 0xd0] */
    r[10] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff30)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a6be: mov byte ptr [r8 + r10], r13b */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[10] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[13] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a6c2: xor dl, 0xb2 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0xb2))) & UINT64_C(0xff)) << 0);
    /* 0x10a6c5: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a6c8: movzx edx, byte ptr [r12 + rdx + 0x5300] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a6d1: xor dl, 0x33 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a6d4: mov rcx, qword ptr [rbp - 0x250] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdb0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a6db: mov byte ptr [r8 + rcx], dl */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[3] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a6df: mov edx, ebx */
    r[3] = (((r[1] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a6e1: shr edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a6e4: xor dl, byte ptr [rbp - 0x288] */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd78)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a6ea: xor dl, 0x1c */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x1c))) & UINT64_C(0xff)) << 0);
    /* 0x10a6ed: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a6f0: movzx edx, byte ptr [r12 + rdx + 0x5300] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a6f9: xor dl, 0x33 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a6fc: mov rcx, qword ptr [rbp - 0x248] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdb8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a703: mov byte ptr [r8 + rcx], dl */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[3] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a707: xor bl, byte ptr [rbp - 0x198] */
    r[1] = (r[1] & UINT64_C(0xffffffffffffff00)) | ((((((r[1] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe68)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a70d: xor bl, 0x20 */
    r[1] = (r[1] & UINT64_C(0xffffffffffffff00)) | ((((((r[1] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x20))) & UINT64_C(0xff)) << 0);
    /* 0x10a710: movzx edx, bl */
    r[3] = (((r[1] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a713: movzx edx, byte ptr [r12 + rdx + 0x5300] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a71c: xor dl, 0x33 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a71f: mov rcx, qword ptr [rbp - 0x98] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff68)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a726: mov byte ptr [r8 + rcx], dl */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[3] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a72a: mov edx, esi */
    r[3] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a72c: shr edx, 0x18 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a72f: xor dl, byte ptr [rbp - 0x200] */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe00)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a735: xor dl, 5 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x5))) & UINT64_C(0xff)) << 0);
    /* 0x10a738: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a73b: movzx edx, byte ptr [r12 + rdx + 0x5300] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a744: xor dl, 0x33 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a747: mov rcx, qword ptr [rbp - 0xc0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff40)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a74e: mov byte ptr [r8 + rcx], dl */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[3] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a752: mov edx, esi */
    r[3] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a754: shr edx, 0x10 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a757: xor dl, byte ptr [rbp - 0x158] */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffea8)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a75d: xor dl, 0xa */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0xa))) & UINT64_C(0xff)) << 0);
    /* 0x10a760: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a763: movzx edx, byte ptr [r12 + rdx + 0x5300] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a76c: xor dl, 0x33 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a76f: mov rcx, qword ptr [rbp - 0x78] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff88)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a773: mov byte ptr [r8 + rcx], dl */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[3] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a777: mov edx, esi */
    r[3] = (((r[4] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a779: shr edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a77c: xor dl, byte ptr [rbp - 0x178] */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe88)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a782: xor dl, 0x32 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x32))) & UINT64_C(0xff)) << 0);
    /* 0x10a785: movzx edx, dl */
    r[3] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a788: movzx edx, byte ptr [r12 + rdx + 0x5300] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a791: xor dl, 0x33 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a794: mov rcx, qword ptr [rbp - 0x68] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff98)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a798: mov byte ptr [r8 + rcx], dl */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[3] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a79c: xor sil, byte ptr [rbp - 0x120] */
    r[4] = (r[4] & UINT64_C(0xffffffffffffff00)) | ((((((r[4] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffee0)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a7a3: xor sil, 0x37 */
    r[4] = (r[4] & UINT64_C(0xffffffffffffff00)) | ((((((r[4] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x37))) & UINT64_C(0xff)) << 0);
    /* 0x10a7a7: movzx edx, sil */
    r[3] = (((r[4] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a7ab: movzx edx, byte ptr [r12 + rdx + 0x5300] */
    r[3] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a7b4: xor dl, 0x33 */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a7b7: mov rcx, qword ptr [rbp - 0xa0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff60)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a7be: mov byte ptr [r8 + rcx], dl */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[3] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a7c2: xor edi, 0x4c */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a7c5: lea edx, [rdi + rdi] */
    r[3] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a7c8: and edx, 0x12 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x12))) & UINT64_C(0xffffffff);
    /* 0x10a7cb: sub edi, edx */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a7cd: xor eax, 0x4c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a7d0: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a7d3: and edx, 0xffffff98 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffff98))) & UINT64_C(0xffffffff);
    /* 0x10a7d6: sub eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a7d8: shl edi, 0x10 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a7db: add edi, 0xeb090000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xeb090000))) & UINT64_C(0xffffffff);
    /* 0x10a7e1: xor edi, 0xeb090000 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xeb090000))) & UINT64_C(0xffffffff);
    /* 0x10a7e7: lea edx, [rdi + rdi] */
    r[3] = ((((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a7ea: and edx, 0x350a0000 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x350a0000))) & UINT64_C(0xffffffff);
    /* 0x10a7f0: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a7f2: add edx, edi */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[5] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a7f4: add edx, 0x1a857072 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x1a857072))) & UINT64_C(0xffffffff);
    /* 0x10a7fa: shl eax, 8 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a7fd: add eax, 0xc955cc00 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xc955cc00))) & UINT64_C(0xffffffff);
    /* 0x10a802: xor eax, 0xc955cc00 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xc955cc00))) & UINT64_C(0xffffffff);
    /* 0x10a807: lea esi, [rax + rax] */
    r[4] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a80a: and esi, 0x63739200 */
    r[4] = ((((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x63739200))) & UINT64_C(0xffffffff);
    /* 0x10a810: neg esi */
    r[4] = ((UINT64_C(0) - ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a812: add eax, esi */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[4] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a814: add eax, 0x31b9c99f */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x31b9c99f))) & UINT64_C(0xffffffff);
    /* 0x10a819: xor edx, 0x1a857072 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x1a857072))) & UINT64_C(0xffffffff);
    /* 0x10a81f: xor eax, 0x31b9c99f */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x31b9c99f))) & UINT64_C(0xffffffff);
    /* 0x10a824: or eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a826: lea edx, [rax + rax] */
    r[3] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a829: and edx, 0x6605064 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x6605064))) & UINT64_C(0xffffffff);
    /* 0x10a82f: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a831: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a833: add eax, 0x3302832 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3302832))) & UINT64_C(0xffffffff);
    /* 0x10a838: xor r11d, 0x4c */
    r[11] = ((((r[11] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a83c: mov edx, r11d */
    r[3] = (((r[11] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a83f: and edx, 0x61 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x61))) & UINT64_C(0xffffffff);
    /* 0x10a842: add edx, edx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a844: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a846: add edx, r11d */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[11] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a849: add edx, 0x60645a61 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x60645a61))) & UINT64_C(0xffffffff);
    /* 0x10a84f: lea r11, [rip - 0x1028b6] */
    r[11] = ((1091670 + 0 * 1 + UINT64_C(0xffffffffffefd74a))) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a856: xor eax, 0x3302832 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3302832))) & UINT64_C(0xffffffff);
    /* 0x10a85b: xor edx, 0x60645a61 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x60645a61))) & UINT64_C(0xffffffff);
    /* 0x10a861: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a863: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a866: and eax, 0xfa9c3e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xfa9c3e))) & UINT64_C(0xffffffff);
    /* 0x10a86b: sub edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a86d: shl edx, 8 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a870: add edx, 0x7d4e1f00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x7d4e1f00))) & UINT64_C(0xffffffff);
    /* 0x10a876: xor edx, 0x7d4e1f00 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x7d4e1f00))) & UINT64_C(0xffffffff);
    /* 0x10a87c: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a87f: and eax, 0x7a617a00 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7a617a00))) & UINT64_C(0xffffffff);
    /* 0x10a884: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a886: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a888: add eax, 0x3d30bd8e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x3d30bd8e))) & UINT64_C(0xffffffff);
    /* 0x10a88d: mov rcx, qword ptr [rbp - 0x1f0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe10)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a894: xor ecx, 0x4c */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a897: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a89a: and edx, 4 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x4))) & UINT64_C(0xffffffff);
    /* 0x10a89d: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a89f: add edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a8a1: add edx, 0x8dff402 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x8dff402))) & UINT64_C(0xffffffff);
    /* 0x10a8a7: xor eax, 0x3d30bd8e */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x3d30bd8e))) & UINT64_C(0xffffffff);
    /* 0x10a8ac: xor edx, 0x8dff402 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x8dff402))) & UINT64_C(0xffffffff);
    /* 0x10a8b2: or edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a8b4: lea eax, [rdx + rdx] */
    r[0] = ((((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a8b7: and eax, 0x403ef20c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x403ef20c))) & UINT64_C(0xffffffff);
    /* 0x10a8bc: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a8be: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a8c0: add eax, 0x201f7906 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x201f7906))) & UINT64_C(0xffffffff);
    /* 0x10a8c5: xor r9d, eax */
    r[9] = ((((r[9] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a8c8: mov eax, r9d */
    r[0] = (((r[9] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a8cb: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a8ce: xor al, byte ptr [rbp - 0x160] */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffea0)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a8d4: xor al, 0x51 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x51))) & UINT64_C(0xff)) << 0);
    /* 0x10a8d6: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a8d9: movzx eax, byte ptr [r12 + rax + 0x5300] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a8e2: xor al, 0x33 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a8e4: mov rcx, qword ptr [rbp - 0x70] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a8e8: mov byte ptr [r8 + rcx], al */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a8ec: mov eax, r9d */
    r[0] = (((r[9] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a8ef: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a8f2: xor al, byte ptr [rbp - 0x170] */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe90)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a8f8: xor al, 0x67 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x67))) & UINT64_C(0xff)) << 0);
    /* 0x10a8fa: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a8fd: movzx eax, byte ptr [r12 + rax + 0x5300] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a906: xor al, 0x33 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a908: mov rcx, qword ptr [rbp - 0x60] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffa0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a90c: mov byte ptr [r8 + rcx], al */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a910: mov eax, r9d */
    r[0] = (((r[9] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a913: shr eax, 8 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a916: xor al, byte ptr [rbp - 0x148] */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffeb8)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a91c: xor al, 0x1a */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x1a))) & UINT64_C(0xff)) << 0);
    /* 0x10a91e: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a921: movzx eax, byte ptr [r12 + rax + 0x5300] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a92a: xor al, 0x33 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a92c: mov rcx, qword ptr [rbp - 0x50] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffb0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a930: mov byte ptr [r8 + rcx], al */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a934: xor r9b, byte ptr [rbp - 0x1e8] */
    r[9] = (r[9] & UINT64_C(0xffffffffffffff00)) | ((((((r[9] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe18)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10a93b: xor r9b, 0xbe */
    r[9] = (r[9] & UINT64_C(0xffffffffffffff00)) | ((((((r[9] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0xbe))) & UINT64_C(0xff)) << 0);
    /* 0x10a93f: movzx eax, r9b */
    r[0] = (((r[9] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10a943: movzx eax, byte ptr [r12 + rax + 0x5300] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a94c: xor al, 0x33 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10a94e: mov rcx, qword ptr [rbp - 0x58] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffa8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a952: mov byte ptr [r8 + rcx], al */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10a956: xor r15d, 0x4c */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a95a: mov eax, r15d */
    r[0] = (((r[15] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a95d: and eax, 0x70 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x70))) & UINT64_C(0xffffffff);
    /* 0x10a960: add eax, eax */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a962: sub r15d, eax */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a965: xor r14d, 0x4c */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a969: lea eax, [r14 + r14] */
    r[0] = ((((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a96d: and eax, 0x142 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x142))) & UINT64_C(0xffffffff);
    /* 0x10a972: sub r14d, eax */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a975: shl r15d, 0x10 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a979: add r15d, 0xd5700000 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xd5700000))) & UINT64_C(0xffffffff);
    /* 0x10a980: xor r15d, 0xd5700000 */
    r[15] = ((((r[15] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xd5700000))) & UINT64_C(0xffffffff);
    /* 0x10a987: lea eax, [r15 + r15] */
    r[0] = ((((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[15] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a98b: and eax, 0xd8fe0000 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xd8fe0000))) & UINT64_C(0xffffffff);
    /* 0x10a990: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a992: add eax, r15d */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[15] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a995: add eax, 0x6c7f0f7a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6c7f0f7a))) & UINT64_C(0xffffffff);
    /* 0x10a99a: shl r14d, 8 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10a99e: add r14d, 0xf853a100 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xf853a100))) & UINT64_C(0xffffffff);
    /* 0x10a9a5: xor r14d, 0xf853a100 */
    r[14] = ((((r[14] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xf853a100))) & UINT64_C(0xffffffff);
    /* 0x10a9ac: lea ecx, [r14 + r14] */
    r[2] = ((((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[14] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a9b0: and ecx, 0xcca23c00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xcca23c00))) & UINT64_C(0xffffffff);
    /* 0x10a9b6: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a9b8: add ecx, r14d */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[14] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a9bb: add ecx, 0x66511ea1 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x66511ea1))) & UINT64_C(0xffffffff);
    /* 0x10a9c1: mov rsi, qword ptr [rbp - 0x370] */
    r[4] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffc90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a9c8: xor eax, 0x6c7f0f7a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c7f0f7a))) & UINT64_C(0xffffffff);
    /* 0x10a9cd: xor ecx, 0x66511ea1 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x66511ea1))) & UINT64_C(0xffffffff);
    /* 0x10a9d3: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a9d5: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10a9d8: and eax, 0xe3c9c238 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe3c9c238))) & UINT64_C(0xffffffff);
    /* 0x10a9dd: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a9df: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a9e1: add eax, 0x71e4e11c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x71e4e11c))) & UINT64_C(0xffffffff);
    /* 0x10a9e6: mov rdx, qword ptr [rbp - 0x270] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd90)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10a9ed: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10a9f0: mov ecx, edx */
    r[2] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10a9f2: and ecx, 0x41 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x41))) & UINT64_C(0xffffffff);
    /* 0x10a9f5: add ecx, ecx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a9f7: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a9f9: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10a9fb: add ecx, 0x8315b41 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x8315b41))) & UINT64_C(0xffffffff);
    /* 0x10aa01: xor ecx, 0x8315b41 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x8315b41))) & UINT64_C(0xffffffff);
    /* 0x10aa07: xor eax, 0x71e4e11c */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x71e4e11c))) & UINT64_C(0xffffffff);
    /* 0x10aa0c: or ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) | ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa0e: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aa11: and eax, 0x7e14fc */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x7e14fc))) & UINT64_C(0xffffffff);
    /* 0x10aa16: sub ecx, eax */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa18: mov rdx, qword ptr [rbp - 0xc8] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff38)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10aa1f: xor edx, 0x4c */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x4c))) & UINT64_C(0xffffffff);
    /* 0x10aa22: mov eax, edx */
    r[0] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10aa24: and eax, 0x4a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0x4a))) & UINT64_C(0xffffffff);
    /* 0x10aa27: add eax, eax */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa29: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa2b: add eax, edx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa2d: add eax, 0x6c524c4a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6c524c4a))) & UINT64_C(0xffffffff);
    /* 0x10aa32: shl ecx, 8 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) << (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10aa35: add ecx, 0xbf0a7e00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0xbf0a7e00))) & UINT64_C(0xffffffff);
    /* 0x10aa3b: xor ecx, 0xbf0a7e00 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0xbf0a7e00))) & UINT64_C(0xffffffff);
    /* 0x10aa41: lea edx, [rcx + rcx] */
    r[3] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aa44: and edx, 0xc86fb400 */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xc86fb400))) & UINT64_C(0xffffffff);
    /* 0x10aa4a: neg edx */
    r[3] = ((UINT64_C(0) - ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa4c: add ecx, edx */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa4e: add ecx, 0x6437da81 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6437da81))) & UINT64_C(0xffffffff);
    /* 0x10aa54: xor ecx, 0x6437da81 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6437da81))) & UINT64_C(0xffffffff);
    /* 0x10aa5a: xor eax, 0x6c524c4a */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c524c4a))) & UINT64_C(0xffffffff);
    /* 0x10aa5f: or eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) | ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa61: lea ecx, [rax + rax] */
    r[2] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aa64: and ecx, 0xe1c9ffe4 */
    r[2] = ((((r[2] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xe1c9ffe4))) & UINT64_C(0xffffffff);
    /* 0x10aa6a: neg ecx */
    r[2] = ((UINT64_C(0) - ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa6c: add eax, ecx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa6e: add eax, 0x70e4fff2 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x70e4fff2))) & UINT64_C(0xffffffff);
    /* 0x10aa73: mov edx, dword ptr [rbp - 0xa8] */
    r[3] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff58)), 4)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aa79: xor edx, eax */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10aa7b: mov eax, edx */
    r[0] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10aa7d: shr eax, 0x18 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x18) & 31))) & UINT64_C(0xffffffff);
    /* 0x10aa80: xor al, byte ptr [rbp - 0x150] */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffeb0)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10aa86: xor al, 1 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x1))) & UINT64_C(0xff)) << 0);
    /* 0x10aa88: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10aa8b: movzx eax, byte ptr [r12 + rax + 0x5300] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aa94: xor al, 0x33 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10aa96: mov rcx, qword ptr [rbp - 0x1a8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe58)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10aa9d: mov byte ptr [r8 + rcx], al */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10aaa1: mov eax, edx */
    r[0] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10aaa3: shr eax, 0x10 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x10) & 31))) & UINT64_C(0xffffffff);
    /* 0x10aaa6: xor al, byte ptr [rbp - 0x130] */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffed0)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10aaac: xor al, 0x9c */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x9c))) & UINT64_C(0xff)) << 0);
    /* 0x10aaae: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10aab1: movzx eax, byte ptr [r12 + rax + 0x5300] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aaba: xor al, 0x33 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10aabc: mov rcx, qword ptr [rbp - 0x280] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd80)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10aac3: mov byte ptr [r8 + rcx], al */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10aac7: mov eax, edx */
    r[0] = (((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10aac9: shr eax, 8 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) >> (UINT64_C(0x8) & 31))) & UINT64_C(0xffffffff);
    /* 0x10aacc: xor al, byte ptr [rbp - 0xf0] */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff10)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10aad2: xor al, 0x9c */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x9c))) & UINT64_C(0xff)) << 0);
    /* 0x10aad4: movzx eax, al */
    r[0] = (((r[0] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10aad7: movzx eax, byte ptr [r12 + rax + 0x5300] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aae0: xor al, 0x33 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10aae2: mov rcx, qword ptr [rbp - 0x48] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffb8)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10aae6: mov byte ptr [r8 + rcx], al */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10aaea: xor dl, byte ptr [rbp - 0x180] */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe80)), 1))) & UINT64_C(0xff)) << 0);
    if (m->error) return m->error;
    /* 0x10aaf0: xor dl, 0x4a */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | ((((((r[3] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x4a))) & UINT64_C(0xff)) << 0);
    /* 0x10aaf3: movzx eax, dl */
    r[0] = (((r[3] >> 0) & UINT64_C(0xff))) & UINT64_C(0xffffffff);
    /* 0x10aaf6: movzx eax, byte ptr [r12 + rax + 0x5300] */
    r[0] = (load(m, (((r[12] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x5300)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aaff: xor al, 0x33 */
    r[0] = (r[0] & UINT64_C(0xffffffffffffff00)) | ((((((r[0] >> 0) & UINT64_C(0xff)) ^ UINT64_C(0x33))) & UINT64_C(0xff)) << 0);
    /* 0x10ab01: mov rcx, qword ptr [rbp - 0x40] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffffc0)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10ab05: mov byte ptr [r8 + rcx], al */
    save(m, (((r[8] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0)), 1, ((r[0] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10ab09: mov rcx, qword ptr [rbp - 0xd0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff30)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10ab10: lea eax, [rcx + rcx] */
    r[0] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab13: add eax, 0x20 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x20))) & UINT64_C(0xffffffff);
    /* 0x10ab16: and eax, 0xd89e7ec */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xd89e7ec))) & UINT64_C(0xffffffff);
    /* 0x10ab1b: neg eax */
    r[0] = ((UINT64_C(0) - ((r[0] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10ab1d: lea edi, [rcx + rax] */
    r[5] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 1 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab20: add edi, 0x6c4f406 */
    r[5] = ((((r[5] >> 0) & UINT64_C(0xffffffff)) + UINT64_C(0x6c4f406))) & UINT64_C(0xffffffff);
    /* 0x10ab26: mov eax, edi */
    r[0] = (((r[5] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffff);
    /* 0x10ab28: xor eax, 0x6c4f3f6 */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffff)) ^ UINT64_C(0x6c4f3f6))) & UINT64_C(0xffffffff);
    /* 0x10ab2d: mov rcx, qword ptr [rbp - 0x2c0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd40)), 8)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10ab34: xor edx, edx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) ^ ((r[3] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10ab36: cmp eax, esi */
    eq = (((r[0] >> 0) & UINT64_C(0xffffffff)) == (((r[4] >> 0) & UINT64_C(0xffffffff)) & UINT64_C(0xffffffff)));
    /* 0x10ab38: sete dl */
    r[3] = (r[3] & UINT64_C(0xffffffffffffff00)) | (((eq) & UINT64_C(0xff)) << 0);
    /* 0x10ab3b: lea r13d, [rcx + rdx*4] */
    r[13] = ((((r[2] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[3] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x0))) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab3f: add edx, ecx */
    r[3] = ((((r[3] >> 0) & UINT64_C(0xffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffff)))) & UINT64_C(0xffffffff);
    /* 0x10ab41: movsxd rax, edx */
    r[0] = ((uint64_t)(int64_t)(int32_t)((r[3] >> 0) & UINT64_C(0xffffffff))) & UINT64_C(0xffffffffffffffff);
    /* 0x10ab44: movsxd rax, dword ptr [r11 + rax*4] */
    r[0] = ((uint64_t)(int64_t)(int32_t)load(m, (((r[11] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) * 4 + UINT64_C(0x0)), 4)) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10ab48: lea rcx, [rip - 0x3adf] */
    r[2] = ((1092431 + 0 * 1 + UINT64_C(0xffffffffffffc521))) & UINT64_C(0xffffffffffffffff);
    if (m->error) return m->error;
    /* 0x10ab4f: add rax, rcx */
    r[0] = ((((r[0] >> 0) & UINT64_C(0xffffffffffffffff)) + ((r[2] >> 0) & UINT64_C(0xffffffffffffffff)))) & UINT64_C(0xffffffffffffffff);
    /* 0x10ab52: movzx ecx, byte ptr [rbp - 0xd8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff28)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab59: mov byte ptr [rbp - 0x198], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe68)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10ab5f: movzx ebx, byte ptr [rbp - 0x108] */
    r[1] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffef8)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab66: movzx ecx, byte ptr [rbp - 0xf8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff08)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab6d: mov byte ptr [rbp - 0x120], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffee0)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10ab73: movzx ecx, byte ptr [rbp - 0x128] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffed8)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab7a: mov byte ptr [rbp - 0x170], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe90)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10ab80: movzx ecx, byte ptr [rbp - 0x100] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff00)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab87: mov byte ptr [rbp - 0x160], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffea0)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10ab8d: movzx ecx, byte ptr [rbp - 0xe8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff18)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ab94: mov byte ptr [rbp - 0x200], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe00)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10ab9a: movzx ecx, byte ptr [rbp - 0x300] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd00)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10aba1: mov byte ptr [rbp - 0x158], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffea8)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10aba7: movzx ecx, byte ptr [rbp - 0x550] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffab0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10abae: mov byte ptr [rbp - 0x1f0], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe10)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10abb4: movzx r9d, byte ptr [rbp - 0x278] */
    r[9] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd88)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10abbc: movzx ecx, byte ptr [rbp - 0xb8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff48)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10abc3: mov byte ptr [rbp - 0x148], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffeb8)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10abc9: movzx ecx, byte ptr [rbp - 0x1a0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe60)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10abd0: mov byte ptr [rbp - 0x190], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe70)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10abd6: movzx ecx, byte ptr [rbp - 0xe0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff20)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10abdd: mov byte ptr [rbp - 0x178], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe88)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10abe3: movzx ecx, byte ptr [rbp - 0x240] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdc0)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10abea: mov byte ptr [rbp - 0x180], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe80)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10abf0: movzx ecx, byte ptr [rbp - 0x2a0] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffd60)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10abf7: mov byte ptr [rbp - 0x130], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffed0)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10abfd: movzx ecx, byte ptr [rbp - 0x228] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffdd8)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ac04: mov byte ptr [rbp - 0xf0], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xffffffffffffff10)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    /* 0x10ac0a: movzx ecx, byte ptr [rbp - 0x1f8] */
    r[2] = (load(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffe08)), 1)) & UINT64_C(0xffffffff);
    if (m->error) return m->error;
    /* 0x10ac11: mov byte ptr [rbp - 0x150], cl */
    save(m, (((r[6] >> 0) & UINT64_C(0xffffffffffffffff)) + 0 * 1 + UINT64_C(0xfffffffffffffeb0)), 1, ((r[2] >> 0) & UINT64_C(0xff)));
    if (m->error) return m->error;
    (void)b; return m->error;
}
