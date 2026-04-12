# ex12_4 — ROM Loader and Header Parser

**Chapter 12 · Difficulty: Integration**

## Task

Implement `rom_load()`: open a `.gb` file, validate it, and parse its header.

## Background

Every Game Boy cartridge begins with a 336-byte header.  The boot ROM on the
original hardware verifies two things before executing cartridge code:

1. **Nintendo logo** (0x0104–0x0133, 48 bytes): must match the canonical bitmap
   exactly.  This was Nintendo's DRM mechanism — the logo is copyrighted, so
   only licensed hardware could pass the check.

2. **Header checksum** (0x014D): computed over bytes 0x0134–0x014C:
   ```
   x = 0
   for each byte b in rom[0x0134 .. 0x014C]:
       x = x - b - 1
   stored checksum must equal x & 0xFF
   ```

## Requirements

Implement:

```c
uint8_t *rom_load(const char *path, long *out_size);
```

Steps:
1. Open the file in binary mode (`"rb"`).
2. Determine size with `fseek`/`ftell`; reject if < `0x014E` bytes.
3. `malloc` a buffer, `fread` the entire file.
4. Compare bytes at `0x0104` against `NINTENDO_LOGO[48]` using `memcmp`.
5. Compute and compare the header checksum; reject if mismatch.
6. On success: set `*out_size` and return the buffer (caller must `free`).
7. On failure: `free` the buffer (if allocated), print to `stderr`, return NULL.

Then in `main`:
- Parse and print: ROM title (0x0134–0x0143, up to 16 bytes), cartridge type
  byte (0x0147), ROM size byte (0x0148), and the validated checksum.

## Provided test ROM

`test_rom.gb` is a 336-byte synthetic ROM that passes both checks.
Expected output:
```
ROM: test_rom.gb  (336 bytes)
  Title:    "TEST"
  Type:     0x00  ROM ONLY
  ROM size: 0x00  32 KB (no banking)
  Checksum: 0xA7  (valid)
```

## Compile

```
gcc -std=c11 -Wall -Wextra -Werror -o ex12_4 ex12_4.c && ./ex12_4 test_rom.gb
```

## Reference

- Pan Docs — Cartridge header: `https://gbdev.io/pandocs/The_Cartridge_Header.html`
