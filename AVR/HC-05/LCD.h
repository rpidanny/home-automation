#ifndef _LCD_H_
#define _LCD_H_
/*
  LCD.h - Liquid Crystal Display library for AVR Microcontroller
  Author: Abhishek Maharjan, abhishekmaharjan1993@gmail.com
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; 
*/

/*
*/

class LCD{
	char LCD_DATA ;
	char ctrl ;
	int en;		
	int rw;		
	int rs;	
	public:
	
	LCD(char DATA,char Control,int enable,int readwrite,int reset);
	void cmd(unsigned char cmd);
	void init(void);
	void write(unsigned char data);
	void Print(const char*,int=0,int=0);
	void Print(unsigned int,int=0,int=0);
};

#endif