/*
* main.c
*
* Created: 1/28/2018
* Author : Nathan Yorio
*
*
* Project name:Three_Modes_Stepper
* Description:
* Control stepper motor thru three different modes:
* Wave step mode
* Full step mode
* Half step mode
*
* Three arrays with data corresponding to the bit
* pattern necessary to move the stepper motor. Code
* has a for loop in either 4 or 8 iterations depending
* on the drive mode for the stepper
*
* Use system delay function _delay_ms(3) Delay 3mS in between
* each step (below 1ms won't work)
*
* Hardware: (output)
* IN1 ---- PORTC.0
* IN2 ---- PORTC.1
* IN3 ---- PORTC.2
* IN4 ---- PORTC.3
*
* Input
* SW0 ---- PORTA.0 WaveStep mode
* SW1 ---- PORTA.1 FullStep mode
* SW2 ---- PORTA.2 HalfStep mode
*
* The code is written as a multi module program
*
****************************************************/
#define F_CPU 16000000UL //define for delay
// include files
#include <avr/io.h>
#include <util/delay.h>
#include "stepper_motor.h"  //stepper motor preproccessor directives
#include "io_ports.h" //ports preprocessor directives


int main(void)
{
	io_init(); // initialize IOs, defined in io_ports module
	//uint8_t n = 2; //number of revolutions for turning the stepper motor
	while(1)
	{
		switch (PushButton)
		{
			//Edited for final part
			case Wave_Step: //if SW0 is pressed, start Wave Step mode
			{
				Stepper_Position('W'); //alternate stepper function
				break;
			}
			
			//First 3 parts
			case Full_Step: //if SW1 is pressed, Full Step mode
			{
				Stepper_Drive('F',n); //calls stepper function
				break;
			}
			case Half_Step: //if SW2 is pressed, Half Step mode
			{
				Stepper_Drive('H',n); //calls stepper function
				break;
			}
		}
		PORTC = 0x00; //clear output when done
	}
}

