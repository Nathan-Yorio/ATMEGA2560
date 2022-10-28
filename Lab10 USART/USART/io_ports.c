/*********************************************
 io_ports.c

 DATE: 2/4/18
 Author: Nathan Yorio

 Function:
 Initialize IO ports 
 Initialize portA as inputs
 Initialize portJ as inputs
 Initialize portC as outputs
 *********************************************/ 

#include <avr/io.h> //standard io


void io_init(void)
{
	//Input
	DDRJ = 0x00; //set PORTJ as inputs
	DDRA = 0x00; //set PORTA as inputs
	PORTA = ~0x00; //pullup resistors
	
	//Output
	DDRC = 0xFF;
	PORTC = 0x00;
}

