/* ex10_2.c — TSan-guided data race: three implementations
 * Racy version:
 *   gcc -Wall -Wextra -std=c11 -pthread -fsanitize=thread -g -o ex10_2_racy ex10_2.c -DRACY && ./ex10_2_racy
 * Mutex fix:
 *   gcc -Wall -Wextra -Werror -std=c11 -pthread -g -o ex10_2_mutex ex10_2.c -DFIX_MUTEX && ./ex10_2_mutex
 * (requires _POSIX_C_SOURCE for clock_gettime)
 * Atomic fix:
 *   gcc -Wall -Wextra -Werror -std=c11 -pthread -g -o ex10_2_atomic ex10_2.c -DFIX_ATOMIC && ./ex10_2_atomic
 */
#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define N_THREADS 8
#define ITERS     100000

#if defined(FIX_ATOMIC)
#include <stdatomic.h>
static _Atomic long counter = 0;
#define INC() atomic_fetch_add(&counter, 1)
#define GET() atomic_load(&counter)
#elif defined(FIX_MUTEX)
static long counter = 0;
static pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
#define INC() do { pthread_mutex_lock(&mu); counter++; pthread_mutex_unlock(&mu); } while(0)
#define GET() counter
#else /* RACY (default) */
static long counter = 0;
#define INC() counter++
#define GET() counter
#endif

static void *inc(void *arg) {
    /* TODO: implement */
}

int main(void) {
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    pthread_t t[N_THREADS];
    for (int i = 0; i < N_THREADS; i++) pthread_create(&t[i], NULL, inc, NULL);
    for (int i = 0; i < N_THREADS; i++) pthread_join(t[i], NULL);

    clock_gettime(CLOCK_MONOTONIC, &t1);
    double elapsed = (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec) / 1e9;

    long expected = (long)N_THREADS * ITERS;
    printf("counter=%ld  expected=%ld  correct=%s  elapsed=%.3fs\n",
           (long)GET(), expected,
           GET() == expected ? "yes" : "no (race!)",
           elapsed);
    return 0;
}
