#ifndef VECTOR_H
#define VECTOR_H
typedef struct { double x, y; } vec2_t;
double vec2_length(vec2_t v);
vec2_t vec2_add(vec2_t a, vec2_t b);
#endif
