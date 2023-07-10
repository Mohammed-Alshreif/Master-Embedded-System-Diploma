/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohammed Adel Alshreif
 * @brief          : PID
 ******************************************************************************
 */
#include "stm32_speed_DRIVER.h"
#include "STM32_TIMERS_DRIVER.h"
#include "stm32f103c6_ADC.h"
#include "stm32f103c6_USART_SRIVER.h"
//===================================
#define clk 36000000
#define max_speed 1000  //from 0-->1000 note do not increase it above 1000

//=============-PID-=================
const float kp=60 ,kd=10,ki=0;
float prev_error,error,pid_d,pid_read,integral;
int pid_res;
//===================================
int PID (int target_position,int actual_position);//pid function
void intA();                                      // Encoder isr function
//===================================
uint32_t Motor_POSETION ;
//===================================
int X=0;
char text[4]={0};

int main(void)
{
	//*******************************************************
	//=====================SYSTEM INIT ======================
	//*******************************************************
	MCAL_speed_init(CLK_SORC_IN_CLK8MHz, mood_FAST_MOOD_36MHzCORE);//speed of CPU to 36MHz
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,clk);
	EXTI(GPIOA,pin4,EXTI_Trigger_Rising,intA);// INIT external interrupt to encoder

	//*******************************************************
	//===================== WHILE ===========================
	//*******************************************************

	while(1){

			pid_read=PID(200,X);
			if(pid_read>0){//right control
				PWM(TIM1, CH_3,0,3500, clk);
				PWM(TIM1, CH_1,pid_read,3500, clk);
			}
			else if(pid_read<0){//left control
				PWM(TIM1, CH_1,0,3500, clk);
				PWM(TIM1, CH_3,-pid_read,3500, clk);
			}
			else{//stop range
				PWM(TIM1, CH_1,0,3500, clk);
				PWM(TIM1, CH_3,0,3500, clk);
			}


			//analysis
			//*******************************************************
			//==================-SEND_ANALYSIS- =====================
			//*******************************************************
			USART_SEND_STRING(USART1,"\n ");
			delay(3, U_ms, clk);
			sprintf(text,"%d",X);
			USART_SEND_STRING(USART1,text);
			delay(5, U_ms, clk);



			//===========================================================

	}
}



//*******************************************************
//===================== -PID- ===========================
//*******************************************************
int PID (int target_position,int actual_position){

	error = target_position - actual_position;
	pid_d =error - prev_error;
	integral+=error;
	pid_res =error * kp + pid_d * kd+integral*ki;

	if(pid_res<-max_speed){
		pid_res=-max_speed;
	}

	if(pid_res>max_speed){
		pid_res=max_speed;
	}

	prev_error=error;
	return pid_res ;
}


//*******************************************************
//===================== encoder ISR =====================
//*******************************************************
void intA(){
	int b = READ_PIN(GPIOA, pin5);
	if(b > 0){
		X--;
	}
	else{
		X++;
	}
}
