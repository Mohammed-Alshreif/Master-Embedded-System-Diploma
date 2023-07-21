/*
 * Triac_drimmer.c
 *
 *  Created on: Jul 12, 2023
 *      Author: 20102
 */


#include "Triac_drimmer.h"

static uint16_t TIME_DELAY=0;

void triac_activat(){
	pinwrite(Drimer_POART,TRIAC_PIN,HIGH);
	for(int i=0;i<100;i++);
	pinwrite(Drimer_POART,TRIAC_PIN,LOW);
}
void zero_cross_ISR(){
	TIMER_ISR(TIM3,TIME_DELAY,U_us, 36000000,triac_activat);
}
void Drimmer_init(void){
	EXTI(Drimer_POART,ZERO_CROS_PIN,EXTI_Trigger_Rising, zero_cross_ISR);
	pinmode(Drimer_POART,TRIAC_PIN,GPIO_MODE_OUTPUT_push_pull_Speed10);

}
void Drimer_set(uint16_t DRIM){
	if(DRIM>1000){
		DRIM=1000;
	}
	if(DRIM<0){
		DRIM=0;
	}
	TIME_DELAY=10000-DRIM*10;
}
