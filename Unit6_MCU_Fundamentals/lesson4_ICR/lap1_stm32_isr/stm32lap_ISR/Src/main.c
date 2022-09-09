#include "stdint.h"
#define RCC_BASE   0x40021000
#define PORTA_BASE 0x40010800
#define PORTC_BASE 0x40011000
#define EXTI       0x40010400
#define AFIO 	   0x40010000

#define RCC_APB2ENR *((volatile uint32_t*)(RCC_BASE+0x18))
#define PORTA_CRL *((volatile uint32_t*)(PORTA_BASE+0x00))
#define ODR *((volatile uint32_t*)(PORTA_BASE+0x0C))
#define CRH_PORTC *((volatile uint32_t*)(PORTC_BASE+0x04))
#define ODR_PORTC *((volatile uint32_t*)(PORTC_BASE+0x0C))


#define EXTI_IMR *((volatile uint32_t*)(EXTI+0x00)) //Configure the mask bits of the 20 Interrupt lines (EXTI_IMR)
#define EXTI_RTSR *((volatile uint32_t*)(EXTI+0x08)) //Rising trigger selection register (EXTI_RTSR)
#define EXTI_PR *((volatile uint32_t*)(EXTI+0x14)) //Pending register (EXTI_PR)
#define AFIO_EXTICR1 *((volatile uint32_t*)(AFIO+0x08)) //External interrupt configuration register 1 (AFIO_EXTICR1)

#define NVIC_EXTIE0 *((volatile uint32_t*)(0xE000E100))
typedef union {
	volatile uint32_t all_bits ;
	struct {
		volatile uint32_t reserved :13;
		volatile uint32_t p13 :1;
		volatile uint32_t p14 :1;
	}pin;
}port;
volatile port* portC =(volatile port*)(PORTC_BASE+0x0C);
int main(void)
{
	//volatile port* portA =(volatile port*)(PORTA_BASE+0x0C);


	RCC_APB2ENR|=1<<2;
	RCC_APB2ENR|=1<<4;
	RCC_APB2ENR|=1<<0;	//AFIO EN
	NVIC_EXTIE0 |=(1<<6);

	//CRH &=0x00000000;
	//CRH |=0x12121212;
	CRH_PORTC &=0x00000000;
	CRH_PORTC |=0x12121212;

	PORTA_CRL |=(1<<2);


	EXTI_IMR |=(1<<0);   //1: Interrupt request from Line x is not masked
	EXTI_RTSR |=(1<<0);  //1 Rising trigger enabled (for Event and Interrupt) for input line.

	AFIO_EXTICR1=0;
	while(1)
	{
	  portC->pin.p14=0;
	  for(int i=0;i<=50000;i++);
	  portC->pin.p14=1;
	  for(int i=0;i<=50000;i++);
	}

	return 0;
}

void EXTI0_IRQHandler()
{
	portC->pin.p13 ^=1;

	EXTI_PR |=(1<<0);
}
