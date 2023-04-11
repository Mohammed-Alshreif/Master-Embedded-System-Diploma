#include "stm32f103c6_USART_SRIVER.h"
#include "stm32_speed_DRIVER.h"
#include "GPIO_DRIVER.h"
#include "STM32_TIMERS_DRIVER.h"

int i=0;
unsigned char ch;
char string_data[50];
uint8_t serial_flag=0,index1;
void read_string (){

	USART_READ(USART3,&ch);

	if(ch=='$'){
		serial_flag=1;
		index1=0;
	}
	if(ch=='\n'){
		serial_flag=0;
		//string_data[index1+1]='\n';
		USART_SEND_STRING(USART3,string_data);
	}

	if(serial_flag==1){
		string_data[index1]=ch;
		index1++;
	}
}
int main(void)
{
	MCAL_speed_init(CLK_SORC_IN_CLK8MHz, mood_FAST_MOOD_36MHzCORE);
	USART_INIT(USART3, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,36000000);
	USART_READ_INTERRUPT_EN(USART3, read_string);

	USART_SEND_STRING(USART3," mohammed alshreif ");

	while(1){
		delay(300, U_ms, 36000000);
		USART_SEND_STRING(USART3,string_data);
		for(int i=0;i<50;i++){
			string_data[i]=0;
		}
	}

}
