/*=====================================
 USART.h
 
 Created: 3/25/2018 5:56:24 PM
 Author: Nathan Yorio
 
 Purpose: USART Function Prototypes etc.
 ======================================*/ 


#ifndef USART_H_
#define USART_H_

//Function Prototypes
void Init_UART3(void);
void UART3_Out(uint8_t ch);
uint8_t UART3_In(void);

//Global Variables
volatile uint8_t rx_ch;
volatile uint8_t i;
volatile uint16_t LCD_update;
volatile uint16_t UART_update;
volatile uint16_t EEPROM_update;
volatile char rx_buffer[25];

#endif /* USART_H_ */