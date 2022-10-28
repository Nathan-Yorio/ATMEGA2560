/*
 * EEPROM.h
 *
 * Created: 4/8/2018 3:29:02 PM
 *  Author: Nathan Yorio
 *
 * Purpose: Header file for EEPROM functions
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(uint16_t uiAddress, uint8_t ucData); //Function to write EEPROM
uint8_t EEPROM_read(uint16_t uiAddress);			   //Function to read EEPROM

#endif /* EEPROM_H_ */