/*
 * OS.c
 *
 *  Created on: Mar 1, 2023
 *      Author: 20102
 */
#include "OS.h"
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
