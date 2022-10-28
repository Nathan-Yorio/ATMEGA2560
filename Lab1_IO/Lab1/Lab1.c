/*===================================================================
Filename: Lab1_IO.c
version: 01

Created: 11:08 AM 1/8/2018
Author: Nathan Yorio

Operations:

Hardware:
Atmega2560
PORTB.7 LED13 Active High

 ====================================================================*/ 

#define F_CPU 16000000UL


#include <avr/io.h>
#include "io_ports.h"
#include <avr/delay.h>


int main(void)
{
        io_init(); //initialize input output
		while(1)
		{
			//procedure 3-7
			if((~PINA & 0x01) == 1)
			{
				PORTC = ~0x01;
				
				//procedure 2
				//PORTB ^ (1<<PB7); //toggle LED13
				//_delay_ms(500);
			}
			else
			if((~PINA & 0x02) == 2)
			{
				PORTC = ~0x02;
			}
			else
			if((~PINA & 0x04) == 4)
			{
				PORTC = ~0x04;
			}
			else
			if((~PINA & 0x08) == 8)
			{
				PORTC = ~0x08;
			}			
			PORTC = ~0x00;
		}
		
}


//This made it work though....
//int main(void)
//{
	//io_init(); //initialize input output
	//while(1)
	//{
		////procedure 3-7
		//while((PINA & 0x01) == 1)
		//{
			//PORTB = 0xFF;
			//
			////procedure 2
			////PORTB ^ (1<<PB7); //toggle LED13
			////_delay_ms(500);
		//}
		//
		//PORTB = 0x00;
	//}
	//
//}