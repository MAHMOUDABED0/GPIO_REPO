/*
 * STM32_GPIO_DRIVER.c
 *
 *  Created on: ١٢‏/٠٣‏/٢٠٢٢
 *      Author: 3abed
 */

#include "STM32_GPIO_DRIVER.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber){
	switch(PinNumber){
	case gpio_pin0:
		return 0;
		break;
	case gpio_pin1:
		return 4;
		break;
	case gpio_pin2:
		return 8;
		break;
	case gpio_pin3:
		return 12;
		break;
	case gpio_pin4:
		return 16;
		break;
	case gpio_pin5:
		return 20;
		break;
	case gpio_pin6:
		return 24;
		break;
	case gpio_pin7:
		return 28;
		break;
	case gpio_pin8:
		return 0;
		break;
	case gpio_pin9:
		return 4;
		break;
	case gpio_pin10:
		return 8;
		break;
	case gpio_pin11:
		return 12;
		break;
	case gpio_pin12:
		return 16;
		break;
	case gpio_pin13:
		return 20;
		break;
	case gpio_pin14:
		return 24;
		break;
	case gpio_pin15:
		return 28;
		break;
	}
	return 0;
}
/**================================================================
* @Fn				-MCAL_GPIO_Init
* @brief			-Initializes the GPIOx PINy according to the specified parameters in PinConfig
* @param [in] 		-GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		-PinConfig pointer to a GPIO_PinConfig_t structure that contains
* 					the configuration infrmation for the specified GPIO PIN.
* @retval 			-None
* Note				-Stm32F103C6 MCU has GPIO A, B, C, D, E Modules
* 					But LQFP48 Package jas only GPIO A, B, PART of C/D exported as external PINs from the Module
*/
void MCAL_GPIO_Init (GPIOX_typedef *GPIOx, Gpio_pinconfig *PinConfig){
	volatile uint32_t *config_register=NULL;
	uint8_t config_pin;
	//Clear CNF[1:0] MODE[1:0]

	config_register=(PinConfig->gpiox_pinnuber<gpio_pin8)? &(GPIOx->CRL):&(GPIOx->CRH);
	//If Pin is output
	*(config_register)&=~(0XF<<Get_CRLH_Position(PinConfig->gpiox_pinnuber));
	if((PinConfig->gpiox_mode==GPIO_MODE_OUTPUT_PP)||(PinConfig->gpiox_mode==GPIO_MODE_OUTPUT_OD)||(PinConfig->gpiox_mode==GPIO_MODE_OUTPUT_AF_OD)||(PinConfig->gpiox_mode==GPIO_MODE_OUTPUT_AF_PP)){
		config_pin=((((PinConfig->gpiox_mode-4)<<2)|(PinConfig->gpiox_outspeed))& 0X0F);

	}
	else{
	//If Pin is INPUT
	if((PinConfig->gpiox_mode==GPIO_MODE_INPUT_FLO)||(PinConfig->gpiox_mode==GPIO_MODE_INPUT_PD)||(PinConfig->gpiox_mode==GPIO_MODE_INPUT_PU)){

		config_pin=(((PinConfig->gpiox_mode)<<2|0X0)& 0X0F);
	}

			else if (PinConfig->gpiox_mode == GPIO_MODE_AF_INPUT){
				config_pin = ( ( (GPIO_MODE_INPUT_FLO << 2) | 0x0 ) & 0x0F);
			}
			//PU or PD input
			else{
				config_pin = ( ( (GPIO_MODE_INPUT_PU << 2) | 0x0 ) & 0x0F);
				if(PinConfig->gpiox_mode == GPIO_MODE_INPUT_PU){
					//Table 20, Port bit configuration table PxODR 1
					GPIOx->ODR |= PinConfig->gpiox_pinnuber;
				}else{
					//Table 20, Port bit configuration table PxODR 0
					GPIOx->ODR &= ~(PinConfig->gpiox_pinnuber);
				}
			}

		}
	(*config_register) |= ((config_pin) << Get_CRLH_Position(PinConfig->gpiox_pinnuber));
}
void MCAL_GPIO_DeInit(GPIOX_typedef *GPIOx){
	if(GPIOx == GPIOA)
		{
			RCC->APB2RSTR |= (1<<2);
			RCC->APB2RSTR &= ~(1<<2);
		}
		else if (GPIOx == GPIOB)
		{
			RCC->APB2RSTR |= (1<<3);
			RCC->APB2RSTR &= ~(1<<3);
		}
		else if (GPIOx == GPIOC)
		{
			RCC->APB2RSTR |= (1<<4);
			RCC->APB2RSTR &= ~(1<<4);
		}
		else if (GPIOx == GPIOD){
			RCC->APB2RSTR |= (1<<5);
			RCC->APB2RSTR &= ~(1<<5);
		}


	}
