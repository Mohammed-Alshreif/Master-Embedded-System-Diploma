/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohammed Alshreif
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

#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"
#include "stm32_speed_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"
#include "LCD.h"
#include <math.h>
//===============================
TIMERS_typeDef * pwm = TIM1;
TIMERS_typeDef * SPWM3PHASE = TIM2;
TIMERS_typeDef * half_wave = TIM3;
//===============================
long x=500;
char flage2=0,flage1=1,flage3=1;
long top=255,presc=0;
long f=32000;
//===============================
int var1 = 0;
int var2 = 0;
int var3 = 0;
int var4 = 0;
int var5 = 0;
int var6 = 0;
//===============================
float Phase1 = 2 * M_PI / 3;
float Phase2 = 4 * M_PI / 3;
float Phase3 = 2 * M_PI;
float A = 0;
float B = .5;
//==============================
int user_freq=1;
int user_freq_control=1;
int user_pre=1;
long user_top=1;
//===========================================================================
//###########################################################################
void timer_INIT_CH2(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ){

	//pwm->TIMx_CR1 &=~(1<<0);

	//	Bit 11 OC2PE: Output Compare 1 preload enable
	//	0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the
	//	new value is taken in account immediately.
	//	1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload
	//	register. TIMx_CCR1 preload value is loaded in the active register at each update event.
	//	Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed
	//	(LOCK bits in TIMx_BDTR register) and CC1S=’00’ (the channel is configured in
	//	output).
	//	2: The PWM mode can be used without validating the preload register only in one
	//	pulse mode (OPM bit set in TIMx_CR1 register). Else the behavior is not guaranteed.

	pwm->TIMx_CCMR1 |=(1<<11);

	pwm->TIMx_CCER |=(1<<4);
	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered

	pwm->TIMx_CR1 |=(1<<7);


	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	pwm->TIMx_CCMR1 |=(0b110<<12);

	pwm->TIMx_ARR=peak;//frec peak value
	pwm->TIMx_CCR2=(duty_cycle);//duty cycle
	pwm->TIMx_PSC=pre;//prescaller

	//	Bit 15 MOE: Main output enable
	//	This bit is cleared asynchronously by hardware as soon as the break input is active. It is set
	//	by software or automatically depending on the AOE bit. It is acting only on the channels
	//	which are configured in output.
	//	0: OC and OCN outputs are disabled or forced to idle state.
	//	1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in
	//	TIMx_CCER register).
	//	See OC/OCN enable description for more details
	pwm->TIMx_BDTR |=(1<<15);

	//	Bit 2 CC2IE: Capture/Compare 2 interrupt enable
	//	0: CC2 interrupt disabled
	//	1: CC2 interrupt enabled
	//	Bit 1 CC1IE: Capture/Compare 1 interrupt enable
	//	0: CC1 interrupt disabled
	//	1: CC1 interrupt enabled
	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	pwm->TIMx_DIER |=(0b101<<0);

	//	UG: Update generation
	//	This bit can be set by software, it is automatically cleared by hardware.
	//	0: No action
	//	1: Reinitialize the counter and generates an update of the registers. Note that the prescaler
	//	counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//	the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//	value (TIMx_ARR) if DIR=1 (downcounting).
	pwm->TIMx_EGR |=(1<<0);

	//pwm->TIMx_CR1 |=(1<<0);//enable the timer


}
//===========================================================================
//###########################################################################
void timer_INIT_CH1(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ){

	//	Bit 3 OC1PE: Output Compare 1 preload enable
	//	0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the
	//	new value is taken in account immediately.
	//	1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload
	//	register. TIMx_CCR1 preload value is loaded in the active register at each update event.
	//	Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed
	//	(LOCK bits in TIMx_BDTR register) and CC1S=’00’ (the channel is configured in
	//	output).
	//	2: The PWM mode can be used without validating the preload register only in one
	//	pulse mode (OPM bit set in TIMx_CR1 register). Else the behavior is not guaranteed.
	pwm->TIMx_CCMR1 |=(1<<3);


	//	Bit 0 CC1E: Capture/Compare 1 output enable
	//	CC1 channel configured as output:
	//	0: Off - OC1 is not active. OC1 level is then function of MOE, OSSI, OSSR, OIS1, OIS1N
	//	and CC1NE bits.
	//	1: On - OC1 signal is output on the corresponding output pin depending on MOE, OSSI,
	//	OSSR, OIS1, OIS1N and CC1NE bits.
	//	CC1 channel configured as input:
	//	This bit determines if a capture of the counter value can actually be done into the input
	//	capture/compare register 1 (TIMx_CCR1) or not.
	//	0: Capture disabled.
	//	1: Capture enabled.
	pwm->TIMx_CCER |=(1<<0);


	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered
	pwm->TIMx_CR1 |=(1<<7);


	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	pwm->TIMx_CCMR1 |=(0b110<<4);

	pwm->TIMx_ARR=peak;//frec peak value
	pwm->TIMx_CCR1=(duty_cycle);//duty cycle
	pwm->TIMx_PSC=pre;//prescaller

	//	Bit 15 MOE: Main output enable
	//	This bit is cleared asynchronously by hardware as soon as the break input is active. It is set
	//	by software or automatically depending on the AOE bit. It is acting only on the channels
	//	which are configured in output.
	//	0: OC and OCN outputs are disabled or forced to idle state.
	//	1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in
	//	TIMx_CCER register).
	//	See OC/OCN enable description for more details
	pwm->TIMx_BDTR |=(1<<15);

	//	Bit 2 CC2IE: Capture/Compare 2 interrupt enable
	//	0: CC2 interrupt disabled
	//	1: CC2 interrupt enabled
	//	Bit 1 CC1IE: Capture/Compare 1 interrupt enable
	//	0: CC1 interrupt disabled
	//	1: CC1 interrupt enabled
	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	pwm->TIMx_DIER |=(0b111<<0);

	//	UG: Update generation
	//	This bit can be set by software, it is automatically cleared by hardware.
	//	0: No action
	//	1: Reinitialize the counter and generates an update of the registers. Note that the prescaler
	//	counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//	the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//	value (TIMx_ARR) if DIR=1 (downcounting).
	pwm->TIMx_EGR |=(1<<0);

	//pwm->TIMx_CR1 |=(1<<0);//enable the timer


}

