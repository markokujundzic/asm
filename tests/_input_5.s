.global _start

.section .text:
_start: 
	  jmp *(%r1)
	  call *_start(%pc)
.section .rodata:
	.skip 4
	jne *_start(%pc)
	   
