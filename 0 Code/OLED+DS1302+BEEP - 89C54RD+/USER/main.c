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
	
	charge_off();//�ر�������
	
	Timer0Init(); //��ʱ��T0������ʱ���߶� ������������ʱ�� �޲���ʱ�����뷵�� �Զ��ر���Ļʡ�� �ֶ����Զ�������Ļ
	Timer1Init(); //��ʱ��T1��������˸Ƶ��
	Timer2Init(); //��ʱ��T2����������
	
	buzzer=1;//�رշ����� �Ͽ������ܼ��ٹ���
	
	OLED_Init();//��ʼ��OLED
	
	//*****************************************************************************//
	OLED_DrawBMP(0,0,128,8,IAP_ADDRESS);  //ͼƬ��ʾ(ͼƬ��ʾ���ã����ɵ��ֱ�ϴ󣬻�ռ�ý϶�ռ䣬FLASH�ռ�8K��������)
	delay_ms(20);
	OLED_ShowCHinese(90,1,0);//��
	OLED_ShowCHinese(108,1,1);//�
	delay_ms(50);
	OLED_Clear(); 
	//*****************************************************************************//
	
	//********************************************************************************//
	for (i=0; i<3; i++)//��ȡeeprom�洢�� NAO1[3] �� hour minute alarm_bit
	{
		NAO1[i]=(u16)IapReadByte(IAP_ADDRESS+(4*512)+k);
		k++;
	}
	for (i=0; i<3; i++)//��ȡeeprom�洢�� NAO2[3] �� hour minute alarm_bit 
	{
		NAO2[i]=(u16)IapReadByte(IAP_ADDRESS+(4*512)+k);
		k++;
	}
	for (i=0; i<3; i++)//��ȡeeprom�洢�� NAO3[3] �� hour minute alarm_bit 
	{
		NAO3[i]=(u16)IapReadByte(IAP_ADDRESS+(4*512)+k);
		k++;
	}
	//********************************************************************************//
	
	while(1)
	{	
		Display(); //oled��ʾ����
		Hexin(); //�����������ĺ���
		
		if(ring_bit==1)
		{
			if(TR2==0) TR2=1;//������
		}
		else
		{
      if(TR2==1) { TR2=0; buzzer=1; }//�ر�����//�رշ����� �Ͽ������ܼ��ٹ���
		}
		
	 XiMie();//oledϨ���Ⲣִ�г���
	 DianLiang();//oled������Ⲣִ�г���
	}
}
