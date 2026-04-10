#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void) {
    char *buf = malloc(256);
    snprintf(buf, 256, "sqrt(2) = %.10f", sqrt(2.0));
    printf("%s\n", buf);
    printf("time = %ld\n", (long)time(NULL));
    free(buf);
    return 0;
}
