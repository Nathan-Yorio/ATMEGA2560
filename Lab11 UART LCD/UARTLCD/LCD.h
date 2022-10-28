/*
 * LCD.h
 *
 * Created: 4/1/2018 10:22:14 AM
 *  Author: Nathan Yorio
 *
 * Purpose: LCD Control Header File
 */ 


#ifndef LCD_H_
#define LCD_H_

//Function Prototypes
void Init_LCD (void);
void LCD_write (unsigned char RS, unsigned char data);
void Print_string(volatile char *data_ptr);

#define  INSTR_WR	0
#define  DATA_WR	1
#endif /* LCD_H_ */