/*
  gpio.h - GPIO library for AVR Microcontroller
  Author: Abhishek Maharjan, abhishekmaharjan1993@gmail.com
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; 
*/

#include <math.h>
#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"


void digitalWrite(char p,int n,int q)//port,pin number , state (HIGH/LOW) 
{
	if (p =='A' || p=='a')
	{
		if(q==1){
			if(n==8)
			PORTA=0xff;
			else
			PORTA|=(q<<n);
		}
		else{
			if(n==8)
			PORTA=0x00;
			else
			PORTA&=(q<<n);
		}
	}
	else if (p=='B' || p=='b')
	{
			if(q==1){
				if(n==8)
				PORTB=0xff;
				else
				PORTB|=(q<<n);
			}			
			else{
				if(n==8)
				PORTB=0x00;
				else
				PORTB&=(q<<n);
			}			
	}
	else if (p=='C' || p=='c')
	{
		if(q==1){
			if(n==8)
			PORTC=0xff;
			else
			PORTC|=(q<<n);
		}		
		else{
			if(n==8)
			PORTC=0x00;
			else
			PORTC&=(q<<n);
		}		
	}
	else if (p=='D' || p=='d')
	{
		if(q==1){
			if(n==8)
			PORTD=0xff;
			else
			PORTD|=(q<<n);	
		}		
		else{
			if(n==8)
			PORTD=0x00;
			else
			PORTD&=(q<<n);	
		}		
	}
	
}  


void pinMode(char p,int y,int z)   //port , pin number, state(INPUT or OUTPUT)
{
	if (p =='A' || p=='a')
	{
		if(y==8)
		{
			if(z==OUTPUT)
			DDRA=0xff;
			else
			DDRA=0x00;
		}
		else{
		    DDRA|=(z<<y);
		}		
	}
	else if (p=='B' || p=='b')
	{		
		if(y==8)
		{
			if(z==OUTPUT)
			DDRB=0xff;
			else
			DDRB=0x00;
			
		}
		else{
			DDRB|=(z<<y);
		}		
	}
	else if (p=='C' || p=='c')
	{
			if(y==8)
		{
			if(z==OUTPUT)
			DDRC=0xff;
			else
			DDRC=0x00;
		}
		else{
			DDRC|=(z<<y);
		}			
	}
	else if (p=='D' || p=='d')
	{
		if(y==8)
		{
			if(z==OUTPUT)
			DDRD=0xff;
			else
			DDRD=0x00;
		}
		else{
			DDRD|=(z<<y);	
		}			
	}
	
}


bool digitalRead(char p,int n)  // port, pin number
{
	
	if (p =='A' || p=='a')
	{
		if((PINA&int(pow(2,n)))==pow(2,n))
			return 1;
		    return 0;
	}
	else if (p=='B' || p=='b')
	{
		if((PINB&int(pow(2,n)))==pow(2,n))
			return 1;
		    return 0;
			
	}
	else if (p=='C' || p=='c')
	{
		if((PINC&int(pow(2,n)))==pow(2,n))
			return 1;
		    return 0;
	}
	else if (p=='D' || p=='d')
	{
		if((PIND&int(pow(2,n)))==pow(2,n))
			return 1;
		    return 0;
	}
	else
	{
		return 0;		
	}


}

unsigned int analogRead(unsigned char ch)//pin number
{
	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ch=ch&0b00000111;
	ADMUX|=ch;
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA&(1<<ADSC)));
	ADCSRA|=(1<<ADIF);
	return(ADC);

}

void delay(unsigned long mili){
	while(mili--)
	_delay_ms(1);
}
void delayMicroseconds(unsigned int micro){
	while (micro--)
	_delay_us(1);
}