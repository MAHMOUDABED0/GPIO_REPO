/*
 * utiliz.h
 *
 * Created: 10/03/2022 11:15:06 م
 *  Author: 3abed
 */ 


#ifndef UTILIZ_H_
#define UTILIZ_H_

#define setbit(reg,bit)     (reg=reg|(1<<bit))
#define clearbit(reg,bit)   (reg=reg&~(1<<bit))
#define redbit(reg,bit)     ((reg>>bit)&1)
#define togglebit(reg,bit)  (reg=reg^(1<<bit))





#endif /* UTILIZ_H_ */