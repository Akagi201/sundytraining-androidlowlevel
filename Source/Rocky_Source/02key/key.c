#include "cpu_io.h"
#include "gpio.h"
#include "key.h"
#include "uart.h"

extern void asm_irq(void);

void irq_init(void){

	// 方法一, pc -> 中断处理函数
	//unsigned int tmp;
	//tmp = *asm_irq;
	//pEXECPTION_IRQ = tmp;

	// 方法二, 直接把地址给CPU来执行(LR的方式)
	pEXECPTION_IRQ = (unsigned int)asm_irq;
}

void irq_c_handler(void){
	void (*handler) (void) = 0x0;

	myputs("in irq_c_handler\n");

	handler = (void (*)(void))VIC0ADDRESS;

	if (handler){
		handler();
	}
}

void key1_handler(void){

	myputs("key1 down!!!\n");

	EXT_INT_2_PEND |= (0x1<<0);

	VIC0ADDRESS = 0x0;
}

void key_init(void){

	struct s5pv210_gph_bank *gph2_base = (struct s5pv210_gph_bank *)s5pv210_gph_bank;
	unsigned int var;

	/* 外部引脚进行功能选择, EINT */
	var = readl(&gph2_base->con);
	var |= (0xf << 0);
	writel(var, &gph2_base->con);

	/* 配置EINT功能 */
	EXT_INT_2_CON &= ~(0x7 << 0);
	EXT_INT_2_CON |= (0x2 << 0);

	EXT_INT_2_MASK &= ~(0x1 << 0);

	/* 配置主中断控制寄存器 */
	VIC0INTENABLE |= (0x1 << 16);
	VIC0VECTADDR16 = (unsigned int)key1_handler;
}

