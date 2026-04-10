/* ex3_1.c — Map the address space
 * gcc -Wall -Wextra -Werror -std=c11 -o ex3_1 ex3_1.c && ./ex3_1
 */
#include <stdio.h>
#include <stdlib.h>

int g_init   = 42;   /* Data segment — initialized global      */
int g_uninit;        /* BSS segment  — zero-initialized global */

static void marker(void) {}   /* Text segment — function address */

void show(int arg) {
    /* TODO: implement */
}

int main(void) {
    show(7);

    int arr[5];
    int *p = arr;
    printf("\nsizeof(arr) = %zu\n", sizeof(arr));
    printf("sizeof(p)   = %zu\n",   sizeof(p));
    printf("arr = %p\n", (void *)arr);
    printf("p   = %p\n", (void *)p);

    return 0;
}
