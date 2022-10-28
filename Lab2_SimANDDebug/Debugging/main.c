/*
 * Debugging.c
 *
 * Created: 1/22/2018 10:50:01 AM
 * Author : Nathan Yorio
 * 
 */ 

#define F_CPU 16000000UL //sets clock speed to this
#include <avr/io.h>
#include "io_ports.h"
#include <avr/delay.h>

int main(void)
{
	uint8_t value = 0x01; //establish a value to bitshift
	
	io_init(); //initialize input output
	while (1)
	{
		while(Pattern_PB == START) //is the pushbutton equal to pushbutton 1?
		{
			while(value != 0x80)
			{
				PORTC = ~value;
				value = value << 1;
				//_delay_ms(100);
				while(Pattern_PB == STOP) //is the pushbutton equal to pushbutton 2?
				{
					PORTC = ~value;
				}
			}
			while(value != 0x01)
			{
				PORTC = ~value;
				value = value >> 1;
				//_delay_ms(100);
				while(Pattern_PB == STOP) //is the pushbutton equal to pushbutton 2?
				{
					PORTC = ~value;
				}
			}
		}

		if(Pattern_PB == RESET)
		{
			PORTC = ~0x00; //turn them all off
		}

	}
}