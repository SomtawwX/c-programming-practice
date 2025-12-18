	.file	"atof_extended.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "%s => %g\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movabsq	$3271079202584212017, %rax
	movq	%rax, -10(%rbp)
	movw	$54, -2(%rbp)
	movl	$1160916529, -16(%rbp)
	movw	$51, -12(%rbp)
	movabsq	$14121462519444525, %rax
	movq	%rax, -24(%rbp)
	leaq	-10(%rbp), %rax
	movq	%rax, %rcx
	call	atof
	movapd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movq	%xmm1, %rdx
	leaq	-10(%rbp), %rax
	movapd	%xmm0, %xmm2
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	atof
	movapd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movq	%xmm1, %rdx
	leaq	-16(%rbp), %rax
	movapd	%xmm0, %xmm2
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	leaq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	atof
	movapd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movq	%xmm1, %rdx
	leaq	-24(%rbp), %rax
	movapd	%xmm0, %xmm2
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	atof
	.def	atof;	.scl	2;	.type	32;	.endef
	.seh_proc	atof
atof:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L4
.L5:
	addl	$1, -20(%rbp)
.L4:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	je	.L5
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	jne	.L6
	movl	$-1, %eax
	jmp	.L7
.L6:
	movl	$1, %eax
.L7:
	movl	%eax, -28(%rbp)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	je	.L8
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$43, %al
	jne	.L9
.L8:
	addl	$1, -20(%rbp)
.L9:
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	jmp	.L10
.L11:
	movsd	-8(%rbp), %xmm1
	movsd	.LC2(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addl	$1, -20(%rbp)
.L10:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L11
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$46, %al
	jne	.L12
	addl	$1, -20(%rbp)
.L12:
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	jmp	.L13
.L14:
	movsd	-8(%rbp), %xmm1
	movsd	.LC2(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-16(%rbp), %xmm1
	movsd	.LC2(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	addl	$1, -20(%rbp)
.L13:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L14
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$101, %al
	je	.L15
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$69, %al
	jne	.L16
.L15:
	addl	$1, -20(%rbp)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	jne	.L17
	movl	$-1, %eax
	jmp	.L18
.L17:
	movl	$1, %eax
.L18:
	movl	%eax, -32(%rbp)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$43, %al
	je	.L19
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	jne	.L20
.L19:
	addl	$1, -20(%rbp)
.L20:
	movl	$0, -24(%rbp)
	jmp	.L21
.L22:
	movl	-24(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %ecx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	addl	%ecx, %eax
	movl	%eax, -24(%rbp)
	addl	$1, -20(%rbp)
.L21:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L22
	movl	-32(%rbp), %eax
	imull	-24(%rbp), %eax
	movl	%eax, %edx
	movq	.LC2(%rip), %rax
	movq	%rax, %xmm0
	call	Mypow
	movsd	-8(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
.L16:
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-28(%rbp), %xmm0
	mulsd	-8(%rbp), %xmm0
	divsd	-16(%rbp), %xmm0
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Mypow
	.def	Mypow;	.scl	2;	.type	32;	.endef
	.seh_proc	Mypow
Mypow:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movl	%edx, 24(%rbp)
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %edx
	negl	%edx
	cmovns	%edx, %eax
	movl	%eax, -16(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L25
.L26:
	movsd	-8(%rbp), %xmm0
	mulsd	16(%rbp), %xmm0
	movsd	%xmm0, -8(%rbp)
	addl	$1, -12(%rbp)
.L25:
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.L26
	cmpl	$0, 24(%rbp)
	jns	.L27
	movsd	.LC3(%rip), %xmm0
	divsd	-8(%rbp), %xmm0
	jmp	.L29
.L27:
	movsd	-8(%rbp), %xmm0
.L29:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC2:
	.long	0
	.long	1076101120
	.align 8
.LC3:
	.long	0
	.long	1072693248
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
