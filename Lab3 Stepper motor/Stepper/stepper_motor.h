/*
 * stepper_motor.h
 *
 * Created: 1/28/2018 6:38:55 PM
 *  Author: Nathan
 *
 * Purpose:
 * Creates function prototype for stepper functions
 * and defines the pins to be pressed for the type of step
 */ 

//Include
//#include "stepper.c"



// Define function prototypes
//void Stepper_Drive(char mode,uint8_t revolutions);
void Stepper_Position(char mode);

// Define
#define PushButton (~PINA & 0x07) //type of step controlled by toggle
#define Wave_Step 0x01
#define Full_Step 0x02
#define Half_Step 0x04

//global variables can’t define the array in .h file
extern uint8_t Wave[4];
extern uint8_t Full[4];
extern uint8_t Half[8];




