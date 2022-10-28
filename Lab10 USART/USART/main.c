/*===========================================
 main.c (USART)
 Created: 3/25/2018 5:53:21 PM
 Author : Nathan Yorio
 
 Function:
 To demonstrate the capability of the arduino
 to perform communication function with
 serial or parallel data transfer
 
 PORTS: PORTA (INPUT), PORTJ (INPUT), PORTC (OUTPUT)
 Inputs:
 =================
 PORTA.0-6 ---- SW0 - SW6
 =================
 PORTJ.0 ---- RX3
 PORTJ.1 ---- TX3
 =================
 Outputs:
 =================
 PORTC.0-7 ---- LEDS
 =================
=============================================*/ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "USART.h"
#include "io_ports.h"
#include "Serial_print.h"


int main (void)
{
	Init_UART3();				   //set up UART0
	io_init();					   //initialize IO
	sei();
	uint8_t txchar;
	////Test Code
	//char ch[] = "One Testy Boi";   //text string to send via serial port
	//uint8_t i = 0;				   //this is index for the ch array
	//while(ch != NULL)			   //if it is NUL, it is 0, indicating end of string
	//{
		//UART3_Out(ch[i]);		   //set the current character in the string to UART
		//i++;					   //increment counter
	//}
	//UART3_Out(0x0D);			   //send carriage return
	uint16_t output;
	
	while(1)
	{
		//txchar = ~PINA;
		txchar = 0x23;
		UART3_Out(txchar);
		PORTC = ~rx_ch;
	}
}

