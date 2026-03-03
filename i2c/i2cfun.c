#include<lpc21xx.h>
#include"i2cdefines.h"
void i2cinit(void)
{
 	PINSEL0|=0x50;
	I2SCLL=75;
	I2SCLH=75;
	I2CONSET=1<<6;
}

void i2cstart(void)
{
 	I2CONSET=1<<5;	//startbitflag
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<5; //clearstartbitflag
}

void i2cstop(void)
{	I2CONCLR=1<<3;//clear si   bit
 	I2CONSET=1<<4; //stopflag	
}
void i2cwrite(unsigned char d)
{
 	I2DAT=d;			  //load data
	I2CONCLR=1<<3;//clear si bit
	while(((I2CONSET>>3)&1)==0);
}
unsigned char ack(void)
{
   	I2CONCLR=0x00;
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
   return I2DAT;
}
void  restart(void)
{
 	I2CONSET=1<<5;
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<5;
}

unsigned char nack(void)
{
 	I2CONSET=1<<2;
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<2;
	return I2DAT;

}