/*
 * gpio_section1.c
 *
 * Created: 07/03/2022 07:20:03 م
 * Author : 3abed
 */ 

#include "MOM_MAP.h"
#include "utilization.h"
#define F_CPU 8000000UL
 
#include <util/delay.h>


int main(void)
{
	unsigned char flag=0;
	DDRA=0b00001101;
	clearbit(DDRC,0);
	setbit(PORTC,0);
    /* Replace with your application code */
    while (1) 
    {
		
		if(redbit(PINC,0)==0){
			
		switch(flag)
			{
			case 0:
			toggle(PORTA,0);
			flag++;
			break;
			case 1:
			toggle(PORTA,2);
			flag++;
			break;
			case 2:
			toggle(PORTA,3);
			flag=0;
			break;
    }
	
}
while(redbit(PINC,0)==0);
	}
}

