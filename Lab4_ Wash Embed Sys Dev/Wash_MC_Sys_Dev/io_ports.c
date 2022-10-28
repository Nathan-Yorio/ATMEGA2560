/*
DATE: 2/4/18
Author: Nathan Yorio

Function:
* Initialize IO ports 
* Initialize portB as outputs
* Initialize portA as inputs
* Initialize portC as outputs
 */ 

#include <avr/io.h> //standard io


void io_init(void)
{
	//inputs
	DDRA = 0x00; //PORTA is inputs
	PORTA = ~0x00; //negative logic for pullup resistors
	DDRD = 0x00; 
	PORTD = ~0x00;
	//outputs
	DDRC = 0xFF; //set PORTC as outputs
	PORTC = ~0x00; //outputs initially off
	DDRB = 0xFF; 
	PORTB = ~0x00;
}

