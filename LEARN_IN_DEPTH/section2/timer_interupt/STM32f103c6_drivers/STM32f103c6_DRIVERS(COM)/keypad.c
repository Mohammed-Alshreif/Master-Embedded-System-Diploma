
#include "keypad.h"

int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columns
char flag1=1;
void Keypad_init(){
	//DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	//DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	pinmode(KEYPAD_PORT,R0 ,GPIO_MODE_OUTPUT_push_pull_Speed2);
	pinmode(KEYPAD_PORT,R1 ,GPIO_MODE_OUTPUT_push_pull_Speed2);
	pinmode(KEYPAD_PORT,R2 ,GPIO_MODE_OUTPUT_push_pull_Speed2);
	pinmode(KEYPAD_PORT,R3 ,GPIO_MODE_OUTPUT_push_pull_Speed2);

	pinmode(KEYPAD_PORT,C0 ,GPIO_MODE_OUTPUT_push_pull_Speed2);
	pinmode(KEYPAD_PORT,C1 ,GPIO_MODE_OUTPUT_push_pull_Speed2);
	pinmode(KEYPAD_PORT,C2 ,GPIO_MODE_OUTPUT_push_pull_Speed2);
	pinmode(KEYPAD_PORT,C3 ,GPIO_MODE_OUTPUT_push_pull_Speed2);
	//KEYPAD_PORT = 0xFF;

}

char Keypad_getkey(){
	int i,j;
	for (i = 0; i < 4; i++){
		//KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));
		set_Value_PORT(KEYPAD_PORT,0b1111,Key_padCol[0]);
		//KEYPAD_PORT &= ~(1<<Key_padCol[i]);
		res_Value_PORT(KEYPAD_PORT, 1, Key_padCol[i]);
		for(j = 0; j < 4; j++){
			//!(keypadPIN & (1 << Key_padRow[j]))
			if ((READ_PIN(KEYPAD_PORT, Key_padRow[j]))==0)
			{
				//if(flag1==1){
				//	flag1=0;
					switch(i){
						case (0):
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
						case (1):
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
						case (2):
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
						case (3):
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
					}
			//	}
				//else flag1=1;
			}

		}
	}
	return 'A';
}
