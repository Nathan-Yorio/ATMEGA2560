/*
 * stepper.c
 *
 * Created: 1/28/2018 8:47:39 PM
 *  Author: Nathan Yorio
 *
 * Purpose:
 * This c file contains functions that control
 * the stepper motor
 */ 

#define F_CPU 16000000UL
#include <avr/io.h> //standard io
#include <util/delay.h>

uint8_t Wave[4] = {1, 2, 4, 8};
uint8_t Full[4] = {9, 3, 0x06, 0x0C};
uint8_t Half[8] = {0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01};

void Stepper_Drive(char mode,uint8_t revolutions)
{
	uint16_t steps; 
	//you need to calculate the steps needed for each revolution
	switch (mode)
	{
		case 'W':
		steps = revolutions * 2048UL / 4; //each rev takes 32*64 steps, array has
										  //4 elements
		for(uint16_t i = 0; i< steps; i++) //loop thru array # of times
		{
			for(uint16_t j = 0; j< 4; j++) //loop thru the whole array
			{
				PORTC = Wave[j]; //output the function to port to step the motor
				_delay_ms(3); //controls motor speed
			}
		}
		break;
		case 'F':
		steps = revolutions * 2048UL / 4;
		//you need to calculate the steps needed for each revolution
		for(uint16_t i = 0; i< steps; i++)
		{
			for(uint16_t j = 0; j< 4; j++) //loop thru the whole array
			{
				PORTC = Full[j];
				_delay_ms(3); //controls motor speed
			}
		}
		break;
		case 'H':
		steps = revolutions * 4096UL / 8;
		//you need to calculate the steps needed for each revolution
		for(uint16_t i = 0; i< steps; i++)
		{
			for(uint16_t j = 0; j< 8; j++) //loop thru the whole array
			{
				PORTC = Half[j];
				_delay_ms(3); //controls motor speed
			}
		}
		break;
	}
}

void Stepper_Position(char mode)
{
		uint16_t degree;
		switch (mode)
		{
			case 'W':
			degree = 84;
			//4 elements
			//you need to calculate the steps needed for each revolution
			for(uint16_t i = 0; i< degree; i++) //loop thru array # of times
			{
				for(uint16_t j = 0; j< 4; j++) //loop thru the whole array
				{
					PORTC = Wave[j];
					_delay_ms(3);
				}
			}
			break;
		}
}