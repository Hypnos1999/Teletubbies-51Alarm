#ifndef __DS1302_H__
#define __DS1302_H__

//---包含头文件---//
#include<reg52.h>
#include<intrins.h>
#include "timer0.h"  //TIME[7]

//---重定义关键词---//
#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif

//---定义ds1302使用的IO口---//
sbit DSIO=P3^4;
sbit RST=P3^5;//CE
sbit SCLK=P3^6;

//---申明外部函数---//
void Ds1302Init();
void Ds1302ReadTime();
void charge_off();//关闭涓流充电

//---申明外部变量---//
//extern uchar TIME0[7];


#endif
