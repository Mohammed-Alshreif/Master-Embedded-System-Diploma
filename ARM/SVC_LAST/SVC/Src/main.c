#include "stm32f103c6_ISR_DRIVER.h"

#define ADD 0
#define SUB 1
volatile int V=3;
/*
//#define SVC_ID(ID)  __asm("TST lr,#4 \n\t" "ITE EQ \n\t"\
//		"MRSEQ r0,MSP \n\t" \
//		"MRSNE r0,PSP \n\t"\
//		"LDR r0,[r0,#24]\n\t"\
//		"LDRB r0,[r0,#-2]\n\t"\
//		"MOV %0,r0"\
//		:"=r"(ID))

*/

void OS_SVC_SERVICES(int* STACK_FRAM_POINTER){
	uint8_t SVC_NUM;
	int val1, val2;
   __asm(   "LDR r0,[r0,#24]\n\t"
			"LDRB r0,[r0,#-2]\n\t"
			"MOV %0,r0"
			:"=r"(SVC_NUM));

	//SVC_NUM=*((unsigned char*)(((unsigned char*)STACK_FRAM_POINTER[6])-2));
	val1=STACK_FRAM_POINTER[0];
	val2=STACK_FRAM_POINTER[1];

	switch(SVC_NUM){
	case 0x01:
		STACK_FRAM_POINTER[0]=val1+val2;
		break;

	case 0x02:
		STACK_FRAM_POINTER[0]=val1-val2;
		break;
	case 0x03:

		break;
	case 0x04:

		break;
	}



}

__attribute__((naked)) void SVC_Handler(){
	__asm("TST lr,#4 \n\t"
			"ITE EQ \n\t"
			"MRSEQ r0,MSP \n\t"
			"MRSNE r0,PSP \n\t"
			"B OS_SVC_SERVICES");
}



int OS_SVC_SET(int x,int y,int id){
	volatile int result;

	switch(id){
	case 0:
		__asm("SVC #0x01");//add
		break;

	case 1:
		__asm("SVC #0x02");//sub
		break;
	case 2:
		__asm("SVC #0x03");
		break;
	case 3:
		__asm("SVC #0x04");
		break;
	}

	return result;

}

int main(){


	V=OS_SVC_SET(10,20,ADD);
	V=OS_SVC_SET(10,20,SUB);


	return 0;
}
