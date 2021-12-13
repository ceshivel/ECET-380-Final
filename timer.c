#include "Timer.h"

uint16_t seconds = 0;
uint16_t tenSeconds = 0;
uint16_t minutes = 0;
uint16_t tenMinutes = 0;
uint8_t number[10] = {0x40, 0xF9, 0x12, 0x30, 0x29, 0x24, 0x04, 0x71, 0x00, 0x20};

//initializes timer 0 as a classic timer
//timer 0 used for delay functions
void init_timer0(void)
{
	TCNT0 = 194; //0.001s * (16,000,000 / 256)
	TCCR0A = 0x00;
	TCCR0B = 0x00;
}

//timer one used for motor pwm
void init_timer1(void)
{
	//9 bit fast PWM, clear on match
	TCCR1A = (1 << WGM11) | (1 << COM1A1);
	
	// 16000000 % 3900Hz % 512 = 8
	TCCR1B = (1 << WGM12) | (1 << CS11); //prescaler of 8
}

//timer three used for procedure three LED
//CTC used for ease of 50% duty cycle
void init_timer3(void)
{
	//set CTC mode, toggle on compare match
	TCCR3A = (1 << COM3A0);

	//set prescaler of 256 in consideration of 16 bit timer
	TCCR3B = (1 << CS32) | (1 << WGM32);
}

//function used to delay 1ms
void delay_1ms(void)
{
	//start the count
	TCCR0B = 1 << CS02;
	
	//wait while the count stops
	while((TIFR0 & (1<<TOV0)) == 0);
	
	TCCR0B = 0;
	TIFR0 |= (1<<TOV0);
	
	//reset TCNT0;
	TCNT0 = 194;
}

//calls delay_1ms a certain amount of time to achieve a specific ms of delay
void delay_ms(uint16_t sec)
{
	for(int i = 0; i < sec; i++)
	{
		delay_1ms();
	}
}

void stopwatch(void)
{
	PORTA = number[seconds % 10];
	delay_ms(1000);
	seconds++;
	if(seconds == 10)
	{
		seconds = 0;
		tenSeconds++;
		PORTC = number[tenSeconds % 6];
		if((tenSeconds == 6))
		{
			tenSeconds = 0;
			minutes += 1;
			PORTL = number[minutes % 10];
			if(minutes == 10)
			{
				minutes = 0;
				tenMinutes += 1;
				PORTK = number[tenMinutes % 6];
			}
		}
	}


}

void reset(void)
{
	PORTA = 0x40;
	PORTC = 0x40;
	PORTL = 0x40;
	PORTK = 0x40;
	seconds = 0;
	tenSeconds = 0;
	minutes = 0;
	tenMinutes = 0;
}

void test(void)
{
	uint8_t testCount = 0;
	for (int f = 0; f < 10; f++)
	{
		PORTA = number[testCount];
		PORTC = number[testCount];
		PORTL = number[testCount];
		PORTK = number[testCount];
		delay_ms(100);
		testCount++;
	}
	PORTA = 0x40;
	PORTC = 0x40;
	PORTL = 0x40;
	PORTK = 0x40;
}