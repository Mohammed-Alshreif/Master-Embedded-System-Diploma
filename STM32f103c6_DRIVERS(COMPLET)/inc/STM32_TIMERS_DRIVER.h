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
#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"
#include "stm32_speed_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"


//@PWM
#define CH_1     1
#define CH_2     2
#define CH_3     3
#define CH_4     4
//@delay
#define U_ms     0 //milli seconds
#define U_us     1 //micro seconds
//===========================================
#define TIMER_START    1
#define TIMER_STOP     0
//==========================================
#define WAVE_NUMBER_4   4
#define WAVE_NUMBER_5   5
#define WAVE_NUMBER_6   6
#define WAVE_NUMBER_7   7
#define WAVE_NUMBER_8   8
#define WAVE_NUMBER_9   9
#define WAVE_NUMBER_10  10
#define WAVE_NUMBER_11  11
#define WAVE_NUMBER_12  12
#define WAVE_NUMBER_13  13
//======================================
#define direction_unticlk 1
#define direction_clk     0

//======================================

//======================================
/*
//timer1 ch_1 --> A8  <> timer2 ch_1 --> A0 <> timer3 ch_1 --> A6 <> timer4 ch_1 --> B6
//timer1 ch_2 --> A9  <> timer2 ch_2 --> A1 <> timer3 ch_2 --> A7 <> timer4 ch_2 --> B7
//timer1 ch_3 --> A10 <> timer2 ch_3 --> A2 <> timer3 ch_3 --> B0 <> timer4 ch_3 --> B8
//timer1 ch_4 --> A11 <> timer2 ch_4 --> A3 <> timer3 ch_4 --> B1 <> timer4 ch_4 --> B9
*/
void PWM(TIMERS_typeDef* TIMERx,uint32_t CH,uint32_t duty_cycle,uint32_t freq,uint32_t clk);


//Enter in while loop and after timer interrupt it break the loop
void delay(float time,uint8_t U,uint32_t clk);


void TIMER_ISR(TIMERS_typeDef* ISR_TIMER,uint16_t time_ms,uint8_t U,uint32_t clk,void (*calback) (void));
uint32_t TIME_CALCULATION(uint32_t clk,uint8_t TIMER_ST);


//========================SPWM==================
void SPWM_SINGLE_PHASE_INIT(uint8_t WAVE_NUMBER,uint8_t freq,uint32_t clk);
void SPWM_WRITE(uint8_t freq,uint8_t WAVE_NUMBER,uint32_t clk);

void stepper_motor_steps(uint32_t CH,GPIO_typeDef* GPIOx,uint16_t pin,uint32_t num_steps,uint32_t duty_cycle,uint32_t freq,uint8_t direction_,uint32_t clk);
#endif /* INC_STM32_TIMERS_DRIVER_H_ */
