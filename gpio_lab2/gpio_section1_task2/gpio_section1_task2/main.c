/*
 * gpio_section1_task2.c
 *
 * Created: 10/03/2022 10:33:31 م
 * Author : 3abed
 */ 

#include "momery_map.h"
#include "utiliz.h"


int main(void)
{
	char i;
/*
	for(i=5;i<8;i++){
		setbit(DDRD,i);
	}
*/
DDRD|=(0b1111<<4);
	
    while (1) 
    {
		if(redbit(DDRD,0)==0){
			setbit(PORTD,5);
			for(i=200;i>0;i--);

			clearbit(PORTD,5);
			for(i=200;i>0;i--);

    }
	
	if(redbit(DDRD,1)==0){
		setbit(PORTD,6);
		for(i=200;i>0;i--);

		clearbit(PORTD,6);
		for(i=200;i>0;i--);

	}
	
	if(redbit(DDRD,2)==0){
		setbit(PORTD,7);
		for(i=200;i>0;i--);

		clearbit(PORTD,7);
		for(i=200;i>0;i--);

	}
	
	}
}

