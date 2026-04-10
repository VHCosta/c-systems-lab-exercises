/* ex2_4.c — Safe integer arithmetic (solution)
 * Compile: gcc -std=c11 -Wall -Wextra -Werror -O1 -o ex2_4 ex2_4.c
 */
#include <stdio.h>
#include <limits.h>
#include <assert.h>

/* Returns 0 and writes the sum to *result on success.
 * Returns -1 if a + b would overflow int. No UB. */
int safe_add(int a, int b, int *result) {
    /* TODO: implement */
}

/* Returns 0 and writes a - b to *result on success. */
int safe_sub(int a, int b, int *result) {
    /* TODO: implement */
}

/* Returns 0 and writes a * b to *result on success. */
int safe_mul(int a, int b, int *result) {
    /* TODO: implement */
}

int main(void) {
    int r;

    /* safe_add */
    assert(safe_add(INT_MAX,  1,       &r) == -1);
    assert(safe_add(INT_MIN, -1,       &r) == -1);
    assert(safe_add(INT_MAX,  INT_MIN, &r) ==  0 && r == -1);
    assert(safe_add(0,        0,       &r) ==  0 && r == 0);
    assert(safe_add(100,      200,     &r) ==  0 && r == 300);
    assert(safe_add(INT_MAX,  0,       &r) ==  0 && r == INT_MAX);
    assert(safe_add(-1,       1,       &r) ==  0 && r == 0);

    /* safe_sub */
    assert(safe_sub(INT_MIN,  1,       &r) == -1);
    assert(safe_sub(0,        INT_MIN, &r) == -1);
    assert(safe_sub(5,        3,       &r) ==  0 && r == 2);
    assert(safe_sub(INT_MIN,  0,       &r) ==  0 && r == INT_MIN);
    assert(safe_sub(INT_MIN, -1,       &r) ==  0 && r == INT_MIN + 1);

    /* safe_mul */
    assert(safe_mul(INT_MAX,  2,       &r) == -1);
    assert(safe_mul(100000,   100000,  &r) == -1);
    assert(safe_mul(INT_MIN,  2,       &r) == -1);
    assert(safe_mul(3,        7,       &r) ==  0 && r == 21);
    assert(safe_mul(-5,       4,       &r) ==  0 && r == -20);
    assert(safe_mul(-3,      -7,       &r) ==  0 && r == 21);
    assert(safe_mul(0,        INT_MAX, &r) ==  0 && r == 0);
    assert(safe_mul(INT_MIN,  1,       &r) ==  0 && r == INT_MIN);
    assert(safe_mul(INT_MIN, -1,       &r) == -1);

    printf("All safe_add / safe_sub / safe_mul tests passed.\n");
    return 0;
}
