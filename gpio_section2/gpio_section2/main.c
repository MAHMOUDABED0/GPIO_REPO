/*
 * gpio_section2.c
 *
 * Created: 11/03/2022 02:06:40 م
 * Author : 3abed
 */ 

#include "lcd_diver/lcd.h"
#include "keypad_driver/keypad.h"

int main(void)
{
    /* Replace with your application code */
	LCD_INIT();
	Keypad_init();
    _delay_ms(50);
    unsigned char key_pressed;
    while(1){
	    key_pressed = Keypad_getkey();
	    switch(key_pressed){
		    case 'A':
		    break;
		    case '?':
		    LCD_clear_screen();
		    break;
		    default:
		    LCD_WRITE_CHAR(key_pressed);
		    break;
	    }
    
    }

}

