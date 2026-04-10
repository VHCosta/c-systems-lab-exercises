#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ARGS 64
#define MAX_LINE 1024

/* Tokenise line into argv. Returns argc (0 for blank lines). */
static int parse_args(char *line, char *argv[], int max) {
    /* TODO: implement */
}

int main(void) {
    /* Shell ignores SIGINT -- only the foreground child receives it. */
    signal(SIGINT, SIG_IGN);

    int last_status = 0;
    char line[MAX_LINE];

    while (1) {
        printf("[%d] $ ", last_status);
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) break;  /* Ctrl-D: EOF */

        char *argv[MAX_ARGS];
        int argc = parse_args(line, argv, MAX_ARGS);
        if (argc == 0) continue;

        /* Built-ins must execute in the parent process. */
        if (strcmp(argv[0], "exit") == 0)
            exit(argc > 1 ? atoi(argv[1]) : last_status);

        if (strcmp(argv[0], "cd") == 0) {
            const char *dir = argc > 1 ? argv[1] : getenv("HOME");
            if (!dir || chdir(dir) < 0)
                fprintf(stderr, "cd: %s\n", strerror(errno));
            continue;
        }

        pid_t pid = fork();
        if (pid < 0) { perror("fork"); continue; }

        if (pid == 0) {
            /* Child: restore SIGINT default so Ctrl-C kills it. */
            signal(SIGINT, SIG_DFL);
            execvp(argv[0], argv);
            fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
            _exit(127);
        }

        int status;
        waitpid(pid, &status, 0);

        if      (WIFEXITED(status))    last_status = WEXITSTATUS(status);
        else if (WIFSIGNALED(status))  last_status = 128 + WTERMSIG(status);
        else                           last_status = -1;
    }

    return last_status;
}
