/*
 * dc.c
 *
 * Created: 2/18/2018 12:05:44 PM
 * Author: Nathan Yorio
 * Purpose:
 * This controls the dc motor with PWM
 */ 
#define F_CPU 16000000UL
#include <avr/io.h> //standard io
#include "timers.h"

//DC motor control functions
void dc_init(void)
{
	TCCR3A = 0x83; //Clear OC3A on compare match (8), fast PWM (1)
	TCCR3B = 0x0C; //1024 Top Value
}

//Fast PWM Function For DC motor
void fast_PWM(uint8_t duty_cycle)
{
	uint16_t num;  								//some value
	TCCR3A |= (1<<COM3A1);  					//Enable this part
	num = ((uint32_t) duty_cycle * 1024)/100;   //calculate the number
	OCR3A = num; 								//output the number to PORTE.6
	//OCR3A  = 614;
	TCCR3B |= (1<<CS32); 						//Actually compare the OCR to the CS
}

//RAMP THAT MOTOR UP AND BRING IT BACK DOWN
void PUMP_IT_UP(void)
{
		uint16_t num = 10; 				//some number
		for(uint8_t i = 0; i < 8; i++)  //loop till you get to 90
		{
			num += 10; 		//add
			fast_PWM(num);  //output
			timer(1000);    //wait
		}
		fast_PWM(num); //hold output
		timer(5000);   //wait
		for(uint8_t i = 15; i > 0; i--)//loop down from 90 to 0
		{
			num -= 6; 		// 90/15
			fast_PWM(num);
			timer(1000);
		}	
}