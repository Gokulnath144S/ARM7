#include<lpc21xx.h>
//#include "lcdheader.h"
void UART0_CONFIG(void);
void UART0_TX(unsigned char);
unsigned char UART0_RX(void);
void UART0_str(unsigned char*);

int main()
{ unsigned char st[100];
int i=0;
char c;
	  PINSEL0=0x05;
UART0_CONFIG();
while(1)
{	 
if((c=UART0_RX())!='\r')
{
  st[i++]=c;	
}
else 
{//LCD_STRING(st);	
UART0_str(st);}}
}
void UART0_CONFIG(void)
{U0LCR=0x83;
U0DLL=97;
U0DLM=0;
U0LCR=0x03;
}
void UART0_TX(unsigned char txbyte)
{U0THR=txbyte;
while(((U0LSR>>5)&1)==0);
}

unsigned char UART0_RX(void)
{while(U0LSR&1==0);
return U0RBR;

}

void UART0_str(unsigned char* s){
 while(*s)
 UART0_TX(*s++);
}



