#ifndef __TIMER1_H__
#define __TIMER1_H__


#include "reg52.h"
#include "intrins.h"
#include "key.h" //KeyValue_plus
#include "timer0.h" //ring_bit


#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif


//---申明外部函数---//
void Timer1Init();//（定时器1）初始化

//---申明外部变量---//
extern bit fq;//接收k_f或k_s的值---控制*P指中的或整个的数码管的闪烁频率


#endif
