/*
 * STM32_I2C_LCD.h
 *
 *  Created on: Dec 7, 2022
 *      Author: 20102
 */

#ifndef STM32F103C6_DRIVERS_INC_STM32_I2C_LCD_H_
#define STM32F103C6_DRIVERS_INC_STM32_I2C_LCD_H_
#include "STM32_I2C_DRIVER.h"
//===========================================================
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)
//=========================================================
void I2C_LCD_Init(I2C_TypeDef* I2Cx,uint16_t address,uint32_t clk);
void I2C_LCD_write_CMD(I2C_TypeDef* I2Cx,char CMD,uint16_t address);
void I2C_LCD_write_data(I2C_TypeDef* I2Cx ,char data,uint16_t address);
void I2C_LCD_write_string(I2C_TypeDef* I2Cx ,char* data,uint16_t address);
void I2C_LCD_setcerser(I2C_TypeDef* I2Cx,uint16_t address,char ROW , char COL);
void I2C_LCD_write_FLOATnumber(I2C_TypeDef* I2Cx,uint16_t address,float num,unsigned char digit);
void I2C_LCD_write_INTnumber(I2C_TypeDef* I2Cx,uint16_t address,int num);
void I2C_LCD_clear(I2C_TypeDef* I2Cx,uint16_t address);

#endif /* STM32F103C6_DRIVERS_INC_STM32_I2C_LCD_H_ */
