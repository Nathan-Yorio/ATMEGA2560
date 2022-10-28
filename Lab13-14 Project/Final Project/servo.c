/*
 servo.c

 Created: 4/20/2018 2:39:27 PM
 Author : Nathan Yorio
 
 Purpose: Control Servo Motors
*/
#define F_CPU 16000000UL
#include <avr/io.h> //standard io
#include <avr/interrupt.h>
#include "USART.h"
#include <util/delay.h>

void servo_init(void)
{
	TCCR4A|=(1<<COM4A1)|(1<<COM4B1)|(1<<WGM41);        //NON Inverted PWM
	TCCR4B|=(1<<WGM43)|(1<<WGM42)|(1<<CS41)|(1<<CS40); //PRESCALER=64 MODE 14(FAST PWM)
	
	
	TCCR4C|= (1<< FOC4B)| (1<< FOC4C); //MIGHT FORCE OC4B and OC4C to work
	
	ICR4=4999;  	//fPWM=50Hz (Period = 20ms Standard).
	OCR4A = 145;	//0 deg
	OCR4B = 145;	//doesn't work, we thought it would
	OCR4C = 145;	//doesn't work, we thought it would
}

void turn_servo(uint16_t deg)
{
	OCR4A = (deg * 2.44) + 145;	//send degree out to servo motor
	
	//OCR4A = 145;	//0 deg 
	//OCR4A = 585;	//180 deg
}

//THESE DON'T WORK, BUT WE TRIED
void turn_servo1(uint16_t deg)
{
	OCR4B = (deg * 2.44) + 145;
	
}

void turn_servo2(uint16_t deg)
{
	OCR4C = (deg * 2.44) + 145;
}