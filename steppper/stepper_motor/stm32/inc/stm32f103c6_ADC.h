/*
 * stm32f103c6_ADC.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Mohammed Alshreif
 */
#ifndef INC_STM32F103C6_ADC_H_
#define INC_STM32F103C6_ADC_H_

#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"

#define ADC_STATE_START  1
#define ADC_STATE_STOP   0


#define ADC_pin_PA0  0b0000
#define ADC_pin_PA1  0b0001
#define ADC_pin_PA2  0b0010
#define ADC_pin_PA3  0b0011
#define ADC_pin_PA4  0b0100
#define ADC_pin_PA5  0b0101
#define ADC_pin_PA6  0b0110
#define ADC_pin_PA7  0b0111
#define ADC_pin_PB0  0b1000
#define ADC_pin_PB1  0b1001

//================= API ================

void ADC_INIT(ADC_typeDef* ADCx,uint8_t ADC_STATE_);

uint16_t ADC_READ(ADC_typeDef* ADCx,uint8_t ADC_pin);

#endif /* INC_STM32F103C6_ADC_H_ */
