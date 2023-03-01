#include "stm32f103c6_ISR_DRIVER.h"
#include "OS.h"
//==================
#define MAIN_OS_STACK_SIZE 1024
#define A_STACK_SIZE 200
#define B_STACK_SIZE 200
//====================================================

#define OS_set_PSP_stack(address) __asm volatile("MOV r0,%0 \n\t" "MSR psp,r0": : "r"(address))
#define OS_set_MSP_stack(address) __asm volatile("MOV r0,%0 \n\t" "MSR msp,r0": : "r"(address))

#define OS_SP2_PSP __asm volatile ("MRS r0,CONTROL \n\t ORR r0,r0,#2 \n\t MSR CONTROL,r0")
#define OS_SP2_MSP __asm volatile ("MRS r0,CONTROL \n\t BIC r0,r0,#2 \n\t MSR CONTROL,r0")

#define SVC __asm volatile ("SVC #3")

//====================================================
uint32_t volatile _estack;
uint32_t volatile _MIN_STACK;
//===================ALL_STACK========================
uint32_t volatile STACK_TOP = & _estack;
uint32_t volatile STACK_BOTTOM =& _MIN_STACK;

//=================MAIN_OS============================
uint32_t MAIN_OS_STACK_BPTTOM;
uint32_t MAIN_OS_STACK_TOP;

//=================TASK_A=============================
uint32_t A_STACK_TOP;
uint32_t A_STACK_BPTTOM;
//=================TASK_B=============================
uint32_t B_STACK_TOP;
uint32_t B_STACK_BPTTOM;

//====================================================
uint8_t task_pointer=0;



//=======================================================================================

void SVC_Handler(){
	CHANGE_CPU_PRIVILDEG(PRIVILDEG);
}
//====================
void fun_task_A(int a,int b,int c){
	a=a+b+c;
	a=a-b-c;
	a=a+b-c;
}
void TASK_A(){
	fun_task_A(1, 2, 3);
}

//===================
void fun_task_B(int a,int b,int c){
	a=a+b+c;
	a=a-b-c;
	a=a+b-c;
}
void TASK_B(){
	fun_task_B(1, 2, 3);
}
//===================
void ISR(){
	switch(task_pointer){
	case 0:
		task_pointer++;
		break;
	case 1:
		task_pointer++;
		break;
	case 2:
		task_pointer--;
		break;
	default :
		break;
	}
}
//===================
void MAIN_OS(){
	MAIN_OS_STACK_TOP=STACK_TOP;
	MAIN_OS_STACK_BPTTOM=(MAIN_OS_STACK_TOP-MAIN_OS_STACK_SIZE);
	//=======
	A_STACK_TOP=(MAIN_OS_STACK_BPTTOM-8);
	A_STACK_BPTTOM=(A_STACK_TOP-A_STACK_SIZE);
	//======
	B_STACK_TOP=(A_STACK_BPTTOM-8);
	B_STACK_BPTTOM=(B_STACK_TOP-B_STACK_SIZE);




	while(1){

		switch(task_pointer){
		case 1:
			OS_set_PSP_stack(A_STACK_TOP);
			OS_SP2_PSP;
			CHANGE_CPU_PRIVILDEG(UNPRIVILDEG);
			TASK_A();
			SVC;
			//OS_set_MSP_stack(address)
			OS_SP2_MSP;
			break;
		case 2:
			OS_set_PSP_stack(B_STACK_TOP);
			OS_SP2_PSP;
			CHANGE_CPU_PRIVILDEG(UNPRIVILDEG);
			TASK_B();
			SVC;
			//OS_set_MSP_stack(address)
			OS_SP2_MSP;
			break;
		default :
			break;
		}



		__asm volatile ("NOP");
		int x=1;
		x++;
	};

}
//===================
int main(void)
{
	EXTI(GPIOA, pin2,EXTI_Trigger_Rising, ISR);
	MAIN_OS();

	while(1){};
}
