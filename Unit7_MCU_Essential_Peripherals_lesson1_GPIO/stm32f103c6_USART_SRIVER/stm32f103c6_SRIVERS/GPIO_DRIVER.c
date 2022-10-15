#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"
uint8_t getposition(uint16_t pin_num){
	uint8_t rval;
	if(pin_num == pin0){
		rval =0;
	}
	if(pin_num == pin1){
		rval =4;
	}
	if(pin_num == pin2){
		rval =8;
	}
	if(pin_num == pin3){
		rval =12;
	}
	if(pin_num == pin4){
		rval =16;
	}
	if(pin_num == pin5){
		rval =20;
	}
	if(pin_num == pin6){
		rval =24;
	}
	if(pin_num == pin7){
		rval =28;
	}
	if(pin_num == pin8){
		rval =0;
	}
	if(pin_num == pin9){
		rval =4;
	}
	if(pin_num == pin10){
		rval =8;
	}
	if(pin_num == pin11){
		rval =12;
	}
	if(pin_num == pin12){
		rval =16;
	}
	if(pin_num == pin13){
		rval =20;
	}
	if(pin_num == pin14){
		rval =24;
	}
	if(pin_num == pin15){
		rval =28;
	}
	return rval;


}
//**================================================================
//* @Fn- pinmode
// * @brief - Initialize a specified GPIO port with specified configurations modes
// * @param [in] - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
// * @param [in] - pin: pin name
// * @param [in] - pinmode:mode of the pin
// * @retval -none
// * Note-
void pinmode(GPIO_typeDef* GPIOx,uint16_t pin,uint32_t pinmode){

	if(pin<8){
		GPIOx->GPIOx_CRL &=~(0xf<<(getposition(pin)));

		if((pinmode==GPIO_MODE_INPUT_PD)||(pinmode==GPIO_MODE_INPUT_PU)){
			if(pinmode == GPIO_MODE_INPUT_PU){
				GPIOx->GPIOx_CRL |=(0b1000<<(getposition(pin)));
				GPIOx->GPIOx_ODR |= (1<<pin);
			}
			else{
				GPIOx->GPIOx_CRL |=(0b1000<<(getposition(pin)));
				GPIOx->GPIOx_ODR &=~(1<<pin);
			}

		}
		else GPIOx->GPIOx_CRL |=(pinmode<<(getposition(pin)));

	}
	else if(pin>7){
		//GPIOx->GPIOx_CRH
		GPIOx->GPIOx_CRH &=~(0xf<<(getposition(pin)));

		if((pinmode==GPIO_MODE_INPUT_PD)||(pinmode==GPIO_MODE_INPUT_PU)){
			if(pinmode == GPIO_MODE_INPUT_PU){
				GPIOx->GPIOx_CRH |=(0b1000<<(getposition(pin)));
				GPIOx->GPIOx_ODR |= (1<<pin);
			}
			else{
				GPIOx->GPIOx_CRH |=(0b1000<<(getposition(pin)));
				GPIOx->GPIOx_ODR &=~(1<<pin);
			}

		}
		else GPIOx->GPIOx_CRH |=(pinmode<<(getposition(pin)));

	}



}


/**================================================================
 * @Fn- pinwrite
 * @brief - Write the GPIOx PINy according to specified parameters in Pin_config
 * @param [in] - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in] - pin: GPIOx PIN Number
 * @param [in] - status: The desired value to write
 * @retval - None
 * Note-
 */
void pinwrite(GPIO_typeDef* GPIOx,uint16_t pin,uint8_t status){
	if(status!=0){
		GPIOx->GPIOx_ODR |=(1<<pin);
	}
	else GPIOx->GPIOx_ODR &=~(1<<pin);

}


/**================================================================
 * @Fn- WRITE_PORT
 * @brief - Write the GPIOx according to specified parameters in Pin_config
 * @param [in] - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in] - value: The desired value to write
 * @retval -
 * Note-
 */
void WRITE_PORT(GPIO_typeDef* GPIOx,uint16_t status){
	GPIOx->GPIOx_ODR = (uint16_t)status;

}

/**================================================================
 * @Fn- set_valio_PORT
 * @brief - Write the GPIOx according to specified parameters in Pin_config
 * @param [in] - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in] - value: The desired value to write
 * @param [in] - position:position of seting Values
 * @retval -
 * Note-
 */

void set_Value_PORT(GPIO_typeDef* GPIOx,uint16_t status,uint16_t position){

	GPIOx->GPIOx_ODR |=(status<<position);
}

/**================================================================
 * @Fn- set_valio_PORT
 * @brief - Write the GPIOx according to specified parameters in Pin_config
 * @param [in] - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in] - value: The desired value to write
 * @param [in] - position:position of seting Values
 * @retval -
 * Note-
 */

void res_Value_PORT(GPIO_typeDef* GPIOx,uint16_t status,uint16_t position){

	GPIOx->GPIOx_ODR &=~(status<<position);
}
/**================================================================
 * @Fn              - READ_PIN
 * @brief           - Read the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin: GPIOx PIN Number
 * @retval          - uint8_t
 * Note             - none
 */

uint8_t READ_PIN(GPIO_typeDef* GPIOx, uint16_t pin){
	return (GPIOx->GPIOx_IDR>>pin)&1;
}

/**================================================================
 * @Fn              - READ_PORT
 * @brief           - Read the GPIOx _PORT according to specified parameters in Pin_config
 * @param [in]      - GPIOx:  GPIO Peripheral

 * @retval          - uint16_t
 * Note             - none
 */
uint16_t READ_PORT(GPIO_typeDef* GPIOx){

	return GPIOx->GPIOx_IDR;
}

void TogglePin(GPIO_typeDef* GPIOx, uint16_t pin){
	GPIOx->GPIOx_ODR ^=(1<<pin);
}
