/*========================================
freq_count.c

Created: 3/18/2018 7:51:38 PM
Author: Nathan Yorio

Purpose: Functions to Find Frequency
 =========================================*/ 

#define F_CPU 16000000UL
#include <avr/io.h> //standard io
#include <avr/interrupt.h>
#include "freq_count.h"

//initialize timer
void init_timer4(void)
{
	TCCR4A = 0x00; //initially off
	TCCR4B = (1<<ICNC4)|(1<<ICES4)|(1<<CS41); //pre-scaler 8, 2mhz, normal, noise cancel
	TCCR4C = 0x00; //no forced compare output
	TIMSK4 = (1<<ICIE4);// Enable input capture interrupt
}

//interrupt
ISR(TIMER4_CAPT_vect)
{
	//calculating duration
	counts_new = ICR4;
	duration = counts_new - counts_prev; 	counts_prev = counts_new;
}

uint16_t freq_detect(void)
{
	uint16_t freq;
	//formula to convert to correct frequency
	freq = (uint16_t)(16000000UL / ((uint32_t)duration*8));	
	return freq; //output frequency at end of function
}