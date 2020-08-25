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


//---�����ⲿ����---//
void Timer0Init();//����ʱ��0����ʼ��
void XiMie();//oledϨ���Ⲣִ�г���
void DianLiang();//oled������Ⲣִ�г���

//---�����ⲿ����---//
extern uint TIME[7]; // second minute hour day month week year
extern uint NAO1[3]; // hour minute alarm_bit
extern uint NAO2[3]; // hour minute alarm_bit
extern uint NAO3[3]; // hour minute alarm_bit
extern uchar ring_s;//�����ʱ����
extern uchar ring_min;//�����ʱ����
extern bit ring_bit;//�����־λ
extern bit mie;//oled���־λ
extern bit signal;//oledϨ�������Ķ����źű�־λ

#endif
