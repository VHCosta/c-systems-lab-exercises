#include <math.h>
#include "vector.h"

double vec2_length(vec2_t v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

/* vec2_add intentionally missing for the exercise */
