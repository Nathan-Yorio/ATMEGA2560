/************************************************************
  ADC.h

  Created: 2/26/2018 10:40:49 AM
  Author: Nathan Yorio
  
 ************************************************************/ 

#ifndef ADC_H_
#define ADC_H_

//Function Prototypes
void init_ADC(void);


#define PUSHBUTTON (~PINA & 0x01)  //PB1
#define PUSHBUTTON2 (~PINA & 0x02) //PB2
#define PUSHBUTTON3 (~PINA & 0x04) //PB3

//global variables
volatile uint16_t adc_tick;
volatile uint16_t value;
volatile uint16_t chan;

#endif