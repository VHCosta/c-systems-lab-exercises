# ex12_3 — SM83 Opcode Dispatch Table

**Chapter 12 · Difficulty: Design + Debug**

## Task

Implement a 256-entry function pointer dispatch table for a subset of the
SM83 instruction set.  This is the core architectural pattern of every
production emulator written in C.

## Background

The SM83 opcode space is 8 bits wide (256 possible opcodes).  The idiomatic
C approach: a `table[256]` of function pointers, one per opcode, indexed
directly by the opcode byte.  This is O(1) dispatch with no branches.

Handler signature: `void handler(CPU *cpu, uint8_t opcode)`

Passing the raw opcode byte allows a single function to handle a family of
related opcodes (e.g. all `LD r,r` variants encode source and destination in
the opcode's bit fields).

## Register index encoding (Pan Docs convention)

Bits 0–2 or 3–5 of the opcode encode a register index:
`0=B  1=C  2=D  3=E  4=H  5=L  6=(HL)  7=A`

Index 6 means a memory reference through HL — skip these in this exercise.

## Opcode families to implement

| Family | Opcodes |
|--------|---------|
| `NOP` | 0x00 |
| `HALT` | 0x76 |
| `LD r, n` | 0x06 0x0E 0x16 0x1E 0x26 0x2E 0x3E |
| `LD r, r` | 0x40–0x7F (excl. (HL) variants and HALT) |
| `INC r` | 0x04 0x0C 0x14 0x1C 0x24 0x2C 0x3C |
| `DEC r` | 0x05 0x0D 0x15 0x1D 0x25 0x2D 0x3D |
| `ADD A, r` | 0x80–0x87 (excl. 0x86) |
| `XOR A, r` | 0xA8–0xAF (excl. 0xAE) |
| `JP nn` | 0xC3 |
| `JR e` | 0x18 |

Flag rules:
- `INC r`: Z=result==0, N=0, H=carry from bit 3; C unaffected.
- `DEC r`: Z=result==0, N=1, H=borrow from bit 4; C unaffected.
- `ADD A,r`: all four flags updated.
- `XOR A,r`: Z=result==0, N=H=C=0.

## Write a test harness

Run at least five bytecode sequences and assert register/flag state after HALT:
1. `LD B,5; LD C,3; LD A,C; ADD A,B; HALT` → A = 8
2. `LD A,0xFF; INC A; HALT` → A = 0, Z = 1
3. `LD A,0x42; XOR A,A; HALT` → A = 0, Z = 1
4. `JP 0x0010; ... LD A,0x55; HALT` → A = 0x55
5. `JR +2; (skip LD A,0xDE); LD A,0xBE; HALT` → A = 0xBE

## Compile

```
gcc -std=c11 -Wall -Wextra -Werror -o ex12_3 ex12_3.c && ./ex12_3
```

## Reference

- Pan Docs — Opcode table: `https://gbdev.io/pandocs/CPU_Instruction_Set.html`
- RGBDS opcode reference: `https://rgbds.gbdev.io/docs/v0.7.0/gbz80.7`
