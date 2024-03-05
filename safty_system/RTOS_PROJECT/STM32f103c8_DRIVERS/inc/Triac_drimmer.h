/*
 * Triac_drimmer.h
 *
 *  Created on: Jul 12, 2023
 *      Author: 20102
 */

#ifndef INC_TRIAC_DRIMMER_H_
#define INC_TRIAC_DRIMMER_H_

#include "STM32_TIMERS_DRIVER.h"
#include "GPIO_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"

#define TRIAC_PIN pin0
#define ZERO_CROS_PIN pin4
#define Drimer_POART GPIOB

void Drimmer_init(void);
void Drimer_set(uint16_t DRIM);

#endif /* INC_TRIAC_DRIMMER_H_ */
