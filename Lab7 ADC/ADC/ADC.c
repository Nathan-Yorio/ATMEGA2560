/***********************************************************************************
	ADC.c
	Author: Nathan Yorio
	Purpose: 
	Initialize and provide functions for analog to digital conversion
	
************************************************************************************/
#include <avr/io.h>

void init_ADC(void)
{
	ADMUX |= (1 << REFS0);			// REFS0: 0, REFS1: 1 0x40
	
	ADCSRA = 0x07;					// select the ADC clock frequency - Clock / 128
	ADCSRA |= (1 << ADEN);			// ADEN, ADC Enable 0x80
	
	//ADCSRB = 0x00;					// ALL OFF
}

	
uint8_t read_ADC(uint8_t chan)		//pass which channel you want to this
{
	uint8_t value;					// 8-bit value to hold the result
	ADMUX |= (1 << ADLAR);			// Left Justified For 8 Bits 0x20
	
	ADMUX  = (ADMUX & 0xE0) | chan;	// Start with zeros 0b11100000
	ADCSRA |= (1 << ADSC);  // ADSC, ADC Start Conversion


	printf("\n8bits");
	
	while( (ADCSRA & 0x10) == 0 )	// wait for conversion to be completed
	{
	}
	
	value = ADCH;			// get the upper 8-bits, Sebastian is trash
	ADCSRA = ADCSRA | 0x10;	// clear ADC Interrupt Flag
	
	return value;			// return the value of the conversion
}

uint16_t readten_ADC(uint16_t chan)
{
	uint16_t other_value;			// 16-bit value to hold the result
	ADMUX &= ~(1 << ADLAR);			// Left Justified For 8 Bits 0x20, turned back off
	
	ADMUX = (ADMUX & 0xE0) | chan;	// Start with zeros 0b11100000
	ADCSRA = ADCSRA | (1 << ADSC);  // ADSC, ADC Start Conversion
	
	printf("\n16bits");
	
	while( (ADCSRA & 0x10) == 0 )	// wait for conversion to be completed
	{
	}
	
	other_value = ADCL;			// get the lower 8-bits
	other_value |= (ADCH << 8);
	ADCSRA = ADCSRA | 0x10;	// clear ADC Interrupt Flag
		
	return other_value;			// return the value of the conversion
}
