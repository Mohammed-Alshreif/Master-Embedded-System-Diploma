//#############################################################
// SAFTY SYSTEM FOR AMR ROBOTE WATRONIX TEAM
// BY Mohammed Adel Alshreif
// Using Alshreif RTOS
// INPUTS (temperature ,EMERGENCY_STOP , battery voltage , mercury sensor )
// OUTPUT (3 relays RELAY_MOTORS RELAY_PRAIN RELAY_Charge , Buzzer )
// TASKS-->>>>
// TASK1 ->
// TASK1 ->
// TASK1 ->
// TASK1 ->
// TASK1 ->
//
//#############################################################


#include "SCEDULER.h"
#include "stm32f103c6_ADC.h"
#include "math.h"
#include "STM32_TIMERS_DRIVER.h"
//=============================================================
#define clk 36000000
#define max_motor_Driver_temp 25.0
#define min_batterry_voltage 14 //todo
//============output=========
#define RELAY_MOTORS pin0  //portB
#define RELAY_PRAIN  pin1  //portB
#define RELAY_Charge pin10 //portB
//===========input===========
#define EMERGENCY_STOP  pin7  //portA
#define MERCURY_SENSOR1 pin6  //portA
#define MERCURY_SENSOR2 pin12 //portB
#define MERCURY_SENSOR3 pin13 //portB
#define MERCURY_SENSOR4 pin14 //portB

//=============================================================
TASK_FRAME_t TASK1,TASK2,TASK3,TASK4,TASK5;
uint8_t T1,T2,T3,T4,T5;
uint8_t buf[7];

struct {

	enum{
		first_start,     //when we turn on the battery
		Normal_Mode,
		Charge_Mode,
		Problem_Mode
	}System_mode;

