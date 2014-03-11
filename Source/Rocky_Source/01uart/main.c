#include "led.h"
#include "cpu_io.h"
#include "uart.h"

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
	uart_init();

	myputc('1');
	myputc('2');
	myputc('3');
	myputc('4');
	myputc('5');
	myputc('6');
	
	myputs("hello world!\n");
	
	led_test();

	return 0;
}

