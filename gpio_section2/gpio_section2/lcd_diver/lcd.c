/*
 * lcd.c
 *
 * Created: 11/03/2022 04:24:22 م
 *  Author: 3abed
 */ 
#include "lcd.h"

void lcd_kick(){
		LCD_CTRL|=(1<<EN_SWITCH);
		_delay_ms(50);
		LCD_CTRL&=~(1<<EN_SWITCH);

	
}

void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void lcdis_busy(){
	DataDir_LCD_PORT=0x00;
	LCD_CTRL|=(1<<RW_SWITCH);
	LCD_CTRL&=~(1<<RS_SWITCH);
	lcd_kick();
	DataDir_LCD_PORT|=0xff;
	LCD_CTRL&=~(1<<RW_SWITCH);

	
}

void LCD_INIT (){
	_delay_ms(20);
	lcdis_busy();
DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	DataDir_LCD_PORT=0xff;
	_delay_ms(15);
	LCD_clear_screen();
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);

	#endif
	#ifdef FOUR_BIT_MODE
	#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);

}
void LCD_WRITE_COMMAND(unsigned char command){
	#ifdef EIGHT_BIT_MODE
	lcdis_busy();
	LCD_PORT = command;
	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	_delay_ms(1);
	lcd_kick();
	#endif
	}
void LCD_WRITE_CHAR(unsigned char data){
		#ifdef EIGHT_BIT_MODE
		lcdis_busy();
		LCD_PORT = data;
		LCD_CTRL &= ~(1 << RW_SWITCH);
		LCD_CTRL |= (1 << RS_SWITCH);
		_delay_ms(1);
		lcd_kick();
		#endif
	}

void LCD_WRITE_STRING(char* string){
	int count=0;

	while(*string>0){
		count ++;
		LCD_WRITE_CHAR(*string++);
		
		if(count==16){
			LCD_GOTO_XY(2,0);
		}
		else if (count==32){
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count=0;
		}
		
	}
}
void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}