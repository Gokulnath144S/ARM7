#include<lpc21xx.h>
void uart_config(void)
{		
	PINSEL0|=0x5;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0x3;
//	U0IER=(1<<0);
	
}
unsigned char uart_rx(void)
{		
	while((U0LSR&1)==0);
			return U0RBR;
}
void uart_tx(unsigned char rxbyte)
{ 
  U0THR=rxbyte;
  while(((U0LSR>>5)&1)==0);
}

void uartstr(unsigned char *s)
{
 while(*s)
 uart_tx(*s++);
}