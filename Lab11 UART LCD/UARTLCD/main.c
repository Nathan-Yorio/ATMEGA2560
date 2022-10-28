/*===========================================
main.c (UART and LCD)

Created: 4/1/2018 9:47:17 AM
Author : Nathan Yorio

Purpose: Utilizing UART to output to a two row
16 slot LCD screen

PORTS: PORTL (OUTPUT), PORTD (OUTPUT), PORTC (OUTPUT), PORTJ (INPUT)
Inputs:
=================
PORTJ.0 ---- RX3
PORTJ.1 ---- TX3
=================
Outputs:
=================
PORTC.0-7 ---- LEDS
PORTJ.0-7 ---- LCD CONTROLLER
PORTD.0-2 ---- LCD CONTROLLER
=================


 ============================================*/ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "io_ports.h"
#include "timers.h"
#include "USART.h"
#include "LCD.h"
#include "EEPROM.h"
#include <avr/interrupt.h>
#include <avr/eeprom.h>


//eeprom_update_byte(uiAddress,*ucData);

int main(void)
{
	//char T_mess[] = {"Test"};
	//char B_mess1[] = {"Test"};
	//char B_mess2[] = {"Test2"};
	
	//Initialization
	io_init();
	Init_LCD();
	Init_UART3();
	sei();

	//LCD_write(INSTR_WR, 0x01);
	//timer(2);	//can remove if use Busy Flag check
	
	//LCD_write(INSTR_WR, 0x02);
	//timer(2);  //can remove if use Busy Flag check

	//LCD_write(INSTR_WR, 0x86);
	//Print_string (T_mess);

	//LCD_write(INSTR_WR, 0xC0);
	//_delay_us(50);	//can remove if use Busy Flag check


	while(1) 
	{
		//UART3_In();
		uint8_t i = 0;
		uint16_t uiAddress = 0;
		char EEPROMBUFFER[50];
		uint16_t location = 0xC0;

		while(UART_update == 1)
		{
			while(rx_buffer[i] != '\0') //is array finished
			{
				EEPROM_write(uiAddress, rx_buffer[i]); //write character of array to address in EEPROM
				timer(2);
				i++;								   //increment counter
				uiAddress++;						   //increment address
			}
			UART_update = 0;
			EEPROM_update = 1;
		}

		
		//Reset Counters
		i = 0;
		uiAddress = 0;
		while(EEPROM_update == 1)						//is global EEPROM 1?
		{
			while(EEPROMBUFFER[i] != 0xFF)
			{
				EEPROMBUFFER[i] = EEPROM_read(uiAddress);
				timer(2);									//delay because LCD was struggling to receive
				i++;
				uiAddress++;
				UART3_Out(EEPROMBUFFER[i]);					//put buffer out to UART
			}
			EEPROM_update = 0;								//update EEPROM to 0
		}
			
		while(LCD_update == 1)							//is global LCD 1?
		{
			LCD_update = 0;
			LCD_write(INSTR_WR, 0x01);
			timer(2);
			LCD_write(INSTR_WR, 0x02);
			timer(2);  
			
			LCD_write(INSTR_WR, location);
			//Print_string(rx_buffer);
			Print_string(EEPROMBUFFER);
		}
		
		
		//LCD_write(INSTR_WR, 0xC6);	// Set DDRAM address to bottom row, left character
		//_delay_us(50);	//can remove if use Busy Flag check
		//Print_string (B_mess1);
		//timer(250);
		//LCD_write(INSTR_WR, 0xC6);	// Set DDRAM address to bottom row, left character
		//_delay_us(50);	//can remove if use Busy Flag check
		//Print_string (B_mess2);
		//timer(250);

	}  

		return(0);

}	/* end main */