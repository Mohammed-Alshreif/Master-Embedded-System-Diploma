#include "SCEDULER.h"
TASK_FRAME_t TASK1,TASK2;
uint8_t T1,T2;
uint8_t X=0;
uint8_t text[5];

void reverse(char* str, int length) {
    int i;
    char temp;
    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void numToString(int num, char* str) {
    int i = 0;
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    while (num != 0) {
        int digit = num % 10;
        str[i++] = digit + '0';
        num = num / 10;
    }
    if (isNegative) {
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse(str, i);
}
int mstrlen(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

char *my_strcat(char *dest, const char *src) {
    int dest_len = mstrlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';

    return dest;
}


void TASK1_fun(){
	
	while(1){//ADC
		T1^=1;TogglePin(GPIOA, pin7);//for test
		X=200*ADC_READ(ADC2, ADC_pin_PA1)/4095+3;

		ALSHREIF_RTOS_TASK_WAIT(&TASK1, 20);
		
	}
}
void TASK2_fun(){//lcd
	
	while(1){
		T2^=1;
		
		TogglePin(GPIOB, pin0);
		numToString(X, text);
		USART_SEND_STRING(USART3,my_strcat(text," \n"));
		
		ALSHREIF_RTOS_TASK_WAIT(&TASK2, 200);
		
	}
}

//============================================================================================================
int main(void)
{

	HARD_WARE_INIT();
	ALSHREIF_RTOS_INIT();

	strcpy(TASK1.NAME,"TASK1");
	TASK1.TASK_FUNCTION=TASK1_fun;
	TASK1.priority=3;
	TASK1.stack_size=1024;

	strcpy(TASK2.NAME,"TASK2");
	TASK2.TASK_FUNCTION=TASK2_fun;
	TASK2.priority=3;
	TASK2.stack_size=1024;

	
	ALSHREIF_RTOS_CREAT_TASK(&TASK1);
	ALSHREIF_RTOS_CREAT_TASK(&TASK2);

	ALSHREIF_RTOS_ACTIVAT_TASK(NULL,&TASK1);
	ALSHREIF_RTOS_ACTIVAT_TASK(NULL,&TASK2);
	//	ALSHREIF_RTOS_ACTIVAT_TASK(&TASK3);

	ALSHREIF_RTOS_START_OS();
	while(1);
}
