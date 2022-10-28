/*===========================================
  main.c (Lab 9)
 
  Created: 3/18/2018 7:49:25 PM
  Author : Nathan Yorio
  
  Purpose: Count frequency with Timer4 and interrupts
  
  PORTS: PORTF-A (INPUT), PORTC (OUTPUT)
  Inputs:
  =================
  PORTL.0 ---- TTL Square Wave
  PORTA.0 ---- SW0 (Start Print to Serial)
  =================
  Outputs:
  =================
  PORTB.7 ---- Onboard LED flashing on interrupt
  =================
============================================= */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "io_ports.h"
#include "freq_count.h"
#include "Serial_print.h"
#include "timers.h"

int main(void)
{
	//Initializations
	uint16_t frequency;
	init_timer4();
	io_init();
	init_UART();
	init_timer0();
	sei();
	
    while (1) 
    {
		//PREVIOUS STEPS COMMENTED
		//if(PUSHBUTTON) //when there is new data
		//{
			//while(PUSHBUTTON);
			//new_data = 0;
			// "duration" has the number of timer ticks F_CPU MHz/pre-scaler
			// between successive rising edges on input capture pin ICP1
			// freq 1/Time = F_CPU / ("duration"* pre-scaler)
			
			//Final Step
			timer(1000);				//wait
			frequency = freq_detect();  //call frequency detect function
			printf("\n\t%d", frequency);//output calculated frequency to terminal
		//}
	}
}
    


