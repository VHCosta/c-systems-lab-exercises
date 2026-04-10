/* ex2_2.c — Spot the UB: signed overflow (fixed solution)
 * Compile: gcc -std=c11 -Wall -Wextra -Werror -O1 -o ex2_2 ex2_2.c
 *
 * The original buggy version:
 *   int x = INT_MAX;
 *   if (x + 1 < x) { printf("overflow detected\n"); }
 * — x+1 is UB; under -O2 the branch is eliminated because the compiler
 *   assumes signed overflow never happens.
 *
 * Fix: check for overflow before performing the addition.
 */
#include <stdio.h>
#include <limits.h>
#include <assert.h>

/* Returns 1 if a + 1 would overflow int, 0 otherwise.
 * No UB: we compare against INT_MAX before adding. */
static int will_overflow_plus1(int a) {
    /* TODO: implement */
}

int main(void) {
    int x = INT_MAX;

    if (will_overflow_plus1(x)) {
        printf("overflow detected\n");
    } else {
        printf("no overflow\n");
    }

    /* Verify the check works for non-overflowing values */
    assert(will_overflow_plus1(INT_MAX) == 1);
    assert(will_overflow_plus1(INT_MAX - 1) == 0);
    assert(will_overflow_plus1(0) == 0);
    assert(will_overflow_plus1(-1) == 0);

    printf("All assertions passed.\n");
    return 0;
}
