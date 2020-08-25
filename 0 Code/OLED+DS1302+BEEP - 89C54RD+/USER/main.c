#include "reg52.h"
#include "intrins.h"

#include "delay.h"
#include "timer0.h"
#include "timer1.h"
#include "key.h"
#include "display.h"
#include "oled.h"
#include "oledfont.h"
#include "ds1302.h"
#include "eeprom.h"
#include "beep.h"


typedef unsigned int u16;	  
typedef unsigned char u8;


void main()
{
	u8 i=0;
	u8 k=0;
	
	charge_off();//关闭涓流充电
	
	Timer0Init(); //定时器T0：控制时间走动 控制闹钟响铃时间 无操作时间检测与返回 自动关闭屏幕省电 手动或自动唤醒屏幕
	Timer1Init(); //定时器T1：控制闪烁频率
	Timer2Init(); //定时器T2：控制响铃
	
	buzzer=1;//关闭蜂鸣器 断开三极管减少功耗
	
	OLED_Init();//初始化OLED
	
	//*****************************************************************************//
	OLED_DrawBMP(0,0,128,8,IAP_ADDRESS);  //图片显示(图片显示慎用，生成的字表较大，会占用较多空间，FLASH空间8K以下慎用)
	delay_ms(20);
	OLED_ShowCHinese(90,1,0);//哈
	OLED_ShowCHinese(108,1,1);//喽
	delay_ms(50);
	OLED_Clear(); 
	//*****************************************************************************//
	
	//********************************************************************************//
	for (i=0; i<3; i++)//读取eeprom存储的 NAO1[3] 的 hour minute alarm_bit
	{
		NAO1[i]=(u16)IapReadByte(IAP_ADDRESS+(4*512)+k);
		k++;
	}
	for (i=0; i<3; i++)//读取eeprom存储的 NAO2[3] 的 hour minute alarm_bit 
	{
		NAO2[i]=(u16)IapReadByte(IAP_ADDRESS+(4*512)+k);
		k++;
	}
	for (i=0; i<3; i++)//读取eeprom存储的 NAO3[3] 的 hour minute alarm_bit 
	{
		NAO3[i]=(u16)IapReadByte(IAP_ADDRESS+(4*512)+k);
		k++;
	}
	//********************************************************************************//
	
	while(1)
	{	
		Display(); //oled显示函数
		Hexin(); //按键操作核心函数
		
		if(ring_bit==1)
		{
			if(TR2==0) TR2=1;//打开响铃
		}
		else
		{
      if(TR2==1) { TR2=0; buzzer=1; }//关闭响铃//关闭蜂鸣器 断开三极管减少功耗
		}
		
	 XiMie();//oled熄灭检测并执行程序
	 DianLiang();//oled点亮检测并执行程序
	}
}