//===========================================================================
//###########################################################################
void timer_INIT_CH3(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ){

	//	Bit 3 OC3PE: Output Compare 1 preload enable
	//	0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the
	//	new value is taken in account immediately.
	//	1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload
	//	register. TIMx_CCR1 preload value is loaded in the active register at each update event.
	//	Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed
	//	(LOCK bits in TIMx_BDTR register) and CC1S=’00’ (the channel is configured in
	//	output).
	//	2: The PWM mode can be used without validating the preload register only in one
	//	pulse mode (OPM bit set in TIMx_CR1 register). Else the behavior is not guaranteed.
	pwm->TIMx_CCMR2 |=(1<<3);


	//	Bit 8 CC3E: Capture/Compare 1 output enable
	//	CC1 channel configured as output:
	//	0: Off - OC1 is not active. OC1 level is then function of MOE, OSSI, OSSR, OIS1, OIS1N
	//	and CC1NE bits.
	//	1: On - OC1 signal is output on the corresponding output pin depending on MOE, OSSI,
	//	OSSR, OIS1, OIS1N and CC1NE bits.
	//	CC1 channel configured as input:
	//	This bit determines if a capture of the counter value can actually be done into the input
	//	capture/compare register 1 (TIMx_CCR1) or not.
	//	0: Capture disabled.
	//	1: Capture enabled.
	pwm->TIMx_CCER |=(1<<8);


	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered
	pwm->TIMx_CR1 |=(1<<7);


	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	pwm->TIMx_CCMR2 |=(0b110<<4);

	pwm->TIMx_ARR=peak;//frec peak value
	pwm->TIMx_CCR3=(duty_cycle);//duty cycle
	pwm->TIMx_PSC=pre;//prescaller

	//	Bit 15 MOE: Main output enable
	//	This bit is cleared asynchronously by hardware as soon as the break input is active. It is set
	//	by software or automatically depending on the AOE bit. It is acting only on the channels
	//	which are configured in output.
	//	0: OC and OCN outputs are disabled or forced to idle state.
	//	1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in
	//	TIMx_CCER register).
	//	See OC/OCN enable description for more details
	pwm->TIMx_BDTR |=(1<<15);

	//	Bit 2 CC2IE: Capture/Compare 2 interrupt enable
	//	0: CC2 interrupt disabled
	//	1: CC2 interrupt enabled
	//	Bit 1 CC1IE: Capture/Compare 1 interrupt enable
	//	0: CC1 interrupt disabled
	//	1: CC1 interrupt enabled
	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	pwm->TIMx_DIER |=(0b1111<<0);

	//	UG: Update generation
	//	This bit can be set by software, it is automatically cleared by hardware.
	//	0: No action
	//	1: Reinitialize the counter and generates an update of the registers. Note that the prescaler
	//	counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//	the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//	value (TIMx_ARR) if DIR=1 (downcounting).
	pwm->TIMx_EGR |=(1<<0);

	pwm->TIMx_CR1 |=(1<<0);//enable the timer


}

