/*
 * dc.c
 *
 * Created: 2/18/2018 12:05:44 PM
 * Author : Nathan Yorio
 * Purpose:
 * This controls the dc motor with PWM
 */ 
#define F_CPU 16000000UL
#include <avr/io.h> //standard io
#include <avr/interrupt.h>
#include "USART.h"
//DC motor control functions


void dc_init(void)
{
	//MOTOR A
	TCCR3A = 0x80; //Clear OC3A on compare match (8), fast PWM (14)
	TCCR3A |= (1<<WGM31);
	TCCR3B |= (1<<WGM33)|(1<<WGM32)|(1<<CS32); //256 prescaler, frequency change thing pwm
	
	////MOTOR B
	//TCCR5A = 0x80; //Clear OC3A on compare match (8), fast PWM (14)
	//TCCR5A |= (1<<WGM31);
	//TCCR5B |= (1<<WGM33)|(1<<WGM32)|(1<<CS32); //256 prescaler, frequency change thing pwm
	
	//MOTOR C
	TCCR1A = 0x80; //Clear OC3A on compare match (8), fast PWM (14)
	TCCR1A |= (1<<WGM31);
	TCCR1B |= (1<<WGM33)|(1<<WGM32)|(1<<CS32); //256 prescaler, frequency change thing pwm
}

//Fast PWM Function For DC motor
void fast_PWM(char motor, uint8_t duty_cycle, uint32_t freq)
{
	uint16_t Freq_change;
	if (motor == 'A')
	{
		uint16_t num;  								//some value
		TCCR3A |= (1<<COM3A1);  					//Enable this part
		//how to change frequency????
		Freq_change = (F_CPU/(freq * 256)) - 1;
		ICR3 = Freq_change;
		
		num = ((uint32_t) duty_cycle * Freq_change)/100;   //calculate the number
		OCR3A = num; 		//output the number to PORTE.6

		TCCR3B |= (1<<CS32); 						//Actually compare the OCR to the CS
	}
	//if (motor == 'B')
	//{
		//uint16_t num;  								//some value
		//TCCR5A |= (1<<COM5A1);  					//Enable this part
		////how to change frequency????
		//Freq_change = (F_CPU/(freq * 256)) - 1;
		//ICR5 = Freq_change;
		//
		//num = ((uint32_t) duty_cycle * Freq_change)/100;   //calculate the number
		//OCR3C = num; 		//output the number to PORTE.6
//
		//TCCR5B |= (1<<CS42); 						//Actually compare the OCR to the CS
	//}
	if (motor == 'C')
	{
		uint16_t num;  								//some value
		TCCR1A |= (1<<COM1A1);  					//Enable this part
		//how to change frequency????
		Freq_change = (F_CPU/(freq * 256)) - 1;
		ICR1 = Freq_change;
		
		num = ((uint32_t) duty_cycle * Freq_change)/100;   //calculate the number
		OCR1A = num; 		//output the number to PORTE.6

		TCCR1B |= (1<<CS12); 						//Actually compare the OCR to the CS
	}
	
	if (motor == 'D')
	{
		//FIRST MOTOR
		uint16_t num;  								//some value
		TCCR3A |= (1<<COM3A1);  					//Enable this part
		Freq_change = (F_CPU/(freq * 256)) - 1;		//how to change frequency
		ICR3 = Freq_change;
		
		num = ((uint32_t) duty_cycle * Freq_change)/100;   //calculate the number
		OCR3A = num; 								//output the number to PORTE.6

		TCCR3B |= (1<<CS32); 						//Actually compare the OCR to the CS
		
		////SECOND MOTOR, DOESN'T WORK
		TCCR5A |= (1<<COM0A1);  					//Enable this part
		ICR5 = Freq_change;
		OCR3C = num; 								//output the number to PORTE.6

		TCCR5B |= (1<<CS42); 						//Actually compare the OCR to the CS		
		
		
		//THIRD MOTOR
		TCCR1A |= (1<<COM1A1);  					//Enable this part
		ICR1 = Freq_change;	
		OCR1A = num; 								//output the number to PORTE.6

		TCCR1B |= (1<<CS12); 						//Actually compare the OCR to the CS		

	}
	
}
