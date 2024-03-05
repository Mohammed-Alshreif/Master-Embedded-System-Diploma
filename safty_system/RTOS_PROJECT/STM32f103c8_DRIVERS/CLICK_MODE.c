/*
 * CLICK_MODE.c
 *
 *  Created on: May 5, 2023
 *      Author: 20102
 */

#include "CLICK_MODE.h"
void time_handler();
uint8_t timer_flag=0;
uint8_t PIN_NUMPERS=0;

typedef struct BUTTON{
	CLICK_MODE mode;
	uint8_t INTERUPPT_FLAG;
	uint8_t CURENT_POS_STAT;
	uint8_t port;

}BUTTON;

BUTTON trak_button[16];
int intt=0;
int num =0;
void CLICK_ISR(interrupt_data* isr_data,uint8_t interupt_num){

	for(int i=0;i<20;i++);
	num=isr_data[interupt_num].pin;
	trak_button[num].port=isr_data[interupt_num].port;
	trak_button[num].CURENT_POS_STAT=1;
	trak_button[num].INTERUPPT_FLAG++;
	++intt;


	if(!timer_flag)
		TIMER_ISR(TIM3,300,U_ms,8000000,time_handler);
}
void time_handler(){
	timer_flag=0;
	uint8_t curent_status=0;
	for(int i =0;i<PIN_NUMPERS;i++){

		if(trak_button[i].CURENT_POS_STAT==1){
			//double
			if(trak_button[i].INTERUPPT_FLAG>1){
				trak_button[i].mode=double_press;
				trak_button[i].INTERUPPT_FLAG=0;
			}
			else{
				//long or single
				if(trak_button[i].port==1){
					curent_status=READ_PIN(GPIOA,i);
				}
				else if (trak_button[i].port==2) {
					curent_status=READ_PIN(GPIOB,i);
				}


				if(curent_status==1){
					trak_button[i].mode=long_press;
				}
				else{
					trak_button[i].mode=single_press;
				}

				trak_button[i].INTERUPPT_FLAG=0;
			}

			trak_button[i].CURENT_POS_STAT=0;
		}
		else {
			trak_button[i].mode=NOT_press;
		}

	}


}






void CLICK_MODE_INIT(GPIO_typeDef* GPIOx,uint16_t pins_numper,uint8_t* arr_pins){

	PIN_NUMPERS=pins_numper;

	for(int i =0;i<pins_numper;i++){
		EXTI(GPIOx,*arr_pins, EXTI_Trigger_Rising, CLICK_ISR);
		arr_pins++;
	}

}



CLICK_MODE CLICK_MODE_UPDATE(uint8_t BUTTON_NUMBER){

	return trak_button[BUTTON_NUMBER].mode;
}
