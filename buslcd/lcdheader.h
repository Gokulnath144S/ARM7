 #include<lpc21xx.h>

#define lcd_l 0xff
#define RS 1<<8
#define E 1<<9

void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void delay(int s)
{T0PR=15000-1;
T0TCR=0x01;
while(T0TC<s);
T0TCR=0x03;
T0TCR=0x00;
}


void LCD_INIT(void)
{IODIR0=lcd_l|RS|E;
LCD_CMD(0X01);
LCD_CMD(0X02);
LCD_CMD(0X0C);
LCD_CMD(0x06);
LCD_CMD(0X38);
}
void LCD_CMD(unsigned char cmd)
{
IOCLR0=lcd_l;
IOSET0=cmd;
IOCLR0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}
void LCD_DATA(unsigned char d)
{
IOCLR0=lcd_l;
IOSET0=d; 
IOSET0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}
