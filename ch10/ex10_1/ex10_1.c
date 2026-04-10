/* ex10_1.c — Thread-safe bounded queue (4 producers, 4 consumers)
 * gcc -Wall -Wextra -Werror -std=c11 -pthread -g -o ex10_1 ex10_1.c && ./ex10_1
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CAPACITY 16
#define N_PROD   4
#define N_CONS   4
#define N_ITEMS  1000

typedef struct {
    pthread_mutex_t mu;
    pthread_cond_t  not_full;
    pthread_cond_t  not_empty;
    int             buf[CAPACITY];
    int             head, tail, count;
    int             closed;
} Queue;

void queue_init(Queue *q) {
    /* TODO: implement */
}

void queue_destroy(Queue *q) {
    /* TODO: implement */
}

void queue_push(Queue *q, int item) {
    /* TODO: implement */
}

/* Returns 0 on success, -1 if closed and empty */
int queue_pop(Queue *q, int *item) {
    /* TODO: implement */
}

void queue_close(Queue *q) {
    /* TODO: implement */
}

/* ─── Test harness ──────────────────────────────────────────────────────────── */

static Queue          g_queue;
static long           g_sum_in  = 0;
static long           g_sum_out = 0;
static pthread_mutex_t g_sum_mu = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    /* TODO: implement */
}

void *consumer(void *arg) {
    /* TODO: implement */
}

int main(void) {
    queue_init(&g_queue);

    pthread_t prod[N_PROD], cons[N_CONS];
    int ids[N_PROD];

    for (int i = 0; i < N_CONS; i++)
        pthread_create(&cons[i], NULL, consumer, NULL);
    for (int i = 0; i < N_PROD; i++) {
        ids[i] = i;
        pthread_create(&prod[i], NULL, producer, &ids[i]);
    }

    for (int i = 0; i < N_PROD; i++) pthread_join(prod[i], NULL);
    queue_close(&g_queue);
    for (int i = 0; i < N_CONS; i++) pthread_join(cons[i], NULL);

    printf("sum_in=%ld  sum_out=%ld  match=%s\n",
           g_sum_in, g_sum_out,
           g_sum_in == g_sum_out ? "YES" : "NO");
    assert(g_sum_in == g_sum_out);

    queue_destroy(&g_queue);
    printf("OK\n");
    return 0;
}
