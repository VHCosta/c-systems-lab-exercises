/* ex11_3.c — volatile vs atomic for inter-thread communication
 *
 * Version 1 (racy — data race, TSan will report):
 *   gcc -std=c11 -pthread -fsanitize=thread -g -DV_PLAIN -o ex11_3_plain ex11_3.c
 *
 * Version 2 (volatile — still a C11 data race, TSan will report):
 *   gcc -std=c11 -pthread -fsanitize=thread -g -DV_VOLATILE -o ex11_3_volatile ex11_3.c
 *
 * Version 3 (atomic — TSan clean):
 *   gcc -Wall -Wextra -Werror -std=c11 -pthread -fsanitize=thread -g \
 *       -o ex11_3_atomic ex11_3.c && ./ex11_3_atomic
 */
#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

#if defined(V_PLAIN)
static int shared = 0;
#define PRODUCER_WRITE(v)  (shared = (v))
#define CONSUMER_READ()    (shared)
#define VERSION "plain int (racy)"

#elif defined(V_VOLATILE)
static volatile int shared = 0;
#define PRODUCER_WRITE(v)  (shared = (v))
#define CONSUMER_READ()    (shared)
#define VERSION "volatile int (still a race — TSan will report)"

#else /* V_ATOMIC default */
static _Atomic int shared = 0;
#define PRODUCER_WRITE(v)  atomic_store_explicit(&shared, (v), memory_order_release)
#define CONSUMER_READ()    atomic_load_explicit(&shared, memory_order_acquire)
#define VERSION "_Atomic int with release/acquire (TSan clean)"
#endif

static void *producer(void *arg) {
    /* TODO: implement */
}

static void *consumer(void *arg) {
    /* TODO: implement */
}

int main(void) {
    printf("Version: %s\n", VERSION);
    pthread_t tp, tc;
    /* Start consumer first so it's ready to spin */
    pthread_create(&tc, NULL, consumer, NULL);
    pthread_create(&tp, NULL, producer, NULL);
    pthread_join(tp, NULL);
    pthread_join(tc, NULL);
    return 0;
}
