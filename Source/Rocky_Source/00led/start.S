.global	_start
.global main

_start:
	bl		main
	
loop:
	b		loop
	
	.end
	