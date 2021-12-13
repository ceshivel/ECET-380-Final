#include "interrupt.h"
#define F_CPU 16000000UL	//Defines CPU speed
#include <avr/io.h>

//This is the old Timer Code modified for interrupt
void timer_delay_init(void)
{
	TCNT0 = 0;
	TCCR0A = 0;
	TCCR0B = 0; //Sets to 0x04 when timer starts
	OCR0A = 62; //OCR0A is equal to num value
}


//interrupt for push button to change modes
ISR (TIMER0_OVF_vect) //timer 0 overflow timer
{
	TCNT0 = 178; //begin counting at 178
	Ticks++; // count ticks up every time
}

//selecting mode
void mode_select(void)
{
	EICRA |= (1 << ISC11) | (1 << ISC10); // the rising edge of INTn generates asynchronously an interrupt reques
	EIMSK |= (1 << INT1); //enable interrupt pin 1
}

//cycle between 3 values each time mode is pressed
ISR(INT1_vect)
{
	mode += 1; //add one to mode every time interrupt is triggered
	if(mode > 3)
	{
		mode = 1; // if mode goes above 3, reset to 1
	}
}