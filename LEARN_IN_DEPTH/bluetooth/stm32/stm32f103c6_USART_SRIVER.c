/*
 * stm32f103c6_USART_SRIVER.c
 *
 *  Created on: Oct 11, 2022
 * @author         : mo alshreif
 */


#include "stm32f103c6_USART_SRIVER.h"
//===============================================================
USART_typeDef* arr[3];
int arr_string_lingh[3];
char * arr_data[3];
uint16_t arr_data_RES[3];

void(* GP_reseve_Callback[3])(void);
//===============================================================
void send_string (){

}
//===============================================================
void USART_INIT(USART_typeDef* USARTx,uint32_t mode,uint32_t word_length,uint32_t stop_bits,uint32_t baud_rate,uint32_t parity,uint32_t CLCK){

	if(USARTx ==USART1){
		USART1_Clock_Enable();
		GPIOA_Clock_Enable();
		NVIC_USART1_interrupt_Enable;
		//TX
		pinmode(GPIOA, pin9,GPIO_MODE_OUTPUT_AF_push_pull_Speed10);
		//RX
		pinmode(GPIOA, pin10,GPIO_MODE_INTPUT_AF);
		arr[0]=USART1;
	}
	else if(USARTx ==USART2){
		USART2_Clock_Enable();
		GPIOA_Clock_Enable();
		NVIC_USART2_interrupt_Enable;
		//TX
		pinmode(GPIOA, pin2,GPIO_MODE_OUTPUT_AF_push_pull_Speed10);
		//RX
		pinmode(GPIOA, pin3,GPIO_MODE_INTPUT_AF);
		arr[1]=USART2;
	}
	else{
		USART3_Clock_Enable();
		GPIOB_Clock_Enable();
		NVIC_USART3_interrupt_Enable;
		//TX
		pinmode(GPIOB, pin10,GPIO_MODE_OUTPUT_AF_push_pull_Speed10);
		//RX
		pinmode(GPIOB, pin11,GPIO_MODE_INTPUT_AF);
		arr[2]=USART3;
	}

	//STEP 1
	//	Bit 13 UE: USART enable
	//	When this bit is cleared the USART prescalers and outputs are stopped and the end of the
	//	current
	//	byte transfer in order to reduce power consumption. This bit is set and cleared by software.
	//	0: USART prescaler and outputs disabled
	//	1: USART enabled
	USARTx->USART_CR1 |=(1<<13);

	//STEP 2
	//	Bit 12 M: Word length
	//	This bit determines the word length. It is set or cleared by software.
	//	0: 1 Start bit, 8 Data bits, n Stop bit
	//	1: 1 Start bit, 9 Data bits, n Stop bit
	USARTx->USART_CR1 |=word_length;

	//STEP 3
	//	Bits 13:12 STOP: STOP bits
	//	These bits are used for programming the stop bits.
	//	00: 1 Stop bit
	//	01: 0.5 Stop bit
	//	10: 2 Stop bits
	//	11: 1.5 Stop bit
	USARTx->USART_CR2 |=stop_bits;

	//STEP 4
	//	Bit 3 TE: Transmitter enable
	//	This bit enables the transmitter. It is set and cleared by software.
	//	0: Transmitter is disabled
	//	1: Transmitter is enabled
	//	Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble
	//	(idle line) after the current word, except in Smartcard mode.
	//	2: When TE is set there is a 1 bit-time delay before the transmission starts.
	//	Bit 2 RE: Receiver enable
	//	This bit enables the receiver. It is set and cleared by software.
	//	0: Receiver is disabled
	//	1: Receiver is enabled and begins searching for a start bit
	USARTx->USART_CR1 |=mode;

	//STEP 5
	//	Bit 10 PCE: Parity control enable
	//	This bit selects the hardware parity control (generation and detection). When the parity
	//	control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
	//	if M=0) and parity is checked on the received data. This bit is set and cleared by software.
	//	Once it is set, PCE is active after the current byte (in reception and in transmission).
	//	0: Parity control disabled
	//	1: Parity control enabled

	//	Bit 9 PS: Parity selection
	//	This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
	//	bit set). It is set and cleared by software. The parity will be selected after the current byte.
	//	0: Even parity
	//	1: Odd parity
	USARTx->USART_CR1 |=parity;

	//STEP 6
	//	Bits 31:16 Reserved, forced by hardware to 0.
	//	Bits 15:4 DIV_Mantissa[11:0]: mantissa of USARTDIV
	//	These 12 bits define the mantissa of the USART Divider (USARTDIV)
	//	Bits 3:0 DIV_Fraction[3:0]: fraction of USARTDIV
	//	These 4 bits define the fraction of the USART Divider (USARTDIV)

	uint16_t DIV_Mantissa =CLCK /(baud_rate*16);
	uint16_t DIV_Fraction =(((CLCK /((baud_rate*16)/100)) - DIV_Mantissa*100)*16)/100;
	USARTx->USART_BRR =( (DIV_Mantissa<<4) | ((DIV_Fraction)& 0xf) );


}
void USART_SEND(USART_typeDef* USARTx,uint16_t* data){

	if(((USARTx->USART_CR1>>12)&1)==1){
		//	Bit 12 M: Word length
		//	1: 1 Start bit, 9 Data bits, n Stop bit
		USARTx->USART_DR=((*data)&(uint16_t)0x01ff);

	}
	else
	{
		//	0: 1 Start bit, 8 Data bits, n Stop bit
		USARTx->USART_DR=((*data)&(uint16_t)0xff);
	}


}

