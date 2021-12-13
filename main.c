#include <avr/io.h>
#define F_CPU 16000000UL
#include "interrupt.h"
#include "io_init.h"
#include "timer.h"



int main(void)
{
	//initialization functions

	io_init();
	init_timer0();
	timer_delay_init();
	sei();

	
	mode = 0;
	test();

	while(1)
	{
		mode_select(); //use isr to toggle modes
		switch(mode)
		{
			case 0:
			{
				//PORTA = number[0];
				//do nothing
			}
			//start timer
			case 1:
			{
				//PORTA = number[1]; //troubleshooting test code
				stopwatch();
			}
			break;
			//stop timer
			case 2:
			{
				//PORTA = number[3]; //troubleshooting test code
				//stop timer
				break;
			}

			//reset timer
			case 3:
			{
				//timer value reset to 0
				reset();
				break;
			}
			
			break;
		}
	}


	

}

