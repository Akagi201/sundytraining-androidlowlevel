.global	_start
.global main
.global irq_c_handler
.global asm_irq

_start:
	bl		main
	
loop:
	b		loop

irq_handler:
	stmfd sp!, {r0-r3, lr}
	bl irq_c_handler
	ldmfdd sp!, {r0-r3, lr}
	subs pc, lr, #4

asm_irq:
	b irq_handler

	.end
	