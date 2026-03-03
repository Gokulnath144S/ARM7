#ifndef __INTPT_H__
#define __INTPT_H__

void intpt(void);


void eint0_isr(void) __irq;
void eint1_isr(void) __irq;

#endif
