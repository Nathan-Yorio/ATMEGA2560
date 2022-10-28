/*
 * USART.c
 *
 * Created: 3/25/2018 5:56:14 PM
 *  Author: Nathan Yorio
 */ 

#define F_CPU 16000000UL
#define BAUD 9600
#include <avr/io.h>
#include <avr/interrupt.h>#include "USART.h"

void Init_UART3(void)
{
	UCSR3A = 0x00;
	UCSR3B |= (1<<TXEN3);					//enable transmit
	UCSR3B |= (1<<RXEN3);					//enable receive
	UCSR3B |= (1<<RXCIE3);					//enable interrupt
	UCSR3C |= (1<<UCSZ31)|(1<<UCSZ30);
	
	uint32_t i = 16UL*BAUD;
	i = F_CPU/i; //OR
	uint16_t myubr = (F_CPU / (16UL*BAUD)) - 1; // Calculate the 16bit UBRR0 register
												//setting for a given baud rate and F_CPU
	UBRR3L = myubr;
	UBRR3H = 0;
	//UBRR3H = (myubr>>8) & 0x0F;				//load UBRR high and ensure bits 15-12 set to zero
}
void UART3_Out(uint8_t ch)
{
	while((UCSR3A & (1<<UDRE3))==0);	//wait until UDR3
										//is ready for new data
	UDR3 = ch;
}
uint8_t UART3_In(void)
{
	while((UCSR3A & (1<<UDRE3))==0);	//wait until UDR3
										//is ready for new data
	return (UDR3);
}
ISR(USART3_RX_vect)
{
	UART_update = 1;					//update global UART variable
	rx_ch = UDR3;						//Set receive channel to UDR3
	//Check if what's being read is finished
	if(rx_ch == 0x0D)					
	{
		rx_buffer[i] = '\0'; //is null?
		i = 0;
		LCD_update = 1; //set update to one
		
	}
	else
	{
		rx_buffer[i] = rx_ch; //set character into buffer
		i++;
	}		
	PORTC = ~0xFF; //testing with LEDS
}
