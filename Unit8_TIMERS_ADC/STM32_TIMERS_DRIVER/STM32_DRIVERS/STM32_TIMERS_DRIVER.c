
/*
 * STM32_TIMERS_DRIVER.c
 *
 *  Created on: Nov 3, 2022
 *      Author: 20102
 */
#include "STM32_TIMERS_DRIVER.h"

uint8_t delay_flag =1;
TIMERS_typeDef* delay_TIMER=TIM2;
//TIMERS_typeDef* ISR_TIMER_COPY;

//void (*ISRcalback[2]) (void);
void PWM(TIMERS_typeDef* TIMERx,uint32_t CH,uint32_t duty_cycle,uint32_t freq,uint32_t clk){

	TIMERx->TIMx_CR1 &=~(1<<0);


	char user_flage=1;
	uint32_t user_top=0;
	uint32_t user_pre=1;

	while(user_flage==1){
		user_top = (clk)/(freq * user_pre );
		if(user_top>=32000){
			user_pre+=2;
		}
		else{
			user_flage=0;
		}
	}


	if(TIMERx==TIM1){
		TIMER1_CLOCK_Enable();//enable timer1 clock
		GPIOA_Clock_Enable();//enable porta clock
		AFIO_Clock_Enable();//enable AF io clock
		if(CH==CH_1){
			pinmode(GPIOA, pin8, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<3);
			TIMERx->TIMx_CCER |=(1<<0);
			TIMERx->TIMx_CCMR1 |=(0b110<<4);
			TIMERx->TIMx_CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_BDTR |=(1<<15);
			TIMERx->TIMx_DIER |=(0b11<<0);
		}
		else if(CH==CH_2){
			pinmode(GPIOA, pin9, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			pinmode(GPIOA, pin1, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<11);
			TIMERx->TIMx_CCER |=(1<<4);
			TIMERx->TIMx_CCMR1 |=(0b110<<12);
			TIMERx->TIMx_CCR2=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_BDTR |=(1<<15);
			TIMERx->TIMx_DIER |=(0b101<<0);
		}
		else if(CH==CH_3){
			pinmode(GPIOA, pin10, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR2 |=(1<<3);
			TIMERx->TIMx_CCER |=(1<<8);
			TIMERx->TIMx_CCMR2 |=(0b110<<4);
			TIMERx->TIMx_CCR3=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_BDTR |=(1<<15);
			TIMERx->TIMx_DIER |=(0b1001<<0);
		}
		else if(CH==CH_4){
			pinmode(GPIOA, pin11, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR2 |=(1<<11);
			TIMERx->TIMx_CCER |=(1<<12);
			TIMERx->TIMx_CCMR2 |=(0b110<<12);
			TIMERx->TIMx_CCR4=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_BDTR |=(1<<15);
			TIMERx->TIMx_DIER |=(0b10001<<0);
		}
	}



	else if (TIMERx==TIM2){
		TIMER2_CLOCK_Enable();//enable timer2 clock
		GPIOA_Clock_Enable();//enable porta clock
		AFIO_Clock_Enable();//enable AF io clock

		if(CH==CH_1){
			pinmode(GPIOA, pin0, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<3);
			TIMERx->TIMx_CCER |=(1<<0);
			TIMERx->TIMx_CCMR1 |=(0b110<<4);
			TIMERx->TIMx_CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b11<<0);
		}
		else if(CH==CH_2){
			pinmode(GPIOA, pin1, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<11);
			TIMERx->TIMx_CCER |=(1<<4);
			TIMERx->TIMx_CCMR1 |=(0b110<<12);
			TIMERx->TIMx_CCR2=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b101<<0);
		}
		else if(CH==CH_3){
			pinmode(GPIOA, pin2, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR2 |=(1<<3);
			TIMERx->TIMx_CCER |=(1<<8);
			TIMERx->TIMx_CCMR2 |=(0b110<<4);
			TIMERx->TIMx_CCR3=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b1001<<0);
		}
		else if(CH==CH_4){
			pinmode(GPIOA, pin3, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR2 |=(1<<11);
			TIMERx->TIMx_CCER |=(1<<12);
			TIMERx->TIMx_CCMR2 |=(0b110<<12);
			TIMERx->TIMx_CCR4=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b10001<<0);
		}
	}

	else if (TIMERx==TIM3){
		TIMER3_CLOCK_Enable();//enable timer3 clock
		GPIOA_Clock_Enable();//enable porta clock
		GPIOB_Clock_Enable();//enable porta clock
		AFIO_Clock_Enable();//enable AF io clock

		if(CH==CH_1){
			pinmode(GPIOA, pin6, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<3);
			TIMERx->TIMx_CCER |=(1<<0);
			TIMERx->TIMx_CCMR1 |=(0b110<<4);
			TIMERx->TIMx_CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b11<<0);
		}
		else if(CH==CH_2){
			pinmode(GPIOA, pin7, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<11);
			TIMERx->TIMx_CCER |=(1<<4);
			TIMERx->TIMx_CCMR1 |=(0b110<<12);
			TIMERx->TIMx_CCR2=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b101<<0);
		}
		else if(CH==CH_3){
			pinmode(GPIOB, pin0, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR2 |=(1<<3);
			TIMERx->TIMx_CCER |=(1<<8);
			TIMERx->TIMx_CCMR2 |=(0b110<<4);
			TIMERx->TIMx_CCR3=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b1001<<0);
		}
		else if(CH==CH_4){
			pinmode(GPIOB, pin1, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR2 |=(1<<11);
			TIMERx->TIMx_CCER |=(1<<12);
			TIMERx->TIMx_CCMR2 |=(0b110<<12);
			TIMERx->TIMx_CCR4=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b10001<<0);
		}
	}



	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered
	TIMERx->TIMx_CR1 |=(1<<7);


	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1


	TIMERx->TIMx_ARR=user_top;//frec peak value

	TIMERx->TIMx_PSC=(user_pre-1);//prescaller

	//	Bit 15 MOE: Main output enable
	//	This bit is cleared asynchronously by hardware as soon as the break input is active. It is set
	//	by software or automatically depending on the AOE bit. It is acting only on the channels
	//	which are configured in output.
	//	0: OC and OCN outputs are disabled or forced to idle state.
	//	1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in
	//	TIMx_CCER register).
	//	See OC/OCN enable description for more details
	//TIMERx->TIMx_BDTR |=(1<<15);

	//	Bit 2 CC2IE: Capture/Compare 2 interrupt enable
	//	0: CC2 interrupt disabled
	//	1: CC2 interrupt enabled
	//	Bit 1 CC1IE: Capture/Compare 1 interrupt enable
	//	0: CC1 interrupt disabled
	//	1: CC1 interrupt enabled
	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	//TIMERx->TIMx_DIER |=(0b101<<0);

	//	UG: Update generation
	//	This bit can be set by software, it is automatically cleared by hardware.
	//	0: No action
	//	1: Reinitialize the counter and generates an update of the registers. Note that the prescaler
	//	counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//	the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//	value (TIMx_ARR) if DIR=1 (downcounting).
	TIMERx->TIMx_EGR |=(1<<0);

	TIMERx->TIMx_CR1 |=(1<<0);//enable the timer

}

