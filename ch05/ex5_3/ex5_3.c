/* ex5_3.c — Union-based tagged variant
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex5_3 ex5_3.c && ./ex5_3
 * valgrind --leak-check=full ./ex5_3
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef enum { VAL_INT, VAL_DOUBLE, VAL_STRING } val_tag_t;

typedef struct {
    val_tag_t tag;
    union {
        int    i;
        double d;
        char  *s;   /* heap-allocated — value_t owns the string */
    };
} value_t;

value_t value_int(int i) {
    /* TODO: implement */
}

value_t value_double(double d) {
    /* TODO: implement */
}

/* Copies the string — caller may free their copy after this call. */
value_t value_string(const char *s) {
    /* TODO: implement */
}

/* Frees heap memory for VAL_STRING, then zeros *v to prevent UAF. */
void value_free(value_t *v) {
    /* TODO: implement */
}

void value_print(const value_t *v) {
    /* TODO: implement */
}

int main(void) {
    value_t vals[3];
    vals[0] = value_int(42);
    vals[1] = value_double(3.14159);
    vals[2] = value_string("hello, world");

    for (int i = 0; i < 3; i++) {
        value_print(&vals[i]);
        printf("\n");
    }

    /* Verify tags and contents */
    assert(vals[0].tag == VAL_INT    && vals[0].i == 42);
    assert(vals[1].tag == VAL_DOUBLE);
    assert(vals[2].tag == VAL_STRING && strcmp(vals[2].s, "hello, world") == 0);

    for (int i = 0; i < 3; i++) value_free(&vals[i]);

    /* After free, tag should be 0 (VAL_INT) and pointer null */
    assert(vals[2].s == NULL);

    printf("All assertions passed — no leaks (verify with Valgrind).\n");
    return 0;
}
