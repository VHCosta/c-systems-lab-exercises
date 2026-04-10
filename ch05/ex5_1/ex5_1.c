/* ex5_1.c — Predict struct layout
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex5_1 ex5_1.c && ./ex5_1
 */
#include <stddef.h>
#include <stdio.h>

struct A { char x; int y; char z; };
struct B { int a; double b; char c; int d; };
struct C { char p; char q; short r; int s; };
struct D { double x; char arr[3]; int y; };

/* TODO: add _Static_assert for each struct's total size */
/* TODO: add _Static_assert for each field's offsetof */

int main(void) {
    /* TODO: print size and offsets of each struct */
    printf("All _Static_asserts passed — layout matches predictions.\n");
    return 0;
}
