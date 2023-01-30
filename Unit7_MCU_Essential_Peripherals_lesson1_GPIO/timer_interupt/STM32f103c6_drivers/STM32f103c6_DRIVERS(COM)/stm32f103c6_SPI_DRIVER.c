/*
 * stm32f103c6_SPI_DRIVER.c
 *
 *  Created on: Oct 26, 2022
 *      Author: MO_ALSHREIF
 */
#include "stm32f103c6_SPI_DRIVER.h"

#define spi1 0
#define spi2 1
uint8_t spi_select=0;
GPIO_typeDef*gpiox;
GPIO_typeDef*gpiox_SS;
SPI_typeDef* SPI[2];
void SPI_INIT(SPI_typeDef* SPIx ,uint16_t SPI_MODE,uint16_t prescaler,uint16_t Clock_polarity,uint16_t Clock_phase,uint16_t frame_size,uint16_t frame_format)
{
	if(SPIx==SPI1){
		SPI[spi1]=SPIx;
		GPIOA_Clock_Enable();
		AFIO_Clock_Enable();
		SPI1_Clock_Enable();
		gpiox=GPIOA;
		spi_select=0;
		//NVIC_SPI1_interrupt_Enable;
	}
	else{
		SPI[spi2]=SPIx;
		GPIOB_Clock_Enable();
		AFIO_Clock_Enable();
		SPI2_Clock_Enable();
		gpiox=GPIOB;
		spi_select=8;
		//NVIC_SPI2_interrupt_Enable;
	}
	SPIx->SPI_CR1 |=(SPI_MODE|prescaler|frame_size|frame_format|Clock_phase|Clock_polarity);

	//	Bit 9 SSM: Software slave management
	//	When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
	//	0: Software slave management disabled
	//	1: Software slave management enabled
	//	Note: This bit is not used in I2S mode
	//	Bit 8 SSI: Internal slave select
	//	This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
	//	NSS pin and the IO value of the NSS pin is ignored.
	SPIx->SPI_CR1 |=(1<<9 | 1<<8);
	//	Bit 7 TXEIE: Tx buffer empty interrupt enable
	//	0: TXE interrupt masked
	//	1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
	//	Bit 6 RXNEIE: RX buffer not empty interrupt enable
	//	0: RXNE interrupt masked
	//	1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is
	//	set.
	//SPIx->SPI_CR2 |=(1<<7 | 1<<6);

	//	Bit 2 SSOE: SS output enable
	//	0: SS output is disabled in master mode and the cell can work in multimaster configuration
	//	1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work
	//	in a multimaster environment.
	//	SPIx->SPI_CR2 |=(1<<2);

	//MASTER================================================================================
	if(SPI_MODE==SPI_MODE_MASTER_full_duplex){
		//pinmode(GPIOA, pin4, pinmode);//nss
		pinmode(gpiox, pin5+spi_select, GPIO_MODE_OUTPUT_AF_push_pull_Speed10);//sck
		pinmode(gpiox, pin6+spi_select, GPIO_MODE_INTPUT_AF);//miso
		pinmode(gpiox, pin7+spi_select, GPIO_MODE_OUTPUT_AF_push_pull_Speed10);//mosi

		//	Bit 6 SPE: SPI enable
		//	0: Peripheral disabled
		//	1: Peripheral enabled
		SPIx->SPI_CR1 |=(1<<6);
	}
	else if(SPI_MODE==SPI_MODE_MASTER_unidirectional_receive_only){
		pinmode(gpiox, pin6+spi_select, GPIO_MODE_INTPUT_AF);//miso
		pinmode(gpiox, pin5+spi_select, GPIO_MODE_OUTPUT_AF_push_pull_Speed10);//sck
	}
	else if(SPI_MODE==SPI_MODE_MASTER_bidirectional_transmit){
		pinmode(gpiox, pin7+spi_select, GPIO_MODE_OUTPUT_AF_push_pull_Speed10);//mosi
		pinmode(gpiox, pin5+spi_select, GPIO_MODE_OUTPUT_AF_push_pull_Speed10);//sck

		//	Bit 6 SPE: SPI enable
		//	0: Peripheral disabled
		//	1: Peripheral enabled
		SPIx->SPI_CR1 |=(1<<6);
	}
	else if(SPI_MODE==SPI_MODE_MASTER_bidirectional_receive){
		pinmode(gpiox, pin7+spi_select, GPIO_MODE_INTPUT_AF);//mosi
		pinmode(gpiox, pin5+spi_select, GPIO_MODE_OUTPUT_AF_push_pull_Speed10);//sck


	}
	//SLAVE================================================================================
	else if(SPI_MODE==SPI_MODE_SLAVE_full_duplex){
		pinmode(gpiox, pin4+spi_select, GPIO_MODE_INTPUT_AF);//nss
		pinmode(gpiox, pin5+spi_select, GPIO_MODE_INTPUT_AF);//sck
		pinmode(gpiox, pin6+spi_select, GPIO_MODE_OUTPUT_AF_push_pull_Speed10);//miso
		pinmode(gpiox, pin7+spi_select, GPIO_MODE_INTPUT_AF);//mosi
		//	Bit 6 SPE: SPI enable
		//	0: Peripheral disabled
		//	1: Peripheral enabled
		SPIx->SPI_CR1 |=(1<<6);
	}
	else if(SPI_MODE==SPI_MODE_SLAVE_unidirectional_receive_only){
		pinmode(gpiox, pin4+spi_select, GPIO_MODE_INTPUT_AF);//nss
		pinmode(gpiox, pin5+spi_select, GPIO_MODE_INTPUT_AF);//sck
		pinmode(gpiox, pin7+spi_select, GPIO_MODE_INTPUT_AF);//mosi
		SPIx->SPI_CR1 |=(1<<6);
	}
	else if(SPI_MODE==SPI_MODE_SLAVE_bidirectional_transmit){
		pinmode(gpiox, pin4+spi_select, GPIO_MODE_INTPUT_AF);//nss
		pinmode(gpiox, pin5+spi_select, GPIO_MODE_INTPUT_AF);//sck
		pinmode(gpiox, pin6+spi_select, GPIO_MODE_OUTPUT_AF_push_pull_Speed10);//miso
		//	Bit 6 SPE: SPI enable
		//	0: Peripheral disabled
		//	1: Peripheral enabled
		SPIx->SPI_CR1 |=(1<<6);
	}
	else if(SPI_MODE==SPI_MODE_SLAVE_bidirectional_receive){
		pinmode(gpiox, pin4+spi_select, GPIO_MODE_INTPUT_AF);//nss
		pinmode(gpiox, pin5+spi_select, GPIO_MODE_INTPUT_AF);//sck
		pinmode(gpiox, pin6+spi_select, GPIO_MODE_INTPUT_AF);//miso
		SPIx->SPI_CR1 |=(1<<6);
	}

	//	Bit 6 SPE: SPI enable
	//	0: Peripheral disabled
	//	1: Peripheral enabled
	//SPIx->SPI_CR1 |=(1<<6);
}

