	.global absum
	.text
	
absum:	
	xordpd %xmm0, %xmm0
	addsd (%rdi),%xmm0
	addsd (%rsi),%xmm0
	ret

