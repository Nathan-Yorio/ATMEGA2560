/*==============================
  interrupt.c

  Created: 3/4/2018 11:57:50 AM
  Author: Nathan
  
  Purpose: Create interrupts

 ===============================*/ 
#define F_CPU 16000000UL
#include <avr/io.h> //standard io
#include <avr/interrupt.h>
#include "interrupt.h"

//function
void init_extint(void)
{
	EICRA = (1 << ISC01)|(1 << ISC00)|(1<<ISC10)|(1<<ISC11);	//turning on interrupt for the pins
	EIMSK = (1 << INT0)|(1 << INT1);							//tell which interrupts to use
}


//interrupts

//These counts select which preset is being displayed on the leds
//as the user pushes the buttons the value is incremented or decremented
//into 1 of 3 possible display modes
ISR(INT0_vect)
{
	cnt++;			//count up
	if(cnt > 3)		//if counter is greater than 3
	{
		cnt = 0;	//set counter to 0
	}
}

ISR(INT1_vect)
{
	cnt--;			//count down
	if(cnt == 255)  //if counter is at max value
	{
			cnt = 3; //set counter to 3
	}
}


	