/*===========================================
 main.c (USART)
 Created: 3/25/2018 5:53:21 PM
 Author : Nathan Yorio
 
 Function:
 Final lab project for ECET 279. Demonstrate functioning of Coolterm
 Multiple PWM Motors, and multiple servo motors with pushbuttons
 
 PORTS: J, C (INPUTS). L, D, H, E, and B (OUTPUTS)
 Inputs:
 =================
 PORTC0-4 ---- Pushbutton Input
 =================
 PORTJ.0 ---- RX3
 PORTJ.1 ---- TX3
 =================
 Outputs:
 =================
 PORTL.0-7 ---- Might not actually do anything but I'm afraid to delete
 =================
 PORTH ---- Servo Control
 =================
 PORTE ---- PWM Operation
 =================
 PORTB ---- ALSO PWM
=============================================*/ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "servo.h"
#include "io_ports.h"
#include "USART.h"
#include "dc.h"
#include "main.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

int main(void)
{
	//Initialize
	io_init();
	Init_UART3();
	servo_init();
	sei();
	dc_init();
	
	char motor;			//which motor
	uint32_t doot = 0; //what duty cycle
	uint32_t freq = 0;		//what frequency
	uint32_t GITSERVED = 0; //value for servo
	int conversion;
	uint8_t k = 0;		//counter for parts of PWM operation
	uint8_t l = 0;		//counter for initial PWM message display
	uint8_t z = 0;		//toggle bit to start commands on PWM
	char killme;		//DECIDES WHAT TO DO
	char message[] = "Enter Motor (ABC) or D(all), Duty Cycle, Then Frequency. Hit 'enter' in between each.\n";
	char message1[] = "servo (S), motor (M)\n";
	char message2[] = "Enter Degree for servo (0 - 180)\n";
	
	//testing ASCII converter
	char test_conv[] = "0000071";
	int conv_test_num = convert_ASCII(test_conv);
	fast_PWM('A', doot, freq);
	fast_PWM('B', doot, freq);
	fast_PWM('C', doot, freq);
	
    while (1) 
    {	
		if(l == 0)		//MOTOR OR SERVO?
		{
			//Initial Message Display
			for(uint8_t j = 0; message1[j] != '\0'; j++)
			{
				UART3_Out(message1[j]); //Display Message One Character at a Time
			}
			l = 3;
		}
		
		if(l == 1)	    //PWM MOTOR MESSAGE
		{
			//Initial Message Display
			for(uint8_t j = 0; message[j] != '\0'; j++)
			{
				UART3_Out(message[j]); //Display Message One Character at a Time
			}
			l = 4;
			k = 1;
		}
			
		if(l == 2)		//SERVO DEGREE MESSAGE ( ?� ?? ?�)
		{
			//Initial Message Display
			for(uint8_t j = 0; message2[j] != '\0'; j++)
			{
				UART3_Out(message2[j]); //Display Message One Character at a Time
			}
			l = 4;
			k = 5;
		}			
		//UART3_Out(UART_update);			
		//Motor Inputs
		while(UART_update == 1) //check for UART char receive
		{
			if(l == 3) //Wait on Initial Message
			{
					
				killme = rx_buffer[0]; //set value to buffer value
				_delay_ms(30);		   //wait for some reason
					
				if(killme == 'S')	   //CASE OF SERVO
				{
					l = 2;			   //Display Servo Message
				}
					
				if(killme == 'M')	   //CASE OF PWM MOTOR
				{
					l = 1;			   //Display PWM Message
				}
			}
				
			if(k == 1)									//first time read motor select
			{
				motor = rx_buffer[0];
				UART3_Out(motor);						//debug
			}
			if(k == 2)									//second time read duty cycle
			{
				_delay_ms(20);							//wait, maybe not necessary
				conversion = convert_ASCII(rx_buffer);	//convert ASCII to Decimal
				doot = conversion;
				UART3_Out(doot);						//debug
					
			}	
			if(k == 3)									//third time read frequency
			{
				_delay_ms(20);
				conversion = convert_ASCII(rx_buffer);
				freq = conversion;				
				UART3_Out(freq);						//debug
				z = 1;
			}
			if(k == 5)
			{
				_delay_ms(20);
				conversion = convert_ASCII(rx_buffer);	//convert ASCII to Decimal
				GITSERVED = conversion;					//Set conversion to servo value
				
				turn_servo(GITSERVED);					//Make servo 1 turn to set value
				turn_servo1(GITSERVED);					//Make servo 2 turn, doesn't work
				turn_servo2(GITSERVED);					//Make servo 3 turn, doesn't work
				k = 3;
			}
			_delay_ms(100);		//wait, maybe not necessary
			k++;				//increment k to accept next piece of command
			UART_update = 0;	//reset UART-update to 0
		}
			
		if(z == 1)
		{
			fast_PWM(motor, doot, freq); //make PWM run from function
		}	
		
		//if all inputs received
		if(k == 4)
		{
			k = 0;
			l = 0;
			z = 1;
		}
		
		
		
		

		if(PUSHBUTTON1) //TURN ON ALL MOTORS to "defaults"
		{
			fast_PWM('D', 50, 200000);	//motor A  duty cycle 0 freq 0
			
			//Reset Entered Values to default
			motor = 'D';
			doot = 50;
			freq = 200000;
			turn_servo(90);			//Reset Servo Motor
		}
		
		if(PUSHBUTTON2)	//TURN OFF ALL MOTORS
		{
			turn_servo(0);	//turns the servo motor at 90 deg steps or something
			
			//Reset all PWM's to initial
			motor = 'D';
			doot = 0;
			freq = 0;
			fast_PWM(motor, doot, freq);
		}
		
		if(PUSHBUTTON4) //RESET MOTORS TO DEFAULTS
		{
			//reset as if no selection pressed
			turn_servo(0);			//Reset Servo Motor
			
		}
    }
}

