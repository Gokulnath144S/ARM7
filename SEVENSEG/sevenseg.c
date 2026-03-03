#include<lpc21xx.h>
#define seg_d 0xff
typedef unsigned char u8;
u8 seg_lut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};


void delay(int s)
{T0PR=15000-1;
T0TCR=0x01;
while(T0TC<s);
T0TCR=0x03;
T0TCR=0x00;
}

int main()
{u8 digit=0;
IODIR0=0xff;
while(digit<10)
{
IOCLR0=seg_d;
IOSET0=seg_lut[digit++];
delay(500);
}
}