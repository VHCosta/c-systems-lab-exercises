# ex12_2 — DMG Memory Bus

**Chapter 12 · Difficulty: Design**

## Task

Implement the Game Boy's 16-bit memory bus as a C dispatch function.

## Requirements

Implement two functions:

```c
uint8_t bus_read(uint16_t addr);
void    bus_write(uint16_t addr, uint8_t val);
```

Back them with static arrays for each mapped region:

| Region | Address range | Size |
|--------|--------------|------|
| ROM stub | 0x0000–0x7FFF | 32 KB |
| VRAM | 0x8000–0x9FFF | 8 KB |
| WRAM | 0xC000–0xDFFF | 8 KB |
| I/O registers | 0xFF00–0xFF7F | 128 B |
| HRAM | 0xFF80–0xFFFE | 127 B |
| IE register | 0xFFFF | 1 B |

Rules:
- Unmapped addresses (external RAM 0xA000–0xBFFF, echo RAM, unusable region)
  must return `0xFF` on read and silently ignore writes.
- ROM is **read-only**: `bus_write` to 0x0000–0x7FFF must do nothing.

Write a test harness that:
1. Primes `rom[]` with `i & 0xFF` and verifies readback.
2. Writes to WRAM at 0xC000 and 0xDFFF; reads back and asserts.
3. Writes to HRAM at 0xFF80 and 0xFFFE; reads back and asserts.
4. Writes `0x1F` to IE (0xFFFF); reads back and asserts.
5. Attempts a ROM write and verifies the value is unchanged.
6. Reads 0xA000 and asserts `0xFF`.

## Compile

```
gcc -std=c11 -Wall -Wextra -Werror -o ex12_2 ex12_2.c && ./ex12_2
```

## Reference

- Pan Docs — Memory map: `https://gbdev.io/pandocs/Memory_Map.html`
