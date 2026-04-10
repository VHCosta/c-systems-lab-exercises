#define _POSIX_C_SOURCE 200809L
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 65536

/*
 * Write helper: retries on EINTR and handles partial writes.
 * Returns 0 on success, -1 on error (errno set).
 *
 * Why partial writes matter here:
 * On a regular file they almost never occur. On stdout redirected to
 * a pipe (e.g., ./mycat bigfile | head), the pipe buffer fills and
 * write() may transfer only some bytes. Without the loop, we silently
 * truncate output.
 */
static int write_all(int fd, const char *buf, ssize_t n) {
    /* TODO: implement */
}

/* Write a string to stderr without stdio (safe to call after errors) */
static void err_write(const char *msg) {
    /* TODO: implement */
}

static int cat_fd(int fd) {
    /* TODO: implement */
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        /* No arguments: cat stdin */
        return cat_fd(STDIN_FILENO) ? 1 : 0;
    }

    int status = 0;
    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd < 0) {
            /* Report error and continue -- matches GNU cat behaviour */
            err_write("cat: cannot open: ");
            err_write(argv[i]);
            err_write(": ");
            err_write(strerror(errno));
            err_write("\n");
            status = 1;
            continue;
        }
        if (cat_fd(fd) < 0) status = 1;
        close(fd);
    }
    return status;
}
