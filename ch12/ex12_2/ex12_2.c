/* ex12_2.c — DMG memory bus
 * Compile: gcc -std=c11 -Wall -Wextra -Werror -o ex12_2 ex12_2.c && ./ex12_2
 *
 * Implement a flat memory bus for the Game Boy's 16-bit address space.
 *
 * DMG memory map:
 *   0x0000–0x7FFF   ROM (32 KB, read-only)
 *   0x8000–0x9FFF   VRAM (8 KB)
 *   0xA000–0xBFFF   External RAM (unmapped — return 0xFF on read)
 *   0xC000–0xDFFF   WRAM (8 KB)
 *   0xFF00–0xFF7F   I/O registers (128 bytes)
 *   0xFF80–0xFFFE   HRAM (127 bytes)
 *   0xFFFF          IE register (1 byte)
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

/* TODO: declare static storage for each mapped region:
 *   uint8_t rom[0x8000]  — 32 KB
 *   uint8_t vram[0x2000] —  8 KB
 *   uint8_t wram[0x2000] —  8 KB
 *   uint8_t io[0x80]     — 128 B
 *   uint8_t hram[0x7F]   — 127 B
 *   uint8_t ie_reg       —   1 B
 */

/* TODO: implement bus_read(uint16_t addr) -> uint8_t
 *   Dispatch by address range; return 0xFF for unmapped addresses.
 */

/* TODO: implement bus_write(uint16_t addr, uint8_t val)
 *   Dispatch by address range.
 *   Writes to ROM (0x0000–0x7FFF) must be silently ignored.
 */

int main(void) {
    /* TODO: add a test harness that:
     *   1. Primes rom[] with a known pattern (e.g. i & 0xFF).
     *   2. Writes to WRAM start and end, reads back and asserts.
     *   3. Writes to HRAM start and end, reads back and asserts.
     *   4. Writes to the IE register (0xFFFF), reads back and asserts.
     *   5. Attempts to write to ROM (0x0100), reads back and asserts the
     *      value is unchanged (write was silently ignored).
     *   6. Reads from an unmapped address (e.g. 0xA000) and asserts 0xFF.
     */
    printf("TODO: implement the test harness\n");
    return 0;
}
