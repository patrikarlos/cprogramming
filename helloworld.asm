;  build: nasm -f elf64 -F stabs name.asm
;  link:  ld -o name name.o

BITS 64

SECTION .data

Hello:		db 72,"ello world!",35,10
len_Hello:	equ $-Hello

SECTION .text

global _start

_start:
		mov rax,1			; write syscall (x86_64)
		mov rdi,1			; fd = stdout
		mov rsi,Hello		; *buf = Hello
		mov rdx,len_Hello	; count = len_Hello
		syscall

		mov rax,60			; exit syscall (x86_64)
		mov rdi,0			; status = 0 (exit normally)
		syscall
