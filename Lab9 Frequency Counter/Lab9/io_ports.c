/*********************************************
 io_ports.c

 DATE: 2/4/18
 Author: Nathan Yorio

 Function:
 Initialize IO ports 
 Initialize portA as inputs
 Initialize portL as inputs
 Initialize portB as outputs
 *********************************************/ 

#include <avr/io.h> //standard io


void io_init(void)
{
	//Input
	DDRL = 0x00; //set PORTL as inputs
	DDRA = 0x00; //set PORTA as inputs
	PORTA = ~0x00; //outputs initially off
	
	//Output
	DDRB = 0xFF;
	PORTB = ~0x00;
}

