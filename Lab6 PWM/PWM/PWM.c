/*
 PWM.c
 
 Created: 2/18/2018 10:30:12 AM
 Author : Nathan Yorio
 
 Purpose: 
 This code is designed to control a dc motor with pulse
 width modulation. It does so by controlling timer 1 and timer 3
 to allow for changing the frequency in steps. This occures in the 
 main and in a separate function as well.
 
 Ports/ Peripherals:
 PORTA is INPUT
 PORTC, B, E(PWM) is OUTPUT
 
 Hardware: DC motor, pushbutton, motor control board
 
 Input:
 PB1 ---- PORTA.0
 PB2 ---- PORTA.1
 PB3 ---- PORTA.2
 
 Output:
 LED13 ---- PORTB.7
 LED   ---- PORTC.X
 PWM   ---- PORTE.6
 
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "timers.h"
#include "io_ports.h"
#include "dc.h"

int main(void)
{
	io_init(); //I/0
	init_timer0(); //timer0
	dc_init(); //the motor
	
    while(1) 
    {
		while(FIRST) //If first pushbutton is pressed
		{
			//RAMPING FUNCTION WITH A MUCH COOLER NAME THAN BEFORE
			PUMP_IT_UP();
			//fast_PWM(0.6);	
		}
		
		//These were for step 5. 
		while(SECOND)
		{
			fast_PWM(0.99); //passing an arbitrary value to this to make the PWM
							//speed change for step 5, it's a decimal because I
							//originally wrote it with float and then changed it
							//for the final step because it was wrong
		}
		while(THIRD)
		{
			fast_PWM(0.3);
		}
    }
}

//Original code for first steps had an LED13 going
//on and off. It was like:
while(1){
	while(FIRST)
	{
		PORTB = ~0XFF; //LED on
		custom_timer() //wait
		PORTB = ~0x00; //LED off
		custom_timer() //wait
	}
}

