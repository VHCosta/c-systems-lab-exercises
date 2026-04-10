#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
    const char *path = "/tmp/ex7_3_shared.txt";

    /* Part 1: shared file offset across fork */

    /* TODO: open path for writing with O_CREAT | O_TRUNC */
    /* TODO: fork */
    /* TODO: child: write "CHILD" (5 bytes), close fd, _exit(0) */
    /* TODO: parent: waitpid, then lseek(fd, 0, SEEK_CUR) and print the offset */
    /* TODO: parent: write "PRNT" and close */

    /* TODO: read the file back and print its contents */
    /* Expected: "CHILDPRNT" */

    /* Part 2: O_CLOEXEC */

    /* TODO: open /dev/null with O_RDONLY | O_CLOEXEC */
    /* TODO: print an explanation of what O_CLOEXEC does */
    /* TODO: close fd2 */

    return 0;
}