// ==  in full duplex mode======
//MISO pin6        |
//MOSI pin7  SPI1  |= pin+8 SPI2
//clk  pin5        |
void SPI_SEND_ERCEIVE(SPI_typeDef* SPIx ,uint16_t* data,uint16_t pin){
	if(SPIx==SPI1)gpiox_SS=GPIOA;
	else gpiox_SS=GPIOB;
	pinwrite(gpiox_SS, pin, LOW);
	//Bit 1 TXE: Transmit buffer empty
	//0: Tx buffer not empty
	//1: Tx buffer empty
	while( !(((SPIx->SPI_SR)>>1)&1) );
	SPIx->SPI_DR =*data;
	while( (((SPIx->SPI_SR)>>7)&1) );
	while( !(((SPIx->SPI_SR)>>0)&1) );
	*data=SPIx->SPI_DR ;
	pinwrite(gpiox_SS, pin, HIGH);
}

// ==  in RECEIVE modes======
//if mode is SPI_MODE_MASTER_unidirectional_receive_only use MISO  pin6+(8)* SPI1 *spi2
//if mode is SPI_MODE_MASTER_bidirectional_receive use MOSI  pin7+(8)* SPI1 *spi2
void SPI_RECEIVE_ONLY_MODE(SPI_typeDef* SPIx ,uint16_t *data,uint16_t pin){
	SPIx->SPI_CR1 |=(1<<6);//en the spi
	if(SPIx==SPI1)gpiox_SS=GPIOA;
	else gpiox_SS=GPIOB;
	pinwrite(gpiox_SS, pin, LOW);
	//	Bit 0 RXNE: Receive buffer not empty
	//	0: Rx buffer empty
	//	1: Rx buffer not empty
	while((((SPIx->SPI_SR)>>0)&1)==0){

	}

	*data=SPIx->SPI_DR;

	//_delay_ms(10);

	pinwrite(gpiox_SS, pin, HIGH);
	SPIx->SPI_CR1 &=~(1<<6);
}

// ==  in SEND modes======
//if mode is SPI_MODE_MASTER_bidirectional_transmit pin7+(8)* mosi spi1  *SPI2
void SPI_SEND(SPI_typeDef* SPIx ,uint16_t *data,uint16_t pin){
	if(SPIx==SPI1)gpiox_SS=GPIOA;
	else gpiox_SS=GPIOB;
	pinwrite(gpiox_SS, pin, LOW);
	//Bit 1 TXE: Transmit buffer empty
	//0: Tx buffer not empty
	//1: Tx buffer empty
	while( !(((SPIx->SPI_SR)>>1)&1) );
	SPIx->SPI_DR =*data;
	while( (((SPIx->SPI_SR)>>7)&1) );
	pinwrite(gpiox_SS, pin, HIGH);
}


void SPI1_IRQHandler(){
	//slave only todo
}
void SPI2_IRQHandler(){
	//slave only todo
}
