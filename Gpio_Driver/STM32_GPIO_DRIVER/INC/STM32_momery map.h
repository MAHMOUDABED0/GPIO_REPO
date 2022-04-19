/*
 * STM32_momery map.h
 *
 *  Created on: Mar 11, 2022
 *      Author: 3abed
 */

#ifndef INC_STM32_MOMERY_MAP_H_
#define INC_STM32_MOMERY_MAP_H_

//-----------------------------
//Includes
//-----------------------------

#include<stdint.h>
#include<stdlib.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define Flash_Base                          0x08000000UL
#define SRAM_Base                           0x20000000UL
#define pripherial_Base                     0x40000000UL
#define Cortex_M3_pripherial_Base           0xE0000000UL

//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------
//APB pripherial
#define RCC_BASE  0x40021000UL


//-----------------------------
//APB2 pripherial
//GPIO +++ INCLUDE IN LQF48
#define GPIOA_BASE  0x40010800UL
#define GPIOB_BASE  0x40010C00UL
#define GPIOC_BASE  0x40011000UL
#define GPIOD_BASE  0x40011400UL

//GPIO +++ NOT INCLUDE IN LQF48

#define GPIOE_BASE  0x40011800UL
#define GPIOF_BASE  0x40011C00UL
#define GPIOG_BASE  0x40012000UL

//EXTI

#define EXTI_BASE  0x40010400UL

//AFIO

#define AFIO_BASE  0x40010000UL

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//Peripheral register:RCC
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;

}RCC_typedef;

//Peripheral register:GPIO
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIOX_typedef;

//Peripheral register:AFIO

typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RR;
	volatile uint32_t MAPR2;
}AFIO_typedef;

//Peripheral register:EXTI
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t PR;
}EXTI_typedef;

//Peripheral register
#define GPIOA          ((GPIOX_typedef *)GPIOA_BASE)
#define GPIOB          ((GPIOX_typedef *)GPIOB_BASE)
#define GPIOC          ((GPIOX_typedef *)GPIOC_BASE)
#define GPIOD          ((GPIOX_typedef *)GPIOD_BASE)

#define EXTI          ((EXTI_typedef *)EXTI_BASE)
#define AFIO          ((AFIO_typedef *)AFIO_BASE)

#define RCC          ((RCC_typedef *)RCC_BASE)

// RCC ENABLE
#define RCC_ENABLE_GPIOA() (RCC->APB2ENR|=1<<2)
#define RCC_ENABLE_GPIOB() (RCC->APB2ENR|=1<<3)
#define RCC_ENABLE_GPIOC() (RCC->APB2ENR|=1<<4)
#define RCC_ENABLE_GPIOD() (RCC->APB2ENR|=1<<5)
#define RCC_ENABLE_GPIOE() (RCC->APB2ENR|=1<<6)

#define RCC_ENABLE_AFIO() (RCC->APB2ENR|=1<<0)




























#endif /* INC_STM32_MOMERY_MAP_H_ */
