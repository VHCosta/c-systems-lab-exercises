#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT    8080
#define BUFSIZE 4096

static int make_server(int port) {
    /* TODO: implement */
}

int main(void) {
    /* Ignore SIGPIPE: broken-pipe on send() becomes EPIPE instead. */
    signal(SIGPIPE, SIG_IGN);

    int server = make_server(PORT);
    if (server < 0) return 1;
    printf("echo server on port %d\n", PORT);

    while (1) {
        struct sockaddr_in peer;
        socklen_t plen = sizeof(peer);
        int client = accept(server, (struct sockaddr *)&peer, &plen);
        if (client < 0) { perror("accept"); continue; }

        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &peer.sin_addr, ip, sizeof(ip));
        printf("connect from %s:%u\n", ip, ntohs(peer.sin_port));

        /* Echo loop: recv returns 0 when the client closes the connection. */
        char buf[BUFSIZE];
        ssize_t n;
        while ((n = recv(client, buf, sizeof(buf), 0)) > 0)
            send(client, buf, (size_t)n, MSG_NOSIGNAL);

        if (n < 0) perror("recv");
        close(client);
        printf("disconnected\n");
    }
}
