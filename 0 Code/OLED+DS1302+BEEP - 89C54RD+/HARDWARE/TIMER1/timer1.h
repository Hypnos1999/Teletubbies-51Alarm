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


//---�����ⲿ����---//
void Timer1Init();//����ʱ��1����ʼ��

//---�����ⲿ����---//
extern bit fq;//����k_f��k_s��ֵ---����*Pָ�еĻ�����������ܵ���˸Ƶ��


#endif
