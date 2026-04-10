/* ex10_3.c — Lock ordering: deadlock demo and fix
 * Deadlock demo (will hang — kill with Ctrl-C):
 *   gcc -Wall -Wextra -std=c11 -pthread -g -o ex10_3 ex10_3.c -DDEADLOCK && ./ex10_3
 * Fixed version:
 *   gcc -Wall -Wextra -Werror -std=c11 -pthread -g -o ex10_3 ex10_3.c && ./ex10_3
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

static pthread_mutex_t mu_a = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mu_b = PTHREAD_MUTEX_INITIALIZER;
static int a = 1, b = 2;

#ifdef DEADLOCK
/* Thread 1: acquires mu_a then mu_b */
static void *t1_fn(void *arg) {
    /* TODO: implement */
}

/* Thread 2: acquires mu_b then mu_a — opposite order */
static void *t2_fn(void *arg) {
    /* TODO: implement */
}
#else
/* Fixed: both threads always acquire mu_a before mu_b */
static void *swap_fn(void *arg) {
    /* TODO: implement */
}
#endif

int main(void) {
#ifdef DEADLOCK
    printf("Running deadlock demo — this will hang. Kill with Ctrl-C.\n");
    pthread_t t1, t2;
    pthread_create(&t1, NULL, t1_fn, NULL);
    pthread_create(&t2, NULL, t2_fn, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
#else
    printf("Running fixed version (consistent lock order)...\n");
    int iters = 1000000;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, swap_fn, &iters);
    pthread_create(&t2, NULL, swap_fn, &iters);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    /* After 2*iters swaps, result depends on parity — just check no deadlock */
    printf("a=%d b=%d (no deadlock after %d total swaps)\n", a, b, 2 * iters);
    printf("OK\n");
#endif
    return 0;
}
