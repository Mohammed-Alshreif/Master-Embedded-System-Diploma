/*
 * STM32f103c6.h
 *
 *  Created on: Sep 21, 2022
 *      Author: moalshreif
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdlib.h>
#include <stdint.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------
#define Flash_Memory_Bae   0x08000000UL
#define System_Memory_Base 0x1FFFF000UL
#define SRAM_Base          0x20000000UL
#define Peripherals_Base   0x40000000UL
#define Cortex_M3_Base     0xE0000000UL

#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE       	 0xE0000000UL


//NVIC register MAP
#define NVIC_BASE								     0xE000E100UL
#define NVIC_ISER0									 *(volatile uint32_t *)(NVIC_BASE + 0x00)
#define NVIC_ISER1									 *(volatile uint32_t *)(NVIC_BASE + 0x04)
#define NVIC_ISER2									 *(volatile uint32_t *)(NVIC_BASE + 0x08)
#define NVIC_ICER0									 *(volatile uint32_t *)(NVIC_BASE + 0x80)
#define NVIC_ICER1									 *(volatile uint32_t *)(NVIC_BASE + 0x84)
#define NVIC_ICER2									 *(volatile uint32_t *)(NVIC_BASE + 0x88)


//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_Base  0x40021000


//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
#define GPIOA_Base  0x40010800UL
#define GPIOB_Base  0x40010C00UL
#define GPIOC_Base  0x40011000UL
#define GPIOD_Base  0x40011400UL
#define GPIOE_Base  0x40011800UL

#define EXIT_Base   0x40010400UL

#define AFIO_Base   0x40010000UL

#define TIM1_Base   0x40012C00UL

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
#define TIM2_Base   0x40000000UL

//=================================================================//


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: TIMERS
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	volatile uint32_t TIMx_SMCR;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	volatile uint32_t TIMx_CCMR1;
	volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCER;
	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;
	volatile uint32_t TIMx_RCR;
	volatile uint32_t TIMx_CCR1;
	volatile uint32_t TIMx_CCR2;
	volatile uint32_t TIMx_CCR3;
	volatile uint32_t TIMx_CCR4;
	volatile uint32_t TIMx_BDTR;
	volatile uint32_t TIMx_DCR;
	volatile uint32_t TIMx_DMAR;

}TIMERS_typeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
}RCC_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t GPIOx_CRL;
	volatile uint32_t GPIOx_CRH;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_BRR;
	volatile uint32_t GPIOx_LCKR;
}GPIO_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXIT
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;
}EXIT_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t AFIO_EVCR;
	volatile uint32_t AFIO_MAPR;
	volatile uint32_t AFIO_EXTICR1;
	volatile uint32_t AFIO_EXTICR2;
	volatile uint32_t AFIO_EXTICR3;
	volatile uint32_t AFIO_EXTICR4;
	uint32_t Reserved;
	volatile uint32_t AFIO_MAPR2;
}AFIO_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA   ((GPIO_typeDef*) GPIOA_Base)
#define GPIOB   ((GPIO_typeDef*) GPIOB_Base)
#define GPIOC   ((GPIO_typeDef*) GPIOC_Base)
#define GPIOD   ((GPIO_typeDef*) GPIOD_Base)
#define GPIOE   ((GPIO_typeDef*) GPIOE_Base)

//=================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: TIM1
//-*-*-*-*-*-*-*-*-*-*-*
#define TIM1   ((TIMERS_typeDef*) TIM1_Base)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: TIM2
//-*-*-*-*-*-*-*-*-*-*-*
#define TIM2   ((TIMERS_typeDef*) TIM2_Base)

//=================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: RCC
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC    ((RCC_typeDef*) RCC_Base)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: EXIT
//-*-*-*-*-*-*-*-*-*-*-*
#define EXIT   ((EXIT_typeDef*) EXIT_Base)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
#define AFIO   ((AFIO_typeDef*) AFIO_Base)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define AFIO_Clock_Enable()    (RCC->RCC_APB2ENR |= 1<<0)
#define GPIOA_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<2)
#define GPIOB_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<3)
#define GPIOC_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<4)
#define GPIOD_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<5)
#define GPIOE_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<6)
#define TIMER1_CLOCK_Enable()  (RCC->RCC_APB2ENR |= 1<<11)
#define TIMER2_CLOCK_Enable()  (RCC->RCC_APB1ENR |= 1<<0)


/*------------------------------
 * NVIC IRQ enable/disable Macros
 */
#define NVIC_TIM1_BRK_Enable 				(NVIC_ISER0	|= 1<<24 )
#define NVIC_TIM1_UP_Enable 				(NVIC_ISER0	|= 1<<25 )
#define NVIC_TIM1_TRG_COM_Enable 			(NVIC_ISER0	|= 1<<26 )
#define NVIC_TIM1_CC_Enable 				(NVIC_ISER0	|= 1<<27 )
#define NVIC_TIM2_global_interrupt_Enable 	(NVIC_ISER0	|= 1<<28 )

#define NVIC_TIM1_BRK_Disable 				(NVIC_ICER0	 |= 1<<24)
#define NVIC_TIM1_UP_Disable 				(NVIC_ICER0 |= 1<<25 )
#define NVIC_TIM1_TRG_COM_Disable 		    (NVIC_ICER0 |= 1<<26 )
#define NVIC_TIM1_CC_Disable 				(NVIC_ICER0	 |= 1<<27)
#define NVIC_TIM2_global_interrupt_Disable 	(NVIC_ICER0	 |= 1<<28)
//=================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-

#endif /* INC_STM32F103C6_H_ */
