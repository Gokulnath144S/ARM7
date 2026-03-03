#ifndef _I2CDEFINES_H
#define  _I2CDEFINES_H

void i2cinit(void);
void i2cstart(void);
void i2cstop(void);
void i2cwrite(unsigned char d);
unsigned char i2cnack(unsigned char d);
void  restart(void);
unsigned char ack(void);

void eepromwrite(unsigned char slave,
			unsigned char dataadd,
			unsigned char data);

unsigned char eepromread(unsigned char slave,unsigned char dataadd);

#endif