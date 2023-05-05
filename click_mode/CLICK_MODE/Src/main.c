#include "CLICK_MODE.h"
uint8_t arr_putton[3]={0,1};
CLICK_MODE data1,data2;
int main(void)
{
	CLICK_MODE_INIT(GPIOA,2,arr_putton);
	/* Loop forever */
	while(1){
		data1= CLICK_MODE_UPDATE(0);
		data2= CLICK_MODE_UPDATE(1);
	}
}
