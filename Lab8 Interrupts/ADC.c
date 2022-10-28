/***********************************************************************************
	ADC.c
	Author: Nathan Yorio
	Purpose: 
	Initialize and provide functions for analog to digital conversion
	
************************************************************************************/
#define F_CPU 16000000UL
#include <avr/io.h>
#include "ADC.h"
#include <avr/interrupt.h>
#include <stdio.h>

void init_ADC(void)
{
	ADMUX |= (1 << REFS0);			// REFS0: 0, REFS1: 1 0x40
	
	ADCSRA = 0x07;					// select the ADC clock frequency - Clock / 128
	ADCSRA |= (1 << ADEN);			// ADEN, ADC Enable 0x80
	//ADMUX &= ~(1 << ADLAR);			// Left Justified For 8 Bits 0x20, turned back off
	ADCSRA |=(1 << ADSC);			// ADSC, ADC Start Conversion
	ADCSRA |= (1<<ADIE);			// Enable input capture interrupt
	
}

ISR(ADC_vect)
{
	ADMUX = (ADMUX & 0xE0) | chan;	// Start with zeros 0b11100000
	ADCSRA |= (1 << ADSC);			// ADSC, ADC Start Conversion
	value = ADCL;					// get the lower 8-bits
	value |= (ADCH << 8);			// shift 'em
}