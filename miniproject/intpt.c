#include <lpc21xx.h>
#include "intpt.h"

/* Configure UART0, EINT0, EINT1 interrupts */
void intpt(void)
{
    /* Pin select */
    PINSEL0 |= 0x20000000;   
    PINSEL1 |= 0x01;         
           

   
    VICIntSelect = 0x00000000;

    VICVectCntl1 = (0x20) | 14;
    VICVectAddr1 = (unsigned long)eint0_isr;
    VICIntEnable |= (1<<14);

    VICVectCntl2 = (0x20) | 15;
    VICVectAddr2 = (unsigned long)eint1_isr;
    VICIntEnable |= (1<<15);
	
		EXTMODE=0x03;
		EXTPOLAR=0x00;
}
