/*
Author: Nathan Yorio

Function:
* Initialize IO ports 
* Initialize portB as outputs
* Initialize portA as inputs
* Initialize portC as outputs
 */ 

#include <avr/io.h> //standard io
#include "io_ports.h" //pulls in io_ports.h

void io_init(void)
{
	DDRB = 0xFF; //PB7 LED On Board or DDRB = 0x80, doesn't matter much
	PORTB = 0x00; //pull up resistors
	
	DDRA = 0x00; //PORTA is inputs
	PORTA = ~0x00; //negative logic for pullup resistors
	DDRC = 0xFF; //set PORTC as outputs
	PORTC = ~0x00; //pull up resistors
}

