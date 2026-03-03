#include<lpc21xx.h>
#define LED 0xf<<4
#define RS 1<<8
#define E 1<<9
void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void delay(int );
void LCD_STRING(unsigned char *s);


void LCD_INIT(void)
{IODIR0=LED|RS|E;
LCD_CMD(0x01);
LCD_CMD(0x02);
LCD_CMD(0x0c);
LCD_CMD(0x28);


}
void LCD_CMD(unsigned char cmd)
{IOCLR0=LED;
IOSET0=((cmd>>4)&0x0f)<<4;
IOCLR0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;

IOCLR0=LED;
IOSET0=(cmd&0x0f)<<4;
IOCLR0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}
void LCD_DATA(unsigned char d)
{IOCLR0=LED;
IOSET0=((d>>4)&0x0f)<<4;
IOSET0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;

IOCLR0=LED;
IOSET0=(d&0x0f)<<4;
IOSET0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}

void delay(int s)
{T0PR=15000-1;
T0TCR=0x01;
while(T0TC<s);
T0TCR=0x03;
T0TCR=0x00;
}
void LCD_STRING(unsigned char *s)
{
  while(*s)
 LCD_DATA(*s++);

}