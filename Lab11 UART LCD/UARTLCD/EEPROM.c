/*
 * EEPROM.c
 *
 * Created: 4/8/2018 3:28:51 PM
 *  Author: Nathan Yorio
 *
 * Purpose: Control functions related to reading and writing from and to EEPROM
 */ 
#include <avr/io.h>
#include <avr/eeprom.h>
#include "EEPROM.h"
void EEPROM_write(uint16_t uiAddress, uint8_t ucData)
{
		EECR = 0b00000000;
		while(EECR & (1<<EEPE))
		{
			/* Wait for completion of previous write */
		}
		/* Set up address and Data Registers */
		EEAR = uiAddress;
		EEDR = ucData;
		/* Write logical one to EEMPE */
		EECR = (1<<EEMPE); //step 5. write 1 to EEMPE and 0 to EEPE
		/* Start EEPROM write by setting EEPE */
		EECR |= (1<<EEPE); //write EEPE within 4 clock cycles
}

//void EEPROM_write(uint16_t uiAddress, volatile
//char *ucData)
//{
	//while (*ucData != '\0')
	//{
		//eeprom_update_byte(uiAddress,
		//*ucData);
		//uiAddress++;
		//ucData++;
	//}
//}

uint8_t EEPROM_read(uint16_t uiAddress)
{
	while(EECR & (1<<EEPE)); /* Wait for completion of previous write */
	EEAR = uiAddress; /* Set up address register */
	EECR |= (1<<EERE); /* Start EEPROM read by writing EERE */
	return EEDR; /* Return data from Data Register */
}