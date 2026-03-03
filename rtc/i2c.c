#include<lpc21xx.h>
#include "rtcdefines.h"

void i2cinit()
{
 	PINSEL0|=0x50;
	I2SCLL=75;
	I2SCLH=75;
	I2CONSET=1<<6;
}
void i2cstart()
{
 	I2CONSET=1<<5;		  //start flag
	while(((I2CONSET>>3)&1)==0);	  //si bit
	I2CONCLR=1<<5;
}
void i2crestart()
{
 	I2CONSET=1<<5;		  //start flag
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);	  //si bit
	I2CONCLR=1<<5;
}

void i2cstop()
{
 	I2CONSET=1<<4;  //stop
		I2CONCLR=1<<3;
}

unsigned char nack(void)
{
 	unsigned char d;
	I2CONSET=0x00;
	I2CONCLR=1<<3;
//	I2CONCLR=0x04;
	while(((I2CONSET>>3)&1)==0);																																																																																																																																																		
	
	d=I2DAT;
	return d;
}

unsigned char masack(void)
{
 	unsigned char d;
	I2CONSET=0x04;
	I2CONCLR=1<<3;
	
	while(((I2CONSET>>3)&1)==0);																																																																																																																																																		
	 I2CONCLR=0x04;
	d=I2DAT;
	return d;
}
void i2cwrite(unsigned char d)
{
  I2DAT=d;
  I2CONCLR=1<<3;
  while(((I2CONSET>>3)&1)==0);
  }


