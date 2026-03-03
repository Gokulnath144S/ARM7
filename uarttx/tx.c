#include<lpc21xx.h>
void UART0_config(void);
void UART0_TX(unsigned char);
int main()
{
 PINSEL0|=0x5;
 UART0_config();
 while(1)
 {UART0_TX('A');
 }
}

void UART0_config(void)
{U0LCR=0x83;
U0DLL=97;
U0DLM=00;
U0LCR=0x3;

}
void UART0_TX(unsigned char tbyte)
{
 U0THR=tbyte;
 while(((U0LSR>>5)&1)==0);
}