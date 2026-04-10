/* ex11_1.c — ABI-conforming assembly: dot product test harness
 * gcc -Wall -Wextra -Werror -std=c11 -O2 -c dot.s -o dot.o
 * gcc -Wall -Wextra -Werror -std=c11 -O2 ex11_1.c dot.o -o ex11_1 && ./ex11_1
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

/* Implemented in dot.s (x86-64 AT&T syntax).
 * On non-x86-64 platforms (aarch64, etc.) the assembler cannot process
 * dot.s, so we provide a C fallback so the harness still compiles and
 * validates the test logic.  The ABI exercise is only meaningful on x86-64.
 */
#ifdef __x86_64__
int dot_product(const int *a, const int *b, int n);
#else
static int dot_product(const int *a, const int *b, int n) {
    /* TODO: implement */
}
#endif

/* Reference implementation */
static int dot_ref(const int *a, const int *b, int n) {
    /* TODO: implement */
}

int main(void) {
    /* Correctness: known vectors */
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    /* 1*5 + 2*6 + 3*7 + 4*8 = 5+12+21+32 = 70 */
    int got = dot_product(a, b, 4);
    int exp = dot_ref(a, b, 4);
    printf("dot([1,2,3,4],[5,6,7,8]) = %d  (expected %d)\n", got, exp);
    assert(got == exp);
    assert(got == 70);

    /* Edge case: n == 0 */
    assert(dot_product(a, b, 0) == 0);

    /* Performance: large arrays */
    int N = 10000000;
    int *x = malloc(N * sizeof *x);
    int *y = malloc(N * sizeof *y);
    if (!x || !y) { perror("malloc"); return 1; }
    for (int i = 0; i < N; i++) {
        x[i] = i & 0xFF;
        y[i] = (N - i) & 0xFF;
    }

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    int asm_result = dot_product(x, y, N);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double asm_ms = (t1.tv_sec - t0.tv_sec) * 1e3 + (t1.tv_nsec - t0.tv_nsec) / 1e6;

    clock_gettime(CLOCK_MONOTONIC, &t0);
    int c_result = dot_ref(x, y, N);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double c_ms = (t1.tv_sec - t0.tv_sec) * 1e3 + (t1.tv_nsec - t0.tv_nsec) / 1e6;

    printf("N=10M: asm=%.1fms  c=%.1fms  match=%s\n",
           asm_ms, c_ms, asm_result == c_result ? "yes" : "NO");
    assert(asm_result == c_result);

    free(x);
    free(y);
    printf("All assertions passed.\n");
    return 0;
}
