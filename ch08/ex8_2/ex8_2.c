#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static volatile sig_atomic_t g_stop = 0;

static void handle_sigint(int sig) {
    /* TODO: implement */
}

int main(void) {
    struct sigaction sa = {0};
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);

    int tick = 0;

    while (!g_stop) {
        /* -- critical section: block SIGINT ---------------------- */
        sigset_t block_set, old_set;
        sigemptyset(&block_set);
        sigaddset(&block_set, SIGINT);
        sigprocmask(SIG_BLOCK, &block_set, &old_set);

        printf("tick %d: critical section (SIGINT blocked)\n", ++tick);
        sleep(1);   /* Ctrl-C here is deferred, not lost */
        printf("tick %d: leaving critical section\n", tick);

        /* Deferred SIGINT fires here when mask is restored. */
        sigprocmask(SIG_SETMASK, &old_set, NULL);
        /* -- end critical section --------------------------------- */

        if (g_stop) break;
        printf("tick %d: outside critical (SIGINT live)\n", tick);
        sleep(1);
    }

    printf("clean shutdown after %d ticks\n", tick);
    return 0;
}
