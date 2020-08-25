#ifndef __TIMER0_H__
#define __TIMER0_H__


#include "reg52.h"
#include "intrins.h"
#include "key.h"  //KeyValue KeyValue_plus KL KM KR
#include "ds1302.h"  //Ds1302ReadTime()
#include "oled.h"  //OLED_Display_On() OLED_Display_Off() OLED_Clear()


#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif


//---申明外部函数---//
void Timer0Init();//（定时器0）初始化
void XiMie();//oled熄灭检测并执行程序
void DianLiang();//oled点亮检测并执行程序

//---申明外部变量---//
extern uint TIME[7]; // second minute hour day month week year
extern uint NAO1[3]; // hour minute alarm_bit
extern uint NAO2[3]; // hour minute alarm_bit
extern uint NAO3[3]; // hour minute alarm_bit
extern uchar ring_s;//响铃计时变量
extern uchar ring_min;//响铃计时变量
extern bit ring_bit;//响铃标志位
extern bit mie;//oled灭标志位
extern bit signal;//oled熄灭或点亮的动作信号标志位

#endif
