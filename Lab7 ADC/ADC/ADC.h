/************************************************************
  ADC.h

  Created: 2/26/2018 10:40:49 AM
  Author: Nathan Yorio
  
 ************************************************************/ 

//Function Prototypes
uint8_t read_ADC(uint8_t chan);
uint16_t readten_ADC(uint8_t chan);
void init_ADC(void);

uint8_t read_ADC_channel(uint8_t);


#define PUSHBUTTON (~PINA & 0x01) //PB1
#define PUSHBUTTON2 (~PINA & 0x02) //PB2