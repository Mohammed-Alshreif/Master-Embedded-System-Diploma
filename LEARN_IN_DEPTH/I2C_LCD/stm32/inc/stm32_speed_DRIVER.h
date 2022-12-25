/*
 * stm32_speed_DRIVER.h
 *
 *  Created on: Sep 27, 2022
 *      Author: 20102
 */

#ifndef STM32F103C6_DRIVERS_INC_STM32_SPEED_DRIVER_H_
#define STM32F103C6_DRIVERS_INC_STM32_SPEED_DRIVER_H_

//include=================================
#include "GPIO_DRIVER.h"
#include "STM32f103c6.h"

#define CLK_SORC_IN_CLK8MHz 0
#define CLK_SORC_EX_CLK4_16MHz 1


#define mood_FAST_MOOD_72MHzCORE 0
#define mood_defult_MOOD_8MHzCORE 1
#define mood_SLOW_MOOD_8MHzCORE 2

void MCAL_speed_init(uint8_t CLK_SORC ,uint8_t mood);

#endif /* STM32F103C6_DRIVERS_INC_STM32_SPEED_DRIVER_H_ */
