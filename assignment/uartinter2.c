#include<lpc21xx.h>
#define LED 1<<17
#define SW 14
volatile int i=0;
unsigned char st[100],d;
void UART0_CONFIG(void);
unsigned char UART0_RX(void);
void UART0_TX(unsigned char);
void UART0_str(unsigned char*);
void UART0_ISR(void) __irq
{
	int temp;
	temp=U0IIR;
	if(temp==0x04)
	{
   		d=U0RBR;
		if(d!='\r')
		st[i++]=d;
		else
	     {
		 st[i]='\r';
		 st[i+1]='\0';
		  i=0;
		  U0THR = st[i++]; 
	}	   }
	if(temp == 0x02)
	{
		if(st[i]!='\0')
		{
			U0THR = st[i++];	
		}
		else
		{	  i=0;
			temp = U0IIR;
		}
	}			
VICVectAddr=0;
}
int main()
{
IODIR0=LED;
UART0_CONFIG();


VICIntSelect=0;
VICVectCntl0=(0x20)|6;
VICVectAddr0=(unsigned long)UART0_ISR;
U0IER=(1<<1)|(1<<0);
VICIntEnable=1<<6;

while(1)
{
if(
((IOPIN0>>SW)&1)==0)
IOSET0=LED;
else 
IOCLR0=LED;

}


								}
void UART0_CONFIG(void)
{
	PINSEL0|=0x05;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0x3;
}
void UART0_TX(unsigned char txbyte)
{U0THR=txbyte;
while(((U0LSR>>5)&1)==0);
}

unsigned char UART0_RX(void)
{while((U0LSR&1)==0);
return U0RBR;}


void UART0_str(unsigned char* s){
 while(*s)
 UART0_TX(*s++);
}