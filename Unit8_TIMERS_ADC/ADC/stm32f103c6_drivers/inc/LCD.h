/*
 * LCD.h
 *
 * Created: 19/09/2022 10:27:34 ص
 *  Author: 20102
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "stdio.h"
#include "stdlib.h"
#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"

#define  lCD_PORT GPIOB

#define E  pin0
#define RW pin1
#define RS pin2
#define D4 pin4
#define D5 pin5
#define D6 pin6
#define D7 pin7


void LCD_Init();
void LCD_write_CMD(char CMD);
void LCD_write_data(char data);
void LCD_write_string(char* data);
void LCD_setcerser(char ROW , char COL);
void LCD_write_FLOATnumber(float num,unsigned char digit);
void LCD_write_INTnumber(int num);
void LCD_clear();

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
#endif /* LCD_H_ */
