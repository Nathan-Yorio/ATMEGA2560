/*
 * Control_stg_1.c
 *
 * Created: 2/4/2018 3:18:35 PM
 * Author : Nathan Yorio
 * 
 * Washing Machine:
 * This code is designed to be essentially a simulation
 * of how a washing machine would theoretically be programmed to run
 * given all of the different actions like motor agitation,
 * hot cold water draining, etc.
 * 
 * Ports/ Peripherals:
 * PORTA is INPUT
 * PORTC is OUTPUT
 * PORTL is OUTPUT
 * 
 * Stepper motor, contact switches, and led bar are used
 * 
 *
 * Input
 * SW0 ---- PORTD.0 TEMP HOT
 * SW1 ---- PORTD.1 TEMP COLD
 * SW2 ---- PORTD.2 TEMP WARM
 * SW3 ---- PORTD.3 DOOR CLOSED
 *
 * PB0 ---- PORTA.3 DOOR OPEN
 * PB1 ---- PORTA.4 START
 *
 * Hardware: (output) WAVE STEPS
 * IN1 ---- PORTB.0
 * IN2 ---- PORTB.1 
 * IN3 ---- PORTB.2
 * IN4 ---- PORTB.3
 *
 * LED1 ---- PORTC.0 Drain
 * LED2 ---- PORTC.1 Cold water
 * LED3 ---- PORTC.2 Hot Water
 * LED4 ---- PORTC.3 Done
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "io_ports.h"
#include "stepper_motor.h"
//#include <util/delay.h>

int main(void)
{
    io_init(); //initialize input output
	init_timer0(); //initialize custom timer
	
    while (1) 
    {
		if(START) //if the start button is pressed
		{
			while(!CLOSED) //while the door is not open
			{
				//hol' up
			}
			
			if(HOT) //if the switch for hot is down
			{
				PORTC = ~0x04; // first LED is hot water
				timer_4s(); //custom timer
				//_delay_ms(4000);//4 sec wait
				PORTC = ~0x00; //turn off
								
				motor('A'); //motor agitation function
				motor('A');
				motor('A');
				PORTC = ~0x00; //motor off
								
				PORTC = ~0x01; //drain on
				timer_4s(); 
				//_delay_ms(4000);
				PORTC = ~0x00; //drain off
								
				PORTC = ~0x04; //rinse is same led as selection
				timer_4s();
				//_delay_ms(4000);//4 sec wait
				PORTC = ~0x00; //turn off all valves
								
				PORTC = ~0x01; //1 indicates drain on
				motor('A'); 
				motor('A');
				motor('A');
								
				PORTC = ~0x01; //drain valve is on
				timer_1s();
				//_delay_ms(1000); //delay 1 s
				PORTC = ~0x00; //All off
								
				motor('S'); //Motor Spin Function
				motor('S');
				motor('S');
								
				PORTC = ~0x08; //done
			}
			//if(COLD) //if the switch for cold is down
			//{
				//PORTC = ~0x02; //second LED is cold water
				//_delay_ms(1000);//4 sec wait
				//PORTC = ~0x00; //turn off
								//
				//motor('A'); //motor agitation function
				//motor('A');
				//motor('A');
				//PORTC = ~0x00; //motor off
				//
				//PORTC = ~0x01; //drain on
				//_delay_ms(4000);
				//PORTC = ~0x00; //drain off
				//
				//PORTC = ~0x02; //rinse is same led as selection
				//_delay_ms(4000);//4 sec wait
				//PORTC = ~0x00; //turn off all valves
				//
				//PORTC = ~0x01; //agitate motor and 1 indicates drain on
				//motor('A');
				//motor('A');
				//motor('A');
				//
				//PORTC = ~0x01; //drain valve is on
				//_delay_ms(1000); //delay 1 s
				//PORTC = ~0x00;
				//
				//motor('S');
				//motor('S');
				//motor('S');
				//
				//PORTC = ~0x08; //done
			//}
			//if(WARM) //if the switch for warm is down
			//{
				//PORTC = ~0x06; //two LEDs is hot and cold, so warm
				//_delay_ms(4000);//4 sec wait
								//
				//motor('A'); //motor agitation function
				//motor('A');
				//motor('A');
				//PORTC = ~0x00; //motor off
				//
				//PORTC = ~0x01; //drain on
				//_delay_ms(4000);
				//PORTC = ~0x00; //drain off
				//
				//PORTC = ~0x06; //rinse is same led as selection
				//_delay_ms(4000);//4 sec wait
				//PORTC = ~0x00; //turn off all valves
				//
				//PORTC = ~0x01; //agitate motor and 1 indicates drain on
				//motor('A');
				//motor('A');
				//motor('A');
				//
				//PORTC = ~0x01; //drain valve is on
				//_delay_ms(1000); //delay 1 s
				//PORTC = ~0x00;
				//
				//motor('S');
				//motor('S');
				//motor('S');
				//
				//PORTC = ~0x08; //done
			//}
					
				
			//PORTC = ~0x00;
			
		}
    }
}

