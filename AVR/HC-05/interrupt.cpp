/*
  interrupt.h - Interrupt library for AVR Microcontroller
  Author: Abhishek Maharjan, abhishekmaharjan1993@gmail.com
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; 
*/
#include <avr/interrupt.h>
#include "interrupt.h"
enum{HIGH=1,LOW=0,OUTPUT=1,INPUT=0,ALL=8,CHANGE=2,RISING=3,FALLING=4};
	
void attachInterrupt(int i,int m) //INT0/INT1/INT2  , MODE of trigger(LOW,CHANGE,RISING/FALLING) ------- ISR (INT0_vect){} /ISR (INT1_vect){}
{
cli();
GICR|=(1<<i);

	if(m==LOW)
			MCUCR&=(0<<ISC11)|(0<<ISC10)|(0<<ISC01)|(0<<ISC00);
	else if(m==CHANGE)
	{
			 MCUCR|=(0<<ISC11)|(1<<ISC10)|(0<<ISC01)|(1<<ISC00);
			 MCUCR&=(0<<ISC11)|(1<<ISC10)|(0<<ISC01)|(1<<ISC00);
	}
	else if (m==RISING)
	{
			MCUCR|=(1<<ISC11)|(1<<ISC10)|(1<<ISC01)|(1<<ISC00);
	}
	else if (m==FALLING)
	{
			 MCUCR|=(1<<ISC11)|(0<<ISC10)|(1<<ISC01)|(0<<ISC00);
			 MCUCR&=(1<<ISC11)|(0<<ISC10)|(1<<ISC01)|(0<<ISC00);
	}
sei();
} 

void dettachInterrupt(){

//Clear interrupt flags

} 