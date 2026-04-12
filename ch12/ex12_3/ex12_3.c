/* ex12_3.c — SM83 opcode dispatch table
 * Compile: gcc -std=c11 -Wall -Wextra -Werror -o ex12_3 ex12_3.c && ./ex12_3
 *
 * Implement a 256-entry function pointer dispatch table for a subset of
 * the SM83 instruction set.  This is the idiomatic C pattern used by
 * virtually every production emulator.
 *
 * Handler signature: void handler(CPU *cpu, uint8_t opcode)
 * The opcode byte is passed to the handler so a single function can service
 * a whole family of related opcodes (e.g. all LD r,r variants).
 *
 * Implement these opcode families:
 *
 *   NOP    (0x00)
 *   HALT   (0x76)
 *   LD r,n (0x06 0x0E 0x16 0x1E 0x26 0x2E 0x3E) — load immediate byte
 *   LD r,r (0x40–0x7F excl. (HL) and HALT)       — register-to-register copy
 *   INC r  (0x04 0x0C 0x14 0x1C 0x24 0x2C 0x3C)  — increment; sets Z N H
 *   DEC r  (0x05 0x0D 0x15 0x1D 0x25 0x2D 0x3D)  — decrement; sets Z N H
 *   ADD A,r (0x80–0x87 excl. (HL))                — add to accumulator
 *   XOR A,r (0xA8–0xAF excl. (HL))                — XOR accumulator
 *   JP nn  (0xC3)                                  — absolute jump
 *   JR e   (0x18)                                  — signed relative jump
 *
 * Register index encoding (bits 0–2 or 3–5 of opcode):
 *   0=B  1=C  2=D  3=E  4=H  5=L  6=(HL) [skip in this subset]  7=A
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

/* ── CPU state ─────────────────────────────────────────────────────────── */
typedef struct {
    uint8_t  a, b, c, d, e, h, l, f;
    uint16_t pc, sp;
    uint8_t  mem[0x10000];
    int      halted;
} CPU;

/* Flag bit positions */
#define FLAG_Z 7
#define FLAG_N 6
#define FLAG_H 5
#define FLAG_C 4

/* TODO: implement cpu_flag(cpu, bit) and cpu_set_flag(cpu, bit, val) */

/* TODO: implement reg_ptr(cpu, idx) returning uint8_t* to the register
 *       indexed by idx (0=B 1=C 2=D 3=E 4=H 5=L 7=A; return NULL for 6).
 */

/* TODO: implement fetch8(cpu) and fetch16(cpu) */

/* TODO: define: typedef void (*OpFn)(CPU *, uint8_t); */

/* TODO: implement the handlers h_nop, h_halt, h_ld_rn, h_ld_rr,
 *       h_inc_r, h_dec_r, h_add_a_r, h_xor_a_r, h_jp, h_jr.
 *
 *       A catch-all h_illegal handler should print to stderr but not crash.
 */

/* TODO: declare static OpFn table[256]; */

/* TODO: implement init_table() that fills table[] with h_illegal then wires
 *       up each implemented family.
 */

static void cpu_step(CPU *c) {
    /* TODO: fetch opcode, dispatch through table */
    (void)c;
}

static void cpu_run(CPU *c, int max_steps) {
    for (int i = 0; i < max_steps && !c->halted; i++)
        cpu_step(c);
}

int main(void) {
    /* TODO: call init_table(), then run these test programs:
     *
     *   1. LD B,5; LD C,3; LD A,C; ADD A,B; HALT  -> A == 8
     *   2. LD A,0xFF; INC A; HALT                  -> A == 0, Z == 1
     *   3. LD A,0x42; XOR A,A; HALT                -> A == 0, Z == 1, N == H == C == 0
     *   4. JP 0x0010; ... LD A,0x55; HALT          -> A == 0x55
     *   5. JR +2; (skip LD A,0xDE); LD A,0xBE; HALT -> A == 0xBE
     */
    printf("TODO: implement tests\n");
    return 0;
}
