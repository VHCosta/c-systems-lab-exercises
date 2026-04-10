/* ex4_3.c — ASan bug hunt: three deliberate memory bugs (FIXED)
 * gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address -g \
 *     -o ex4_3 ex4_3.c && ./ex4_3
 *
 * This file is the FIXED version. The original buggy version would have:
 *   Bug 1: malloc(5) for "Hello" (needs 6 bytes for '\0')
 *   Bug 2: write to arr after free
 *   Bug 3: early return without freeing tmp
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void bug1_overflow_fixed(void) {
    /* TODO: implement */
}

static void bug2_uaf_fixed(void) {
    /* TODO: implement */
}

static void bug3_leak_fixed(int condition) {
    /* TODO: implement */
}

int main(void) {
    bug1_overflow_fixed();
    bug2_uaf_fixed();
    bug3_leak_fixed(1);
    bug3_leak_fixed(0);
    return 0;
}
