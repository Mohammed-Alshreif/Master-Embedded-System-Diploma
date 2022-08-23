#include "uart.h"
#define  UATR0DR *((volatile unsigned int* const )(unsigned int*)(0x101f1000))

void dend_uart0(unsigned char* text)
{
   while(*text !='\0')
   {
   	UATR0DR=(unsigned int)(*text);
   	text++;

   }


}