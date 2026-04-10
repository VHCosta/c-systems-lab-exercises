/* ex6_2.c — Type-safe min/max with _Generic
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex6_2 ex6_2.c && ./ex6_2
 */
#include <stdio.h>
#include <assert.h>

/* TODO: implement max_int, max_long, max_double as static inline functions */

/* TODO: define safe_max(a, b) using _Generic to dispatch to the typed function */

/* TODO: define type_name(x) using _Generic to return "int", "long", "double",
 * or "other" */

int main(void) {
    int a = safe_max(3, 5);
    assert(a == 5);
    printf("safe_max(3, 5)     = %d   type=%s\n", a, type_name(a));

    double b = safe_max(3.0, 5.0);
    assert(b == 5.0);
    printf("safe_max(3.0, 5.0) = %g   type=%s\n", b, type_name(b));

    long c = safe_max(3L, 5L);
    assert(c == 5L);
    printf("safe_max(3L, 5L)   = %ld  type=%s\n", c, type_name(c));

    printf("All assertions passed.\n");
    return 0;
}
