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
	//Outputs
	DDRL = 0xFF;	/* PORTL all outputs */
	PORTL = 0x00;	/* Set all outputs to 0 initially */
	DDRD = 0xFF;	/* Set D.0 through A.2 to outputs for LCD control */
	DDRC = 0xFF;    //debug purposes
	PORTC = ~0x00;
	//Inputs
	DDRJ = 0x00;

}
