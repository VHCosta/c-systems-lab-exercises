/* ex3_2.c — Bounds-checked string copy
 * gcc -Wall -Wextra -Werror -std=c11 -o ex3_2 ex3_2.c && ./ex3_2
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

/* Copy at most max-1 bytes from src to dst; always null-terminate dst.
 * Writes nothing if max == 0. */
void str_ncopy(char *dst, const char *src, size_t max) {
    /* TODO: implement */
}

int main(void) {
    char buf[8];

    /* Normal copy — src shorter than max */
    str_ncopy(buf, "hello", sizeof(buf));
    assert(strcmp(buf, "hello") == 0);

    /* Truncation — src longer than max-1 */
    str_ncopy(buf, "hello, world!", sizeof(buf));
    assert(buf[sizeof(buf) - 1] == '\0');           /* always null-terminated */
    assert(strlen(buf) == sizeof(buf) - 1);          /* 7 bytes of content */

    /* max == 0 — must write nothing; guard with a canary byte */
    char guarded[4];
    guarded[0] = (char)0xAA;
    str_ncopy(guarded, "hi", 0);
    assert((unsigned char)guarded[0] == 0xAA);      /* canary intact */

    /* max == 1 — only the null terminator fits */
    char one[1];
    str_ncopy(one, "hi", 1);
    assert(one[0] == '\0');

    /* Empty source */
    str_ncopy(buf, "", sizeof(buf));
    assert(buf[0] == '\0');

    printf("All assertions passed.\n");
    return 0;
}
