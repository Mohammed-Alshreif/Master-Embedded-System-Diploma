#include "Platform_Types.h"

// Main function prototype
extern void main(void);

// Vector table handlers
void Reset_Handler() ;
void Default_Handler() {
	Reset_Handler() ;
}
void NMI_Handler() __attribute__((weak,alias("Default_Handler"))) ;
void H_Fault_Handler() __attribute__((weak,alias("Default_Handler"))) ;
void MM_Fault_Handler() __attribute__((weak,alias("Default_Handler"))) ;
void Bus_Fault_Handler() __attribute__((weak,alias("Default_Handler"))) ;
void Usage_Fault_Handler() __attribute__((weak,alias("Default_Handler"))) ;

// Linker script symbols
extern unsigned int _STACK_TOP ;
extern unsigned int _E_TEXT ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS ;
extern unsigned int _E_BSS ;

// Passing vector table handlers to .vector section
uint32 vectors[] __attribute__((section(".vectors"))) = {
	(uint32) &_STACK_TOP,
	(uint32) &Reset_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &MM_Fault_Handler,
	(uint32) &Bus_Fault_Handler,
	(uint32) &Usage_Fault_Handler
} ;

void Reset_Handler(){
	// Copy .data section from flash to sram
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char *P_DATA_SRC = (unsigned char*)&_E_TEXT ;
	unsigned char *P_DATA_DES = (unsigned char*)&_S_DATA ;
	for(int Idx;Idx<DATA_SIZE;Idx++)
		*((unsigned char*)P_DATA_DES++) = *((unsigned char*)P_DATA_SRC++) ;
	
	// Init .bss section with zeros in sram
	unsigned int BSS_SIZE = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS ;
	unsigned char *P_BSS_DES = (unsigned char*)&_S_BSS ;
	for(int Idx;Idx<BSS_SIZE;Idx++)
		*((unsigned char*)P_BSS_DES++) = (unsigned char)0 ;
	
	// Jump to main()
	main();
}