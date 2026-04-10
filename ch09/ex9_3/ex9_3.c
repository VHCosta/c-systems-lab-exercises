#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT  8080
#define ROOT  "./www"
#define HBUF  1024
#define RBUF  4096

static const char *mime(const char *path) {
    /* TODO: implement */
}

static void send_status(int fd, int code, const char *reason) {
    /* TODO: implement */
}

static int serve_file(int client, const char *path) {
    /* TODO: implement */
}

static void handle(int client) {
    /* TODO: implement */
}

static int make_server(int port) {
    /* TODO: implement */
}

int main(void) {
    signal(SIGPIPE, SIG_IGN);
    int server = make_server(PORT);
    printf("HTTP/1.0 server on port %d, root: %s\n", PORT, ROOT);

    while (1) {
        int client = accept(server, NULL, NULL);
        if (client < 0) { perror("accept"); continue; }
        handle(client);
        close(client);
    }
}
