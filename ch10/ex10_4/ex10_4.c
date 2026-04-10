/* ex10_4.c — Atomic reference counter stress test
 * gcc -Wall -Wextra -Werror -std=c11 -pthread -fsanitize=address -g \
 *     -o ex10_4 ex10_4.c && ./ex10_4
 */
#include <stdatomic.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

/* Layout: [_Atomic int refcount][user data...]
 * Pointer arithmetic: header is the word before the returned pointer. */
typedef struct {
    _Atomic int refcount;
} RcHeader;

void *rc_alloc(size_t size) {
    /* TODO: implement */
}

void *rc_retain(void *ptr) {
    /* TODO: implement */
}

void rc_release(void *ptr) {
    /* TODO: implement */
}

/* ─── Stress test ───────────────────────────────────────────────────────────── */

#define N_THREADS 8
#define ITERS     100000

static void *stress(void *ptr) {
    /* TODO: implement */
}

int main(void) {
    int *data = rc_alloc(sizeof(int));
    assert(data != NULL);
    *data = 42;

    pthread_t t[N_THREADS];
    for (int i = 0; i < N_THREADS; i++) {
        rc_retain(data);   /* give each thread one reference */
        pthread_create(&t[i], NULL, stress, data);
    }

    for (int i = 0; i < N_THREADS; i++) pthread_join(t[i], NULL);

    /* All threads have released their references. The object is freed.
     * Do NOT access *data here — that would be use-after-free. */
    printf("Stress test complete — run with -fsanitize=address to verify no double-free or leak.\n");
    return 0;
}
