/* ex3_3.c — Pointer arithmetic without array syntax
 * gcc -Wall -Wextra -Werror -std=c11 -O1 -o ex3_3 ex3_3.c && ./ex3_3
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    /* Part 1: void * base, byte arithmetic via unsigned char * */
    void *raw = malloc(64);
    if (!raw) { fprintf(stderr, "malloc failed\n"); return 1; }

    /* TODO: write 10, 20, 30, 40 at byte offsets 0, 8, 16, 24.
     * Cast to unsigned char * for byte arithmetic, then to int * to store.
     * Do NOT use array subscripts. */

    /* TODO: assert each value */
    free(raw);

    /* Part 2: int * base, element arithmetic */
    int *ibuf = malloc(64);
    if (!ibuf) { fprintf(stderr, "malloc failed\n"); return 1; }

    /* TODO: write 10, 20, 30, 40 at element offsets 0, 2, 4, 6.
     * Use *(ibuf + N) = value syntax — no [] allowed. */

    /* TODO: assert each value */
    free(ibuf);

    printf("All assertions passed.\n");
    return 0;
}
