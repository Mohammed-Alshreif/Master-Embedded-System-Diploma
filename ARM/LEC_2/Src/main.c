#include "stm32f103c6_ISR_DRIVER.h"

int p=7;
int y=3;
int z,VAL1,ISR_NUM;
void ISR(){
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
