/*
 * IncFile1.h
 *
 * Created: 10/03/2022 02:47:40 م
 *  Author: 3abed
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define setbit(reg,bit)    (reg=reg|(1<<bit))
#define clearbit(reg,bit)  (reg=reg&~(1<<bit))
#define redbit(reg,bit)    ((reg>>bit)&1)
#define toggle(reg,bit)    (reg=reg^(1<<bit))



#endif /* INCFILE1_H_ */