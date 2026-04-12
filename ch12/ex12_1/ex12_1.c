/* ex12_1.c — SM83 register file
 * Compile: gcc -std=c11 -Wall -Wextra -Werror -o ex12_1 ex12_1.c && ./ex12_1
 *
 * Implement the Sharp SM83 register file — the CPU at the heart of the
 * original Game Boy (DMG).  The SM83 has eight 8-bit general-purpose
 * registers (A, B, C, D, E, H, L, F), a 16-bit program counter (PC),
 * and a 16-bit stack pointer (SP).
 *
 * The F register is special: only the upper nibble is used.
 *   Bit 7 — Z (Zero)
 *   Bit 6 — N (Subtract)
 *   Bit 5 — H (Half-carry)
 *   Bit 4 — C (Carry)
 *   Bits 3-0 — always 0
 */
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

/* TODO: define SM83Regs as a struct with fields:
 *   uint8_t a, b, c, d, e, h, l, f;
 *   uint16_t pc, sp;
 */

/* TODO: implement the four flag-bit constants:
 *   FLAG_Z, FLAG_N, FLAG_H, FLAG_C (bit positions 7, 6, 5, 4)
 */

/* TODO: implement getter functions (return 0 or 1):
 *   int regs_flag_z(const SM83Regs *r);
 *   int regs_flag_n(const SM83Regs *r);
 *   int regs_flag_h(const SM83Regs *r);
 *   int regs_flag_c(const SM83Regs *r);
 */

/* TODO: implement setter functions (val is 0 or 1):
 *   void regs_set_z(SM83Regs *r, int val);
 *   void regs_set_n(SM83Regs *r, int val);
 *   void regs_set_h(SM83Regs *r, int val);
 *   void regs_set_c(SM83Regs *r, int val);
 *
 * Invariant: the low nibble of F must always remain 0.
 */

int main(void) {
    /* TODO: add a test harness that:
     *   1. Sets and clears each flag independently, asserting the getter matches.
     *   2. Iterates all 16 flag combinations (Z/N/H/C each 0 or 1) and verifies
     *      that after setting each combination the four getters return the correct
     *      values and (r.f & 0x0F) == 0.
     *   3. Sets all 8-bit registers to known values and reads them back.
     *   4. Sets PC = 0x0150 and SP = 0xFFFE and reads them back.
     */
    printf("TODO: implement the test harness\n");
    return 0;
}
