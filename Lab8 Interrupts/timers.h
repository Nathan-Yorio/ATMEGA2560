/*
 * timers.h
 *
 * Created: 1/28/2018 6:38:55 PM
 *  Author: Nathan Yorio
 *
 * Purpose:
 * This is all for custom timers
 */ 

#ifndef TIMERS_H_
#define TIMERS_H_

//custom timer stuff
void custom_timer(void);
void init_timer0(void);
void timer(uint16_t time);

//PINS
#define START (~PINA & 0x01) //PB1
#define EIGHT (~PINA & 0x02) //PB2
#define TEN (~PINA & 0x04) //PB3

//GLobal Variables
volatile uint16_t timer_tick;



#endif