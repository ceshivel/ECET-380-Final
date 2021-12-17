#ifndef INIT_TIMER_H_
#define INIT_TIMER_H_


#include <avr/io.h>
#define F_CPU 16000000UL

void init_timer0(void);

uint8_t number[10];

/*
* delay_1ms is used as the base code for custom delay function with the timer
* delay_ms calls delay_1ms an amount of time to achieve that many miliseconds of delay
*
*/

//function prototypes
void delay_1ms();
void delay_ms(uint16_t sec);
void test(void);
void stopwatch(void);
void reset(void);

#endif /* INIT_TIMER_H_ */