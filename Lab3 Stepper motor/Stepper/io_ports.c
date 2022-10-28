/*
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
	DDRA = 0x00; //PORTA is inputs
	PORTA = ~0x00; //negative logic for pullup resistors
	DDRC = 0xFF; //set PORTC as outputs
	PORTC = ~0x00; //outputs initially off
}

