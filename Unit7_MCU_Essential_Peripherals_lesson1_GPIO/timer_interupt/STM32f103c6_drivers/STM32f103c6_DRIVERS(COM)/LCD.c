/*
 * LCD.c
 *
 * Created: 19/09/2022 10:28:16 ص
 *  Author: 20102
 */ 
static unsigned flag_init=0;
#include "LCD.h"

void _delay_ms(long x){
	for(long i=0;i<(x*40);i++);
}
void LCD_SEND_EN(){
	//setpit(lCD_PORT,E);
	pinwrite(lCD_PORT, E, HIGH);
	_delay_ms(1);
	pinwrite(lCD_PORT, E, LOW);
}
void LCD_write_CMD(char CMD){
	//clearpit(lCD_PORT,RS);
	//clearpit(lCD_PORT,RW);
	pinwrite(lCD_PORT, RW, LOW);
	pinwrite(lCD_PORT, RS, LOW);
	//for left 4 pit HSP 
	//lCD_PORT &=~(0b1111<<4);
	//lCD_PORT |=((CMD>>4)<<4);
	res_Value_PORT(lCD_PORT,0b1111,4);
	set_Value_PORT(lCD_PORT,(CMD>>4),4);
	LCD_SEND_EN();

	if(flag_init)
	{
		//for right 4 pit LSP 
		//	lCD_PORT &=~(0b1111<<4);
		//	lCD_PORT |=(CMD<<4);
		res_Value_PORT(lCD_PORT,0b1111,4);
		set_Value_PORT(lCD_PORT,(CMD),4);
		LCD_SEND_EN();

	}
	_delay_ms(2);
}
void LCD_Init(){
	flag_init=0;
	//setport(lCD_DDR);
	pinmode(lCD_PORT,  E,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(lCD_PORT, RS,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(lCD_PORT, RW,GPIO_MODE_OUTPUT_push_pull_Speed10);

	pinmode(lCD_PORT, D4,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(lCD_PORT, D5,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(lCD_PORT, D6,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(lCD_PORT, D7,GPIO_MODE_OUTPUT_push_pull_Speed10);

	_delay_ms(20);
	LCD_write_CMD(0x20);
	LCD_write_CMD(0x20);
	LCD_write_CMD(0x80);// 2 line and 5x7 pixel N=1 f=0
	_delay_ms(1);
	LCD_write_CMD(0x00);
	LCD_write_CMD(0xC0);//cerser
	_delay_ms(1);
	LCD_write_CMD(0x00);
	LCD_write_CMD(0x10);
	_delay_ms(2);

	flag_init=1;
}
void LCD_write_data(char data){
	//	setpit(lCD_PORT,RS);
	//	clearpit(lCD_PORT,RW);
	pinwrite(lCD_PORT, RW, LOW);
	pinwrite(lCD_PORT, RS, HIGH);
	//for left 4 pit HSP
	//	lCD_PORT &=~(0b1111<<4);
	//	lCD_PORT |=((data>>4)<<4);
	res_Value_PORT(lCD_PORT,0b1111,4);
	set_Value_PORT(lCD_PORT,(data>>4),4);
	LCD_SEND_EN();

	//for right 4 pit LSP
	//	lCD_PORT &=~(0b1111<<4);
	//	lCD_PORT |=(data<<4);
	res_Value_PORT(lCD_PORT,0b1111,4);
	set_Value_PORT(lCD_PORT,(data),4);
	LCD_SEND_EN();


	_delay_ms(1);
}
void LCD_write_string(char* data){
//	setpit(lCD_PORT,RS);
//	clearpit(lCD_PORT,RW);
	pinwrite(lCD_PORT, RW, LOW);
	pinwrite(lCD_PORT, RS, HIGH);
	while((*data)!=0){

		LCD_write_data(*data);
		data++;
	}

}
void LCD_setcerser(char ROW , char COL){
	volatile unsigned char addres ;
	if(ROW<2 && COL<16){
		addres =(0x40 * ROW) + COL ;
		addres |=(1<<7);
	}

	LCD_write_CMD(addres);
}
void LCD_clear(){
	LCD_write_CMD(LCD_CLEAR_SCREEN);
}

void LCD_write_FLOATnumber(float num,unsigned char digit){
	char text[20];
	gcvt(num,digit,text);
	LCD_write_string(text);
}
void LCD_write_INTnumber(int num){
	char text[20];
	sprintf(text,"%d",num);
	LCD_write_string(text);
}
