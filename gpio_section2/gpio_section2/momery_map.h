/*
 * IncFile1.h
 *
 * Created: 11/03/2022 04:23:01 م
 *  Author: 3abed
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define PORTA *(volatile char *)0x3B
#define DDRA  *(volatile char *)0x3A
#define PINA  *(volatile char *)0x39

#define PORTB *(volatile char *)0x3B
#define DDRB  *(volatile char *)0x37
#define PINB  *(volatile char *)0x36

#define PORTC *(volatile char *)0x35
#define DDRC  *(volatile char *)0x34
#define PINC  *(volatile char *)0x33

#define PORTD *(volatile char *)0x32
#define DDRD  *(volatile char *)0x31
#define PIND  *(volatile char *)0x30




#endif /* INCFILE1_H_ */