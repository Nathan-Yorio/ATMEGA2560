/*
 * timers.c
 *
 * Created: 1/28/2018 8:47:39 PM
 *  Author: Nathan Yorio
 *
 * Purpose:
 * This c file contains functions that control
 * the custom timers
 */ 

#define F_CPU 16000000UL
#include <avr/io.h> //standard io
#include <avr/interrupt.h>
#include "timers.h"

//initialize timer
void init_timer0(void)
{
	TCCR0A = 0x00; //initially off
	TCCR0B = 0x05; //prescaler
	TCNT0 = 0;	   //off
	OCR0A = 16;    //1 ms
	TIMSK0 = (1<<OCIE0A);// Enable input capture interrupt
}

//interrupt
ISR(TIMER0_COMPA_vect)
{
	TCNT0 = 0;
	timer_tick++; //increase timer tick
}

