/* ex2_3.c — Fixed-width struct with _Static_assert
 * Compile: gcc -std=c11 -Wall -Wextra -Werror -O1 -o ex2_3 ex2_3.c
 */
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

/* TODO: define struct packet_header with fixed-width fields ordered to
 * avoid padding. Required fields and their types:
 *   timestamp   uint64_t   Unix timestamp
 *   payload_len uint32_t   payload byte count
 *   checksum    uint16_t   CRC16
 *   version     uint8_t    protocol version
 *   flags       uint8_t    flag bits
 * Total size must be exactly 16 bytes. */

/* TODO: add _Static_assert checks for field widths, offsets, and total size */

int main(void) {
    /* TODO: populate a struct packet_header and print each field */
    return 0;
}
