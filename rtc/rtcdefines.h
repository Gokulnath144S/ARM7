#ifndef RTCDEFINES_H_
#define RTCDEFINES_H_
#define LCDHEADER_H_
#define slaveaddress 0x68

void i2cinit(void);
unsigned char masack(void);
void i2cstart(void);
void i2cstop(void);
void i2crestart(void);
unsigned char nack(void);
void i2cwrite(unsigned char d);
void rtcwrite(unsigned char reg,unsigned char* d);
void rtcread(unsigned char w,unsigned char* p);
unsigned char dectobin(unsigned char d);
void rtcsettime(int h,int m,int s);
unsigned char dec(int n);

//void LCD_display(int ,int ,int);

#endif
