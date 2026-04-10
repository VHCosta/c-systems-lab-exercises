/* ex6_1.c — Macro pitfall repair
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex6_1 ex6_1.c && ./ex6_1
 */
#include <stdio.h>
#include <stdlib.h>

/* ── Buggy versions (for demonstration) ── */
#define DOUBLE_BAD(x)   x + x
#define SQUARE_BAD(x)   x * x
#define MAX_BAD(a, b)   a > b ? a : b
/* ASSERT_BAD and LOG_BAD are not used in tests to avoid UB */

/* ── Fixed versions ── */
#define DOUBLE(x)   ((x) + (x))
#define SQUARE(x)   ((x) * (x))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))
/* do-while(0) prevents the dangling-else bug */
#define ASSERT(cond) do { \ {
    /* TODO: implement */
}
/* ##__VA_ARGS__ eats the comma when __VA_ARGS__ is empty */
#define LOG(fmt, ...)  printf(fmt, ##__VA_ARGS__)

int main(void) {
    /* DOUBLE: operator precedence */
    printf("DOUBLE_BAD(3)*2 = %d  (wrong: expect 12)\n", DOUBLE_BAD(3) * 2);
    printf("DOUBLE(3)*2     = %d  (correct)\n",           DOUBLE(3) * 2);

    /* SQUARE: missing inner parens */
    printf("SQUARE_BAD(1+2) = %d  (wrong: expect 9)\n",  SQUARE_BAD(1 + 2));
    printf("SQUARE(1+2)     = %d  (correct)\n",           SQUARE(1 + 2));

    /* MAX: double evaluation */
    int i = 3, j = 5;
    int m = MAX(i++, j++);
    printf("MAX(i++,j++): m=%d i=%d j=%d  (j incremented twice due to double-eval)\n",
           m, i, j);

    /* ASSERT: correct usage */
    ASSERT(1 == 1);  /* passes */
    /* ASSERT(0 == 1); would abort with a message */

    /* LOG: variadic with and without extra args */
    LOG("hello %d\n", 42);
    LOG("no extra args\n");  /* would crash with LOG_BAD */

    printf("All demos complete.\n");
    return 0;
}
