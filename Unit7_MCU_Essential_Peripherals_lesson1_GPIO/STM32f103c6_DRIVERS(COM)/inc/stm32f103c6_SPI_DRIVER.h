/*
 * stm32f103c6_SPI_DRIVER.h
 *
 *  Created on: Oct 26, 2022
 *      Author: 20102
 */

#ifndef STM32F103C6_DRIVERS_INC_STM32F103C6_SPI_DRIVER_H_
#define STM32F103C6_DRIVERS_INC_STM32F103C6_SPI_DRIVER_H_

#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"


//@ref SPI_MOOD

//Bit 2 MSTR: Master selection
//0: Slave configuration
//1: Master configuration

//Bit 15 BIDIMODE: Bidirectional data mode enable
//0: 2-line unidirectional data mode selected
//1: 1-line bidirectional data mode selected

//Bit 10 RXONLY: Receive only
//This bit combined with the BIDImode bit selects the direction of transfer in 2-line
//unidirectional mode. This bit is also useful in a multislave system in which this particular
//slave is not accessed, the output from the accessed slave is not corrupted.
//0: Full duplex (Transmit and receive)
//1: Output disabled (Receive-only mode)

//• In full-duplex (BIDIMODE=0 and RXONLY=0)
//– The sequence begins when data are written into the SPI_DR register (Tx buffer).
//– The data are then parallel loaded from the Tx buffer into the 8-bit shift register
//during the first bit transmission and then shifted out serially to the MOSI pin.
//– At the same time, the received data on the MISO pin is shifted in serially to the 8-
//bit shift register and then parallel loaded into the SPI_DR register (Rx buffer).
#define SPI_MODE_MASTER_full_duplex                         (uint16_t)(1<<2)

//• In full-duplex mode (BIDIMODE=0 and RXONLY=0)
//– The sequence begins when the slave device receives the clock signal and the first
//bit of the data on its MOSI pin. The 7 remaining bits are loaded into the shift
//register.
//– At the same time, the data are parallel loaded from the Tx buffer into the 8-bit shift
//register during the first bit transmission, and then shifted out serially to the MISO
//pin. The software must have written the data to be sent before the SPI master
//device initiates the transfer.
#define SPI_MODE_SLAVE_full_duplex                          (uint16_t)( 0 )

//• In unidirectional receive-only mode (BIDIMODE=0 and RXONLY=1)
//– The sequence begins as soon as SPE=1
//– Only the receiver is activated and the received data on the MISO pin are shifted in
//serially to the 8-bit shift register and then parallel loaded into the SPI_DR register
//(Rx buffer).
#define SPI_MODE_MASTER_unidirectional_receive_only         (uint16_t)(1<<2|1<<10)


//• In unidirectional receive-only mode (BIDIMODE=0 and RXONLY=1)
//– The sequence begins when the slave device receives the clock signal and the first
//bit of the data on its MOSI pin. The 7 remaining bits are loaded into the shift
//register.
//– The transmitter is not activated and no data are shifted out serially to the MISO
//pin.
#define SPI_MODE_SLAVE_unidirectional_receive_only          (uint16_t)(0|1<<10)

//• In bidirectional mode, when transmitting (BIDIMODE=1 and BIDIOE=1)
//– The sequence begins when data are written into the SPI_DR register (Tx buffer).
//– The data are then parallel loaded from the Tx buffer into the 8-bit shift register
//during the first bit transmission and then shifted out serially to the MOSI pin.
//– No data are received.
#define SPI_MODE_MASTER_bidirectional_transmit              (uint16_t)(1<<2|1<<15|1<<14)

//• In bidirectional mode, when transmitting (BIDIMODE=1 and BIDIOE=1)
//– The sequence begins when the slave device receives the clock signal and the first
//bit in the Tx buffer is transmitted on the MISO pin.
//– The data are then parallel loaded from the Tx buffer into the 8-bit shift register
//during the first bit transmission and then shifted out serially to the MISO pin. The
//software must have written the data to be sent before the SPI master device
//initiates the transfer.
//– No data are received
#define SPI_MODE_SLAVE_bidirectional_transmit               (uint16_t)(0|1<<15|1<<14)

