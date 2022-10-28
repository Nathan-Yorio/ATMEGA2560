/*
 * timers.h
 *
 * Created: 1/28/2018 6:38:55 PM
 *  Author: Nathan Yorio
 *
 * Purpose:
 * This is all for custom timers
 */ 

//custom timer stuff
void custom_timer(void);
void init_timer0(void);
void timer(uint16_t time);

//PINS
#define FIRST (~PINA & 0x01) //PB1
#define SECOND (~PINA & 0x02) //PB2
#define THIRD (~PINA & 0x04) //PB3





