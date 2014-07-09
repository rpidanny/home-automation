#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
/*
  interrupt.h - Interrupt library for AVR Microcontroller
  Author: Abhishek Maharjan, abhishekmaharjan1993@gmail.com
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; 
*/

void attachInterrupt(int,int);
void dettachInterrupt();
#endif
