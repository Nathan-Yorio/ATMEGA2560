/*********************************************
 io_ports.c

 DATE: 2/4/18
 Author: Nathan Yorio

 Function:
 Initialize IO ports 
 Initialize portA as inputs
 Initialize portF as inputs
 Initialize portC as outputs
 *********************************************/ 

#include <avr/io.h> //standard io


void io_init(void)
{
	//Input
	DDRD = 0x00; //PORTD is inputs
	PORTD = ~0x00; //negative logic for pullup resistors
	//Analog Input
	DDRF = 0x00;
	PORTF =~0x00; //maybe 0xFF something something ADC is different.
	//Output
	DDRL = 0xFF; //set PORTL as outputs
	PORTL = ~0x00; //outputs initially off
}

