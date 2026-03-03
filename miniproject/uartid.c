#include<lpc21xx.h>
#include "uart.h"
#include "lcdheader.h"
#include"uart.c"




int main()
{
int i=0;
  unsigned char s[13];
   uart_config();
  LCD_INIT();
 
  // LCD_DATA('a');
  while(1)
  {	  
     for(i=0;i<12;i++)
		s[i]=uart_rx();
		s[i]='\0';
	  	LCD_STRING(s);
		delay(500);
		LCD_CMD(0x01);
		uartstr(s);
   }

	
}

