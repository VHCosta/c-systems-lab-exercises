# dot.s — dot_product(const int *a, const int *b, int n)
# System V AMD64 ABI: rdi=a, rsi=b, edx=n, return in rax
# Compile: gcc -c dot.s -o dot.o

	.globl dot_product
	.type  dot_product, @function
dot_product:
	xorl    %eax, %eax          # sum = 0
	testl   %edx, %edx          # if n <= 0
	jle     .Ldot_done          # return 0

	pushq   %rbx                # save callee-saved rbx
	xorl    %ecx, %ecx          # i = 0

.Ldot_loop:
	movl    (%rdi,%rcx,4), %ebx # ebx = a[i]
	imull   (%rsi,%rcx,4), %ebx # ebx *= b[i]
	addl    %ebx, %eax          # sum += ebx
	incl    %ecx                # i++
	cmpl    %edx, %ecx          # if i < n
	jl      .Ldot_loop

	popq    %rbx                # restore callee-saved rbx
.Ldot_done:
	ret
	.size dot_product, .-dot_product
