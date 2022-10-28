/*
  ADC.c
 
 Created: 2/25/2018 5:10:49 PM
 Author : Nathan Yorio
 
 Purpose:
 The purpose of this code is to control the arduino using
 analog to digital conversion with potentiometers
 
 PORTS: PORTF-A (INPUT), PORTC (OUTPUT)
 Inputs:
 PORTF.0 ---- ADC0
 PORTF.1 ---- ADC1
 PORTF.2 ---- ADC2
 =================
 PORTA.0 ---- SW1 (Start display)
 PORTA.1 ---- SW2 (display 8bit)
 PORTA.2 ---- SW3 (display 10bit)(only 8 MSBs)
 
 Outputs:
 PORTC.0~PORTC.7 (LED0 - LED7)
 
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "io_ports.h"
#include "timers.h"
#include "Serial_print.h"
#include "ADC.h"

int main(void)
{
	//Initializations
	init_UART(); 	
	init_ADC();				
	io_init();
	init_timer0();
	
	//Declare some values for ADC
	uint16_t ADC_value0;
	uint16_t ADC_value1;
	
    while (1) 
    {
		
		if(PUSHBUTTON)						//if one button is pushed
		{
				ADC_value0 = read_ADC(0);	//read ADC from the first pin
				PORTC = ~ADC_value0;		//output the value of the ADC to LEDS
				printf("\nThe voltage is %d V", ADC_value0); //output it to terminal
					
				timer(500);					//wait 0.5 sec
		}

		if(PUSHBUTTON2)						//if one button is pushed
		{
				ADC_value1 = readten_ADC(1);//read ADC from the second pin
				PORTC = ~(ADC_value1 >> 2); //output the value of the ADC to LEDS
				printf("\nThe voltage is %d V", ADC_value1); //output it to terminal	
				
				timer(500);					//wait 0.5 sec
		}
    }
}

