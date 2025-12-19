#include<lpc21xx.h>
#include "lcdheader.h"
volatile int roll=1;
 unsigned char cgram_lut[]={
0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,
0x00,0x0a,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x0a,0x00,0x00,0x00,0x0a,0x00,0x00,
0x00,0x0a,0x00,0x04,0x00,0x0a,0x00,0x00,
0x00,0x0a,0x00,0x0a,0x00,0x0a,0x00,0x00
} ;

void cgram_write(unsigned char bytes);
void LCD_STRING(char*s);
void delays(int s);
int main()
{char symbol;
int i=0;
char history[10];
LCD_INIT();
LCD_CMD(0x80);
LCD_STRING("DIGITAL DICE");
cgram_write(48);
while(1)
{if(roll)
   {   LCD_CMD(0x8c);
   LCD_DATA(symbol);
   symbol++;
   if(symbol==6)
   symbol=0;
   }


if(((IOPIN0>>14)&1)==0)
{roll=0;
delays(3000);
for(i=0;i<9;i++)
{history[10-1-i]=history[10-2-i];
if(symbol == 0)
	symbol = 6;

} 
if(symbol == 0)
	symbol = 6;
else
history[0]=symbol;

roll=1;
while(((IOPIN0>>14)&1)==0);
}
if(((IOPIN0>>15)&1)==0)
{LCD_CMD(0xc0);
 for(i=0;i<10;i++)
	LCD_DATA(history[i]+48);

while(((IOPIN0>>15)&1)==0);
}
	 }
}

void cgram_write(unsigned char bytes)

{  unsigned char i;

LCD_CMD(0x40);

for(i=0;i<bytes;i++)

LCD_DATA(cgram_lut[i]);

}

void LCD_STRING(char*s)

{while(*s)

LCD_DATA(*s++);


}
void delays(int s)
{int i,j;
for(i=0;i<=s;i++)
for(j=12000;j>=0;j--);

}