//===========================================================================
//###########################################################################

void timer2_INIT_CH1(uint32_t pre , uint32_t peak ){

	SPWM3PHASE->TIMx_CR1 &=~(1<<0);
	SPWM3PHASE->TIMx_EGR &=~(1<<0);


	SPWM3PHASE->TIMx_CR1  |=(1<<2);
	SPWM3PHASE->TIMx_DIER |=(1<<0);



	SPWM3PHASE->TIMx_ARR=peak;//frec peak value

	SPWM3PHASE->TIMx_PSC=pre;//prescaller

	SPWM3PHASE->TIMx_EGR |=(1<<0);
	SPWM3PHASE->TIMx_CR1 |=(1<<0);//enable the timer




}
//===========================================================================
//###########################################################################
//===========================================================================
//###########################################################################
void timer3_INIT_CH2(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ){

	//pwm->TIMx_CR1 &=~(1<<0);

	//	Bit 11 OC2PE: Output Compare 1 preload enable
	//	0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the
	//	new value is taken in account immediately.
	//	1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload
	//	register. TIMx_CCR1 preload value is loaded in the active register at each update event.
	//	Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed
	//	(LOCK bits in TIMx_BDTR register) and CC1S=’00’ (the channel is configured in
	//	output).
	//	2: The PWM mode can be used without validating the preload register only in one
	//	pulse mode (OPM bit set in TIMx_CR1 register). Else the behavior is not guaranteed.

	half_wave->TIMx_CCMR1 |=(1<<11);

	half_wave->TIMx_CCER |=(1<<4);
	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered

	half_wave->TIMx_CR1 |=(1<<7);


	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	half_wave->TIMx_CCMR1 |=(0b110<<12);

	half_wave->TIMx_ARR=peak;//frec peak value
	half_wave->TIMx_CCR2=(duty_cycle);//duty cycle
	half_wave->TIMx_PSC=pre;//prescaller

	//	Bit 15 MOE: Main output enable
	//	This bit is cleared asynchronously by hardware as soon as the break input is active. It is set
	//	by software or automatically depending on the AOE bit. It is acting only on the channels
	//	which are configured in output.
	//	0: OC and OCN outputs are disabled or forced to idle state.
	//	1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in
	//	TIMx_CCER register).
	//	See OC/OCN enable description for more details
	half_wave->TIMx_BDTR |=(1<<15);

	//	Bit 2 CC2IE: Capture/Compare 2 interrupt enable
	//	0: CC2 interrupt disabled
	//	1: CC2 interrupt enabled
	//	Bit 1 CC1IE: Capture/Compare 1 interrupt enable
	//	0: CC1 interrupt disabled
	//	1: CC1 interrupt enabled
	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	half_wave->TIMx_DIER |=(0b101<<0);

	//	UG: Update generation
	//	This bit can be set by software, it is automatically cleared by hardware.
	//	0: No action
	//	1: Reinitialize the counter and generates an update of the registers. Note that the prescaler
	//	counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//	the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//	value (TIMx_ARR) if DIR=1 (downcounting).
	half_wave->TIMx_EGR |=(1<<0);

	//half_wave->TIMx_CR1 |=(1<<0);//enable the timer


}
//===========================================================================
//###########################################################################
void timer3_INIT_CH1(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ){

	//	Bit 3 OC1PE: Output Compare 1 preload enable
	//	0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the
	//	new value is taken in account immediately.
	//	1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload
	//	register. TIMx_CCR1 preload value is loaded in the active register at each update event.
	//	Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed
	//	(LOCK bits in TIMx_BDTR register) and CC1S=’00’ (the channel is configured in
	//	output).
	//	2: The PWM mode can be used without validating the preload register only in one
	//	pulse mode (OPM bit set in TIMx_CR1 register). Else the behavior is not guaranteed.
	half_wave->TIMx_CCMR1 |=(1<<3);


	//	Bit 0 CC1E: Capture/Compare 1 output enable
	//	CC1 channel configured as output:
	//	0: Off - OC1 is not active. OC1 level is then function of MOE, OSSI, OSSR, OIS1, OIS1N
	//	and CC1NE bits.
	//	1: On - OC1 signal is output on the corresponding output pin depending on MOE, OSSI,
	//	OSSR, OIS1, OIS1N and CC1NE bits.
	//	CC1 channel configured as input:
	//	This bit determines if a capture of the counter value can actually be done into the input
	//	capture/compare register 1 (TIMx_CCR1) or not.
	//	0: Capture disabled.
	//	1: Capture enabled.
	half_wave->TIMx_CCER |=(1<<0);


	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered
	half_wave->TIMx_CR1 |=(1<<7);


	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	half_wave->TIMx_CCMR1 |=(0b110<<4);

	half_wave->TIMx_ARR=peak;//frec peak value
	half_wave->TIMx_CCR1=(duty_cycle);//duty cycle
	half_wave->TIMx_PSC=pre;//prescaller

	//	Bit 15 MOE: Main output enable
	//	This bit is cleared asynchronously by hardware as soon as the break input is active. It is set
	//	by software or automatically depending on the AOE bit. It is acting only on the channels
	//	which are configured in output.
	//	0: OC and OCN outputs are disabled or forced to idle state.
	//	1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in
	//	TIMx_CCER register).
	//	See OC/OCN enable description for more details
	half_wave->TIMx_BDTR |=(1<<15);

	//	Bit 2 CC2IE: Capture/Compare 2 interrupt enable
	//	0: CC2 interrupt disabled
	//	1: CC2 interrupt enabled
	//	Bit 1 CC1IE: Capture/Compare 1 interrupt enable
	//	0: CC1 interrupt disabled
	//	1: CC1 interrupt enabled
	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	half_wave->TIMx_DIER |=(0b111<<0);

	//	UG: Update generation
	//	This bit can be set by software, it is automatically cleared by hardware.
	//	0: No action
	//	1: Reinitialize the counter and generates an update of the registers. Note that the prescaler
	//	counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//	the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//	value (TIMx_ARR) if DIR=1 (downcounting).
	half_wave->TIMx_EGR |=(1<<0);

	//half_wave->TIMx_CR1 |=(1<<0);//enable the timer


}