//• In bidirectional mode, when receiving (BIDIMODE=1 and BIDIOE=0)
//– The sequence begins as soon as SPE=1 and BIDIOE=0.
//– The received data on the MOSI pin are shifted in serially to the 8-bit shift register
//and then parallel loaded into the SPI_DR register (Rx buffer).
//– The transmitter is not activated and no data are shifted out serially to the MOSI
//pin.
#define SPI_MODE_MASTER_bidirectional_receive               (uint16_t)(1<<2|1<<15)

//• In bidirectional mode, when receiving (BIDIMODE=1 and BIDIOE=0)
//– The sequence begins when the slave device receives the clock signal and the first
//bit of the data on its MISO pin.
//– The received data on the MISO pin are shifted in serially to the 8-bit shift register
//and then parallel loaded into the SPI_DR register (Rx buffer).
//– The transmitter is not activated and no data are shifted out serially to the MISO
//pin.
#define SPI_MODE_SLAVE_bidirectional_receive                (uint16_t)(0|1<<15)

//======================================
//@ref prescaler

//Bits 5:3 BR[2:0]: Baud rate control
//000: fPCLK/2
//001: fPCLK/4
//010: fPCLK/8
//011: fPCLK/16
//100: fPCLK/32
//101: fPCLK/64
//110: fPCLK/128
//111: fPCLK/256

#define prescaler_2    (uint16_t)(0b000<<3)
#define prescaler_4    (uint16_t)(0b001<<3)
#define prescaler_8    (uint16_t)(0b010<<3)
#define prescaler_16   (uint16_t)(0b011<<3)
#define prescaler_32   (uint16_t)(0b100<<3)
#define prescaler_64   (uint16_t)(0b101<<3)
#define prescaler_128  (uint16_t)(0b110<<3)
#define prescaler_256  (uint16_t)(0b111<<3)
//======================================
//@ref Clock_polarity
//Bit1 CPOL: Clock polarity
//0: CK to 0 when idle
//1: CK to 1 when idle

#define Clock_polarity_idle_zero   0
#define Clock_polarity_idle_one    (uint16_t)(1<<1)
//======================================
//@ref Clock phase
//Bit 0 CPHA: Clock phase
//0: The first clock transition is the first data capture edge
//1: The second clock transition is the first data capture edge

#define Clock_phase_first_clock_transition    0
#define Clock_phase_second_clock_transition   (uint16_t)(1<<0)
//======================================
//@ref frame_size
//Bit 11 DFF: Data frame format
//0: 8-bit data frame format is selected for transmission/reception
//1: 16-bit data frame format is selected for transmission/reception

#define frame_size_8   0
#define frame_size_16  (uint16_t)(1<<11)

//======================================
//@ref Frame format
//Bit 7 LSBFIRST: Frame format
//0: MSB transmitted first
//1: LSB transmitted first
#define Frame_format_MSB 0
#define Frame_format_LSB (uint16_t)(1<<7)

//======================================


void SPI_INIT(SPI_typeDef* SPIx ,uint16_t SPI_MODE,uint16_t prescaler,uint16_t Clock_polarity,uint16_t Clock_phase,uint16_t frame_size,uint16_t frame_format);

void SPI_SEND_ERCEIVE(SPI_typeDef* SPIx ,uint16_t *data,uint16_t pin);
void SPI_SEND(SPI_typeDef* SPIx ,uint16_t *data,uint16_t pin);
void SPI_RECEIVE_ONLY_MODE(SPI_typeDef* SPIx ,uint16_t *data,uint16_t pin);

#endif /* STM32F103C6_DRIVERS_INC_STM32F103C6_SPI_DRIVER_H_ */
