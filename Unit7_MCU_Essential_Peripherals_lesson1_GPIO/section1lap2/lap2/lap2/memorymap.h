/*
 * memorymap.h
 *
 * Created: 17/09/2022 01:54:45 م
 *  Author: moAlshreif
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_
//PORT A
#define PORTA (*(volatile unsigned int*)(0x3B))
#define DDRA (*(volatile unsigned int*)(0x3A))
#define PINA (*(volatile unsigned int*)(0x39))
//PORT B
#define PORTB (*(volatile unsigned int*)(0x38))
#define DDRB (*(volatile unsigned int*)(0x37))
#define PINB (*(volatile unsigned int*)(0x36))
//PORT C
#define PORTC (*(volatile unsigned int*)(0x35))
#define DDRC (*(volatile unsigned int*)(0x34))
#define PINC (*(volatile unsigned int*)(0x33))
//PORT D
#define PORTD (*(volatile unsigned int*)(0x32))
#define DDRD (*(volatile unsigned int*)(0x31))
#define PIND (*(volatile unsigned int*)(0x30))


#endif /* MEMORYMAP_H_ */