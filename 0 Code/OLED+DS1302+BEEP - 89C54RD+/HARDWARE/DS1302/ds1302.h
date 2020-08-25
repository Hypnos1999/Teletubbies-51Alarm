#ifndef __DS1302_H__
#define __DS1302_H__

//---����ͷ�ļ�---//
#include<reg52.h>
#include<intrins.h>
#include "timer0.h"  //TIME[7]

//---�ض���ؼ���---//
#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif

//---����ds1302ʹ�õ�IO��---//
sbit DSIO=P3^4;
sbit RST=P3^5;//CE
sbit SCLK=P3^6;

//---�����ⲿ����---//
void Ds1302Init();
void Ds1302ReadTime();
void charge_off();//�ر�������

//---�����ⲿ����---//
//extern uchar TIME0[7];


#endif
