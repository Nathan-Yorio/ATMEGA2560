/*
 * timers.h
 *
 * Created: 1/28/2018 6:38:55 PM
 *  Author: Nathan Yorio
 *
 * Purpose:
 * This is all for custom timers
 */ 
#include <avr/io.h>

//Function prototypes

void init_timer0(void);
void timer(uint16_t time);

//PINS
#define START (~PINA & 0x01) //PB1
#define EIGHT (~PINA & 0x02) //PB2
#define TEN (~PINA & 0x04) //PB3





