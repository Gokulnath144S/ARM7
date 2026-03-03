#include<lpc21xx.h>
#include"rtcdef.h"
 void i2cinit()
 {
  	PINSEL0|=0x50;
	I2SCLL=75;
	I2SCLH=75;
	I2CONSET=1<<6;

 }

 int bintodec(unsigned char d)
 {
  	return ((d>>4)*10)+(d&0x0f);

 }

 void rtcwrite(unsigned char reg,unsigned char d)
 {
  	   i2cstart();
	   i2cwrite(slaveaddress<<1);
	   i2cwrite(reg);
	   i2cwrite(d);
	   i2cstop();
 }

 unsigned char rtcread(unsigned char reg)
 {	 	
 		unsigned char p;
 		i2cstart();
	   i2cwrite(slaveaddress<<1);
	   i2cwrite(reg);
	   restart();
	   i2cwrite(slaveaddress<<1|1);
	   	 p=nack();
		 i2cstop();
		 return p;

 }

 void i2cstart()
 {
  	I2CONSET=1<<5;
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<5;
 }
 void i2cstop()
 {
  	I2CONSET=1<<4;
	I2CONCLR=1<<3;
 }
 void i2cwrite(unsigned char d)
 {
		I2DAT=d;
		I2CONCLR=1<<3;
		while(((I2CONSET>>3)&1)==0);

 }
 void restart()
 {	I2CONCLR=1<<3;
	I2CONSET=1<<5;
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<5;

 }

 unsigned char nack()
 {	
	I2CONSET=0x00;
	I2CONCLR=1<<3;
	 while(((I2CONSET>>3)&1)==0);
	 return I2DAT;

 }
