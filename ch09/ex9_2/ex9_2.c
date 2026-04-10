#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT    8080
#define MAXFDS  64
#define BUFSIZE 1024

static int make_server(int port) {
    /* TODO: implement */
}

int main(void) {
    signal(SIGPIPE, SIG_IGN);

    int server = make_server(PORT);
    int clients[MAXFDS];
    int n = 0;
    for (int i = 0; i < MAXFDS; i++) clients[i] = -1;

    printf("select server on port %d (max %d clients)\n", PORT, MAXFDS);

    while (1) {
        /* Rebuild fd_set — select() clears bits of non-ready FDs. */
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(server, &rfds);
        int maxfd = server;

        for (int i = 0; i < n; i++) {
            if (clients[i] >= 0) {
                FD_SET(clients[i], &rfds);
                if (clients[i] > maxfd) maxfd = clients[i];
            }
        }

        /* NULL timeout = wait forever until at least one FD is ready. */
        if (select(maxfd + 1, &rfds, NULL, NULL, NULL) < 0) {
            perror("select"); break;
        }

        /* New connection? */
        if (FD_ISSET(server, &rfds) && n < MAXFDS) {
            clients[n] = accept(server, NULL, NULL);
            if (clients[n] >= 0) {
                printf("new client fd=%d (total: %d)\n", clients[n], n + 1);
                n++;
            }
        }

        /* Data on existing connections? */
        for (int i = 0; i < n; i++) {
            if (clients[i] < 0 || !FD_ISSET(clients[i], &rfds)) continue;

            char buf[BUFSIZE];
            ssize_t r = recv(clients[i], buf, sizeof(buf), 0);
            if (r <= 0) {
                printf("client fd=%d closed\n", clients[i]);
                close(clients[i]);
                clients[i] = clients[--n]; /* O(1) swap-remove */
            } else {
                send(clients[i], buf, (size_t)r, MSG_NOSIGNAL);
            }
        }
    }

    close(server);
    return 0;
}
