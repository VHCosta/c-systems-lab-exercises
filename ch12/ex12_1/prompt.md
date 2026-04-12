# ex12_1 — SM83 Register File

**Chapter 12 · Difficulty: Drill**

## Task

Implement the Sharp SM83 register file — the CPU at the heart of the original
Game Boy (DMG, 1989).

## Requirements

1. Define `SM83Regs` as a struct with eight 8-bit registers (`a b c d e h l f`)
   and two 16-bit registers (`pc sp`).
2. The `F` register uses only the upper nibble:
   - Bit 7 — **Z** (Zero): set when the result of an operation is zero.
   - Bit 6 — **N** (Subtract): set after subtraction operations.
   - Bit 5 — **H** (Half-carry): set when there's a carry from bit 3 to bit 4.
   - Bit 4 — **C** (Carry): set when there's a carry out of bit 7.
   - Bits 3–0 — always 0 (SM83 hardware invariant).
3. Implement getter functions `regs_flag_z`, `regs_flag_n`, `regs_flag_h`,
   `regs_flag_c` that each return 0 or 1.
4. Implement setter functions `regs_set_z`, `regs_set_n`, `regs_set_h`,
   `regs_set_c` that accept 0 or 1 without disturbing other flags.
5. Write a test harness that:
   - Sets and clears each flag independently and verifies via getters.
   - Iterates all 16 flag combinations (Z/N/H/C each 0 or 1) and asserts each
     getter matches, and that `(r.f & 0x0F) == 0` throughout.
   - Verifies the 8-bit and 16-bit register fields can be read and written.

## Compile

```
gcc -std=c11 -Wall -Wextra -Werror -o ex12_1 ex12_1.c && ./ex12_1
```

## Reference

- Pan Docs — CPU registers: `https://gbdev.io/pandocs/CPU_Registers_and_Flags.html`
