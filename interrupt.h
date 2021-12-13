#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#define F_CPU 16000000UL

//include files
#include <avr/io.h>
#include <avr/interrupt.h>

//global variables
volatile uint16_t Ticks;
volatile uint16_t Tick2;
volatile uint8_t mode;

//function prototypes
void mode_select(void);
void timer_delay_init(void);

#endif /* INTERRUPT_H_ */