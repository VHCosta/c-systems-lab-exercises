/* ex6_3.c — Portable platform detection
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex6_3 ex6_3.c && ./ex6_3
 */
#include "platform.h"
#include <stdio.h>

/* Verify at compile time that our platform macros match sizeof(void*) */
#if defined(PLATFORM_64BIT)
_Static_assert(sizeof(void *) == 8,
               "PLATFORM_64BIT defined but sizeof(void*) != 8");
#elif defined(PLATFORM_32BIT)
_Static_assert(sizeof(void *) == 4,
               "PLATFORM_32BIT defined but sizeof(void*) != 4");
#endif

int main(void) {
    printf("Platform:     %s\n", PLATFORM_NAME);
    printf("Pointer size: %zu bytes (%d-bit)\n",
           sizeof(void *), (int)(sizeof(void *) * 8));

#if defined(PLATFORM_64BIT)
    printf("Width:        64-bit\n");
#else
    printf("Width:        32-bit\n");
#endif

#if defined(PLATFORM_LINUX)
    printf("OS detail:    __linux__ detected\n");
#elif defined(PLATFORM_MACOS)
    printf("OS detail:    __APPLE__ detected\n");
#elif defined(PLATFORM_WINDOWS)
    printf("OS detail:    _WIN32/_WIN64 detected\n");
#endif

    return 0;
}
