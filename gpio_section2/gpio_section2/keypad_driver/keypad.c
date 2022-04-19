/*
 * keypad.c
 *
 * Created: 13/03/2022 07:04:31 م
 *  Author: 3abed
 */ 
#include "keypad.h"

int keypad_R[4]={R0,R1,R2,R3};
int keypad_c[4]={C0,C1,C2,C3};
void Keypad_init(){
	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	KEYPAD_PORT=0xff;
		
	
}
char Keypad_getkey(){
	int x ,i;
	for(i=0;i<4;i++){
	KEYPAD_PORT |= ((1 << keypad_c[0]) | (1 <<  keypad_c[1]) | (1 <<  keypad_c[2]) | (1 <<  keypad_c[3]));
	KEYPAD_PORT &=~(1<<keypad_c[i]);
	for(x=0;x<4;x++){
	if(!(keypadPIN&(1<<keypad_R[x]))){
	while(!(keypadPIN&(1<<keypad_R[x])));
	
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