//===========================================================================
//###########################################################################
void timer3_INIT_CH3(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ){

	//	Bit 3 OC3PE: Output Compare 1 preload enable
	//	0: Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the
	//	new value is taken in account immediately.
	//	1: Preload register on TIMx_CCR1 enabled. Read/Write operations access the preload
	//	register. TIMx_CCR1 preload value is loaded in the active register at each update event.
	//	Note: 1: These bits can not be modified as long as LOCK level 3 has been programmed
	//	(LOCK bits in TIMx_BDTR register) and CC1S=’00’ (the channel is configured in
	//	output).
	//	2: The PWM mode can be used without validating the preload register only in one
	//	pulse mode (OPM bit set in TIMx_CR1 register). Else the behavior is not guaranteed.
	half_wave->TIMx_CCMR2 |=(1<<3);


	//	Bit 8 CC3E: Capture/Compare 1 output enable
	//	CC1 channel configured as output:
	//	0: Off - OC1 is not active. OC1 level is then function of MOE, OSSI, OSSR, OIS1, OIS1N
	//	and CC1NE bits.
	//	1: On - OC1 signal is output on the corresponding output pin depending on MOE, OSSI,
	//	OSSR, OIS1, OIS1N and CC1NE bits.
	//	CC1 channel configured as input:
	//	This bit determines if a capture of the counter value can actually be done into the input
	//	capture/compare register 1 (TIMx_CCR1) or not.
	//	0: Capture disabled.
	//	1: Capture enabled.
	half_wave->TIMx_CCER |=(1<<8);


	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered
	half_wave->TIMx_CR1 |=(1<<7);


	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	half_wave->TIMx_CCMR2 |=(0b110<<4);

	half_wave->TIMx_ARR=peak;//frec peak value
	half_wave->TIMx_CCR3=(duty_cycle);//duty cycle
	half_wave->TIMx_PSC=pre;//prescaller

	//	Bit 15 MOE: Main output enable
	//	This bit is cleared asynchronously by hardware as soon as the break input is active. It is set
	//	by software or automatically depending on the AOE bit. It is acting only on the channels
	//	which are configured in output.
	//	0: OC and OCN outputs are disabled or forced to idle state.
	//	1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in
	//	TIMx_CCER register).
	//	See OC/OCN enable description for more details
	half_wave->TIMx_BDTR |=(1<<15);

	//	Bit 2 CC2IE: Capture/Compare 2 interrupt enable
	//	0: CC2 interrupt disabled
	//	1: CC2 interrupt enabled
	//	Bit 1 CC1IE: Capture/Compare 1 interrupt enable
	//	0: CC1 interrupt disabled
	//	1: CC1 interrupt enabled
	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	half_wave->TIMx_DIER |=(0b1111<<0);

	//	UG: Update generation
	//	This bit can be set by software, it is automatically cleared by hardware.
	//	0: No action
	//	1: Reinitialize the counter and generates an update of the registers. Note that the prescaler
	//	counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//	the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//	value (TIMx_ARR) if DIR=1 (downcounting).
	half_wave->TIMx_EGR |=(1<<0);

	half_wave->TIMx_CR1 |=(1<<0);//enable the timer


}
//===========================================================================
//###########################################################################
//===========================================================================
//###########################################################################

