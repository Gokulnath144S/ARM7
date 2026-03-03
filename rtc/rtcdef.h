#ifndef _RTCDEF_H
#define slaveaddress 0x68
void i2cinit(void);
 void rtcwrite(unsigned char reg,unsigned char d);
  unsigned char rtcread(unsigned char reg);
  void i2cstart(void);
   void i2cstop(void);
   void i2cwrite(unsigned char d);
   void restart(void);
   unsigned char nack(void);
   int bintodec(unsigned char d);


   #endif
