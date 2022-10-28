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

//function prototypes
void motor(char);

//custom timer stuff
void custom_timer(void);
void init_timer0(void);
void timer_1s(void);
void timer_3s(void);
void timer_4s(void);
void timer_5s(void);
void timer_6s(void);


//#define Wave_Step 0x01 //this is old too
#define Full_Step 0x02 //wave stepper
#define Half_Step 0x04 //half stepper

#define START (~PINA & 0x01)       //PINA.0
#define STOP (~PINA & 0x02)        //PINA.1
 
#define HOT (~PIND & 0x01) //hot is 1
#define COLD (~PIND & 0x02) //cold is 2
#define WARM (~PIND & 0x04) //warm is 3
#define CLOSED (~PIND & 0x08) //closed door is 4

//global variables can’t define the array in .h file
extern uint8_t Wave[4];
extern uint8_t Full[4];
extern uint8_t Half[8];




