#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"
#include "stm32f103c6_SPI_DRIVER.h"
#include "stm32f103c6_USART_SRIVER.h"
#include "stm32_speed_DRIVER.h"
#include "STM32_I2C_LCD.h"
#include "STM32_TIMERS_DRIVER.h"
int i=0;
#define address 0x3f
uint16_t spi1_c='1';
char text[5];
int main(void)
{

	GPIOB_Clock_Enable();
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,8000000);
	SPI_INIT(SPI1, SPI_MODE_MASTER_unidirectional_receive_only, prescaler_256, Clock_polarity_idle_one, Clock_phase_first_clock_transition, frame_size_16, Frame_format_MSB);
	pinmode(GPIOB, pin15,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(GPIOA, pin4,GPIO_MODE_OUTPUT_push_pull_Speed10);//ss 1
	pinwrite(GPIOA, pin4, HIGH);

	delay(200, U_ms,8000000);
	I2C_LCD_Init(I2C1,address);
	I2C_LCD_write_string(I2C1,"MOHAMMED",address);
	I2C_LCD_setcerser(I2C1, address,1,0);
	while(1){
		USART_SEND_STRING(USART1," \n ");
		_delay_ms(1400);
		SPI_RECEIVE_ONLY_MODE(SPI1,&spi1_c,pin4);//spi
		_delay_ms(1400);
		spi1_c=((spi1_c>>4)-5);
		I2C_LCD_clear( I2C1,address);
		I2C_LCD_setcerser(I2C1, address,1,0);
		I2C_LCD_write_string(I2C1,"temp:  ",address);
		I2C_LCD_write_INTnumber(I2C1, address,spi1_c);
		I2C_LCD_write_string(I2C1,"C",address);
		delay(300, U_ms,8000000);
		sprintf(text,"%d",spi1_c);
		_delay_ms(1400);
		USART_SEND_STRING(USART1,text);
		_delay_ms(1400);
		USART_SEND_STRING(USART1," \n ");

	}
}
