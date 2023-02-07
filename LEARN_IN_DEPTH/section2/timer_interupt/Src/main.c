#include "stm32f103c6_USART_SRIVER.h"
#include "STM32_TIMERS_DRIVER.h"
#include "GPIO_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"
#include "stm32_speed_DRIVER.h"
#include "I2C_LCD.h"

#define clk 8000000

char text [5];
uint32_t X=0,time;
uint8_t flag_ehco=0;
void echo(){
	if(flag_ehco==0){
		TIME_CALCULATION(clk, TIMER_START);
		flag_ehco=1;
	}
	else{
		time=TIME_CALCULATION(clk, TIMER_STOP);
		sprintf(text,"%d",((time*170)/10000));
		USART_SEND_STRING(USART1,text);
		flag_ehco=0;
	}

}

int main (){
	GPIOA_Clock_Enable();
	GPIOB_Clock_Enable();
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,clk);
	pinmode(GPIOB, pin11,GPIO_MODE_OUTPUT_push_pull_Speed2);//trigr
	EXTI(GPIOA,pin1,EXTI_Trigger_RisingAndFalling,echo);//echo
	while(1){
		pinwrite(GPIOB, pin11,HIGH);
		delay(10, U_ms, clk);
		pinwrite(GPIOB, pin11,LOW);
		USART_SEND_STRING(USART1,"\n");
		delay(200,U_ms,clk);
	}



	return 0;
}
