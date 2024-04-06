//*******************************************************
//BY/MOHAMMED ADEL ALSHREIF
//AMR MANSOURA SIEMENS BLDC MOTOR CONTROL
// 2022/10/1
//*******************************************************
#include "STM32_TIMERS_DRIVER.h"
#include "stm32_speed_DRIVER.h"
#include "stm32f103c6_ISR_DRIVER.h"
#include "stm32f103c6_ADC.h"
#include "stm32f103c6_USART_SRIVER.h"
#include "math.h"
#include <string.h>
//*******************************************************
#define MOTOR_MASTER //select driver that works on the correct motor
//#define Encoder_16_P //if it comment the number of pulses in one rotation is 31 pulses
//*******************************************************
#define clk 36000000                 //system clock
#define SYSTEM_DELAY 90              //main delay
#define NUM_OF_HALLSENSOR_PULS 30    //pulses per rotation
#define MAX_PWM 2000                 //max motor PWM high
#define MOTOR_PWM_LOW 800            //motor PWM LOW
#define MAX_SPEED 2300               //MAX_SPEED
#define Ki_INV 5.0
//*******************************************************
void state();                        //action of the next state
void wate();                         //make the 3 phases floating so it make the low side of pwm
void NextStep_NORMAL();				 //what is the next step
void NextStep_REVERES();			 //what is the next step reveres the motor direction
void MOTOR_STOP();                   //stop the motor
void BLDC_init();
void read_string();
void read_string_MOTOR2ENCODER();
//*******************************************************

uint8_t hall1state=1;                 //hall sensor
uint8_t hall2state=0;
uint8_t hall3state=1;

uint8_t MOTOR_state =0;              //motor state
uint8_t MOTOR_DIRECTION;            //motor direction

uint32_t SET_MOTOR_SPEED;
long long encoder_pulses;
int MOTOR_SPEED_RPM,last_read_motor_speed;
int error,MOTOR_PWM;

uint32_t TIME_CALC;

char buf[50];
uint8_t stop_flage,flag_SPEED;
uint8_t HALL2READ;

