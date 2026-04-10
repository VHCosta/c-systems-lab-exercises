#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define ECHO_PORT  19876
#define MESSAGES   100

/* Simple loopback echo server — run in a child process. */
static void run_echo_server(void) {
    /* TODO: implement */
}

static long long now_us(void) {
    /* TODO: implement */
}

static double measure(int nodelay) {
    /* TODO: implement */
}

int main(void) {
    signal(SIGPIPE, SIG_IGN);

    /* Start echo server in background. */
    pid_t srv = fork();
    if (srv < 0) { perror("fork"); return 1; }
    if (srv == 0) run_echo_server();

    struct timespec delay = { .tv_sec = 0, .tv_nsec = 50000000L };
    nanosleep(&delay, NULL);  /* wait for server to bind */

    printf("Nagle ON  (default):  %.1f µs/msg\n", measure(0));
    printf("TCP_NODELAY:          %.1f µs/msg\n", measure(1));
    printf("\n");
    printf("Nagle doubles latency on loopback because it waits for the\n");
    printf("previous byte's ACK before sending the next one.\n");
    printf("TCP_NODELAY sends each byte immediately.\n");

    kill(srv, SIGTERM);
    waitpid(srv, NULL, 0);
    return 0;
}