	enum{
		Motor_over_heat,
		Charger_over_heat,
		Overcharg,
		High_Current,
		FallOff,
		Emergency_Stop
	}ERRORS;

}Safty_System;
enum {
	Buzzer_DURATION_1000ms=1000,
	Buzzer_DURATION_500ms=500,
	Buzzer_DURATION_200ms=200,
	Buzzer_DURATION_100ms=100

}Buzzer_DURATION;
//=============================================================
uint8_t T3_flag1=0,T3_flag2=0;
//=============================================================
void HOOK_fun_buzzer(){
	pinwrite(GPIOB, pin11,LOW);
}
//=============================================================
const double c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07,R1 = 10000;
double MOTOR_TEMP;
//=============================================================
uint8_t Battery_Volte;
//=============================================================
uint8_t MERCURY_SENSOR_ARR[4];
uint8_t ROPOT_FALL_OF;
//=============================================================
//#############################################################
//#############################################################
//*************************************************************
//#############################################################
//#############################################################
//=============================================================
double ADC_TO_TEMP(uint16_t ADC_READ);
//=============================================================
//=============================================================
double ADC_TO_TEMP(uint16_t ADC_READ){
	double logR2;
	logR2 = log(R1 * (4095.0 / ADC_READ - 1.0));
	return (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2))- 273.15;
}
//=============================================================
void TASK1_fun(){
	while(1){
		T1^=1;
		Safty_System.System_mode=first_start;
		//3s Delay first(All output relays=0 ,turn on the buzzer with duration 500ms)
		Buzzer_DURATION=Buzzer_DURATION_500ms;
		ALSHREIF_RTOS_ACTIVAT_TASK(&TASK1,&TASK2);
		ALSHREIF_RTOS_TASK_WAIT(&TASK1, 3000);
		// turn on the buzzer with duration 200ms to indicate the second stage <activate checking task>
		ALSHREIF_RTOS_TERMINAT_TASK(&TASK2,HOOK_fun_buzzer);
		Buzzer_DURATION=Buzzer_DURATION_200ms;
		ALSHREIF_RTOS_ACTIVAT_TASK(&TASK1,&TASK2);
		// activate checking task
		ALSHREIF_RTOS_ACTIVAT_TASK(&TASK1,&TASK3);
		ALSHREIF_RTOS_ACTIVAT_TASK(&TASK1,&TASK5);
		ALSHREIF_RTOS_TERMINAT_TASK(&TASK1,NULL);

	}
}
//#####################################################################################
void TASK2_fun(){
	static volatile uint32_t co=0;
	while(1){
		T2^=1;
		co++;
		TogglePin(GPIOB, pin11);
		ALSHREIF_RTOS_TASK_WAIT(&TASK2, Buzzer_DURATION);


	}
}
//#####################################################################################
void TASK3_fun(){

	while(1){
		T3^=1;
		static uint16_t buffer_Battery_Volte=0;
		static float buffer_MOTOR_TEMP=0;

		//Read the motor temperature 2 times with delay 500ms and take the average
		if(T3_flag1==2){
			MOTOR_TEMP=buffer_MOTOR_TEMP/2.0;
			buffer_MOTOR_TEMP=0;
			T3_flag1=0;
		}
		else{
			buffer_MOTOR_TEMP+=ADC_TO_TEMP(ADC_READ(ADC1, ADC_pin_PA0));
			T3_flag1++;
		}
		gcvt(MOTOR_TEMP,3,buf);
		USART_SEND_STRING(USART1,buf);
		ALSHREIF_RTOS_TASK_WAIT(&TASK3, 50);
		USART_SEND_STRING(USART1," C \n");
		ALSHREIF_RTOS_TASK_WAIT(&TASK3, 50);

		//Read Battery Voltage 3 times with delay 500ms and take the average


		if(T3_flag2==2){
			Battery_Volte=buffer_Battery_Volte/2;
			buffer_Battery_Volte=0;
			T3_flag2=0;
			ALSHREIF_RTOS_ACTIVAT_TASK(&TASK3, &TASK4);
		}
		else{
			buffer_Battery_Volte+=(266.0*(ADC_READ(ADC1, ADC_pin_PA1)/4095.0)); //8gain * 3 volt
			T3_flag2++;
		}

		sprintf(buf,"%d",Battery_Volte);
		USART_SEND_STRING(USART1,buf);
		ALSHREIF_RTOS_TASK_WAIT(&TASK3, 50);
		USART_SEND_STRING(USART1," V \n");
		ALSHREIF_RTOS_TASK_WAIT(&TASK3, 1000);


	}
}
//#####################################################################################
void TASK4_fun(){

	while(1){
		T4^=1;
		static uint32_t TIME=0;
		//Problem_Mode Emergency_Stop or over heat or FallOff...
		if(READ_PIN(GPIOA, EMERGENCY_STOP)==HIGH||ROPOT_FALL_OF==HIGH||MOTOR_TEMP>max_motor_Driver_temp){
			Safty_System.System_mode=Problem_Mode;

			if(READ_PIN(GPIOA, EMERGENCY_STOP)==HIGH){
				Safty_System.ERRORS=Emergency_Stop;
				pinwrite(GPIOB, RELAY_MOTORS,LOW);
				pinwrite(GPIOB, RELAY_PRAIN,LOW);
				pinwrite(GPIOB, RELAY_Charge,LOW);
				Buzzer_DURATION=Buzzer_DURATION_100ms;

			}
			else if(ROPOT_FALL_OF==HIGH){
				Buzzer_DURATION=Buzzer_DURATION_500ms;
				Safty_System.ERRORS=FallOff;
				pinwrite(GPIOB, RELAY_PRAIN,HIGH);
				pinwrite(GPIOB, RELAY_MOTORS,LOW);
				pinwrite(GPIOB, RELAY_Charge,LOW);
			}
			else if(MOTOR_TEMP>max_motor_Driver_temp){
				Buzzer_DURATION=Buzzer_DURATION_200ms;
				Safty_System.ERRORS=Motor_over_heat;
				pinwrite(GPIOB, RELAY_PRAIN,HIGH);
				pinwrite(GPIOB, RELAY_MOTORS,LOW);
				pinwrite(GPIOB, RELAY_Charge,LOW);
			}
			ALSHREIF_RTOS_ACTIVAT_TASK(&TASK4, &TASK2);

		}
		//charging mode
		else if(Battery_Volte<min_batterry_voltage*10){
			Buzzer_DURATION=Buzzer_DURATION_200ms;
			Safty_System.System_mode=Charge_Mode;
			pinwrite(GPIOB, RELAY_MOTORS,HIGH);
			pinwrite(GPIOB, RELAY_PRAIN,HIGH);
			pinwrite(GPIOB, RELAY_Charge,HIGH);
			ALSHREIF_RTOS_ACTIVAT_TASK(&TASK4, &TASK2);
		}
		//normal mode
		else{
			Buzzer_DURATION=Buzzer_DURATION_1000ms;
			Safty_System.System_mode=Normal_Mode;
			pinwrite(GPIOB, RELAY_MOTORS,HIGH);
			pinwrite(GPIOB, RELAY_PRAIN,HIGH);
			pinwrite(GPIOB, RELAY_Charge,LOW);
			if(TIME>60){
				TIME++;
				ALSHREIF_RTOS_ACTIVAT_TASK(&TASK4, &TASK2);
				if(TIME>64){
					TIME=0;
				}
			}
			else{
				TIME++;
				ALSHREIF_RTOS_TERMINAT_TASK(&TASK2,HOOK_fun_buzzer);
			}
		}

		ALSHREIF_RTOS_TASK_WAIT(&TASK4, 100);

	}
}
//#####################################################################################
void TASK5_fun(){

	while(1){
		T5^=1;
		static num_sensor_high=0;
		MERCURY_SENSOR_ARR[0]=READ_PIN(GPIOA, MERCURY_SENSOR1);
		MERCURY_SENSOR_ARR[1]=READ_PIN(GPIOB, MERCURY_SENSOR2);
		MERCURY_SENSOR_ARR[2]=READ_PIN(GPIOB, MERCURY_SENSOR3);
		MERCURY_SENSOR_ARR[3]=READ_PIN(GPIOB, MERCURY_SENSOR4);
		for(int i=0;i<4;i++){
			num_sensor_high+=MERCURY_SENSOR_ARR[i];
		}
		if(num_sensor_high>2){
			ROPOT_FALL_OF=HIGH;
		}
		else{
			ROPOT_FALL_OF=LOW;
		}
		num_sensor_high=0;
		ALSHREIF_RTOS_TASK_WAIT(&TASK5, 1000);
	}
}
//============================================================================================================
int main(void)
{

	HARD_WARE_INIT();
	ALSHREIF_RTOS_INIT();

	strcpy(TASK1.NAME,"TASK1");
	TASK1.TASK_FUNCTION=TASK1_fun;
	TASK1.priority=4;
	TASK1.stack_size=1024;

	strcpy(TASK2.NAME,"TASK2");
	TASK2.TASK_FUNCTION=TASK2_fun;
	TASK2.priority=3;
	TASK2.stack_size=1024;

	strcpy(TASK3.NAME,"TASK3");
	TASK3.TASK_FUNCTION=TASK3_fun;
	TASK3.priority=2;
	TASK3.stack_size=1024;

	strcpy(TASK4.NAME,"TASK4");
	TASK4.TASK_FUNCTION=TASK4_fun;
	TASK4.priority=0;
	TASK4.stack_size=1024;


	strcpy(TASK5.NAME,"TASK5");
	TASK5.TASK_FUNCTION=TASK5_fun;
	TASK5.priority=1;
	TASK5.stack_size=1024;

	ALSHREIF_RTOS_CREAT_TASK(&TASK1);
	ALSHREIF_RTOS_CREAT_TASK(&TASK2);
	ALSHREIF_RTOS_CREAT_TASK(&TASK3);
	ALSHREIF_RTOS_CREAT_TASK(&TASK4);
	ALSHREIF_RTOS_CREAT_TASK(&TASK5);

	ALSHREIF_RTOS_ACTIVAT_TASK(NULL,&TASK1);
	//	ALSHREIF_RTOS_ACTIVAT_TASK(&TASK2);
	//	ALSHREIF_RTOS_ACTIVAT_TASK(&TASK3);
	ALSHREIF_RTOS_START_OS();
	while(1);
}
