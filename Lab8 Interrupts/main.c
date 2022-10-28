/************************************************************
 Main.c (Interrupts)
 
 Created: 3/4/2018 11:59 AM
 Author : Nathan Yorio
 
 Purpose:
 The purpose of this code is to gain a fundamental understanding
 of the usage of interrupts in relation to the ATMEGA2560
 
 PORTS: PORTF-A (INPUT), PORTC (OUTPUT) 
 Inputs:
 =================
 PORTF.0 ---- ADC0
 PORTF.1 ---- ADC1
 PORTF.2 ---- ADC2
 =================
 PORTD.0 ---- SW1 (display 8bit)
 PORTD.1 ---- SW2 (display 10bit)(only 8 MSBs)
 =================
 Outputs:
 PORTC.0~PORTC.7 (LED0 - LED7)
 
 *************************************************************/ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timers.h"
#include "ADC.h"
#include "io_ports.h"
#include "interrupt.h"


int main(void)
{
	//initialize
	init_ADC();
	io_init();
	init_timer0();
	sei(); //start interrupt
	init_extint();
	chan = 0;
	
	//Declare some values for ADC
	uint16_t ADC_value0;
	uint8_t LED = 0;
    while (1) 
    {
		chan = cnt; //set channel equal to ext variable cnt
		if (timer_tick >= 500) //interrupt timer
		{
			LED ^= (1 << PL7); //blink led
			timer_tick = 0;
		}
		
		PORTL = ~((value >> 3) | LED); //Display ADC value from interrupt
    }
}

