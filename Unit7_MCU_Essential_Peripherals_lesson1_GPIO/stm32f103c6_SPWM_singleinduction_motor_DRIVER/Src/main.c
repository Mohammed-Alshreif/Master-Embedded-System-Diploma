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

#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"
#include "stm32_speed_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"
#include "LCD.h"
TIM1_typeDef * pwm = TIM1;
long x=70;
char flage2=0,flage1=1,flage3=1;
long top=1000,presc=1,top_max=10000,top_min=1000;
long c=1000;

//=================================functions============================

void frec_controle(){
   TogglePin(GPIOA, pin4);
	_delay_ms(1000);
	if(c>=(top_max-100))c=top_min;
	else c+=40;
	_delay_ms(1000);
}
void frec_controle_decrease(){
	 TogglePin(GPIOA, pin4);
	_delay_ms(1000);
	if(c<=(top_min-100))c=top_max;
	else c-=40;
	_delay_ms(1000);
}



void pwm_INIT(){
	MCAL_speed_init(CLK_SORC_IN_CLK8MHz, mood_FAST_MOOD_72MHzCORE);//speed of all 36MHz
	GPIOA_Clock_Enable();//enable porta clock
	GPIOB_Clock_Enable();//enable portb clock
	TIMER1_CLOCK_Enable();//enable timer1 clock
	AFIO_Clock_Enable();//enable AF io clock
	NVIC_TIM1_UP_Enable;
	NVIC_TIM1_CC_Enable;//enable capture compare nvic

	//=====================pins mode============================
	pinmode(GPIOA, pin9, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
	pinmode(GPIOA, pin1,GPIO_MODE_OUTPUT_push_pull_Speed50);
    pinmode(GPIOA, pin4,GPIO_MODE_OUTPUT_push_pull_Speed50);
   //pinmode(GPIOA, pin5,GPIO_MODE_OUTPUT_push_pull_Speed2);
}
void timer_INIT(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ){

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

	pwm->TIMx_CR1 |=(1<<0);//enable the timer


}
int main(void)
{
	LCD_Init();
	pwm_INIT();
	timer_INIT(presc,x,top);
	EXTI(GPIOA,pin7,EXTI_Trigger_Falling,frec_controle);
	EXTI(GPIOA,pin6,EXTI_Trigger_Falling,frec_controle_decrease);
	LCD_write_string("SPWM Generator");
	 while (1)
		    {
		 _delay_ms(5000);
		    LCD_setcerser(1,0);
		 	LCD_write_string("value");
		 	LCD_write_INTnumber(c);
		    }


}

void TIM1_UP_IRQHandler(){
	pinwrite(GPIOA, pin1,HIGH);

	if(x>=(top-100)){
		flage2=1;
		flage1=0;

	}
	else if(x<75)
		{
		flage2=0;
		flage1=1;
	    flage3 ^=(1<<0);
		}
	if(flage1==1){
		top=c; timer_INIT(presc,x,top);x=x+70;
	}
	else if (flage2==1){
		top=c; timer_INIT(presc,x,top);x-=70;
	}
	else pwm->TIMx_CR1 &=~(1<<0);//disable counter


	if(flage3==1){
		pinmode(GPIOA, pin9, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
		pinmode(GPIOA, pin1,GPIO_MODE_INPUT_FLO);
	}
	else if(flage3==0){
		//pwm->TIMx_BDTR &=~(1<<15);
		pinmode(GPIOA, pin9, GPIO_MODE_INPUT_FLO);
		pinmode(GPIOA, pin1,GPIO_MODE_OUTPUT_push_pull_Speed50);
	}
	pwm->TIMx_SR &=~(1<<0);
}
void TIM1_CC_IRQHandler(){
	//pwm->TIMx_SR &=~(1<<2);
	pinwrite(GPIOA, pin1, LOW);
	if(x>=top-70) pinwrite(GPIOA, pin1,HIGH);
	//	timer_INIT(60,x,32766);
	//	if(x>32766)x=500;
	//	else x=x+500;
	pwm->TIMx_SR &=~(1<<2);
}


