#include<lpc21xx.h>
#include"defines.h"
#include "lcdheader.h"

volatile int flag =0;
void uartinit(void);
unsigned char uartrx(void);
void timerinit(void);
//void enableIRQ(void)
//{
//    __asm
//    {
//        MRS R0, CPSR
//        BIC R0, R0, #0x80   // Clear I-bit (enable IRQ)
//        MSR CPSR_c, R0
//    }
//}
void timer_isr(void) __irq
{	 
	  flag=1;
	 T1IR=0x1;
//	 if(flag==0)
//	{
//	IOCLR0=led5;

//	}
		IOSET0=led5;
//	flag=0;}
	 VICVectAddr=0;

}
int main()
{	
	unsigned char ch;
	float f,temp;
	IODIR0|=led|led1|led2|led3|led5;
	IOSET0|=led|led1|led2|led3|led5;
	LCD_INIT();
	LCD_STRING("INDUSTRIAL AUTOMATION 4.0 USING IOT CLOUD");
//	delay(100);
	//LCD_CMD(0x01);
 	uartinit();
	timerinit();
//	enableIRQ();
	spiinit();

	while(1)
	{	 if(flag==1)
		{	flag=0;
			IOCLR0=led5;
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STRING("temp monitor"); 
 			f=adc(0);
			temp=f/0.01;
			LCD_CMD(0xc0);
			LCD_float(temp);
			if(temp>30)
				IOCLR0=buzzer;
			else
				IOSET0=buzzer;
				}
	ch=uartrx();
	//LCD_CMD(0x80);
	//LCD_DATA(ch);
	 switch(ch)
	 {	case 'c':IOCLR0=led;
			 	break;
	  	
	  	case 'd':IOSET0=led;
				break;
		 case 'a':IOCLR0=led1;
				break;
		case 'b':IOSET0=led1;
				break;
		case 'e':IOCLR0=led2;
				break;
		case 'f':IOSET0=led2;
				break; 
		case 'g':IOCLR0=led3;
				break;
		case 'h':IOSET0=led3;
				break;
	  }

	}

}

 void timerinit(void)
 {
  	T1MR0=7500000-1;
	T1MCR=0x03;
	VICIntSelect&=~(1<<5);;
	VICVectCntl0=(0x20)|5;
	
	VICVectAddr0=(unsigned long)timer_isr;
	VICIntEnable|=1<<5;
		T1TCR=0x1;
 }

void uartinit(void)
{
 	PINSEL0|=0x5;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0x3;

}
unsigned char uartrx(void)
{
 while((U0LSR&1)==0);
 return U0RBR;

}

