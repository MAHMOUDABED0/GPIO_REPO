/*
 * keypad.c
 *
 * Created: 13/03/2022 07:04:31 م
 *  Author: 3abed
 */ 
#include "keypad.h"

int key_row[]={R0,R1,R2,R3}; //rows of the keypad
int Key_Col[] = { C0, C1, C2, C3 }; //columns
void delay_mss(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void Keypad_init(){

	Gpio_pinconfig Keypad_conf;
	Keypad_conf.gpiox_pinnuber=R0;
	Keypad_conf.gpiox_mode=GPIO_MODE_OUTPUT_PP;
	Keypad_conf.gpiox_pinnuber=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT,&Keypad_conf);

	Keypad_conf.gpiox_pinnuber=R1;
	Keypad_conf.gpiox_mode=GPIO_MODE_OUTPUT_PP;
	Keypad_conf.gpiox_pinnuber=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT,&Keypad_conf);

	Keypad_conf.gpiox_pinnuber=R2;
	Keypad_conf.gpiox_mode=GPIO_MODE_OUTPUT_PP;
	Keypad_conf.gpiox_pinnuber=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT,&Keypad_conf);

	Keypad_conf.gpiox_pinnuber=R3;
	Keypad_conf.gpiox_mode=GPIO_MODE_OUTPUT_PP;
	Keypad_conf.gpiox_pinnuber=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT,&Keypad_conf);

	Keypad_conf.gpiox_pinnuber=C0;
	Keypad_conf.gpiox_mode=GPIO_MODE_OUTPUT_PP;
	Keypad_conf.gpiox_pinnuber=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT,&Keypad_conf);


	Keypad_conf.gpiox_pinnuber=C1;
	Keypad_conf.gpiox_mode=GPIO_MODE_OUTPUT_PP;
	Keypad_conf.gpiox_pinnuber=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT,&Keypad_conf);

	Keypad_conf.gpiox_pinnuber=C2;
	Keypad_conf.gpiox_mode=GPIO_MODE_OUTPUT_PP;
	Keypad_conf.gpiox_pinnuber=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT,&Keypad_conf);

	Keypad_conf.gpiox_pinnuber=C3;
	Keypad_conf.gpiox_mode=GPIO_MODE_OUTPUT_PP;
	Keypad_conf.gpiox_pinnuber=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT,&Keypad_conf);
	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);

}

char Keypad_getkey(){
	int x ,i;
	for(i=0;i<4;i++){
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_Col[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_Col[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_Col[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_Col[3], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_Col[i], GPIO_PIN_RESET);
		for (x = 0; x < 4;x++) {
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, key_row[x]) == 0) {
				while (MCAL_GPIO_ReadPin(KEYPAD_PORT, key_row[x]) == 0)
					;
				switch(i){
				case (0):
				if (x == 0) return '7';
				else if (x == 1) return '4';
				else if (x == 2) return '1';
				else if (x == 3) return '?';
				break;
				case (1):
				if (x== 0) return '8';
				else if (x == 1) return '5';
				else if (x == 2) return '2';
				else if (x == 3) return '0';
				break;
				case (2):
				if (x == 0) return '9';
				else if (x == 1) return '6';
				else if (x == 2) return '3';
				else if (x == 3) return '=';
				break;
				case (3):
				if (x == 0) return '/';
				else if (x == 1) return '*';
				else if (x == 2) return '-';
				else if (x == 3) return '+';
				break;
				}

			}

		}

	}
	return 'a';
}
