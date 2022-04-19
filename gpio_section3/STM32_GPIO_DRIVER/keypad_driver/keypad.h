/*
 * keypad.h
 *
 * Created: 13/03/2022 07:04:50 م
 *  Author: 3abed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STM32_GPIO_DRIVER.h"
#include "STM32_momery map.h"
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT GPIOB

void Keypad_init();
char Keypad_getkey();




#endif /* KEYPAD_H_ */
