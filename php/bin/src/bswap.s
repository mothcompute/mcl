section .text

global bswap32
global bswap64
global to_little_endian32
global to_little_endian64
global to_big_endian32
global to_big_endian64

to_big_endian32:
bswap32:
	mov eax, edi
	bswap eax
	ret

to_big_endian64:
bswap64:
	mov rax, rdi
	bswap rax
	ret

to_little_endian32:
to_little_endian64:
	mov rax, rdi
