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
	test(); //make sure all seven segments are working

	while(1)
	{
		mode_select(); //use isr to toggle modes
		switch(mode)
		{
			case 0:
			{
				//do nothing
			}
			//start timer

			case 1:
			{
				stopwatch(); //run stopwatch function
			}
			break;
			//stop timer

			case 2:
			{
				break; //stop timer
			}

			//reset timer
			case 3:
			{
				reset(); //reset 7 segments back to 0
				break;
			}
			
			break;
		}
	}


	

}

