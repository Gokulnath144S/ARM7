#include<lpc21xx.h>
#define seg_d 0xff
#define seg_1 1<<8
#define seg_2 1<<9
#define seg_3 1<<10
#define seg_4 1<<11
void four_digit(int);
typedef unsigned char g1;
g1 s_lut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};

void delay(int s)
{T0PR=15000-1;
T0TCR=0x01;
while(T0TC<s);
T0TCR=0x03;
T0TCR=0x00;
}

int main()
{IODIR0=seg_d|seg_1|seg_2|seg_3|seg_4;
while(1)
{four_digit(4561);
}
}										                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     

void four_digit(int n)
{unsigned char l;
for(l=0;l<100;l++)
{IOCLR0=seg_d;
IOSET0=s_lut[n/1000];
IOCLR0=seg_1;
delay(5);
IOSET0=seg_1;

IOCLR0=seg_d;
IOSET0=s_lut[n/1000];
IOCLR0=seg_2;
delay(5);
IOSET0=seg_2;

IOCLR0=seg_d;
IOSET0=s_lut[(n/100)%10];
IOCLR0=seg_3;
delay(5);
IOSET0=seg_3;

IOCLR0=seg_d;
IOSET0=s_lut[(n/10)%10];
IOCLR0=seg_4;
delay(5);
IOSET0=seg_4;

}
}