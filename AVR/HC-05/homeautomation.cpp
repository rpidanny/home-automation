/*
 * homeautomation.cpp
 *
 * Created: 7/6/2014 1:25:55 PM
 *  Author: Danny
 */ 

#define F_CPU 8000000UL

#include <avr/interrupt.h>
#include "USART.h"

void CheckButtons();

int timercount=0;


int light1flag=0;
int light2flag=0;
int light3flag=0;
int light4flag=0;

char tempdata;


ISR (TIMER2_OVF_vect)
{

   timercount++;
   if(timercount==20)
   {
		PORTD^=0b10000000;
		 timercount=0;
   }
}

int main(void)
{	
	
	TCCR2|=(1<<CS22)|(1<<CS20)|(1<<CS21);
	TIMSK|=(1<<TOIE2);
	TCNT2=0;
	
	Serial.begin(9600);
	DDRD=0x80;
	DDRA=0x00;
	PORTA=0x00;
	DDRC=0xff;
	PORTC=0x00;

	
	sei();
	while(1)
    {
		if (Serial.available())
		{
			tempdata=Serial.read();
			if(tempdata=='1')
				{
					PORTC^=0b00000001;
									
				}
			else if(tempdata=='2')
				{
					PORTC^=0b00000010;					
				}
			else if(tempdata=='3')
				{
					PORTC^=0b00000100;					
				}
			else if(tempdata=='4')
				{
					PORTC^=0b00001000;					
				}
			_delay_ms(50);      

		}
	else{
	
			if(bit_is_set(PINA, PA0))
			{
				_delay_ms(80);
					if(bit_is_set(PINA, PA0))
					{
						_delay_ms(20);
						PORTC^=0b00000001;
						//systemonlineflag=1;				
					}
			}
	
			else if(bit_is_set(PINA, PA1))
			{
				_delay_ms(80);
					if(bit_is_set(PINA, PA1))
					{
						_delay_ms(20);
						PORTC^=0b00000010;
						//systemonlineflag=1;				
					}
			}
	
			else if(bit_is_set(PINA, PA2))
			{
				_delay_ms(80);
					if(bit_is_set(PINA, PA2))
					{
						_delay_ms(20);
						PORTC^=0b00000100;
					}
			}	
	
			else if(bit_is_set(PINA, PA3))
			{
				_delay_ms(80);
					if(bit_is_set(PINA, PA3))
					{
						_delay_ms(20);
						PORTC^=0b00001000;
					}
			}	
				
			_delay_ms(100);
			
		}
		//CheckButtons();
		
    }
}

/*
void gotoXY(int x,int y)
{
	if(x<40)
	{
		if(y) x|=0b01000000;
		x|=0b10000000;
		lcd.cmd(x);
	}
}*/


//void CheckButtons()
