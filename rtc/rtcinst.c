#include<lpc21xx.h>
#include "rtcdefines.h"



void rtcread(unsigned char w,unsigned char*p)
{	 int i;
	
	i2cstart();
	i2cwrite(slaveaddress<<1);
	i2cwrite(w);
	
	i2crestart();
	i2cwrite(slaveaddress<<1|1);
	for(i=0;i<3;i++)
	{ p[i]=masack();
	}
	p[i]=nack();
	i2cstop();
	 
}

unsigned char dectobin(unsigned char d)
{
  return(((d>>4)* 10)+(d&0x0f));

}
/*void rtcsettime(int s,int m,int h)
{
 	rtcwrite(0x00,dec(s)&0x7f);
	rtcwrite(0x01,dec(m));
	rtcwrite(0x02,dec(h));


} */
unsigned char dec(int n)
{
 	return (((n/10)<<4)|(n%10));

}

void rtcwrite(unsigned char reg,unsigned char* d)
{ int i;
   i2cstart();
   i2cwrite(slaveaddress<<1);
   i2cwrite(reg);
	for(i=0;i<3;i++)
   { i2cwrite(d[i]);
   }
   i2cstop();
   

}

