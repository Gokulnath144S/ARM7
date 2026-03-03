#include<lpc21xx.h>
#include"i2cdefines.h"

void eepromwrite(unsigned char slave,
			unsigned char dataadd,
			unsigned char data)

			{
			    i2cstart();
				i2cwrite(slave<<1);
				i2cwrite(dataadd);
				i2cwrite(data);
				i2cstop();
			}

unsigned char eepromread(unsigned char slave,unsigned char dataadd)
		{	   
				unsigned char c;
				i2cstart();
				i2cwrite(slave<<1);
				i2cwrite(dataadd);
				restart();
				i2cwrite(slave<<1|1);
				c=ack();
				i2cstop();
				return c;

				}
