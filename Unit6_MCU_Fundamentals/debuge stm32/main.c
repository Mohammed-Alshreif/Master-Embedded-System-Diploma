
#include "stdint.h"
#define RCC_BASE   0x40021000
#define PORTA_BASE 0x40010800
#define PORTC_BASE 0x40011000

#define RCC_APB2ENR *((volatile uint32_t*)(RCC_BASE+0x18))
#define CRH *((volatile uint32_t*)(PORTA_BASE+0x04))
#define ODR *((volatile uint32_t*)(PORTA_BASE+0x0C))
#define CRH_PORTC *((volatile uint32_t*)(PORTC_BASE+0x04))
#define ODR_PORTC *((volatile uint32_t*)(PORTC_BASE+0x0C))
typedef union {
	volatile uint32_t all_bits ;
	struct {
		volatile uint32_t reserved :13;
		volatile uint32_t p13 :1;
	}pin;
}port;

int main(void)
{
	//volatile port* portA =(volatile port*)(PORTA_BASE+0x0C);
	volatile port* portC =(volatile port*)(PORTC_BASE+0x0C);
	//RCC_APB2ENR|=1<<2;
	RCC_APB2ENR|=1<<4;
	//CRH &=0x00000000;
	//CRH |=0x12121212;
	CRH_PORTC &=0x00000000;
	CRH_PORTC |=0x12121212;

	while(1){
		portC->pin.p13=0;
		for(int i=0;i<=50000;i++);
		portC->pin.p13=1;
		for(int i=0;i<=50000;i++);
	}
	return 0;
}
