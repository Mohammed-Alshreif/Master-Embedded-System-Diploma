/*
 * stm32f103c6_ADC.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Mohammed Alshreif
 */

#include "stm32f103c6_ADC.h"


uint8_t flag_ADC_INIT=0;

void ADC_INIT(ADC_typeDef* ADCx,uint8_t ADC_STATE_){

	if(ADC_STATE_==ADC_STATE_START){
		if(ADCx==ADC1){
			ADC1_Clock_Enable();
		}
		else if(ADCx==ADC2){
			ADC2_Clock_Enable();
		}
		//		Bit 0 ADON: A/D converter ON / OFF
		//		This bit is set and cleared by software. If this bit holds a value of zero and a 1 is written to it
		//		then it wakes up the ADC from Power Down state.
		//		Conversion starts when this bit holds a value of 1 and a 1 is written to it. The application
		//		should allow a delay of tSTAB between power up and start of conversion. Refer to Figure 23.
		//		0: Disable ADC conversion/calibration and go to power down mode.
		//		1: Enable ADC and to start conversion
		ADCx->ADC_CR2 |=(1<<0);


		//		Bit 1 CONT: Continuous conversion
		//		This bit is set and cleared by software. If set conversion takes place continuously till this bit is
		//		reset.
		//		0: Single conversion mode
		//		1: Continuous conversion mode
		ADCx->ADC_CR2 &=~(1<<1);

		//		Bit 2 CAL: A/D Calibration
		//		This bit is set by software to start the calibration. It is reset by hardware after calibration is
		//		complete.
		//		0: Calibration completed
		//		1: Enable calibratio
		ADCx->ADC_CR2 |=(1<<2);
		while(((ADCx->ADC_CR2>>2)&1)){};


		flag_ADC_INIT=1;
	}
	else{

		ADCx->ADC_CR2 &=~(1<<0);
		ADC1_Clock_DESABLE();
		ADC2_Clock_DESABLE();
		flag_ADC_INIT=0;
	}


}





uint16_t ADC_READ(ADC_typeDef* ADCx,uint8_t ADC_pin){
	if(flag_ADC_INIT){

		if(ADC_pin<0b0111)
			pinmode(GPIOA, ADC_pin, GPIO_MODE_ANALOG);
		else
			pinmode(GPIOB, ADC_pin, GPIO_MODE_ANALOG);

		ADCx->ADC_CR2=0;
		ADCx->ADC_SQR3 =0;

		//Bits 4:0 SQ1[4:0]: first conversion in regular sequence
		ADCx->ADC_SQR3 |=(ADC_pin << 0);






		//		Bit 0 ADON: A/D converter ON / OFF
		//		This bit is set and cleared by software. If this bit holds a value of zero and a 1 is written to it
		//		then it wakes up the ADC from Power Down state.
		//		Conversion starts when this bit holds a value of 1 and a 1 is written to it. The application
		//		should allow a delay of tSTAB between power up and start of conversion. Refer to Figure 23.
		//		0: Disable ADC conversion/calibration and go to power down mode.
		//		1: Enable ADC and to start conversion
		ADCx->ADC_CR2 |=(1<<0);
		ADCx->ADC_CR2 |=(1<<0);

		//		Bit 22 SWSTART: Start conversion of regular channels
		//		This bit is set by software to start conversion and cleared by hardware as soon as
		//		conversion starts. It starts a conversion of a group of regular channels if SWSTART is
		//		selected as trigger event by the EXTSEL[2:0] bits.
		//		0: Reset state
		//		1: Starts conversion of regular channels
		ADCx->ADC_CR2 |=(1<<22);

		//		Bit 1 EOC: End of conversion
		//		This bit is set by hardware at the end of a group channel conversion (regular or injected). It is
		//		cleared by software or by reading the ADC_DR.
		//		0: Conversion is not complete
		//		1: Conversion complete
		while(! ((ADCx->ADC_SR>>1)&1) ){};

		return((uint16_t)ADCx->ADC_DR);

	}
	else{
		return 0;
	}


}
