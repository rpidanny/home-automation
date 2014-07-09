#ifndef USART_H
#define USART_H
/*
  USART.h - USART library for AVR Microcontroller
  Author: Abhishek Maharjan, abhishekmaharjan1993@gmail.com
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; 
*/

#ifndef F_CPU
# warning "F_CPU not defined for <util/delay.h>"
# define F_CPU 8000000UL
#endif

#define value (((F_CPU / (baud * 16UL))) - 1)
#include <math.h>
#include <avr/io.h>
#include <util/delay.h>
class USART{	
	int baud;
	public:
	USART():baud(0){}
	
	void begin(int x)
	{   
		baud=x;
	
		UCSRB |= (1 << RXEN)|(1 << TXEN);   
		UCSRC |= (1 << URSEL) | (0<<USBS) | (1 << UCSZ0) | (1 << UCSZ1); 
		UBRRL = value; 
	}

	uint8_t read()
	{   
		//while ((UCSRA & (1 << RXC)) == 0); 
		
			return UDR;
		
		
		
	}
	
	void send(char datam)
	{
		 while(!(UCSRA & (1 << UDRE)));   
		 UDR = datam; 
	 }
 	
	void print(const char *str)
	{
			unsigned int i=0;
			while(str[i]!='\0')
			  {
				send(str[i]);
				i++;
			  }
	}
	
	int available()
	{
		if ((UCSRA & (1 << RXC)) == 0)
		{
			return 0;
		}
		else{
			return 1;
		}
		
	}

}Serial;

#endif