/* ex12_4.c — DMG ROM loader and header parser
 * Compile: gcc -std=c11 -Wall -Wextra -Werror -o ex12_4 ex12_4.c && ./ex12_4 test_rom.gb
 *
 * A test_rom.gb file is provided in this directory — a minimal synthetic ROM
 * (336 bytes) that passes both the logo check and the header checksum.
 * Students do not need a real Game Boy ROM to complete this exercise.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* ── Cartridge header offsets ───────────────────────────────────────────── */
#define HDR_LOGO     0x0104
#define HDR_TITLE    0x0134
#define HDR_TYPE     0x0147
#define HDR_ROM_SIZE 0x0148
#define HDR_CHECKSUM 0x014D
#define HDR_MIN_SIZE 0x014E

/*
 * Nintendo logo — must match bytes at 0x0104–0x0133 in every valid ROM.
 * The original boot ROM compared this pattern byte-for-byte.
 */
static const uint8_t NINTENDO_LOGO[48] = {
    0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B,
    0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
    0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
    0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
    0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC,
    0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
};

/* TODO: implement compute_header_checksum(const uint8_t *rom)
 *
 *   The checksum is computed over bytes 0x0134–0x014C:
 *
 *     x = 0
 *     for each byte b in rom[0x0134..0x014C]:
 *         x = x - b - 1
 *     return x & 0xFF
 *
 *   The result must equal rom[0x014D].
 */

/* TODO: implement rom_load(const char *path, long *out_size)
 *
 *   1. Open the file in binary mode.
 *   2. Determine its size; reject if < HDR_MIN_SIZE.
 *   3. Allocate a heap buffer and read the entire file into it.
 *   4. Call memcmp to verify the 48 logo bytes at 0x0104.
 *   5. Call compute_header_checksum and compare to rom[HDR_CHECKSUM].
 *   6. On success: set *out_size and return the buffer (caller must free).
 *      On failure: free the buffer, print to stderr, return NULL.
 */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <rom.gb>\n", argv[0]);
        return 1;
    }

    /* TODO: call rom_load(), print the header fields, then free the buffer.
     *
     *   Print:
     *     ROM: <filename>  (<size> bytes)
     *       Title:    "<title>"
     *       Type:     0xNN  <name>
     *       ROM size: 0xNN  <description>
     *       Checksum: 0xNN  (valid)
     *
     *   Use test_rom.gb (provided) to verify — expected output:
     *     Title:    "TEST"
     *     Type:     0x00  ROM ONLY
     *     ROM size: 0x00  32 KB (no banking)
     *     Checksum: 0xA7  (valid)
     */
    printf("TODO: implement rom_load and print header fields\n");
    return 0;
}
