/*
 * STM32_I2C_DRIVER.c
 *
 *  Created on: Nov 5, 2022
 *      Author: 20102
 */


#include "STM32_I2C_DRIVER.h"
//SM 100K
//master only
//no stretch

void I2C_INIT(I2C_TypeDef* I2Cx,uint32_t APB_clock){
	if(I2Cx==I2C1){
		I2C1_Clock_Enable();
		GPIOB_Clock_Enable();
		//PB6 I2C SCL
		//PB7 IC2 SDA
		pinmode(GPIOB, pin6,GPIO_MODE_OUTPUT_AF_Open_drain_Speed10);
		pinmode(GPIOB, pin7,GPIO_MODE_OUTPUT_AF_Open_drain_Speed10);

	}
	else if(I2Cx==I2C2){
		I2C2_Clock_Enable();
		GPIOB_Clock_Enable();
		//PB10 I2C SCL
		//PB11 IC2 SDA
		pinmode(GPIOB, pin10,GPIO_MODE_OUTPUT_AF_Open_drain_Speed10);
		pinmode(GPIOB, pin11,GPIO_MODE_OUTPUT_AF_Open_drain_Speed10);
	}

	//• Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
	//Bits 5:0 FREQ[5:0]: Peripheral clock frequency
	I2Cx->CR2 &=~(0b111111<<0);
	I2Cx->CR2 |=((APB_clock/1000000)<<0);
	//Bits 11:0 CCR[11:0]: Clock control register in Fm/Sm mode (Master mode)
	//• Configure the clock control registers
	I2Cx->CCR &=~(0b11111111111<<0);
	I2Cx->CCR |=((APB_clock/1000)/(2*100));
	//• Configure the rise time register
	//Bits 5:0 TRISE[5:0]: Maximum rise time in Fm/Sm mode (Master mode)
	I2Cx->TRISE &=(0b111111<<0);
	I2Cx->TRISE |=(((APB_clock/1000000)/2)+1);

	I2C_Acknowledge(I2Cx,ENABLE);
	//• Program the I2C_CR1 register to enable the peripheral
	//Bit 0 PE: Peripheral enable
	I2Cx->CR1|=(1<<0);

}
void I2C_Start_PIT(I2C_TypeDef* I2Cx,Repeated_Start Start){

	if(Start !=RepeatedSart){
		//check the buss
		while(I2C_GetFlagStatus(I2Cx,I2C_FLAG_BUSY));

	}
	//Bit 8 START: Start generation
	I2Cx->CR1 |=(1<<8);
}

void I2C_Master_Send(I2C_TypeDef* I2Cx,uint8_t* data, uint32_t dataLen,uint16_t devAdd,Stop_Condition Stop , Repeated_Start start){
	int i=0;
	I2C_Start_PIT(I2Cx,start);//start
	while(!I2C_GetFlagStatus(I2Cx, EV5));//Start condition generated.
	I2C_SEND_ADRRESS(I2Cx, devAdd, i2c_direction_Write);
	//2.Wait for EV6
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while( !(I2C_GetFlagStatus( I2Cx, EV6)));

	while( !(I2C_GetFlagStatus( I2Cx, MASTER_BYTE_TRANSMITING)));//Busy MSL TXE TRA
	for(;i<dataLen;i++){
		I2Cx->DR=data[i];
		while(!(I2C_GetFlagStatus( I2Cx, EV8)));
	}
	if(Stop == WithStop){
		//Send Stop Condition
		I2C_Stop_PIT(I2Cx);
	}

}
void I2C_Master_Recive(I2C_TypeDef* I2Cx,uint8_t* data, uint32_t dataLen,uint16_t devAdd,Stop_Condition Stop , Repeated_Start start){

	int i=dataLen;

	I2C_Start_PIT(I2Cx,start);//start

	while(!I2C_GetFlagStatus(I2Cx, EV5));//Start condition generated.

	I2C_SEND_ADRRESS(I2Cx, devAdd, i2c_direction_Read);
	//2.Wait for EV6
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while( !(I2C_GetFlagStatus( I2Cx, EV6)));

	I2C_Acknowledge(I2Cx,ENABLE);

	for(;i>1;i--){
		while( !(I2C_GetFlagStatus( I2Cx, EV7)));
		*data = I2Cx->DR ;
		data++;
	}

	I2C_Acknowledge(I2Cx,DISABLE);

	if(Stop == WithStop){
		//Send Stop Condition
		I2C_Stop_PIT(I2Cx);
	}

	I2C_Acknowledge(I2Cx,ENABLE);
}



FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, Status Flag)
{
	FlagStatus bitstatus = RESET;
	volatile uint32_t dummy_Read;
	uint32_t flag1 = 0 ,flag2 =0 , lastevent =0;


	switch(Flag)
	{
	case I2C_FLAG_BUSY:
	{
		//		Bit 1 BUSY: Bus busy
		//		0: No communication on the bus
		//		1: Communication ongoing on the bus
		//		– Set by hardware on detection of SDA or SCL low
		//		– cleared by hardware on detection of a Stop condition.
		//		It indicates a communication in progress on the bus. This information is still updated when
		//		the interface is disabled (PE=0).

		if(((I2Cx->SR2)>>1) & 1 )
			bitstatus = SET;
		else
			bitstatus = RESET;
		break;
	}
	case EV5:
	{

		//		Bit 0 SB: Start bit (Master mode)
		//		0: No Start condition
		//		1: Start condition generated.
		//		– Set when a Start condition generated.
		//		– Cleared by software by reading the SR1 register followed by writing the DR register, or by
		//		hardware when PE=0		the interface is disabled (PE=0).

		if( (I2Cx->SR1>>0) & 1 )
			bitstatus = SET;
		else
			bitstatus = RESET;
		break;
	}
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	case EV6:
	{
		//
		//			Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
		//			This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
		//			when PE=0.
		//			Address matched (Slave)
		//			0: Address mismatched or not received.
		//			1: Received address matched.
		//			– Set by hardware as soon as the received slave address matched with the OAR registers
		//			content or a general call or a SMBus Device Default Address or SMBus Host or SMBus Alert
		//			is recognized. (when enabled depending on configuration).
		//			Note: In slave mode, it is recommended to perform the complete clearing sequence (READ
		//			SR1 then READ SR2) after ADDR is set. Refer to Figure 272.
		//			Address sent (Master)
		//			0: No end of address transmission
		//			1: End of address transmission
		//			– For 10-bit addressing, the bit is set after the ACK of the 2nd byte.
		//			– For 7-bit addressing, the bit is set after the ACK of the byte.
		//			Note: ADDR is not set after a NACK reception
		if( (I2Cx->SR1>>1) & 1 )
			bitstatus = SET;
		else
			bitstatus = RESET;
		dummy_Read = I2Cx->SR2;

		break;
	}
	case EV8_1:
	case EV8:
	{
		//				Bit 7 TxE: Data register empty (transmitters)
		//				0: Data register not empty
		//				1: Data register empty
		//				– Set when DR is empty in transmission. TxE is not set during address phase.
		//				– Cleared by software writing to the DR register or by hardware after a start or a stop condition
		//				or when PE=0.
		//				TxE is not set if either a NACK is received, or if next byte to be transmitted is PEC (PEC=1)
		//				Note: TxE is not cleared by writing the first data being transmitted, or by writing data when
		//				BTF is set, as in both cases the data register is still empty
		if( (I2Cx->SR1>>7) & 1 )
			bitstatus = SET;
		else
			bitstatus = RESET;


		break;
	}

	case EV8_2:
	{
		//					Bit 2 BTF: Byte transfer finished
		//					0: Data byte transfer not done
		//					1: Data byte transfer succeeded
		//					– Set by hardware when NOSTRETCH=0 and:
		//					– In reception when a new byte is received (including ACK pulse) and DR has not been read
		//					yet (RxNE=1).
		//					– In transmission when a new byte should be sent and DR has not been written yet (TxE=1).
		//					– Cleared by software reading SR1 followed by either a read or write in the DR register or by
		//					hardware after a start or a stop condition in transmission or when PE=0.
		//					Note: The BTF bit is not set after a NACK reception
		//					The BTF bit is not set if next byte to be transmitted is the PEC (TRA=1 in I2C_SR2
		//					register and PEC=1 in I2C_CR1 register)
		if( (I2Cx->SR1>>2) & 1 )
			bitstatus = SET;
		else
			bitstatus = RESET;


		break;
	}
	case EV7:
	{
		//					Bit 6 RxNE: Data register not empty (receivers)
		//					0: Data register empty
		//					1: Data register not empty
		//					– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
		//					– Cleared by software reading or writing the DR register or by hardware when PE=0.
		//					RxNE is not set in case of ARLO event.
		//					Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full

		if( (I2Cx->SR1>>6) & 1 )
			bitstatus = SET;
		else
			bitstatus = RESET;


		break;
	}
	case MASTER_BYTE_TRANSMITING:
	{

		/*Read The I2Cx Statu Register*/
		flag1 = I2Cx->SR1;
		flag2 = I2Cx->SR2;
		flag2 = flag2<<16;
		/*Get the last Event value from I2C Statu Register*/
		lastevent = (flag1 | flag2) & ((uint32_t) 0xffffffff);
		//Check whether lastevent contain THE I2C_EVENT
		if((lastevent & MASTER_BYTE_TRANSMITING) == MASTER_BYTE_TRANSMITING)
			bitstatus = SET;
		else
			bitstatus = RESET;
	}
	}
	return bitstatus;
}

void I2C_SEND_ADRRESS(I2C_TypeDef* I2Cx,uint8_t address,uint8_t i2c_direction){

	I2Cx->DR = (address << 1 | i2c_direction);

}
void I2C_Stop_PIT(I2C_TypeDef* I2Cx){
	/*Generate Stop Condition*/
	//	Bit 9 STOP: Stop generation
	//	The bit is set and cleared by software, cleared by hardware when a Stop condition is
	//	detected, set by hardware when a timeout error is detected.
	//	In Master Mode:
	//	0: No Stop generation.
	//	1: Stop generation after the current byte transfer or after the current Start condition is sent.
	//	In Slave mode:
	//	0: No Stop generation.
	//	1: Release the SCL and SDA lines after the current byte transfer
	I2Cx->CR1 |= (1<<9);
}

void I2C_Acknowledge(I2C_TypeDef *I2Cx,FunctionalState State)
{

	//	Bit 10 ACK: Acknowledge enable
	//	This bit is set and cleared by software and cleared by hardware when PE=0.
	//	0: No acknowledge returned
	//	1: Acknowledge returned after a byte is received (matched address or data)

	if(State != DISABLE)
	{
		/*Generate Stop Condition*/
		I2Cx->CR1 |= (1<<10);
	}
	else
	{
		/*Disable  Stop Condition Generation*/
		I2Cx->CR1 &= ~(1<<10);
	}
}
