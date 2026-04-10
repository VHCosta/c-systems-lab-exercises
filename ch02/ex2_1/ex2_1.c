/* ex2_1.c — Integer promotion quiz
 * Compile: gcc -std=c11 -Wall -Wextra -Werror -O1 -o ex2_1 ex2_1.c
 */
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>

int main(void) {
    unsigned char a = 200, b = 100;
    unsigned int  u = 0;
    int           s = -1;

    /* 1. a + b — what type does a + b have? What is the value? */
    /* TODO: add _Static_assert and assert, then printf */

    /* 2. sizeof('A') — is a char literal of type char or int in C? */
    /* TODO: add _Static_assert and printf */

    /* 3. s < u — compare as signed vs as unsigned */
    /* TODO: compute and print both signed and unsigned comparisons */

    /* 4. (unsigned int)s — what value does -1 become? */
    /* TODO: assert and printf */

    /* 5. s < (int)u — explicit cast forces signed comparison */
    /* TODO: assert and printf */

    /* 6. (1 ? -1 : 2U) — what is the common type of int and unsigned int? */
    /* TODO: assert and printf */

    printf("All checks passed.\n");
    return 0;
}
