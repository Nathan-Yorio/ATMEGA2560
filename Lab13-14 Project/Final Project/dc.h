/*
 * dc.h
 *
 * Created: 2/18/2018 12:39:40 PM
 * Author : Nathan Yorio
 * Purpose: dc.c header file
 */ 

#ifndef DC_H_
#define DC_H_

//DC motor function prototypes
void dc_init(void);
void fast_PWM(char motor, uint8_t duty_cycle, uint32_t freq);
volatile uint8_t off_flag = 0;

#endif