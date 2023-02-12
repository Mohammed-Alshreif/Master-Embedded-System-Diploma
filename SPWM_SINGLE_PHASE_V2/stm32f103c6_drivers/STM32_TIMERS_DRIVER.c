
/*
 * STM32_TIMERS_DRIVER.c
 *
 *  Created on: Nov 3, 2022
 *      Author: 20102
 */
#include "STM32_TIMERS_DRIVER.h"

#define SPWM_MOOD_INIT    0
#define SPWM_MOOD_START   1

//=============>>>>>>SPWM<<<<<<<<<===============

TIMERS_typeDef * pwm = TIM1;
uint8_t numper_waves;
uint8_t flage2=0,flage1=1,flage3=1;
uint32_t top=1000,presc=1,top_max=10000,top_min=1000;
uint32_t c=1000;
uint32_t x=125;

//==============================================================================================
uint8_t delay_flag =1;
uint16_t overflowtims=0;
uint16_t timer_ticks=0;

TIMERS_typeDef* delay_TIMER=TIM2;
TIMERS_typeDef* ISR_TIMER_COPY;

void (*ISRcalback[2]) (void);

//====================================
void SPWM_timer_INIT(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ,uint8_t SPWM_MOOD_);

//===============================================================================================

void PWM(TIMERS_typeDef* TIMERx,uint32_t CH,uint32_t duty_cycle,uint32_t freq,uint32_t clk){

	TIMERx->TIMx_CR1 &=~(1<<0);//Counter disabled


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

	//====================TIM1===================


	if(TIMERx==TIM1){
		TIMER1_CLOCK_Enable();//enable timer1 clock
		GPIOA_Clock_Enable();//enable porta clock
		AFIO_Clock_Enable();//enable AF io clock
		if(CH==CH_1){
			pinmode(GPIOA, pin8, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<3); //Output compare 1 preload enable
			TIMERx->TIMx_CCER |=(1<<0); // Capture/Compare 1 output enable
			TIMERx->TIMx_CCMR1 |=(0b110<<4);//110: PWM mode 1 - In upcounting, channel 1 is active
			TIMERx->TIMx_CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_BDTR |=(1<<15); // Main output enable
			TIMERx->TIMx_DIER |=(0b11<<0);//Update interrupt enable Capture/Compare 1 interrupt enable
		}
		else if(CH==CH_2){
			pinmode(GPIOA, pin9, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			//pinmode(GPIOA, pin1, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
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

	//====================TIM2===================

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
	//====================TIM3===================

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


	//====================TIM4===================

	else if (TIMERx==TIM4){
		TIMER4_CLOCK_Enable();//enable timer3 clock
		GPIOB_Clock_Enable();//enable porta clock
		AFIO_Clock_Enable();//enable AF io clock

		if(CH==CH_1){
			pinmode(GPIOB, pin6, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<3);
			TIMERx->TIMx_CCER |=(1<<0);
			TIMERx->TIMx_CCMR1 |=(0b110<<4);
			TIMERx->TIMx_CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b11<<0);
		}
		else if(CH==CH_2){
			pinmode(GPIOB, pin7, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR1 |=(1<<11);
			TIMERx->TIMx_CCER |=(1<<4);
			TIMERx->TIMx_CCMR1 |=(0b110<<12);
			TIMERx->TIMx_CCR2=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b101<<0);
		}
		else if(CH==CH_3){
			pinmode(GPIOB, pin8, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
			TIMERx->TIMx_CCMR2 |=(1<<3);
			TIMERx->TIMx_CCER |=(1<<8);
			TIMERx->TIMx_CCMR2 |=(0b110<<4);
			TIMERx->TIMx_CCR3=(user_top*duty_cycle/100);//duty cycle
			TIMERx->TIMx_DIER |=(0b1001<<0);
		}
		else if(CH==CH_4){
			pinmode(GPIOB, pin9, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
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


//=======================================================================================
void delay(uint16_t time,uint8_t U,uint32_t clk){

	TIMER2_CLOCK_Enable();//enable timer2 clock

	delay_TIMER->TIMx_CR1 &=~(1<<0);//timer off
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


	delay_TIMER->TIMx_CR1 &=~(1<<0);//timer off

	delay_TIMER->TIMx_CR1  |=(1<<2);//Only counter overflow/underflow generates an update

	delay_TIMER->TIMx_DIER |=(1<<0);//Update interrupt enabled



	delay_TIMER->TIMx_ARR=user_top;//frec peak value

	delay_TIMER->TIMx_PSC=(user_pre-1);//prescaller

	delay_TIMER->TIMx_EGR |=(1<<0);//1: Re-initialize the counter and generates an update of the registers. Note that the prescaler

	delay_TIMER->TIMx_CR1 |=(1<<0);//enable the timer



	delay_flag=1;
	NVIC_TIM2_global_interrupt_Enable;
	while(delay_flag){

	}
}

//==================================================================================================

void TIMER_ISR(TIMERS_typeDef* ISR_TIMER,uint16_t time_ms,uint32_t clk,void (*calback) (void)){

	TIMER3_CLOCK_Enable();//enable timer3 clock
	ISR_TIMER->TIMx_CR1 &=~(1<<0);
	ISRcalback[0] = calback;
	ISR_TIMER_COPY=ISR_TIMER;

	char user_flage=1;
	uint32_t user_top=0;
	uint32_t user_pre=1;
	uint8_t  increase=2;

	if (time_ms > 3000)increase = 100;
	else increase = 10;

	while(user_flage==1){
		user_top = (clk/1000*time_ms)/( user_pre );
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


	ISR_TIMER->TIMx_CR1 &=~(1<<0);

	ISR_TIMER->TIMx_CR1  |=(1<<2);

	ISR_TIMER->TIMx_DIER |=(1<<0);

	ISR_TIMER->TIMx_ARR=user_top;//frec peak value

	ISR_TIMER->TIMx_PSC=(user_pre-1);//prescaller

	ISR_TIMER->TIMx_EGR |=(1<<0);//		Bit 0 UG: Update generation

	ISR_TIMER->TIMx_CR1 |=(1<<0);//enable the timer

	NVIC_TIM3_global_interrupt_Enable;

}
//======================================================================================================

uint32_t TIME_CALCULATION(uint32_t clk,uint8_t TIMER_ST){
	if(TIMER_ST==TIMER_START){
		TIMER4_CLOCK_Enable();//enable timer3 clock
		TIM4->TIMx_CR1 &=~(1<<0);//stop

		TIM4->TIMx_CR1  |=(1<<2);

		TIM4->TIMx_DIER |=(1<<0);//Update interrupt enable

		TIM4->TIMx_ARR=64000;//peak value 8ms of freq=8000000hz

		TIM4->TIMx_PSC=0;//prescaller

		TIM4->TIMx_EGR |=(1<<0);//Bit 0 UG: Update generation

		TIM4->TIMx_CR1 |=(1<<0);//enable the timer
		NVIC_TIM4_global_interrupt_Enable;
		return 1;
	}
	else {
		TIM4->TIMx_CR1 &=~(1<<0);//stop
		timer_ticks=TIM4->TIMx_CNT;
		uint32_t X=((timer_ticks+(overflowtims*64000))/(clk/1000000));
		overflowtims=0;
		timer_ticks=0;
		return X;
	}
}


//==================================================================================================

void SPWM_SINGLE_PHASE_INIT(uint8_t WAVE_NUMBER,uint8_t freq,uint32_t clk){
	numper_waves=WAVE_NUMBER;
	//MCAL_speed_init(CLK_SORC_IN_CLK8MHz,mood_FAST_MOOD_36MHzCORE);//speed of all 36MHz
	GPIOA_Clock_Enable();//enable porta clock
	TIMER1_CLOCK_Enable();//enable timer1 clock
	AFIO_Clock_Enable();//enable AF i/o clock
	NVIC_TIM1_UP_Enable;//interrupt

	//=====================pins mode============================
	pinmode(GPIOA, pin9, GPIO_MODE_OUTPUT_AF_push_pull_Speed50);
	pinmode(GPIOA, pin8,GPIO_MODE_OUTPUT_AF_push_pull_Speed50);


	char user_flage=1;
	uint32_t user_top=0;
	uint32_t user_pre=1;

	while(user_flage==1){
		user_top = (clk/(freq*4*user_pre*numper_waves))-(40*numper_waves);//10 instruction *numper_waves in a total wave =delay of execution

		if(user_top>=32000){
			user_pre+=1;
		}
		else{
			user_flage=0;
		}
	}
	presc=user_pre-1;
	c=top=user_top;
	x=(top/numper_waves);
	SPWM_timer_INIT(presc,x,top,SPWM_MOOD_INIT);

}
void SPWM_timer_INIT(uint32_t pre ,uint32_t duty_cycle,uint32_t peak ,uint8_t SPWM_MOOD_){

	pwm->TIMx_CR1 &=~(1<<0);

	if(SPWM_MOOD_==SPWM_MOOD_INIT){
		//CH 2
		pwm->TIMx_CCMR1 |=(1<<11); //Bit 11 OC2PE: Output Compare 2 preload enable
		pwm->TIMx_CCMR1 |=(0b110<<12);//110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
		//else inactive. In downcounting, channel 1 is inactive (OC1REF=‘0’) as long as
		//TIMx_CNT>TIMx_CCR1 else active (OC1REF=’1’).
		//CH 1
		pwm->TIMx_CCMR1 |=(1<<3);//Bit 3 OC1PE: Output Compare 1 preload enable
		pwm->TIMx_CCMR1 |=(0b110<<4);//Bits 6:4 OC1M: Output Compare 1 mode


		//	1: On - OC1 signal is output on the corresponding output pin depending on MOE, OSSI,
		//	OSSR, OIS1, OIS1N and CC1NE bits.
		pwm->TIMx_CCER |=(1<<4);//Bit 4 CC2E: Capture/Compare 2 output enable
		pwm->TIMx_CCER |=(1<<0);//Bit 0 CC2E: Capture/Compare 1 output enable
	}

	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered
	pwm->TIMx_CR1 |=(1<<7);



	pwm->TIMx_ARR=peak;//frec peak value
	pwm->TIMx_CCR2=(duty_cycle);//duty cycle
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
	pwm->TIMx_BDTR |=(1<<15);//	Bit 15 MOE: Main output enable


	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	pwm->TIMx_DIER |=(0b1<<0);

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


void SPWM_WRITE(uint8_t freq,uint8_t WAVE_NUMBER,uint32_t clk){

	char user_flage=1;
	uint32_t user_top=0;
	uint32_t user_pre=1;

	while(user_flage==1){
		user_top = (clk/(freq*4*user_pre*numper_waves))-(40*numper_waves);//10 instruction *numper_waves in a total wave =delay of execution

		if(user_top>=32000){
			user_pre+=1;
		}
		else{
			user_flage=0;
		}
	}
	presc=user_pre-1;
	c=top=user_top;
	x=(top/numper_waves);
	SPWM_timer_INIT(presc,x,top,SPWM_MOOD_INIT);
}
//========<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  ISR  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void TIM2_IRQHandler(){
	delay_TIMER->TIMx_SR &=~(1<<0);//Bit 0 UIF: Update interrupt flag
	delay_flag=0;
	//NVIC_TIM2_global_interrupt_Disable;
	delay_TIMER->TIMx_CR1 &=~(1<<0);//timer off

}
void TIM3_IRQHandler(){
	//pinwrite(GPIOB, pin10,LOW);
	ISR_TIMER_COPY->TIMx_CR1 &=~(1<<0);
	ISR_TIMER_COPY->TIMx_SR &=~(1<<0);
	ISRcalback[0]();
	//NVIC_TIM3_global_interrupt_Disable;
	//pinwrite(GPIOB, pin10,HIGH);
}

void TIM4_IRQHandler(){
	TIM4->TIMx_SR &=~(1<<0);
	overflowtims++;
}



void TIM1_UP_IRQHandler(){

	//algorithm who select the action
	if(x>top){
		flage2=1;
		flage1=0;
		x=top+(top/numper_waves);
	}
	else if(x<100)
	{
		flage2=0;
		flage1=1;
		flage3 ^=(1<<0);
		x=(top/numper_waves);//reset incremental variable
		//for(volatile int s=0;s<300;s++);//delay between the two half waves

	}

	//select first or second half wave
	if(flage3==1){
		pwm->TIMx_CCER &=~(1<<0);//ch1_off
		pwm->TIMx_CCER |=(1<<4);//ch2_on
	}
	else if(flage3==0){
		pwm->TIMx_CCER &=~(1<<4);//ch2_off
		pwm->TIMx_CCER |=(1<<0);//ch1_on
	}

	//make this wave and increment/decrement the next value of next wave
	if((flage1==1)&&(flage2==0)){
		top=c;
		SPWM_timer_INIT(presc,x,top,SPWM_MOOD_START);
		x+=(top/numper_waves);
	}
	else if ((flage2==1)&&(flage1==0)){
		top=c;
		x=x-(top/numper_waves);
		SPWM_timer_INIT(presc,x,top,SPWM_MOOD_START);
		if(x==(top/numper_waves))x=0;
	}
	else pwm->TIMx_CR1 &=~(1<<0);//disable counter

	pwm->TIMx_SR &=~(1<<0);//flag off
}

