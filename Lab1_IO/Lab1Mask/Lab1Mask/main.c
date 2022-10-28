/*
 * Lab1Mask.c
 *
 * Created: 1/8/2018 7:28:25 PM
 * Author : Nathan
 
 * Function:
 * Use pushbuttons to make leds turn on and alternate
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
				_delay_ms(100);
				while(Pattern_PB == STOP) //is the pushbutton equal to pushbutton 2?
				{
					PORTC = ~value;
				}	
			}
			while(value != 0x01)
			{
				PORTC = ~value;
				value = value >> 1;
				_delay_ms(100);
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

		// //if(pattern_pb == start) //is the pushbutton equal to pushbutton 1?
		// //{
			// //portc = 0x55; //every other led
			// //_delay_ms(500); //wait
			// //portc = 0xaa; //alternate
			// //_delay_ms(500); //wait
		// //}
		// //else
		// //if(pattern_pb == stop) //is the pushbutton equal to pushbutton 2?
		// //{
			// //portc = 0xaa; //alternate
			// //_delay_ms(500); //wait
			// //portc = 0x55; //every other led
			// //_delay_ms(500); //wait
		// //}
		// //portc = ~0x00; //turn them all off
    }
}