unsigned char ch;
unsigned char ch2;
char string_data[15];
char string_data2[35];
uint8_t serial_flag=0,index1;
uint8_t serial_flag2=0,index2;
//=================
uint8_t system_count =0;
//*******************************************************
//===================== -INTERRUPT- =====================
//*******************************************************
void s1(){
	hall1state=READ_PIN(GPIOA, pin0);

	//calculate the distance
	HALL2READ = READ_PIN(GPIOA, pin1);
	if(hall1state==1){
		if(HALL2READ > 0){
			encoder_pulses++;
		}
		else{
			encoder_pulses--;
		}
	}

	//motor direction
	if(MOTOR_DIRECTION==0){
		NextStep_NORMAL();
	}
	else {
		NextStep_REVERES();
	}

}
void s2(){
	//calculate the speed
	if(flag_SPEED==0){
		TIME_CALCULATION(clk, TIMER_START);
		flag_SPEED=1;
	}
	else{
		MOTOR_SPEED_RPM=600000000/(TIME_CALCULATION(clk, TIMER_STOP)*NUM_OF_HALLSENSOR_PULS);//read the actual speed //60second *(1000000 micro seconds)*(10 increase the scale)
		flag_SPEED=0;
	}

	//hall read
	hall2state=READ_PIN(GPIOA, pin1);
	//motor direction
	if(MOTOR_DIRECTION==0){
		NextStep_NORMAL();
	}
	else {
		NextStep_REVERES();
	}
}
void s3(){
	//hall read
	hall3state=READ_PIN(GPIOA, pin2);

#ifndef Encoder_16_P
	//calculate the distance
	HALL2READ = READ_PIN(GPIOA, pin1);
	if(hall3state==1){
		if(HALL2READ > 0){
			encoder_pulses--;
		}
		else{
			encoder_pulses++;
		}
	}
#endif
	//motor direction
	if(MOTOR_DIRECTION==0){
		NextStep_NORMAL();
	}
	else {
		NextStep_REVERES();
	}
}
//*******************************************************
//=============== -NextStep action- =====================
//*******************************************************
void NextStep_NORMAL() {
	if ((hall1state == 1) && (hall2state == 0) && (hall3state == 1)) {
		MOTOR_state = 0;
	}
	if ((hall1state == 0) && (hall2state == 0) && (hall3state == 1)) {
		MOTOR_state = 1;
	}
	if ((hall1state == 0) && (hall2state == 1) && (hall3state == 1)) {
		MOTOR_state = 2;
	}
	if ((hall1state == 0) && (hall2state == 1) && (hall3state == 0)) {
		MOTOR_state = 3;
	}
	if ((hall1state == 1) && (hall2state == 1) && (hall3state == 0)) {
		MOTOR_state = 4;
	}
	if ((hall1state == 1) && (hall2state == 0) && (hall3state == 0)) {
		MOTOR_state = 5;
	}
	//second problem % interrupt debouncing %
	//when the interrupt Happens the state change if we first put a rest(LOW PWM),
	//the motor will lose the torque and it return and it make another interrupt
	//and it happens again and again so we start with high side for 50 us to shore the motor pass the sensor
	TIMER_ISR(TIM3,50, U_us, clk, state);
	// 3 phase as a float to solve the pulse stop of motor when it run at high speed
	// when changing the step without rest the motor stuck at pulse time , make it very violent
	//A floating
	pinwrite(GPIOB, pin0,LOW);
	pinwrite(GPIOB, pin1,HIGH);
	//B floating
	pinwrite(GPIOB, pin10,LOW);
	pinwrite(GPIOB, pin7,HIGH);
	//C floating
	pinwrite(GPIOB, pin8,LOW);
	pinwrite(GPIOB, pin5,HIGH);
}
void NextStep_REVERES() {
	if ((hall2state == 1) && (hall1state == 0) && (hall3state == 1)) {
		MOTOR_state = 5;
	}
	if ((hall2state == 0) && (hall1state == 0) && (hall3state == 1)) {
		MOTOR_state = 4;
	}
	if ((hall2state == 0) && (hall1state == 1) && (hall3state == 1)) {
		MOTOR_state = 3;
	}
	if ((hall2state == 0) && (hall1state == 1) && (hall3state == 0)) {
		MOTOR_state = 2;
	}
	if ((hall2state == 1) && (hall1state == 1) && (hall3state == 0)) {
		MOTOR_state = 1;
	}
	if ((hall2state == 1) && (hall1state == 0) && (hall3state == 0)) {
		MOTOR_state = 0;
	}

	TIMER_ISR(TIM3,50, U_us, clk, state);
	// 3 phase as a float to solve the pulse stop of motor when it run at high speed
	// when changing the step without rest the motor stuck at pulse time , make it very violent
	//A floating
	pinwrite(GPIOB, pin0,LOW);
	pinwrite(GPIOB, pin1,HIGH);
	//B floating
	pinwrite(GPIOB, pin10,LOW);
	pinwrite(GPIOB, pin7,HIGH);
	//C floating
	pinwrite(GPIOB, pin8,LOW);
	pinwrite(GPIOB, pin5,HIGH);
}
//*******************************************************
//==================== -LOW PWM- ========================
//*******************************************************
void wate(){
	//A floating
	pinwrite(GPIOB, pin0,LOW);
	pinwrite(GPIOB, pin1,HIGH);
	//B floating
	pinwrite(GPIOB, pin10,LOW);
	pinwrite(GPIOB, pin7,HIGH);
	//C floating
	pinwrite(GPIOB, pin8,LOW);
	pinwrite(GPIOB, pin5,HIGH);
	TIMER_ISR(TIM3,MOTOR_PWM_LOW, U_us, clk, state);
}
//*******************************************************
//==================== -HIGH PWM- =======================
//*******************************************************
void state(){
	switch (MOTOR_state) {
	case 0:
		//MOTOR_state++;
		//A h
		pinwrite(GPIOB, pin0,HIGH);
		pinwrite(GPIOB, pin1,HIGH);
		//B floating
		pinwrite(GPIOB, pin10,LOW);
		pinwrite(GPIOB, pin7,HIGH);
		//C LOW
		pinwrite(GPIOB, pin8,LOW);
		pinwrite(GPIOB, pin5,LOW);
		break;

	case 1:
		//MOTOR_state++;
		//A floating
		pinwrite(GPIOB, pin0,LOW);
		pinwrite(GPIOB, pin1,HIGH);
		//B h
		pinwrite(GPIOB, pin10,HIGH);
		pinwrite(GPIOB, pin7,HIGH);
		//C LOW
		pinwrite(GPIOB, pin8,LOW);
		pinwrite(GPIOB, pin5,LOW);
		break;

	case 2:
		//MOTOR_state++;
		//A l
		pinwrite(GPIOB, pin0,LOW);
		pinwrite(GPIOB, pin1,LOW);
		//B h
		pinwrite(GPIOB, pin10,HIGH);
		pinwrite(GPIOB, pin7,HIGH);
		//C floating
		pinwrite(GPIOB, pin8,LOW);
		pinwrite(GPIOB, pin5,HIGH);
		break;

	case 3:
		//MOTOR_state++;
		//A l
		pinwrite(GPIOB, pin0,LOW);
		pinwrite(GPIOB, pin1,LOW);
		//B floating
		pinwrite(GPIOB, pin10,LOW);
		pinwrite(GPIOB, pin7,HIGH);
		//C h
		pinwrite(GPIOB, pin8,HIGH);
		pinwrite(GPIOB, pin5,HIGH);
		break;

	case 4:
		//MOTOR_state++;
		//A floating
		pinwrite(GPIOB, pin0,LOW);
		pinwrite(GPIOB, pin1,HIGH);
		//B l
		pinwrite(GPIOB, pin10,LOW);
		pinwrite(GPIOB, pin7,LOW);
		//C h
		pinwrite(GPIOB, pin8,HIGH);
		pinwrite(GPIOB, pin5,HIGH);
		break;

	case 5:
		//MOTOR_state=0;
		//A h
		pinwrite(GPIOB, pin0,HIGH);
		pinwrite(GPIOB, pin1,HIGH);
		//B l
		pinwrite(GPIOB, pin10,LOW);
		pinwrite(GPIOB, pin7,LOW);
		//C floating
		pinwrite(GPIOB, pin8,LOW);
		pinwrite(GPIOB, pin5,HIGH);
		break;
	}
	TIMER_ISR(TIM3,MOTOR_PWM, U_us, clk, wate);

}
//*******************************************************
//==================== -MOTOR_STOP- =====================
//*******************************************************
void MOTOR_STOP(){
	//A h
	pinwrite(GPIOB, pin0,LOW);
	pinwrite(GPIOB, pin1,LOW);
	//B floating
	pinwrite(GPIOB, pin10,LOW);
	pinwrite(GPIOB, pin7,LOW);
	//C LOW
	pinwrite(GPIOB, pin8,LOW);
	pinwrite(GPIOB, pin5,LOW);
	stop_flage=1;
}
//*******************************************************
//==================== -BLDC_init- ======================
//*******************************************************
void BLDC_init(){
	MCAL_speed_init(CLK_SORC_IN_CLK8MHz, mood_FAST_MOOD_36MHzCORE);
#ifdef MOTOR_MASTER
	USART_INIT(USART2, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,clk);
	//to receive the data from slave motor control
#endif
	//motor control pins
	pinmode(GPIOB, pin0,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(GPIOB, pin1,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(GPIOB, pin10,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(GPIOB, pin7,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(GPIOB, pin8,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(GPIOB, pin5,GPIO_MODE_OUTPUT_push_pull_Speed10);
	//encoder interrupt pins
	EXTI(GPIOA, pin0,EXTI_Trigger_RisingAndFalling, s1);
	EXTI(GPIOA, pin1,EXTI_Trigger_RisingAndFalling, s2);
	EXTI(GPIOA, pin2,EXTI_Trigger_RisingAndFalling, s3);
	//send data to ttl on master , send encoder and velocity data on slave
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,clk);
	//start motor sequence
	s1();
	s2();
	s3();
	//soft start
	for(int i=0;i<10;i++){
		MOTOR_PWM+=1;
		delay(2, U_ms, clk);
	}
	//Receive the velocity & direction command
	USART_READ_INTERRUPT_EN(USART1, read_string);
#ifdef MOTOR_MASTER
	USART_READ_INTERRUPT_EN(USART2, read_string_MOTOR2ENCODER);
#endif
}
//*******************************************************
//==================== -READ_DATA- ======================
//*******************************************************
void read_string (){

	USART_READ(USART1,&ch);

	if(ch=='$'){
		serial_flag=1;
		index1=0;
	}
	if(ch=='e'){
		serial_flag=0;
		string_data[index1]='\n';
		string_data[index1+1]=0;

	}

	if(serial_flag==1){
		string_data[index1]=ch;
		index1++;
	}
}
#ifdef MOTOR_MASTER
//##COMENT it in motor 2
//*******************************************************
//==================== -READ_MOTOR(2)ENCODER_DATA- ======================
//*******************************************************
void read_string_MOTOR2ENCODER (){

	USART_READ(USART2,&ch2);

	if(ch2=='C'){
		serial_flag2=1;
		index2=0;
	}
	if(ch2=='*'){
		serial_flag2=0;
		string_data2[index2]='\n';
		string_data2[index2+1]=0;

	}

	if(serial_flag2==1){
		string_data2[index2]=ch2;
		index2++;
	}
}
//###
#endif
//*******************************************************
//==================== -MAIN Fun- =======================
//*******************************************************
int main (){
	//******************************
	//======== -BLDC_init- ========
	//******************************
	BLDC_init();

	while(1){
		delay(SYSTEM_DELAY, U_ms, clk);
		system_count++;
		//******************************
		//======== -speed- ============
		//******************************
		//read speed value
		//$.direction.speed.s
		SET_MOTOR_SPEED=atoi(string_data+3)*10;//reat user set point speed

		//(filter) if actual speed is hire than 2300/10 RPM make speed 2300
		//to remove hall effect noise
		if( (abs(MOTOR_SPEED_RPM-last_read_motor_speed))>MAX_SPEED ){
			MOTOR_SPEED_RPM=last_read_motor_speed;
		}
		else {
			last_read_motor_speed=MOTOR_SPEED_RPM;
		}

		//******************************
		//============ -PID- ===========
		//******************************
		error=abs(MOTOR_SPEED_RPM-SET_MOTOR_SPEED);

		if(MOTOR_SPEED_RPM<SET_MOTOR_SPEED){
			MOTOR_PWM+=(error/Ki_INV);
			if(MOTOR_PWM>=MAX_PWM){
				MOTOR_PWM=MAX_PWM;
			}
		}
		else if(MOTOR_SPEED_RPM>SET_MOTOR_SPEED){
			MOTOR_PWM-=(error/Ki_INV);
			if(MOTOR_PWM<=5){
				MOTOR_PWM=5;
			}
		}
		else{//error=0
			if(SET_MOTOR_SPEED==0){
				MOTOR_PWM=2;
			}
			else{
				MOTOR_PWM=MOTOR_PWM;
			}

		}

		//******************************
		//======== -direction- ========
		//******************************
#ifdef MOTOR_MASTER
		if(string_data[2]=='1'){//if motor 2 string_data[1]
			MOTOR_DIRECTION=0;
		}
		else {
			MOTOR_DIRECTION=1;
		}
#endif
#ifndef MOTOR_MASTER
		if(string_data[1]=='1'){//if motor 2 string_data[1]
			MOTOR_DIRECTION=0;
		}
		else {
			MOTOR_DIRECTION=1;
		}
#endif

		//******************************
		//======== -display- ========
		//******************************
		if(system_count>1){
#ifdef MOTOR_MASTER
			//master
			sprintf (buf, "R=%d,C1=%ld,",MOTOR_SPEED_RPM/10,encoder_pulses);
			strcat(buf, string_data2);
			strcat(buf, "\n");
			USART_SEND_STRING(USART1,buf);
#endif
#ifndef MOTOR_MASTER
			sprintf (buf, "C2=%ld*",encoder_pulses);
			USART_SEND_STRING(USART1,buf);
#endif

			system_count=0;
		}
		MOTOR_SPEED_RPM=0;

	}

}


