#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define NUM_WRITERS 4
#define LINES_EACH  100

/*
 * O_APPEND atomicity -- POSIX.1-2017 section 2.9.7:
 *   "If the O_APPEND flag of the file status flags is set, the file
 *    offset shall be set to the end of the file prior to each write
 *    and no intervening file modification operation shall occur
 *    between changing the file offset and the write operation."
 *
 * The kernel implements this as an atomic seek+write under a lock.
 * No process can interleave its write between another process's
 * seek and write. Each write is placed atomically at the end.
 *
 * PIPE_BUF atomicity guarantee (Linux: PIPE_BUF = 4096 bytes):
 *   For writes of up to PIPE_BUF bytes to a file opened with O_APPEND,
 *   the kernel guarantees the bytes are not interleaved with other
 *   processes' writes. Lines shorter than 4096 bytes are safe.
 *
 * What breaks with lseek + write (WITHOUT O_APPEND):
 *   Process A:  lseek(fd, 0, SEEK_END)  -> offset = 1000
 *   Process B:  lseek(fd, 0, SEEK_END)  -> offset = 1000 (same!)
 *   Process A:  write(fd, lineA, 50)    -> writes at offset 1000
 *   Process B:  write(fd, lineB, 60)    -> OVERWRITES at offset 1000
 *   Result: lineA is lost; lineB partially overlaps.
 */
static int log_append(const char *path, const char *msg) {
    /* TODO: implement */
}

int main(void) {
    const char *log_path = "/tmp/ex7_4_log.txt";
    unlink(log_path);   /* start fresh */

    for (int i = 0; i < NUM_WRITERS; i++) {
        pid_t pid = fork();
        if (pid < 0) { perror("fork"); return 1; }
        if (pid == 0) {
            for (int j = 0; j < LINES_EACH; j++) {
                char buf[128];
                int len = snprintf(buf, sizeof(buf),
                                   "[pid %d] line %d\n", (int)getpid(), j);
                (void)len;   /* len < PIPE_BUF, so write is atomic */
                if (log_append(log_path, buf) < 0) {
                    perror("log_append");
                    _exit(1);
                }
            }
            _exit(0);
        }
    }

    for (int i = 0; i < NUM_WRITERS; i++) wait(NULL);

    /* Count lines -- each should be complete, none interleaved */
    FILE *f = fopen(log_path, "r");
    if (!f) { perror("fopen"); return 1; }
    int lines = 0;
    char buf[256];
    while (fgets(buf, sizeof(buf), f)) lines++;
    fclose(f);

    int expected = NUM_WRITERS * LINES_EACH;
    printf("Expected %d lines, got %d -- %s\n",
           expected, lines,
           lines == expected ? "PASS" : "FAIL (interleaving detected)");
    return lines == expected ? 0 : 1;
}
