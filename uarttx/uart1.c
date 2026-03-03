#include<lpc21xx.h>

unsigned char s[20];
unsigned char uartrx(void);
void uarttx(unsigned char d);
void uartinit(void);
int main()
{
	int i=0;
	 char c;
	uartinit();
	while(1)
	{
	 
			  while((c=uartrx())!='\r')
					s[i++]=c;
			s[i]='\0';

			for(i=0;s[i];i++)
			{
			 	if(s[i]!='a'&& s[i]!='e'&& s[i]!='o'&& s[i]!='u')
					uarttx(s[i]);
			}

	}

}
void uartinit(void)
{
	PINSEL0|=0x05;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0x03;

}

void uarttx(unsigned char d)
{
 	  U0THR=d;
	  while(((U0LSR>>5)&1)==0);

}

unsigned char uartrx(void)
{
 	while((U0LSR&1)==0);
	return U0RBR;
}