/**
 ******************************************************************************
 * @file           : main.c
 * @author         : MOHAMMED ADEL ALSHREIF
 * @brief          : IR smart home

 ******************************************************************************
 */

#include "stm32_speed_DRIVER.h"
#include "I2C_LCD.h"
#include "STM32_TIMERS_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"
#include "IR_NEC.h"
#define clk 36000000
#define address 0x3f

IR My_IR;
//============================================================================

int main(void)
{
	MCAL_speed_init(CLK_SORC_EX_CLK8MHz, mood_FAST_MOOD_72MHzCORE36MHzpref);
	delay(200, U_ms,clk);
	I2C_LCD_Init(I2C1,address,clk);
	I2C_LCD_write_string(I2C1,"SANDY",address);
	I2C_LCD_setcerser(I2C1, address,1,0);
	I2C_LCD_write_string(I2C1,"Katcoty",address);
	delay(1000, U_ms,clk);
	IR_NEC_init(GPIOB, pin0,GPIOA, pin11);
	I2C_LCD_clear(I2C1, address);
	I2C_LCD_setcerser(I2C1, address,0,0);
	while(1){
		My_IR=IR_CONVERT_READ();
		I2C_LCD_setcerser(I2C1, address,0,0);
		I2C_LCD_write_INTnumber(I2C1, address,My_IR.IR_address);
		I2C_LCD_setcerser(I2C1, address,1,0);
		I2C_LCD_write_INTnumber(I2C1, address,My_IR.command);
		delay(250, U_ms, clk);
		I2C_LCD_clear(I2C1, address);
		IR_SEND(My_IR, GPIOA,pin11);

	}
}
