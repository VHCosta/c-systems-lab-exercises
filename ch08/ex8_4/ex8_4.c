#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * Connect stdout of cmd1 to stdin of cmd2 via a pipe (cmd1 | cmd2).
 * Returns cmd2's exit status, or -1 on error.
 */
static int run_pipeline(char *const cmd1[], char *const cmd2[]) {
    /* TODO: implement */
}

int main(void) {
    /* Equivalent to: ls /usr/bin | wc -l */
    char *ls_args[] = { "ls", "/usr/bin", NULL };
    char *wc_args[] = { "wc", "-l",       NULL };
    int rc = run_pipeline(ls_args, wc_args);
    printf("pipeline exit: %d\n", rc);
    return 0;
}
