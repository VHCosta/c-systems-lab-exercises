#include <stdio.h>
#include "vector.h"
int main(void) {
    vec2_t a = {3.0, 4.0};
    vec2_t b = {1.0, 2.0};
    vec2_t c = vec2_add(a, b);
    printf("length = %.2f\n", vec2_length(c));
    return 0;
}
