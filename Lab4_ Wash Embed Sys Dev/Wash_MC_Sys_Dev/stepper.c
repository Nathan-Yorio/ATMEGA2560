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

//uint8_t Wave[4] = {1, 2, 4, 8}; This is from before
uint8_t Full[4] = {9, 3, 0x06, 0x0C};
uint8_t Half[8] = {0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01};


void motor(char mode)
{
		uint16_t degree;
		degree = 25; //1s / 0.040s
		switch (mode)
		{
			case 'A': //agitate
			//turn motor one way
			for(uint16_t i = 0; i< degree; i++) //loop thru array # of times
			{
				for(uint16_t j = 0; j < 8; j++) //loop thru the whole array
				{
					PORTB = Half[j];
					_delay_ms(5);
				}
			}
		
			//turn motor the other way
			for(uint16_t i = 0; i< degree; i++) //loop thru array # of times
			{
				for(uint16_t j = 8; j > 0; j--) //loop thru the whole array
				{
					PORTB = Half[j];
					_delay_ms(5);
				}
			}
			break;
			
			case 'S':
			for(uint16_t i = 0; i< 300; i++) //loop thru array # of times
			{
				for(uint16_t j = 0; j< 4; j++) //loop thru the whole array
				{
					PORTB = Full[j]; //output the function to port to step the motor
					_delay_ms(3); //controls motor speed
				}
			}
			break;
		}
}

//custom timer stuff

//initialize timer
void init_timer0(void)
{
	TCNT0 = 0; //initially off
	OCR0A = 156; //10 ms
	TCCR0A = 0x00; //initially off
	TCCR0B = 0x00; //initially off
}
//timer itself
void custom_timer(void)
{
	TCCR0B = 0x05;   // 1024 pre-scaler
	while((TIFR0 & (1<<OCF0A)) == 0);   //wait until overflow
	TCCR0B = 0;      //disable timer
	TIFR0 = TIFR0 | (1<<OCF0A);        //clear overflow
	TCNT0 = 0;       //end	
};
//timer loops to whatever you want
void timer_6s(void)
{
	for(uint16_t i = 0; i < 600; i++)
	{
		custom_timer(); //loop the 10 ms custom timer to get full seconds
	}
}
void timer_5s(void)
{
	for(uint16_t i = 0; i < 500; i++)
	{
		custom_timer();
	}
}
void timer_4s(void)
{
	for(uint16_t i = 0; i < 400; i++)
	{
		custom_timer();
	}	
}
void timer_3s(void)
{
	for(uint16_t i = 0; i < 300; i++)
	{
		custom_timer();
	}	
}
void timer_1s(void)
{
	for(uint16_t i = 0; i < 100; i++)
	{
		custom_timer();
	}	
}