/**================================================================
* @Fn				-MCAL_GPIO_ReadPin
* @brief			-Read Specific PIN
* @param [in] 		-GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		-PinNumber: Set Pin Number according to @ref GPIO_PINS_define
* @retval 			-The input pin value (two values based on @ref GPIO_PIN_state)
* Note				-None
*/
uint8_t MCAL_GPIO_ReadPin(GPIOX_typedef *GPIOx, uint16_t PinNumber){
	if((GPIOx->IDR &PinNumber)!=GPIO_PIN_RESET){
		return GPIO_PIN_SET;
	}
	else{
	return	GPIO_PIN_RESET;

	}
///	* @Fn				-MCAL_GPIO_ReadPort
//	* @brief			-Read Specific PORT
//	* @param [in] 		-GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
//	* @retval 			-The input port value
//	* Note				-None
//	*/
}
uint16_t MCAL_GPIO_ReadPort(GPIOX_typedef *GPIOx){
		return (uint16_t)GPIOx->IDR;

}
/**================================================================
* @Fn				-MCAL_GPIO_WritePin
* @brief			-Write on Specific pin
* @param [in] 		-GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		-PinNumber: specific the port bit to read @ref GPIO_PINS_define
* @param [in] 		-Value: Pin value
* @retval 			-None
* Note				-None
*/
void MCAL_GPIO_WritePin(GPIOX_typedef *GPIOx, uint16_t PinNumber, uint8_t Value){
	if (Value != GPIO_PIN_RESET)
		{
			//GPIOx->ODR |= PinNumber;
			//OR by using BSRR register
			GPIOx->BSRR = (uint32_t)PinNumber;
		}
		else
		{
			GPIOx->BRR = (uint32_t)PinNumber;
		}
}



/**================================================================
* @Fn				-MCAL_GPIO_LockPin
* @brief			-The locking mechanism allows the IO configuration to be frozen
* @param [in] 		-GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		-PinNumber: specific the port bit to read @ref GPIO_RETURN_LOCK
* @retval 			-OK if pin configure is locked Or ERROR if pin is not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK)
* Note				-None
*/
uint8_t MCAL_GPIO_LockPin(GPIOX_typedef *GPIOx, uint16_t PinNumber){

	//Set LCKK[16]
	volatile uint32_t temp = 1<<16;
	//Set the LCKy
	temp |= PinNumber;

	//Write 1
	GPIOx->LCKR = temp;
	//Write 0
	GPIOx->LCKR = PinNumber;
	//Write 1
	GPIOx->LCKR = temp;
	//Read 0
	temp = GPIOx->LCKR;
	//Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)GPIOx->LCKR & 1<<16){
		return GPIO_RETURN_LOCK_Enabled;
	}
	else{
		return GPIO_RETURN_LOCK_ERROR;
	}
}
	/**================================================================
	* @Fn				-MCAL_GPIO_TogglePin
	* @brief			-Toggle Specific pin
	* @param [in] 		-GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
	* @param [in] 		-PinNumber: specific the port bit to read @ref GPIO_PINS_define
	* @retval 			-None
	* Note				-None
	*/
void MCAL_GPIO_TogglePin(GPIOX_typedef *GPIOx, uint16_t PinNumber){
		GPIOx->ODR ^= (PinNumber);

	}
void MCAL_GPIO_WritePort(GPIOX_typedef *GPIOx, uint16_t Value)
{
	GPIOx->ODR = Value;
}

