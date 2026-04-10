#include <stdio.h>
#include "util.h"
static int global = 42;
int main(void) {
    printf("add(3,4)  = %d\n", add(3, 4));
    printf("SQUARE(5) = %d\n", SQUARE(5));
    printf("global    = %d\n", global);
    return 0;
}
