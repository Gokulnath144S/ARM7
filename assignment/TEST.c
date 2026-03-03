#include<lpc21xx.h>
#include"lcdheader.h"

void LCD_STRING(unsigned char *s);
int main()
{int i,j,n;
 char s[40]="GOKULNATH IES ";
LCD_INIT();
LCD_CMD(0x80);
 
while(1)
{	 for(i=0;s[i];i++);
n=i;
 for(i=0;i<n;i++)
 {		LCD_CMD(0x80);
 for(j=0;j<16;j++)
 {		LCD_DATA(s[(i+j)%n]);
   
 }	  delay(1000);	
 LCD_CMD(0x01);}
}
}