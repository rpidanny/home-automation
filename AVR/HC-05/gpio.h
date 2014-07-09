#ifndef _GPIO_H
#define _GPIO_H

/*
  gpio.h - GPIO library for AVR Microcontroller
  Author: Abhishek Maharjan, abhishekmaharjan1993@gmail.com
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; 
*/

enum{HIGH=1,LOW=0,OUTPUT=1,INPUT=0,ALL=8,CHANGE=2,RISING=3,FALLING=4};

extern "C" {
void pinMode(char,int,int);
void digitalWrite(char,int,int);
bool digitalRead(char,int);
unsigned int analogRead( unsigned char ch);
void delay(unsigned long);
void delayMicroseconds(unsigned int);
}
#endif