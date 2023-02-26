#include "stm32f103c6_ISR_DRIVER.h"

int p=7;
int y=3;
int z,VAL1,ISR_NUM;

typedef enum CPU_PRIVILDEG {
	PRIVILDEG,
	UNPRIVILDEG
}CPU_PRIVILDEG_STAT;

void CHANGE_CPU_PRIVILDEG (CPU_PRIVILDEG_STAT STAT){
	switch(STAT){
	case PRIVILDEG:
		__asm(  "MRS r3,CONTROL \n\t"
				"BIC r3,r3,#0x1 \n\t"
				"MSR CONTROL,r3"
		);
		break;
	case UNPRIVILDEG :
		__asm(  "MRS r3,CONTROL \n\t"
				"ORR r3,r3,#0x1 \n\t"
				"MSR CONTROL,r3"
		);
		break;
	}
}
void ISR(){

	CHANGE_CPU_PRIVILDEG(PRIVILDEG);

	__asm("MRS %0,CONTROL"
			:"=r"(VAL1)
	);

	__asm("MRS %0,IPSR"
			:"=r"(ISR_NUM)
	);

}

int main(void)
{
	EXTI(GPIOA, pin2,EXTI_Trigger_Rising, ISR);
	CHANGE_CPU_PRIVILDEG(UNPRIVILDEG);
	while(1){
		__asm("nop");__asm("nop");

		//z=p+y
		__asm("ADD %0,%1,%2"
				:"=r"(z) //output
				 :"r"(p),
				  "r"(y) //input
				  :"r3"  //do not us r3 reg.
		);

		__asm("nop");__asm("nop");

		//VAL1 <--- CONTROL
		__asm("MRS %0,CONTROL"
				:"=r"(VAL1)
		);
		__asm("nop");__asm("nop");

		//ISR_NUM <---IPSR
		__asm("MRS %0,IPSR"
				:"=r"(ISR_NUM)
		);


		__asm("nop");__asm("nop");
	}


}
