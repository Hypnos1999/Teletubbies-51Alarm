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


//---�����ⲿ����---//
void Timer2Init();//����ʱ��T2����ʼ��

//---�����ⲿ����---//


#endif
