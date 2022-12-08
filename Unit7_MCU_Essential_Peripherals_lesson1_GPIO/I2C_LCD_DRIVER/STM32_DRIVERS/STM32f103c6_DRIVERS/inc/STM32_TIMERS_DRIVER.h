/*
 * STM32_TIMERS_DRIVER.h
 *
 *  Created on: Nov 3, 2022
 *      Author: 20102
 */

#ifndef INC_STM32_TIMERS_DRIVER_H_
#define INC_STM32_TIMERS_DRIVER_H_
//include     ============================
#include "stdio.h"
#include "stdint.h"
#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"

#define CH_1     1
#define CH_2     2
#define CH_3     3
#define CH_4     4

#define U_ms     0 //milli seconds
#define U_us     1 //micro seconds


void PWM(TIMERS_typeDef* TIMERx,uint32_t CH,uint32_t duty_cycle,uint32_t freq,uint32_t clk);
void delay(uint16_t time,uint8_t U,uint32_t clk);
//void TIMER_ISR(TIMERS_typeDef* ISR_TIMER,uint16_t time_ms,uint32_t clk,void *calback(void));
#endif /* INC_STM32_TIMERS_DRIVER_H_ */
