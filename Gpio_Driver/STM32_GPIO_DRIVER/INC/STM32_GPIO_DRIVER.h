/*
 * STM32_GPIO_DRIVER.h
 *
 *  Created on: Mar 11, 2022
 *      Author: 3abed
 */

#ifndef INC_STM32_GPIO_DRIVER_H_
#define INC_STM32_GPIO_DRIVER_H_
#include "STM32_momery map.h"



typedef struct{
	uint16_t gpiox_pinnuber;//select gpio pin to be configured
	                        // Value define at @pin_number

	uint8_t gpiox_mode ;  //select mode of gpio pin to be configured
	                      // Value define at @gpio_mode

	uint8_t gpiox_outspeed;  //detect speed  of gpio pin
                            	// Value define at @gpio_speed
}Gpio_pinconfig;




//==============================================
//Macros Configuration References
//==============================================

//@ref GPIO_PINS_define

#define gpio_pin0   ((uint16_t)0x0001)
#define gpio_pin1   ((uint16_t)0x0002)
#define gpio_pin2   ((uint16_t)0x0004)
#define gpio_pin3   ((uint16_t)0x0008)
#define gpio_pin4   ((uint16_t)0x0010)
#define gpio_pin5   ((uint16_t)0x0020)
#define gpio_pin6   ((uint16_t)0x0040)
#define gpio_pin7   ((uint16_t)0x0080)
#define gpio_pin8   ((uint16_t)0x0100)
#define gpio_pin9   ((uint16_t)0x0200)
#define gpio_pin10  ((uint16_t)0x0400)
#define gpio_pin11  ((uint16_t)0x0800)
#define gpio_pin12  ((uint16_t)0x1000)
#define gpio_pin13  ((uint16_t)0x2000)
#define gpio_pin14  ((uint16_t)0x4000)
#define gpio_pin15  ((uint16_t)0x8000)

#define gpio_pin16					((uint16_t)0xFFFF) /* All pins selected */

#define All_pins 0x0000FFFFu /* PIN mask for assert test */

//@ref GPIO_Mode_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input

#define GPIO_MODE_ANALOG				0x00000000u /* Analog mode */
#define GPIO_MODE_INPUT_FLO				0x00000001u /* Floating input */
#define GPIO_MODE_INPUT_PU				0x00000002u /* Input with pull-up */
#define GPIO_MODE_INPUT_PD				0x00000003u /* Input with pull-down */
#define GPIO_MODE_OUTPUT_PP				0x00000004u /* General purpose output push-pull */
#define GPIO_MODE_OUTPUT_OD				0x00000005u /* General purpose output Open-drain */
#define GPIO_MODE_OUTPUT_AF_PP			0x00000006u /* Alternate function output Push-pull */
#define GPIO_MODE_OUTPUT_AF_OD			0x00000007u /* Alternate function output Open-drain */
#define GPIO_MODE_AF_INPUT			    0x00000008u /* Alternate function input */


//@ref GPIO_SPEED_define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.
#define GPIO_SPEED_10M					0x00000001u /* Output mode, max speed 10 MHz. */
#define GPIO_SPEED_2M					0x00000002u /* Output mode, max speed 2 MHz. */
#define GPIO_SPEED_50M					0x00000003u /* Output mode, max speed 50 MHz. */

//@ref GPIO_PIN_state
#define GPIO_PIN_SET  					1
#define GPIO_PIN_RESET  				0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_Enabled 		1
#define GPIO_RETURN_LOCK_ERROR	 		0

/*
 * =======================================================================================
 * 								APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */
void MCAL_GPIO_Init (GPIOX_typedef *GPIOx, Gpio_pinconfig *PinConfig);
void MCAL_GPIO_DeInit(GPIOX_typedef *GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIOX_typedef *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIOX_typedef *GPIOx);

void MCAL_GPIO_WritePin(GPIOX_typedef *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIOX_typedef *GPIOx, uint16_t Value);

void MCAL_GPIO_TogglePin(GPIOX_typedef *GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIOX_typedef *GPIOx, uint16_t PinNumber);

#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
