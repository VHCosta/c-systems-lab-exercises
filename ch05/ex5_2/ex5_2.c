/* ex5_2.c — Pack a protocol header (IPv4, 20 bytes)
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex5_2 ex5_2.c && ./ex5_2
 */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

typedef struct __attribute__((packed)) {
    uint8_t  version_ihl;
    uint8_t  tos;
    uint16_t total_length;
    uint16_t id;
    uint16_t flags_frag_offset;
    uint8_t  ttl;
    uint8_t  protocol;
    uint16_t checksum;
    uint32_t src_addr;
    uint32_t dst_addr;
} IPv4Header;

_Static_assert(sizeof(IPv4Header) == 20, "IPv4 header must be exactly 20 bytes");

/* Serialize to a byte buffer.
 * Use memcpy — do NOT cast uint8_t * to IPv4Header * and dereference;
 * that is strict-aliasing UB. */
void serialize_ipv4(const IPv4Header *hdr, uint8_t *out) {
    /* TODO: implement */
}

void deserialize_ipv4(const uint8_t *in, IPv4Header *hdr) {
    /* TODO: implement */
}

int main(void) {
    IPv4Header original = {
        .version_ihl       = 0x45,   /* version=4, IHL=5 (20-byte header) */
        .tos               = 0x00,
        .total_length      = 0x0028, /* 40 bytes total (20 header + 20 data) */
        .id                = 0xABCD,
        .flags_frag_offset = 0x4000, /* DF bit set, no fragmentation */
        .ttl               = 64,
        .protocol          = 6,      /* TCP */
        .checksum          = 0x0000, /* would be computed in real code */
        .src_addr          = 0xC0A80101, /* 192.168.1.1 in host byte order */
        .dst_addr          = 0xC0A80102, /* 192.168.1.2 */
    };

    uint8_t wire[20];
    serialize_ipv4(&original, wire);

    /* Print wire bytes for inspection */
    printf("Wire bytes:");
    for (int i = 0; i < 20; i++) printf(" %02X", wire[i]);
    printf("\n");

    /* Round-trip: deserialize and verify */
    IPv4Header recovered;
    deserialize_ipv4(wire, &recovered);

    assert(recovered.version_ihl       == original.version_ihl);
    assert(recovered.tos               == original.tos);
    assert(recovered.total_length      == original.total_length);
    assert(recovered.id                == original.id);
    assert(recovered.flags_frag_offset == original.flags_frag_offset);
    assert(recovered.ttl               == original.ttl);
    assert(recovered.protocol          == original.protocol);
    assert(recovered.checksum          == original.checksum);
    assert(recovered.src_addr          == original.src_addr);
    assert(recovered.dst_addr          == original.dst_addr);

    printf("src=%08X dst=%08X proto=%u ttl=%u\n",
           recovered.src_addr, recovered.dst_addr,
           recovered.protocol, recovered.ttl);
    printf("Round-trip OK — all fields preserved.\n");
    return 0;
}
