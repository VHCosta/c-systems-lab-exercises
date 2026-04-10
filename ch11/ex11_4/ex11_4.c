/* ex11_4.c — Disassembly archaeology: the mystery function is max(a, b)
 *
 * Assembly to analyse:
 *   mystery:
 *       movl    %edi, %eax      # (1) copy arg1 to return register (tentative return = a)
 *       cmpl    %esi, %edi      # (2) compare a with b (sets flags: a - b)
 *       jge     .Ldone          # (3) if a >= b, jump to return (rax already holds a)
 *       movl    %esi, %eax      # (4) a < b: overwrite return value with b
 *   .Ldone:
 *       ret                     # (5) return whatever is in eax
 *
 * ABI annotation:
 *   - edi = first integer argument (a)   [System V AMD64: arg1 in rdi/edi]
 *   - esi = second integer argument (b)  [System V AMD64: arg2 in rsi/esi]
 *   - eax = return value register        [System V AMD64: return in rax/eax]
 *   - No callee-saved registers used, no stack frame needed
 *
 * Reconstructed C source:
 *   int mystery(int a, int b) { return a >= b ? a : b; }
 *   i.e., max(int a, int b)
 *
 * gcc -Wall -Wextra -Werror -std=c11 -o ex11_4 ex11_4.c && ./ex11_4
 */
#include <stdio.h>
#include <assert.h>

/* The reconstructed function */
int mystery(int a, int b) {
    /* TODO: implement */
}

int main(void) {
    assert(mystery(3,  5) == 5);
    assert(mystery(7,  2) == 7);
    assert(mystery(-1, 0) == 0);
    assert(mystery(4,  4) == 4);
    assert(mystery(-5, -3) == -3);
    printf("mystery(a, b) = max(a, b)\n");
    printf("All assertions passed.\n");
    return 0;
}
