#ifndef __KEY_H__
#define __KEY_H__


#include "reg52.h"
#include "intrins.h"
#include "delay.h"	
#include "timer0.h"  //TIME[7] NAO1[3] NAO2[3] NAO3[3] ring_s ring_min ring_bit mie signal
#include "oled.h" //OLED_DrawBMP() delay_ms() OLED_ShowCHinese() OLED_Clear()
#include "ds1302.h" //Ds1302Init()
#include "eeprom.h" //IapEraseSector() IapProgramByte()


#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif


sbit KL=P0^0;//按键：左
sbit KM=P0^1;//按键：中
sbit KR=P0^2;//按键：右


//---申明外部函数---//
void Hexin(); //按键操作核心函数

//---申明外部变量---//
extern uchar KeyValue;
extern uchar KeyValue_plus;
extern uchar q;//作用：代表数据（用于修改）


#endif
