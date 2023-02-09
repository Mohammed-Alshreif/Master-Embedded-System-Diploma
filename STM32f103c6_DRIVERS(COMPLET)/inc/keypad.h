
#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "stdio.h"
#include "stdlib.h"
#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"

#define R0 pin8
#define R1 pin9
#define R2 pin10
#define R3 pin11
#define C0 pin12
#define C1 pin13
#define C2 pin14
#define C3 pin15

#define KEYPAD_PORT GPIOA
//#define DataDir_KEYPAD_PORT DDRD
//#define keypadPIN PIND

void Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_H_ */
