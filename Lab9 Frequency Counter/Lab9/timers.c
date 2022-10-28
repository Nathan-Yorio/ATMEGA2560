/*
 * stepper.c
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

//initialize timer
void init_timer0(void)
{
	TCNT0 = 0;     //initially off
	OCR0A = 16;    //1 ms
	TCCR0A = 0x00; //initially off
	TCCR0B = 0x00; //initially off
}
//timer itself
void custom_timer(void)
{
	TCCR0B = 0x05;   				   // 1024 pre-scaler
	while((TIFR0 & (1<<OCF0A)) == 0);  //wait until overflow
	TCCR0B = 0;      				   //disable timer
	TIFR0 = TIFR0 | (1<<OCF0A);        //clear overflow
	TCNT0 = 0;       				   //end	
};

//timer loops to whatever you want
void timer(uint16_t time) //increments of 1000 for each second
{
	for(uint16_t i = 0; i < time; i++)
	{
		custom_timer();
	}	
}
