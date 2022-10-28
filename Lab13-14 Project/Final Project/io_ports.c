/*********************************************
 io_ports.c

 DATE: 2/4/18
 Author : Nathan Yorio

 Function:
 Initialize IO ports 
 Initialize portJ as inputs
 Initialize portC as inputs
 Port L, D, H, E, and B as outputs
 *********************************************/ 

#include <avr/io.h> //standard io

void io_init(void)
{
	//Outputs
	DDRL = 0xFF;	/* PORTC all outputs */
	PORTL = 0x00;	/* Set all outputs to 0 initially */
	DDRD = 0xFF;	/* Set D.0 through A.2 to outputs for LCD control */
	DDRH = 0xFF;    //Servos
	DDRE = 0xFF;	//port for PWM operation
	PORTE =~0x00;	//Initially off
	DDRB = 0xFF;	
	PORTB = 0xFF;
	//PORTE = 0x00;
	
	//Inputs
	DDRJ = 0x00;	//coolterm input
	DDRC = 0x00;    //debug purposes
}

