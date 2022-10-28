/*=================================================
   freq_count.h

   Created: 3/18/2018 7:51:55 PM
   Author: Nathan Yorio
   
   Purpose: Include file for freq count functions
 ==================================================*/ 

#include <avr/io.h> //standard io

#ifndef FREQ_COUNT_H_
#define FREQ_COUNT_H_

//Function Prototypes
void init_timer4(void);


//Global Variables
volatile uint8_t LED;

volatile uint16_t counts_prev;
volatile uint16_t counts_new;
volatile uint16_t duration;
volatile uint8_t new_data;

//Definitions
#define PUSHBUTTON (~PINA & 0x01)  //PB1

#endif /* FREQ_COUNT_H_ */