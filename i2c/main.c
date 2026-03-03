#include<lpc21xx.h>
#include "i2cdefines.h"


#include"lcdheader.h"
int main()
{	   char ch;
	//PINSEL0|=0x5;
	i2cinit();
	LCD_INIT();
	LCD_STRING("I2C");
	eepromwrite(0x50,0x00,'G');
	delay(10);
	ch=eepromread(0x50,0x00);
	
	LCD_CMD(0xc0);
	LCD_DATA(ch);
	 while(1);

}
