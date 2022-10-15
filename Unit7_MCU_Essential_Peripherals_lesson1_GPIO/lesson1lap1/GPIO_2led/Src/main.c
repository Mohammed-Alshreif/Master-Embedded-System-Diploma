/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "stdint.h"
#define RCC_BASE   0x40021000
#define PORTA_BASE 0x40010800

#define GPIOA_CRL *((volatile unsigned long*)(PORTA_BASE+0x00))
#define GPIOA_ODR *((volatile unsigned long*)(PORTA_BASE+0x0C))
#define GPIOA_IDR *((volatile unsigned long*)(PORTA_BASE+0x08))
#define RCC_APB2ENR *((volatile unsigned long*)(RCC_BASE+0x18))

typedef struct {
	volatile unsigned long res1 :1;
	volatile unsigned long p1   :1;
	volatile unsigned long res2 :1;
	volatile unsigned long p3   :1;
}PORT;

volatile PORT* portA =(volatile PORT*)(PORTA_BASE+0x0C);
char flag1=1;
int main(void)
{
	RCC_APB2ENR |=(1<<2);
	GPIOA_CRL &=0x00000000;
	GPIOA_CRL |=(0b0001100000011000<<0);
	GPIOA_ODR &=~(1<<0);
	GPIOA_ODR &=~(1<<2);

	while(1)
	{

		if((((GPIOA_IDR>>0)&1)==1))
		{
			if(flag1==1)
			{
				portA->p1^=1;
				flag1=0;
			}

		}

		else flag1=1;

		if(((GPIOA_IDR>>2)&1)==1)
		{
			portA->p3^=1;
		}
		for(int i=0;i<500;i++);
	}
}