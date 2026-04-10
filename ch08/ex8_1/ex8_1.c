#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Read VmRSS (resident set size in KiB) from /proc/self/status. */
static long read_rss_kb(void) {
    /* TODO: implement */
}

int main(void) {
    const size_t BUF_SZ = 64 * 1024 * 1024;  /* 64 MiB */
    char *buf = malloc(BUF_SZ);
    if (!buf) { perror("malloc"); return 1; }

    /* Touch all pages so they are physically backed before fork. */
    memset(buf, 'A', BUF_SZ);

    printf("parent [%d] RSS before fork : %ld KiB\n",
           getpid(), read_rss_kb());

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        /* Child: show RSS before and after dirtying the buffer. */
        printf("child  [%d] RSS before write: %ld KiB\n",
               getpid(), read_rss_kb());

        /* Every write faults in a private copy of each shared page. */
        memset(buf, 'B', BUF_SZ);

        printf("child  [%d] RSS after  write: %ld KiB\n",
               getpid(), read_rss_kb());
        printf("child  [%d] buf[0]='%c'  (B = child's private copy)\n",
               getpid(), buf[0]);
        _exit(0);
    }

    waitpid(pid, NULL, 0);
    printf("parent [%d] RSS after  fork : %ld KiB\n",
           getpid(), read_rss_kb());
    printf("parent [%d] buf[0]='%c'  (A = unchanged, shared page)\n",
           getpid(), buf[0]);

    free(buf);
    return 0;
}
