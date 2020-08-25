#ifndef __BEEP_H__
#define __BEEP_H__


#include "reg52.h"
#include "intrins.h"


#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif	


sbit buzzer=P0^3;


//---申明外部函数---//
void Timer2Init();//（定时器T2）初始化

//---申明外部变量---//


#endif
