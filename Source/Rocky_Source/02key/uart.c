#include "cpu_io.h"
#include "uart.h"
#include "gpio.h"

void uart_init()
{
	struct s5pv210_gpio *gpio_base = (struct s5pv210_gpio *)S5PV210_GPIO_BASE;
	struct s5pv2xx_uart *uart_base = (struct s5pv2xx_uart *)S5PV210_UART_BASE;
	unsigned int var;

	/*根据引脚，选择功能*/
	var = readl(&gpio_base->gpio_a0.con);
	var &= ~(0xff<<0);
	var |= (0x22<<0);
	writel(var,&gpio_base->gpio_a0.con);

	/*对串口控制器进行配置*/
	__REG(&uart_base->ulcon) = 0x3;		/*8bit 1stop non-even*/ 
	__REG(&uart_base->ucon) = 0x5;		/*enable recv send*/
	__REG(&uart_base->ubrdiv) = 35;
	__REG(&uart_base->udivslot) = 0x80;
}

void myputc(char c)
{
	struct s5pv2xx_uart *uart_base = (struct s5pv2xx_uart *)S5PV210_UART_BASE;

	if(c == '\n'){
		while( !(__REG(&uart_base->utrstat)&(0x1<<2)) );
		__REG(&uart_base->utxh) = '\r';
		
	}
	
	/*判断发送缓存区是否为空*/
	while( !(__REG(&uart_base->utrstat)&(0x1<<2)) );

	/*再发送数据*/
	__REG(&uart_base->utxh) = c;

	return;
}

void myputs(const char *str)
{
	while(*str){
		myputc(*str);
		str++;
	}
}
