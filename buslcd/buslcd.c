#include<lpc21xx.h>
#include"lcdheader.h"

unsigned char cgram_lut[]={
0x00,0x1f,0x11,0x11,0x11,0x11,0x1f,0x01,
0x01,0x01,0x01,0x01,0x1f,0x00,0x00,0x00,
0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00

} ;
void cgram_write(unsigned char );
void LCD_STRING(char *s);
int main()
{  char s[56]="Via Perungudi-Echangadu-Chromepet-Tambaram-vandalur Zoo"; 
int i,n,j;
LCD_INIT();
cgram_write(32);
LCD_CMD(0x80);
LCD_DATA(0);
 LCD_CMD(0xc0);
LCD_DATA(1);
LCD_CMD(0x81);
LCD_DATA(2);
LCD_CMD(0xc1);
LCD_DATA(3); 
LCD_CMD(0x84);
LCD_STRING("KILAMBAKKAM");
while(1)
{for(i=0;s[i];i++);
n=i;
for(i=0;i<n;i++)
{LCD_CMD(0xc2);
   for(j=0;j<16;j++)
 	{LCD_DATA(s[(i+j)%n]);
     
     } delay(250);
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

