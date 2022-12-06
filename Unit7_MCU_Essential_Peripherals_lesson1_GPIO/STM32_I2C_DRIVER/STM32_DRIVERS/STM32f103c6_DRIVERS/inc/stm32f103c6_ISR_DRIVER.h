/*
 * stm32f103c6_ISR_DRIVER.h
 *
 *  Created on: Sep 27, 2022
 *      Author: 20102
 */

#ifndef STM32F103C6_DRIVERS_INC_STM32F103C6_ISR_DRIVER_H_
#define STM32F103C6_DRIVERS_INC_STM32F103C6_ISR_DRIVER_H_

//include     ============================
#include "stdio.h"
#include "stdint.h"
#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"


#define EXTI0 		0
#define EXTI1 		1
#define EXTI2 		2
#define EXTI3 		3
#define EXTI4 		4
#define EXTI5 		5
#define EXTI6 		6
#define EXTI7 		7
#define EXTI8 		8
#define EXTI9 		9
#define EXTI10 		10
#define EXTI11 		11
#define EXTI12 		12
#define EXTI13 		13
#define EXTI14 		14
#define EXTI15 		15


#define EXTI_Trigger_Rising					0
#define EXTI_Trigger_Falling				1
#define EXTI_Trigger_RisingAndFalling		2

/*------------------------------
 * NVIC IRQ enable/disable Macros
 */
#define NVIC_IRQ6_EXTI0_Enable 				(NVIC_ISER0	|= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable 				(NVIC_ISER0	|= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable 				(NVIC_ISER0	|= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable 				(NVIC_ISER0	|= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable 			(NVIC_ISER0	|= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable 			(NVIC_ISER0	|= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable 		(NVIC_ISER1	|= 1<<8)


#define NVIC_IRQ6_EXTI0_Disable 			(NVIC_ICER0	|= 1<<6)
#define NVIC_IRQ7_EXTI1_Disable 			(NVIC_ICER0	|= 1<<7)
#define NVIC_IRQ8_EXTI2_Disable 			(NVIC_ICER0	|= 1<<8)
#define NVIC_IRQ9_EXTI3_Disable 			(NVIC_ICER0	|= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable 			(NVIC_ICER0	|= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable 			(NVIC_ICER0	|= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable 		(NVIC_ICER1	|= 1<<8)



//*************************
 //API   ==  ==  ==  ==  ==
//*************************

void EXTI(GPIO_typeDef* PORTx ,uint16_t pin,uint16_t triggercase,void *function_addres(void));

#endif /* STM32F103C6_DRIVERS_INC_STM32F103C6_ISR_DRIVER_H_ */
