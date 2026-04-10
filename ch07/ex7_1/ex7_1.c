#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#define FILE_SIZE (1024 * 1024)   /* 1 MB */
#define CHUNK     4

static double elapsed_ms(struct timespec a, struct timespec b) {
    /* TODO: implement */
}

static void bench_fwrite(const char *path, const char *buf) {
    /* TODO: implement */
}

static void bench_write(const char *path, const char *buf) {
    /* TODO: implement */
}

int main(void) {
    char *buf = malloc(FILE_SIZE);
    if (!buf) { perror("malloc"); return 1; }
    memset(buf, 'A', FILE_SIZE);

    struct timespec t0, t1;

    clock_gettime(CLOCK_MONOTONIC, &t0);
    bench_fwrite("/tmp/ex7_1_buffered.bin", buf);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("fwrite (4-byte chunks): %.2f ms\n", elapsed_ms(t0, t1));

    clock_gettime(CLOCK_MONOTONIC, &t0);
    bench_write("/tmp/ex7_1_direct.bin", buf);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("write  (4-byte chunks): %.2f ms\n", elapsed_ms(t0, t1));

    /*
     * ANALYSIS
     *
     * fwrite path:
     *   262,144 calls to fwrite(buf+i, 1, 4, f)
     *   stdio accumulates into an 8 KB (BUFSIZ) buffer
     *   -> approximately 128 write() syscalls (1MB / 8KB)
     *   strace -c will show ~128 write calls
     *
     * write path:
     *   262,144 calls to write(fd, buf+i, 4)
     *   each call is a kernel entry (~100-500 ns on modern hardware)
     *   strace -c will show 262,144 write calls
     *
     * Typical results:
     *   fwrite:  ~2-5 ms    (dominated by memcpy into buffer)
     *   write:  ~50-200 ms  (dominated by syscall overhead)
     *
     * Per-syscall overhead ~= (write_time - fwrite_time) / 262144
     * e.g., (150ms - 3ms) / 262144 ~= 560 ns per syscall
     *
     * Lesson: stdio buffering is not optional overhead -- it is the
     * mechanism that makes file I/O practical.
     */
    printf("\nVerify: strace -c ./ex7_1 2>&1 | grep -E 'write|calls'\n");

    free(buf);
    return 0;
}
