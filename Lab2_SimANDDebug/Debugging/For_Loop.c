/*
 * For_Loop.c
 *
 * Created: 1/22/2018 11:22:27 AM
 * Author: Nathan Yorio
 * Purpose: Use a simulator to step through a for-loop and see what it does
 * Hardware connections:
 * PORTA is INPUTS PORTC is OUTPUTS
 */ 


#define F_CPU 16000000UL //sets clock speed to this
#include <avr/io.h> //input output
#include "io_ports.h" //pulling in personal library for ports
#include <avr/delay.h> //delay library
void minute_counter(void); //function prototype for minute counter
uint8_t minute; //global variable for minutes

int main(void)
{
	uint8_t value = 0x01; //establish a value to bitshift
	
	io_init(); //initialize input output

	
	while (1)
	{
		if(Pattern_PB == START) //is the pushbutton equal to pushbutton 1?
		{
			minute_counter(); //calls the minute counter function
			minute++; //increase minutes by 1 whenever the function is done
		}
	}
}


void minute_counter(void) //minute counter function
{
	uint8_t ctr; //one counter
	uint8_t ctr1; //another counter
	uint8_t inner_loop = 0; //little loop
	uint8_t outer_loop = 0; //big loop

		for(ctr = 0; ctr < 6; ctr++) //count from 0 to 5
		{
			for(ctr1 = 0; ctr1 < 10; ctr1++) //count from 0 to 9
			{
				_delay_ms(1000); //wait
				inner_loop++; //increase value
				PORTC = ~((outer_loop << 4) | inner_loop); //set the port equal to the loop value
			}
			inner_loop = 0; //reset inside loop
			_delay_ms(1000); //wait
			outer_loop++; //increase big loop value
			PORTC = ~((outer_loop << 4) | inner_loop); //set the value of big loop
		}											   //and little loop to LEDS

}