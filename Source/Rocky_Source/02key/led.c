#include "gpio.h"
#include "led.h"
#include "cpu_io.h"


void led_init(void)
{
	struct s5pv210_gpio *gpio_base = (struct s5pv210_gpio *)S5PV210_GPIO_BASE;
	unsigned int var;

	var = __REG(&gpio_base->gpio_j2.con);
	var &= ~(0xffff<<0);
	var |= (0x1111<<0);
	writel(var,&gpio_base->gpio_j2.con);
}

void led_blink(int status)
{
	struct s5pv210_gpio *gpio_base = (struct s5pv210_gpio *)S5PV210_GPIO_BASE;
	unsigned int var;

	if(status){
		var = __REG(&gpio_base->gpio_j2.dat);
		var &= ~0xf;
		writel(var,&gpio_base->gpio_j2.dat);
	}
	else{
		var = __REG(&gpio_base->gpio_j2.dat);
		var |= 0xf;
		writel(var,&gpio_base->gpio_j2.dat);
	}
}
