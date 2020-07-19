.extern i

.section .data:
.equ j, i + 0x1
.equ k, 13

.section .data:
mov $j, k(%r6)
