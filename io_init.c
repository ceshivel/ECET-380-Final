#include "io_init.h"

void io_init(void)
{
	//seconds output
	DDRA = 0xFF;
	PORTA = 0x00;

	//10 seconds output
	DDRC = 0xFF;
	PORTC = 0x00;

	//pb input
	DDRD = 0x00;

	//minutes output
	DDRL = 0xFF;
	PORTL = 0x00;

	//10minutes output
	DDRK = 0xFF;
	PORTK = 0x00;
}