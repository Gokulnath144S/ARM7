#include<lpc21xx.h>
#include"rtcdef.h"
#include "lcdheader.h"
void LCD_display(int,int,int);
int main()
{	 int s,m,h;
 	i2cinit();
	LCD_INIT();
	LCD_STRING("TIME goes");
	rtcwrite(0x00,0x00);
	rtcwrite(0x01,0x00);
	rtcwrite(0x02,0x09);
	while(1)
	{
	 	s=bintodec(rtcread(0x00));
		m=bintodec(rtcread(0x01));
		h=bintodec(rtcread(0x02));
		LCD_display(h,m,s);

	}

}
void LCD_display(int h,int m,int s)
{
 	LCD_CMD(0xc0);
	LCD_INT(h);
	LCD_INT(m);
	LCD_INT(s);
}