void pwm_INIT(){
	MCAL_speed_init(CLK_SORC_IN_CLK8MHz, mood_FAST_MOOD_72MHzCORE);//speed of all 36MHz
	GPIOA_Clock_Enable();//enable porta clock
	GPIOB_Clock_Enable();//enable portb clock
	TIMER1_CLOCK_Enable();//enable timer1 clock
	TIMER2_CLOCK_Enable();//enable timer2 clock
	TIMER3_CLOCK_Enable();//enable timer3 clock
	AFIO_Clock_Enable();//enable AF io clock
	//NVIC_TIM1_UP_Enable;
	//NVIC_TIM1_CC_Enable;//enable capture compare nvic
	NVIC_TIM2_global_interrupt_Enable;
	//=====================pins mode============================
	pinmode(GPIOA, pin8, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
	pinmode(GPIOA, pin9, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
	pinmode(GPIOA, pin10,GPIO_MODE_OUTPUT_AF_push_pull_Speed50);

	pinmode(GPIOA, pin6, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
	pinmode(GPIOA, pin7, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
	pinmode(GPIOB, pin0,GPIO_MODE_OUTPUT_AF_push_pull_Speed50);

	var4 = 126 * sin(A + Phase1);
	var1 = var4 + 128;
	var5 = 126 * sin(A + Phase2);
	var2 = var5 + 128;
	var6 = 126 * sin(A + Phase3);
	var3 = var6 + 128;
	timer_INIT_CH1(presc,var1,top);
	timer_INIT_CH2(presc,var2,top);
	timer_INIT_CH3(presc, var3, top);

	timer3_INIT_CH1(presc,0,top);
	timer3_INIT_CH2(presc,0,top);
	timer3_INIT_CH3(presc, 0, top);
	pinmode(GPIOB, pin1,GPIO_MODE_OUTPUT_push_pull_Speed10);
	//    pinmode(GPIOA, pin4,GPIO_MODE_OUTPUT_push_pull_Speed50);
	//pinmode(GPIOA, pin5,GPIO_MODE_OUTPUT_push_pull_Speed2);
}
//============================================================
//############################################################
//######################## interface #########################
//############################################################
//============================================================
void frec_controle(){
	//pinwrite(GPIOB, pin1 ,HIGH);
	SPWM3PHASE->TIMx_CR1 &=~(1<<0);
	_delay_mss(1000);
	char user_flage=1;
	if(user_freq_control>=299)user_freq_control=1;
	else{
		user_freq_control++;
	}
	user_freq=user_freq_control;

	while(user_flage==1){
		user_top = (36000000)/(user_freq *13 * user_pre );
		if(user_top>=32000){
			user_pre+=2;
		}
		else{
			user_flage=0;
		}
	}
	top=user_top/5;
	timer2_INIT_CH1(user_pre-1,user_top);
	//pinwrite(GPIOB, pin1 ,LOW);

}
//void frec_controle_decrease(){
//	_delay_ms(1000);
//	if(user_freq<=(1))user_freq=370;
//	else user_freq-=1;
//	user_flage=0;
//	//notes============================
//	//min top=7485 when presc =0
//	//max top=32000
//	//to calculate an accurate frequency
//	//you must use this formula
//	//inputs frequency and prescaler and the output is top"counterstics"
//	//top=1/(f*(1\36*10^6) *13 * prescaler )
//
//	while(user_flage==1){
//		user_top = (36000000)/(user_freq *13 * user_pre );
//		if(user_top>=32000){
//			user_pre+=2;
//		}
//		else{
//			user_flage=0;
//		}
//	}
//
//	timer2_INIT_CH1(user_pre-1,user_top);
//}
void _delay_mss(long x){
	for(long i=0;i<(x*50);i++);
}
//============================================================
//########################### main ##########################
//============================================================
int main(void)
{
	_delay_mss(2000);
	//==================$$$$$$$$$$$$$$$$$$==================
	pwm_INIT();
	LCD_Init();
	//=================$$$$$$$$$$$$$$$$$$===================
	EXTI(GPIOA,pin1,EXTI_Trigger_Falling,frec_controle);
	//	EXTI(GPIOB,pin11,EXTI_Trigger_Falling,frec_controle_decrease);


	//	//notes============================
	//	//min top=7485 when presc =0
	//	//max top=32000
	//	//to calculate an accurate frequency
	//	//you must use this formula
	//	//inputs frequency and prescaler and the output is top"counterstics"
	//	//top=1/(f*(1\36*10^6) *13 * prescaler )//2pi/.5
	//max frq=300 on accuracy .5  13
	//max frq=150 on accuracy .3  21

	user_freq=300;
	char user_flage=1;
	while(user_flage==1){
		user_top = (36000000)/(user_freq *13 * user_pre );
		if(user_top>=32000){
			user_pre+=2;
		}
		else{
			user_flage=0;
		}
	}
	top=user_top/5;
	timer2_INIT_CH1(user_pre-1,user_top);
	while (1)
	{
		_delay_mss(90);
		LCD_setcerser(0,0);
		LCD_write_string("user_freq:");
		_delay_mss(20);
		LCD_setcerser(0,10);
		_delay_mss(20);
		LCD_write_INTnumber(user_freq);
		_delay_mss(110);
		LCD_write_string("Hz");
		_delay_mss(110);
		LCD_setcerser(1,0);
		_delay_mss(20);
		LCD_write_string(" MO_Alshreif");
		_delay_mss(3200);
		LCD_clear();


	}
}
//============================================================
//####################### interrupt ##########################
//============================================================
void TIM2_IRQHandler(){

	pinwrite(GPIOB, pin1 ,HIGH);
	SPWM3PHASE->TIMx_SR &=~(1<<0);
	//timer2_INIT_CH1(user_pre-1,user_top);
	A += B;
	if (A >=2* M_PI)
	{
		A = 0;
	}

	//==================================================
	var1 = (127 * sinf(A + Phase1) + 128)*top/255;
	var2 = (127 * sinf(A + Phase2) + 128)*top/255;
	var3 = (127 * sinf(A + Phase3) + 128)*top/255;
	//==================================================
	pwm->TIMx_ARR=top;//frec peak value
	half_wave->TIMx_ARR=top;//frec peak value

	if(var1>=(top/2)){
		//pwm->TIMx_CCR1=(0);//duty cycle
		pinmode(GPIOA, pin8, GPIO_MODE_INTPUT_AF);
		pinmode(GPIOA, pin6, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
		half_wave->TIMx_CCR1=(var1);//duty cycle
	}
	else{
		pinmode(GPIOA, pin6, GPIO_MODE_INTPUT_AF);
		pinmode(GPIOA, pin8, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
		pwm->TIMx_CCR1=(var1);//duty cycle
	}

	if(var2>=(top/2)){
		//pwm->TIMx_CCR2=(0);//duty cycle
		pinmode(GPIOA, pin9, GPIO_MODE_INTPUT_AF);
		pinmode(GPIOA, pin7, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
		half_wave->TIMx_CCR2=(var2);//duty cycle
	}
	else
	{
		pinmode(GPIOA, pin7, GPIO_MODE_INTPUT_AF);
		pinmode(GPIOA, pin9, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
		pwm->TIMx_CCR2=(var2);//duty cycle
	}

	if(var3>=(top/2)){
		//pwm->TIMx_CCR3=(0);//duty cycle
		pinmode(GPIOA, pin10,GPIO_MODE_INTPUT_AF);
		pinmode(GPIOB, pin0, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
		half_wave->TIMx_CCR3=(var3);//duty cycle
	}
	else{
		pinmode(GPIOB, pin0, GPIO_MODE_INTPUT_AF);
		pinmode(GPIOA, pin10,GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
		pwm->TIMx_CCR3=(var3);//duty cycle
	}
	pwm->TIMx_PSC=presc;//prescaller
	half_wave->TIMx_PSC=presc;//prescaller
	pwm->TIMx_EGR |=(1<<0);
	half_wave->TIMx_EGR |=(1<<0);
	pwm->TIMx_CR1 |=(1<<0);//enable the timer
	half_wave->TIMx_CR1 |=(1<<0);//enable the timer
	pinwrite(GPIOB, pin1 ,LOW);
}
