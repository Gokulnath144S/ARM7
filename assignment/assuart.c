#include <lpc21xx.h>

#define LED (1<<5)
#define SW  14

void UART0_config(void);
void UART0_isr(void) __irq;

char s[] = "gokul";
volatile int i = 0;

void UART0_isr(void) __irq
{ int temp;
    if (U0LSR & (1<<5)) // THR empty
    {
        if (s[i] != '\0')
        {
            U0THR = s[i++];
        }
        else
        {
            i = 0;             // reset index
           
	   temp=U0IIR;  // disable THRE interrupt
        }
    }
    VICVectAddr = 0;
}

int main()
{
    IODIR0 = LED;
    UART0_config();

    VICIntSelect = 0;
    VICVectCntl0 = (0x20 | 6);
    VICVectAddr0 = (unsigned long)UART0_isr;
    VICIntEnable |= (1<<6);

    U0IER = (1<<1);   // enable THRE interrupt
    U0THR = s[i++];   // start transmission

    while(1)
    {
        if(((IOPIN0 >> SW) & 1) == 0)
            IOCLR0 = LED;
        else
            IOSET0 = LED;
    }
}

void UART0_config(void)
{
    PINSEL0 |= 0x05;
    U0LCR = 0x83;
    U0DLL = 97;
    U0DLM = 0;
    U0LCR = 0x03;
}
