#include "led.h"
#include "cpu_io.h"

static void mydelay()
{
	volatile unsigned int i = 0xfffff;

	while(i--);
}

void led_test()
{
	led_init();

	while(1){
		led_blink(1);
		mydelay();
		led_blink(0);
		mydelay();
	}
	
}

int main()
{
	led_test();

	return 0;
}

