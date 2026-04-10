/* ex11_2.c — False sharing benchmark
 * gcc -Wall -Wextra -Werror -std=c11 -pthread -O2 -o ex11_2 ex11_2.c && ./ex11_2
 */
#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdatomic.h>

#define ITERS      200000000LL
#define CACHE_LINE 64

/* Version A: false sharing — both counters in the same 64-byte cache line */
struct SharedCounters {
    long a;
    long b;
};

/* Version B: padded — each counter on its own cache line */
struct PaddedCounters {
    long a;
    char _pad0[CACHE_LINE - sizeof(long)];
    long b;
    char _pad1[CACHE_LINE - sizeof(long)];
};

/* Version C: relaxed atomics (still padded to isolate the atomic overhead) */
struct AtomicCounters {
    _Atomic long a;
    char _pad0[CACHE_LINE - sizeof(_Atomic long)];
    _Atomic long b;
};

static struct SharedCounters  shared  = {0, 0};
static struct PaddedCounters  padded  = {0, {0}, 0, {0}};
static struct AtomicCounters  atomics = {0, {0}, 0};

/* ── Thread functions ── */
static void *t0_shared(void *arg)  { (void)arg; for (long i = 0; i < ITERS; i++) shared.a++; return NULL; }
static void *t1_shared(void *arg)  { (void)arg; for (long i = 0; i < ITERS; i++) shared.b++; return NULL; }
static void *t0_padded(void *arg)  { (void)arg; for (long i = 0; i < ITERS; i++) padded.a++; return NULL; }
static void *t1_padded(void *arg)  { (void)arg; for (long i = 0; i < ITERS; i++) padded.b++; return NULL; }
static void *t0_atomic(void *arg)  { (void)arg; for (long i = 0; i < ITERS; i++) atomic_fetch_add_explicit(&atomics.a, 1, memory_order_relaxed); return NULL; }
static void *t1_atomic(void *arg)  { (void)arg; for (long i = 0; i < ITERS; i++) atomic_fetch_add_explicit(&atomics.b, 1, memory_order_relaxed); return NULL; }

static double run(void *(*fn0)(void *), void *(*fn1)(void *)) {
    /* TODO: implement */
}

int main(void) {
    printf("Cache line size: %d bytes\n", CACHE_LINE);
    printf("sizeof(SharedCounters) = %zu\n", sizeof(struct SharedCounters));
    printf("sizeof(PaddedCounters) = %zu\n", sizeof(struct PaddedCounters));

    double t_shared = run(t0_shared, t1_shared);
    double t_padded = run(t0_padded, t1_padded);
    double t_atomic = run(t0_atomic, t1_atomic);

    printf("\nResults (%lld iterations per thread):\n", ITERS);
    printf("  shared:  %.3fs  (false sharing — cache line bounces)\n", t_shared);
    printf("  padded:  %.3fs  %.1fx faster  (each thread owns its line)\n",
           t_padded, t_shared / t_padded);
    printf("  atomic:  %.3fs  %.1fx vs shared  (relaxed atomic, padded)\n",
           t_atomic, t_shared / t_atomic);

    /* Atomics version should be exact; shared/padded have races but we only care about timing */
    printf("\natomics.a=%ld  atomics.b=%ld  (both should be %lld)\n",
           (long)atomics.a, (long)atomics.b, ITERS);

    return 0;
}
