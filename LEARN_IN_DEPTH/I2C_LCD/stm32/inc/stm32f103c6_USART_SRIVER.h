/*
 * stm32f103c6_USART_SRIVER.h
 *
 *  Created on: Oct 11, 2022
 * @author : mo alshreif
 */

#ifndef STM32F103C6_USART_SRIVER_H_
#define STM32F103C6_USART_SRIVER_H_
#include "stdio.h"
#include "stdlib.h"
#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"
//==============================================
//@ref interrupt

//Bit 7 TXEIE: TXE interrupt enable
//This bit is set and cleared by software.
//0: Interrupt is inhibited
//1: A USART interrupt is generated whenever TXE=1 in the USART_SR register
#define Transmit_data_register_empty    (uint32_t)(1<<7)

//Bit 6 TCIE: Transmission complete interrupt enable
//This bit is set and cleared by software.
//0: Interrupt is inhibited
//1: A USART interrupt is generated whenever TC=1 in the USART_SR register
#define Transmission_complete            (uint32_t)(1<<6)

//Bit 5 RXNEIE: RXNE interrupt enable
//This bit is set and cleared by software.
//0: Interrupt is inhibited
//1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register
#define Received_data_ready_to_be_read  (uint32_t)(1<<5)


//==============================================
//@ref mode
//Bit 3 TE: Transmitter enable
//This bit enables the transmitter. It is set and cleared by software.
//0: Transmitter is disabled
//1: Transmitter is enabled
//Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble
//(idle line) after the current word, except in Smartcard mode.
//2: When TE is set there is a 1 bit-time delay before the transmission starts.
//Bit 2 RE: Receiver enable
//This bit enables the receiver. It is set and cleared by software.
//0: Receiver is disabled
//1: Receiver is enabled and begins searching for a start bit

#define mode_RX_ENABLE     (uint32_t)(1<<2)
#define mode_TX_ENABLE     (uint32_t)(1<<3)
#define mode_RX_TX_ENABLE  (uint32_t)(1<<3 | 1<<2)
//===============================================
//Bit 12 M: Word length
//This bit determines the word length. It is set or cleared by software.
//0: 1 Start bit, 8 Data bits, n Stop bit
//1: 1 Start bit, 9 Data bits, n Stop bit

#define word_length_8     (uint32_t)(0)
#define word_length_9     (uint32_t)(1<<12)
//===============================================
//@ref baud_rate

#define baud_rate_2400         2400
#define baud_rate_9600         9600
#define baud_rate_19200        19200
#define baud_rate_57600        57600
#define baud_rate_115200       115200
#define baud_rate_230400       230400
#define baud_rate_460800       460800
#define baud_rate_921600       921600
#define baud_rate_2250000      2250000
#define baud_rate_4500000      4500000
//===============================================
//@ref stop_bits

//Bits 13:12 STOP: STOP bits
//These bits are used for programming the stop bits.
//00: 1 Stop bit
//01: 0.5 Stop bit
//10: 2 Stop bits
//11: 1.5 Stop bit
//The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5
#define stop_bits_1           (uint32_t)(0)
#define stop_bits_HALF        (uint32_t)(1<<12)
#define stop_bits_2           (uint32_t)(1<<13)
#define stop_bits_ONE_HALF    (uint32_t)(0b11<<12)
//===============================================
//@ref parity
//Bit 10 PCE: Parity control enable
//This bit selects the hardware parity control (generation and detection). When the parity
//control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
//if M=0) and parity is checked on the received data. This bit is set and cleared by software.
//Once it is set, PCE is active after the current byte (in reception and in transmission).
//0: Parity control disabled
//1: Parity control enabled
//Bit 9 PS: Parity selection
//This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
//bit set). It is set and cleared by software. The parity will be selected after the current byte.
//0: Even parity
//1: Odd parity
#define parity_none (uint32_t)(0)
#define parity_even (uint32_t)(1<<10)
#define parity_odd  (uint32_t)(1<<10|1<<9)
//===============================================
//---------------------
//======= APIs =======
//---------------------

void USART_INIT(USART_typeDef* USARTx,uint32_t mode,uint32_t word_length,uint32_t stop_bits,uint32_t baud_rate,uint32_t parity,uint32_t CLCK);
void USART_READ_INTERRUPT_EN(USART_typeDef* USARTx,void *calback(void));
void USART_RX_INTERRUPT_DE(USART_typeDef* USARTx);
void USART_SEND(USART_typeDef* USARTx,uint16_t* data);
void USART_SEND_STRING(USART_typeDef* USARTx,char* data);
void USART_READ(USART_typeDef* USARTx,uint16_t* data);

#endif /* STM32F103C6_USART_SRIVER_H_ */
