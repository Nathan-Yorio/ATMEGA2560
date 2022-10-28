/*
Author: Nathan Yorio

Function:
* Initialize IO ports for LED13
* Initialize portA as inputs
* Initialize portL as outputs
 */ 

#include <avr/io.h>
#include "io_ports.h"

void io_init(void)
{
	DDRB = 0xFF; //PB7 LED On Board or DDRB = 0x80, doesn't matter much
	PORTB = 0x00;
	
	DDRA = 0x00; //PORTA is inputs
	DDRC = 0xFF;
	PORTC= 0x00;
}

//This made it work though....
//#include <avr/io.h>
//#include "io_ports.h"
//
//void io_init(void)
//{
	//DDRB = 0xFF; //PB7 LED On Board or DDRB = 0x80, doesn't matter much
	//PORTB = 0x00;
	//
	//DDRA = 0x00; //PORTA is inputs
	//DDRC = 0xFF;
	//PORTC= 0x00;
//}