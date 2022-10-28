/*
Author: Nathan Yorio

Function: call other function for io ports
 */ 



#ifndef IO_PORTS_H_
#define IO_PORTS_H_

void io_init(void); //initialize io ports

#endif /* IO_PORTS_H_ */

#define Pattern_PB (~PINA & 0x07) //port a's pushbutton locations

#define START 1               //PINA.0
#define STOP 2               //PINA.1
#define RESET 4               //PINA.2
//#define Pattern_A 1               //PINA.0
//#define Pattern_B 2               //PINA.1
//#define Pattern_C 4               //PINA.2