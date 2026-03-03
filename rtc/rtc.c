#include<lpc21xx.h>
#include "rtcdefines.h"
#include"lcdheader.h"
unsigned char arr[3]={0x00,0x01,0x02};
;
unsigned char p[3] __attribute__((at(0x40000040)));
void LCD_display(int ,int ,int);
int main()
{	
	 int s,m,h;
	i2cinit();
	LCD_INIT();
	LCD_CMD(0x80);
	LCD_STRING("RTC");

/*	rtcwrite(0x00,0x03);
	rtcwrite(0x01,0x15);
	rtcwrite(0x02,0x00);	 */
		rtcwrite(0x00,arr); 
		delay(10);
		  
	  	while(1)
		{	
		rtcread(0x00,p);
	  	s=dectobin(p[0]);
		m=dectobin(p[1]);
		h=dectobin(p[2]);
		LCD_display(h,m,s);  
		}//LCD_STRING(p);
	
}
void LCD_display(int h,int y,int z)
{
 LCD_CMD(0xc0);
 //LCD_DATA('g');
 LCD_INT(h);
 LCD_STRING(":");
 LCD_INT(y);
 LCD_STRING(":");
 LCD_INT(z);



}
