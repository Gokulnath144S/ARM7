#include<lpc21xx.h>
#include<string.h>
#include "intpt.h"
#include "uart.h"
#include "lcdheader.h"
#define PRICE1 15
#define PRICE2 10
#define book 1
#define pen 2
#define LED1 1<<3
#define LED2 1<<4
volatile int Total1=0;
volatile int Total2=0;
volatile int Total=0;
unsigned char id[13]="0600679AE41F";
unsigned char id1[13]="060067DBFC46";
volatile int lastitem=0;
unsigned char s[13],d;
volatile int bcount=0;
volatile int pcount=0;
volatile int flag=0;
volatile int uflag=0;
volatile int flag1=0;
volatile int i=0;

void eint0_isr(void) __irq
{	
			EXTINT=0x01;
			flag=1;
			VICVectAddr=0;
}

void eint1_isr(void) __irq
{	
			EXTINT=0x02;
			flag1=1;
			LCD_CMD(0x80);
			LCD_STRING("Reduction");
			VICVectAddr=0;
}



int main()
{		
		//IODIR0=LED1|LED2;
		LCD_INIT();
		uart_config();
		intpt();
		LCD_CMD(0x80);
		LCD_STRING("smart trolley using rfid");

 	
		while(1)
		{	
			
				if(flag)
					{		Total1=bcount*PRICE1;
							Total2=pcount*PRICE2;
						    Total=Total1+Total2;
							IOSET0=LED1;
							delay(50);
							IOCLR0=LED1;
							LCD_CMD(0x01);
							LCD_CMD(0x80);
							LCD_STRING("Book");
							LCD_CMD(0x87);
							LCD_INT(Total1);
							LCD_CMD(0xc0);
							LCD_STRING("Pen");
							LCD_CMD(0xc7);
							LCD_INT(Total2);
							LCD_CMD(0xcb);
							LCD_INT(Total);
							delay(900);
							LCD_CMD(0x01);
							flag=0;
					}
			 if(U0LSR&0X01)
			 {				
					for(i=0;i<12;i++)
						s[i]=uart_rx();

						s[i]='\0';
					if(strcmp(s,id)==0)
					{	
					    if(flag1)
						{
						   if(bcount>0)
						     { bcount--;
							  flag1=0; }
						}
					   else
					   {
					    	bcount++;
					   }
					   		LCD_CMD(0x01);
							LCD_CMD(0x80);
							LCD_STRING("Book");
							LCD_CMD(0x87);
							LCD_INT(bcount);
						}
					
						if(strcmp(s,id1)==0)
				     	{
							 if(flag1)
							{
						  		 if(pcount>0)
						    	  { pcount--;
								  flag1=0;}
							}
					   		else
					  		 {
					    		pcount++;
					 	 	 }
							 	LCD_CMD(0x01);
								LCD_CMD(0x80);
								LCD_STRING("Pen");
								LCD_CMD(0x87);
								LCD_INT(pcount);
						}
				}		
						
	 }



}