void delay(uint16_t time,uint8_t U,uint32_t clk){
	TIMER2_CLOCK_Enable();//enable timer2 clock
	delay_TIMER->TIMx_CR1 &=~(1<<0);
	///TIMERS_typeDef* TIMERx=TIM2;
	char user_flage=1;
	uint32_t user_top=0;
	uint32_t user_pre=1;
	uint32_t unit =1000;
	uint8_t  increase=2;

	if (U == 0){
		unit = 1000;
		if (time > 3000)increase = 100;
		else increase = 10;
	}
	else {
		unit = 1000000;
		if (time > 3000)increase = 10;
		else increase = 5;
	}

	while(user_flage==1){
		user_top = (clk/unit*time)/( user_pre );
		if(user_top>=32000){

			if(user_pre>65530){
				user_pre=65530;
				user_flage=0;
			}
			else user_pre+=increase;

		}
		else{
			user_flage=0;
		}
	}
	delay_TIMER->TIMx_CR1 &=~(1<<0);

	delay_TIMER->TIMx_CR1  |=(1<<2);

	delay_TIMER->TIMx_DIER |=(1<<0);



	delay_TIMER->TIMx_ARR=user_top;//frec peak value

	delay_TIMER->TIMx_PSC=(user_pre-1);//prescaller

	delay_TIMER->TIMx_EGR |=(1<<0);
	//		Bit 0 UG: Update generation
	//		This bit can be set by software, it is automatically cleared by hardware.
	//		0: No action
	//		1: Re-initialize the counter and generates an update of the registers. Note that the prescaler
	//		counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//		the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//		value (TIMx_ARR) if DIR=1 (downcounting).
	delay_TIMER->TIMx_CR1 |=(1<<0);//enable the timer
	delay_flag=1;
	NVIC_TIM2_global_interrupt_Enable;
	while(delay_flag){

	}
}


//void TIMER_ISR(TIMERS_typeDef* ISR_TIMER,uint16_t time_ms,uint32_t clk,void *calback(void)){
//
//	TIMER3_CLOCK_Enable();//enable timer2 clock
//
//	ISR_TIMER_COPY=ISR_TIMER;
//	char user_flage=1;
//	uint32_t user_top=0;
//	uint32_t user_pre=1;
//	uint8_t  increase=2;
//
//
//		if (time_ms > 3000)increase = 100;
//		else increase = 10;
//
//	while(user_flage==1){
//		user_top = (clk/1000*time_ms)/( user_pre );
//		if(user_top>=32000){
//
//			if(user_pre>65530){
//				user_pre=65530;
//				user_flage=0;
//			}
//			else user_pre+=increase;
//
//		}
//		else{
//			user_flage=0;
//		}
//	}
//	ISR_TIMER->TIMx_CR1 &=~(1<<0);
//
//	ISR_TIMER->TIMx_CR1  |=(1<<2);
//
//	ISR_TIMER->TIMx_DIER |=(1<<0);
//
//
//
//	ISR_TIMER->TIMx_ARR=user_top;//frec peak value
//
//	ISR_TIMER->TIMx_PSC=(user_pre-1);//prescaller
//
//	ISR_TIMER->TIMx_EGR |=(1<<0);
//	//		Bit 0 UG: Update generation
//	//		This bit can be set by software, it is automatically cleared by hardware.
//	//		0: No action
//	//		1: Re-initialize the counter and generates an update of the registers. Note that the prescaler
//	//		counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
//	//		the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
//	//		value (TIMx_ARR) if DIR=1 (downcounting).
//	ISR_TIMER->TIMx_CR1 |=(1<<0);//enable the timer
//
//	NVIC_TIM3_global_interrupt_Enable;
//	ISRcalback[0]=calback;
//}

void TIM2_IRQHandler(){
	delay_TIMER->TIMx_SR &=~(1<<0);
	delay_flag=0;
	NVIC_TIM2_global_interrupt_Disable;

}
//void TIM3_IRQHandler(){
//	ISR_TIMER_COPY->TIMx_SR &=~(1<<0);
//	ISRcalback[0]();
//}
