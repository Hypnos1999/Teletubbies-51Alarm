#ifndef __DISPLAY_H__
#define __DISPLAY_H__


#include "reg52.h"
#include "intrins.h"
#include "timer0.h" //TIME[7] NAO1[3] NAO2[3] NAO3[3] ring_bit
#include "key.h" //KeyValue KeyValue_plus q
#include "timer1.h" //fq
#include "oled.h" //OLED_ShowString() OLED_ShowChar() OLED_ShowNum()


#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif


//---申明外部函数---//
void Display(); //oled显示函数

//---申明外部变量---//


#endif
