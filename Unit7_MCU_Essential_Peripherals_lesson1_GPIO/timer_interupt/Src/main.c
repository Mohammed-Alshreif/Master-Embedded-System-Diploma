#include "stm32f103c6_USART_SRIVER.h"
#include "STM32_TIMERS_DRIVER.h"
#include "GPIO_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"
int coun=10;
uint32_t v=0;uint32_t v2=0;
char text[4];
char text2 [4];
uint8_t flagecho=0;
uint8_t flagecho2=0;
void echo(void){
	//TogglePin(GPIOB, pin0);
	if(flagecho==0){
		flagecho=1;
		TIME_CALCULATION(8000000, TIMER_START);

	}
	else{
		//USART_SEND_STRING(USART1,"1:: \n ");
		flagecho=0;
		v=TIME_CALCULATION(8000000, TIMER_STOP);
		sprintf(text,"%d",((v)*170)/10000);
		USART_SEND_STRING(USART1,text);

	}
}
void echo2(void){
	TogglePin(GPIOB, pin1);
	if(flagecho2==0){
		flagecho2=1;
		TIME_CALCULATION(8000000, TIMER_START);

	}
	else{
		//USART_SEND_STRING(USART1,"2:: \n ");
		flagecho2=0;
		v2=TIME_CALCULATION(8000000, TIMER_STOP);
		sprintf(text2,"%d",((v2)*170)/10000);
		USART_SEND_STRING(USART1,text2);

	}
}
void ultrasonic_INIT(){
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,8000000);
	GPIOA_Clock_Enable();
	GPIOB_Clock_Enable();
	pinmode(GPIOB, pin11,GPIO_MODE_OUTPUT_push_pull_Speed2);
	EXTI(GPIOA,pin1,EXTI_Trigger_RisingAndFalling,echo);
}
void ultrasonic_INIT2(){
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,8000000);
	GPIOA_Clock_Enable();
	GPIOB_Clock_Enable();
	pinmode(GPIOB, pin0,GPIO_MODE_OUTPUT_push_pull_Speed2);
	pinmode(GPIOB, pin1,GPIO_MODE_OUTPUT_push_pull_Speed2);
	EXTI(GPIOA,pin2,EXTI_Trigger_RisingAndFalling,echo2);
}
void distance (){
	pinwrite(GPIOB, pin11,HIGH);
	delay(10, U_ms,8000000);
	pinwrite(GPIOB, pin11,LOW);
	USART_SEND_STRING(USART1,"\n");

}
void distance2 (){
	pinwrite(GPIOB, pin0,HIGH);
	delay(10, U_ms,8000000);
	pinwrite(GPIOB, pin0,LOW);
	USART_SEND_STRING(USART1,"\n");

}
int main (){
	ultrasonic_INIT();
	ultrasonic_INIT2();
	while(1){

		delay(140,U_ms,8000000);
		distance();
		delay(140,U_ms,8000000);
		distance2();

	}
	return 0;

}
/*


#include <string.h>
#include "stm32f103c6_USART_SRIVER.h"
#include "STM32_TIMERS_DRIVER.h"
#include "GPIO_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"
int coun=10;
uint16_t v=0;
char text[8];

uint8_t flagecho=0;
void time(void){
	pinwrite(GPIOB, pin0,1);
	for(int i=0;i<10000;i++);
	pinwrite(GPIOB, pin0,0);
}

void echo(){
	pinwrite(GPIOB, pin0,HIGH);
	if(flagecho==0){
		flagecho=1;
		//TIME_CALCULATION(8000000, TIMER_START);

	}
	else{
		//USART_SEND_STRING(USART1,"\n ");
		flagecho=0;
	//	v=TIME_CALCULATION(8000000, TIMER_STOP);


	}
	pinwrite(GPIOB, pin0,LOW);
}
int main(void)
{
	GPIOA_Clock_Enable();
	GPIOB_Clock_Enable();
	EXTI(GPIOA,pin1,EXTI_Trigger_Rising,echo);
	pinmode(GPIOB, pin11,GPIO_MODE_OUTPUT_push_pull_Speed2);
    pinmode(GPIOB, pin0,GPIO_MODE_OUTPUT_push_pull_Speed2);
	//pinwrite(GPIOB, pin10,HIGH);
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,8000000);
	//	PWM(TIM4, CH_1,50,1000,8000000);
	//	PWM(TIM1, CH_1,50,1000,8000000);
	//TogglePin(GPIOB, pin1);
	//TIMER_ISR(TIM3,1000,8000000,time);
	/* Loop forever */
/*
	pinwrite(GPIOB, pin11,HIGH);
	delay(10, U_ms,8000000);
	pinwrite(GPIOB, pin11,LOW);
	while(1){
		//		TIME_CALCULATION(8000000, TIMER_START);
		//		pinwrite(GPIOB, pin1,HIGH);
		delay(30,U_ms,8000000);
		//		delay(1,U_ms,8000000);delay(1,U_ms,8000000);delay(12,U_ms,8000000);delay(1,U_ms,8000000);
		//		pinwrite(GPIOB, pin1,LOW);
		//if(coun>=0){
		//	TIMER_ISR(TIM3,10,8000000,time);
		//coun--;
		//}
		//		v=TIME_CALCULATION(8000000, TIMER_STOP);
		//		sprintf(text,"%d",v);
		//		USART_SEND_STRING(USART1,text);
		//		delay(300,U_ms,8000000);
		pinwrite(GPIOB, pin11,HIGH);
		delay(10, U_ms,8000000);
		pinwrite(GPIOB, pin11,LOW);
		delay(100,U_ms,8000000);
		USART_SEND_STRING(USART1,"\n");
		delay(300,U_ms,8000000);
		sprintf(text,"%d",v);
				USART_SEND_STRING(USART1,text);

	}
//}





*/

