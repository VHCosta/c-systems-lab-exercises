/* ex5_4.c — Bit field register model
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex5_4 ex5_4.c && ./ex5_4
 */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/* TODO: define StatusReg as a struct with bit fields:
 *   ready    : 1   (bit 0)
 *   error    : 1   (bit 1)
 *   overflow : 1   (bit 2)
 *   state    : 4   (bits 3-6)
 *   counter  : 16  (bits 7-22)
 *   reserved : 9   (bits 23-31)
 * All fields are unsigned int. */

/* TODO: define mask/shift constants for state and counter */
/* TODO: implement reg_get_state, reg_set_state, reg_get_counter, reg_set_counter */

int main(void) {
    /* TODO: set fields via bit field struct, read raw bits via memcpy,
     * verify via mask/shift functions */

    /* TODO: set fields via mask/shift, read back via bit field struct,
     * verify they agree */

    printf("All assertions passed — both implementations agree on bit layout.\n");
    return 0;
}
