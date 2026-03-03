#include<lpc21xx.h>
#include"defines.h"
#include"lcdheader.h"
int main()
{
	float f,temp;
 	spiinit();
	LCD_INIT();
	LCD_CMD(0X80);
	LCD_STRING("SPI READING");
	while(1)
	{
			
			f=adc(0);
			temp=f/0.01;
			LCD_CMD(0xc0);
			LCD_float(temp);
			delay(500);
			//LCD_CMD(0x01);

	}



}
