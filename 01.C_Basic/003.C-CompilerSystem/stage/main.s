	.file	"main.c"
	.text
	.data
	.align 4
	.type	sA, @object
	.size	sA, 4
sA:
	.long	10
	.text
	.type	eventHandler, @function
eventHandler:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	eventHandler, .-eventHandler
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	testStatic1
	.type	testStatic1, @function
testStatic1:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	sA1.2845(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, sA1.2845(%rip)
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	testStatic1, .-testStatic1
	.globl	testStatic2
	.type	testStatic2, @function
testStatic2:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	sA1.2848(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, sA1.2848(%rip)
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	testStatic2, .-testStatic2
	.section	.rodata
.LC1:
	.string	"%d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	eventHandler(%rip), %rdi
	call	setcb@PLT
	movl	$6, %esi
	leaq	sA(%rip), %rdi
	call	callcb@PLT
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -12(%rbp)
	jmp	.L6
.L7:
	movl	$0, %eax
	call	testStatic1
	addl	$1, -12(%rbp)
.L6:
	cmpl	$9, -12(%rbp)
	jle	.L7
	movl	$0, -8(%rbp)
	jmp	.L8
.L9:
	movl	$0, %eax
	call	testStatic1
	addl	$1, -8(%rbp)
.L8:
	cmpl	$9, -8(%rbp)
	jle	.L9
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.local	sA1.2845
	.comm	sA1.2845,4,4
	.data
	.align 4
	.type	sA1.2848, @object
	.size	sA1.2848, 4
sA1.2848:
	.long	10
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
