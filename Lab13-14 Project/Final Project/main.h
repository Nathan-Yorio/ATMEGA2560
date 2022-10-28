/*
 * main.h

 Created: 4/20/2018 2:37:44 PM
 Author : Nathan Yorio
 Purpose: Main function header
 */ 


#ifndef MAIN_H_
#define MAIN_H_

//Define Pushbuttons
#define PUSHBUTTON1 (~PINC & 0x01)
#define PUSHBUTTON2 (~PINC & 0x02)
#define PUSHBUTTON3 (~PINC & 0x04)
#define PUSHBUTTON4 (~PINC & 0x08)



#endif /* MAIN_H_ */