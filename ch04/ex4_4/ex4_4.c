/* ex4_4.c — Arena allocator with alignment + malloc benchmark
 * gcc -Wall -Wextra -Werror -std=c11 -O2 -g -o ex4_4 ex4_4.c && ./ex4_4
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>

typedef struct {
    unsigned char *buf;
    size_t         cap;
    size_t         pos;
} arena_t;

static size_t align_up(size_t n, size_t align) {
    /* TODO: implement */
}

arena_t *arena_new(size_t capacity) {
    /* TODO: implement */
}

void *arena_alloc(arena_t *a, size_t size, size_t align) {
    /* TODO: implement */
}

void arena_reset(arena_t *a) {
    /* TODO: implement */
}

void arena_destroy(arena_t *a) {
    /* TODO: implement */
}

typedef struct { int x, y; double z; char name[16]; } SmallStruct;

#define N 10000

static double ns_per(struct timespec start, struct timespec end, int iters) {
    /* TODO: implement */
}

int main(void) {
    struct timespec t0, t1;
    volatile long sink = 0;

    arena_t *a = arena_new((size_t)N * sizeof(SmallStruct) * 2);
    assert(a);

    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < N; i++) {
        SmallStruct *s = arena_alloc(a, sizeof(SmallStruct), _Alignof(SmallStruct));
        assert(s);
        s->x = i; sink += s->x;
    }
    arena_reset(a);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double arena_ns = ns_per(t0, t1, N);

    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < N; i++) {
        SmallStruct *s = malloc(sizeof(SmallStruct));
        if (!s) { perror("malloc"); exit(1); }
        s->x = i; sink += s->x;
        free(s);
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double malloc_ns = ns_per(t0, t1, N);

    printf("arena:   %.1f ns/alloc\n", arena_ns);
    printf("malloc:  %.1f ns/alloc\n", malloc_ns);
    printf("speedup: %.1fx\n",         malloc_ns / arena_ns);
    printf("(sink=%ld)\n",             sink);

    arena_destroy(a);
    return 0;
}