void USART_READ(USART_typeDef* USARTx,uint16_t* data){

	if(USARTx==USART1){
		*data=arr_data_RES[0];
	}
	if(USARTx==USART2){
		*data=arr_data_RES[1];
	}
	if(USARTx==USART3){
		*data=arr_data_RES[2];
	}

}

void USART_SEND_STRING(USART_typeDef* USARTx,char* data){

	if(USARTx==USART1){
		arr_data[0]=data;
		arr[0]=USART1;
	}
	if(USARTx==USART2){
		arr_data[1]=data;
		arr[1]=USART2;
	}
	if(USARTx==USART3){
		arr_data[2]=data;
		arr[2]=USART3;
	}
	//Bit 7 TXEIE: TXE interrupt enable
	//This bit is set and cleared by software.
	//0: Interrupt is inhibited
	//1: A USART interrupt is generated whenever TXE=1 in the USART_SR register
	USARTx->USART_CR1 |=Transmit_data_register_empty;//open flage of interrupt
}

void USART_READ_INTERRUPT_EN(USART_typeDef* USARTx,void *calback(void)){

	if(USARTx==USART1){
		GP_reseve_Callback[0] = calback;
	}
	else if(USARTx==USART2){
		GP_reseve_Callback[1] = calback;
	}
	else{
		GP_reseve_Callback[2] = calback;
	}
	//RX INTRRUPT
	//Bit 5 RXNEIE: RXNE interrupt enable
	//This bit is set and cleared by software.
	//0: Interrupt is inhibited
	//1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register
	USARTx->USART_CR1 |=Received_data_ready_to_be_read;
}
void USART_RX_INTERRUPT_DE(USART_typeDef* USARTx){
	//RX INTRRUPT
	//Bit 5 RXNEIE: RXNE interrupt enable
	//This bit is set and cleared by software.
	//0: Interrupt is inhibited
	//1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register
	USARTx->USART_CR1 &=~Received_data_ready_to_be_read;
}
void USART1_IRQHandler(){
	pinwrite(GPIOB, pin1,HIGH);
	//arr[0]->USART_SR &=~(1<<6);
	if(  (( (arr[0]->USART_SR>>7) & 1) ==1)&&(((arr[0]->USART_CR1 >>7)&1)==1) ){   //Transmit data register empty

		if((*arr_data[0])!=0){
			USART_SEND(arr[0],arr_data[0]);
			++arr_data[0];
		}
		else {
			//Bit 7 TXEIE: TXE interrupt enable
			//This bit is set and cleared by software.
			//0: Interrupt is inhibited
			//1: A USART interrupt is generated whenever TXE=1 in the USART_SR register
			arr[0]->USART_CR1 &=~Transmit_data_register_empty;
			//arr[0]->USART_SR |=(1<<6);
		}

	}

	//===========================================================================

	if(  (( (arr[0]->USART_SR>>5) & 1) ==1)&&(( (arr[0]->USART_CR1 >>5) &1)==1) ){
		//		Bit 5 RXNE: Read data register not empty
		//		This bit is set by hardware when the content of the RDR shift register has been transferred to
		//		the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
		//		It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by
		//		writing a zero to it. This clearing sequence is recommended only for multibuffer
		//		communication.
		//		0: Data is not received
		//		1: Received data is ready to be read



		//	Bit 12 M: Word length
		//	This bit determines the word length. It is set or cleared by software.
		if(((arr[0]->USART_CR1>>12)&1) ==1){
			//	1: 1 Start bit, 9 Data bits, n Stop bit

			if(((arr[0]->USART_CR1>>10)&1) ==1){
				//Bit 10 PCE: Parity control enable
				// 1: Parity control enabled
				arr_data_RES[0] =(arr[0]->USART_DR & (uint16_t)0xff);
			}
			else{
				//0: Parity control disabled
				arr_data_RES[0]=arr[0]->USART_DR;
			}
		}
		else{
			//	0: 1 Start bit, 8 Data bits, n Stop bit

			if(((arr[0]->USART_CR1>>10)&1) ==1){
				//Bit 10 PCE: Parity control enable
				// 1: Parity control enabled
				arr_data_RES[0] =(arr[0]->USART_DR & (uint16_t)0x7f);
			}
			else{
				//0: Parity control disabled
				arr_data_RES[0] =(arr[0]->USART_DR & (uint16_t)0xff);
			}
		}
		//pinwrite(GPIOB, pin1,HIGH);

		GP_reseve_Callback[0]();

		for(long i=0;i<(20000);i++);
		//pinwrite(GPIOB, pin1,LOW);
		arr[0]->USART_SR &=~(1<<5);//clear
		//arr[0]->USART_CR1 &=~Received_data_ready_to_be_read;
		if(((arr[0]->USART_SR>>3)&1)|1){
			volatile uint16_t d=USART1->USART_DR;
			arr[0]->USART_SR &=~(1<<5);
		}
	}
	if(((arr[0]->USART_SR>>3)&1)|1){
		volatile uint16_t w =USART1->USART_DR;
		arr[0]->USART_SR &=~(1<<5);
	}
	//_delay_ms(500);
	pinwrite(GPIOB, pin1,LOW);
}
void USART2_IRQHandler(){
	//pinwrite(GPIOB, pin1,HIGH);
	//arr[0]->USART_SR &=~(1<<6);
	if(  (( (arr[1]->USART_SR>>7) & 1) ==1)&&(((arr[1]->USART_CR1 >>7)&1)==1) ){   //Transmit data register empty

		if((*arr_data[1])!=0){
			USART_SEND(arr[1],arr_data[1]);
			++arr_data[1];
		}
		else {
			//Bit 7 TXEIE: TXE interrupt enable
			//This bit is set and cleared by software.
			//0: Interrupt is inhibited
			//1: A USART interrupt is generated whenever TXE=1 in the USART_SR register
			arr[1]->USART_CR1 &=~Transmit_data_register_empty;
			//arr[1]->USART_SR |=(1<<6);
		}

	}

	//===========================================================================

	if(  (( (arr[1]->USART_SR>>5) & 1) ==1)&&(( (arr[1]->USART_CR1 >>5) &1)==1) ){
		//		Bit 5 RXNE: Read data register not empty
		//		This bit is set by hardware when the content of the RDR shift register has been transferred to
		//		the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
		//		It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by
		//		writing a zero to it. This clearing sequence is recommended only for multibuffer
		//		communication.
		//		0: Data is not received
		//		1: Received data is ready to be read



		//	Bit 12 M: Word length
		//	This bit determines the word length. It is set or cleared by software.
		if(((arr[1]->USART_CR1>>12)&1) ==1){
			//	1: 1 Start bit, 9 Data bits, n Stop bit

			if(((arr[1]->USART_CR1>>10)&1) ==1){
				//Bit 10 PCE: Parity control enable
				// 1: Parity control enabled
				arr_data_RES[1] =(arr[1]->USART_DR & (uint16_t)0xff);
			}
			else{
				//0: Parity control disabled
				arr_data_RES[1]=arr[1]->USART_DR;
			}
		}
		else{
			//	0: 1 Start bit, 8 Data bits, n Stop bit

			if(((arr[1]->USART_CR1>>10)&1) ==1){
				//Bit 10 PCE: Parity control enable
				// 1: Parity control enabled
				arr_data_RES[1] =(arr[1]->USART_DR & (uint16_t)0x7f);
			}
			else{
				//0: Parity control disabled
				arr_data_RES[1] =(arr[1]->USART_DR & (uint16_t)0xff);
			}
		}
		//pinwrite(GPIOB, pin1,HIGH);

		GP_reseve_Callback[1]();
		for(long i=0;i<(20000);i++);
		//pinwrite(GPIOB, pin1,LOW);
		arr[1]->USART_SR &=~(1<<5);//clear
		//arr[1]->USART_CR1 &=~Received_data_ready_to_be_read;
		if(((arr[1]->USART_SR>>3)&1)|1){
			volatile uint16_t d =USART2->USART_DR;
			arr[1]->USART_SR &=~(1<<5);
		}
	}
	if(((arr[1]->USART_SR>>3)&1)|1){
		volatile uint16_t w =USART2->USART_DR;
		arr[1]->USART_SR &=~(1<<5);
	}
	//	_delay_ms(500);
	//	pinwrite(GPIOB, pin1,LOW);
}
void USART3_IRQHandler(){
	//pinwrite(GPIOB, pin1,HIGH);
	//arr[2]->USART_SR &=~(1<<6);
	if(  (( (arr[2]->USART_SR>>7) & 1) ==1)&&(((arr[2]->USART_CR1 >>7)&1)==1) ){   //Transmit data register empty

		if((*arr_data[2])!=0){
			USART_SEND(arr[2],arr_data[2]);
			++arr_data[2];
		}
		else {
			//Bit 7 TXEIE: TXE interrupt enable
			//This bit is set and cleared by software.
			//0: Interrupt is inhibited
			//1: A USART interrupt is generated whenever TXE=1 in the USART_SR register
			arr[2]->USART_CR1 &=~Transmit_data_register_empty;
			//arr[2]->USART_SR |=(1<<6);
		}

	}

	//===========================================================================

	if(  (( (arr[2]->USART_SR>>5) & 1) ==1)&&(( (arr[2]->USART_CR1 >>5) &1)==1) ){
		//		Bit 5 RXNE: Read data register not empty
		//		This bit is set by hardware when the content of the RDR shift register has been transferred to
		//		the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
		//		It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by
		//		writing a zero to it. This clearing sequence is recommended only for multibuffer
		//		communication.
		//		0: Data is not received
		//		1: Received data is ready to be read



		//	Bit 12 M: Word length
		//	This bit determines the word length. It is set or cleared by software.
		if(((arr[2]->USART_CR1>>12)&1) ==1){
			//	1: 1 Start bit, 9 Data bits, n Stop bit

			if(((arr[2]->USART_CR1>>10)&1) ==1){
				//Bit 10 PCE: Parity control enable
				// 1: Parity control enabled
				arr_data_RES[2] =(arr[2]->USART_DR & (uint16_t)0xff);
			}
			else{
				//0: Parity control disabled
				arr_data_RES[2]=arr[2]->USART_DR;
			}
		}
		else{
			//	0: 1 Start bit, 8 Data bits, n Stop bit

			if(((arr[2]->USART_CR1>>10)&1) ==1){
				//Bit 10 PCE: Parity control enable
				// 1: Parity control enabled
				arr_data_RES[2] =(arr[2]->USART_DR & (uint16_t)0x7f);
			}
			else{
				//0: Parity control disabled
				arr_data_RES[2] =(arr[2]->USART_DR & (uint16_t)0xff);
			}
		}
		//pinwrite(GPIOB, pin1,HIGH);

		GP_reseve_Callback[2]();
		for(long i=0;i<(20000);i++);
		//pinwrite(GPIOB, pin1,LOW);
		arr[2]->USART_SR &=~(1<<5);//clear
		//arr[2]->USART_CR1 &=~Received_data_ready_to_be_read;
		if(((arr[2]->USART_SR>>3)&1)|1){
			volatile uint16_t d =USART3->USART_DR;
			arr[2]->USART_SR &=~(1<<5);
		}
	}
	if(((arr[2]->USART_SR>>3)&1)|1){
		volatile uint16_t w =USART3->USART_DR;
		arr[2]->USART_SR &=~(1<<5);
	}
	//	_delay_ms(500);
	//	pinwrite(GPIOB, pin1,LOW);
}
