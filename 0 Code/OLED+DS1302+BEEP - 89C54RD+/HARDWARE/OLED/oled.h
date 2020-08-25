#ifndef __OLED_H__
#define __OLED_H__


#include "reg52.h"
#include "intrins.h"
#include "oledfont.h"
#include "eeprom.h" //IapReadByte()


#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
#define OLED_MODE 0


sbit OLED_CS=P1^4; //片选
sbit OLED_RST =P1^2;//复位
sbit OLED_DC =P1^3;//数据/命令控制
sbit OLED_SCL=P1^0;//时钟 D0（SCLK?
sbit OLED_SDIN=P1^1;//D1（MOSI） 数据


#define OLED_CS_Clr()  OLED_CS=0
#define OLED_CS_Set()  OLED_CS=1

#define OLED_RST_Clr() OLED_RST=0
#define OLED_RST_Set() OLED_RST=1

#define OLED_DC_Clr() OLED_DC=0
#define OLED_DC_Set() OLED_DC=1

#define OLED_SCLK_Clr() OLED_SCL=0
#define OLED_SCLK_Set() OLED_SCL=1

#define OLED_SDIN_Clr() OLED_SDIN=0
#define OLED_SDIN_Set() OLED_SDIN=1;

//OLED模式设置
//0:4线串行模式
//1:并行8080模式

#define SIZE 16
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED端口定义----------------  					   

void delay_ms(uint ms);


//OLED控制用函数
void OLED_WR_Byte(uchar dat,uchar cmd);	    
void OLED_Display_On();
void OLED_Display_Off();
void OLED_Init();
void OLED_Clear();
void OLED_DrawPoint(uchar x,uchar y,uchar t);
void OLED_Fill(uchar x1,uchar y1,uchar x2,uchar y2,uchar dot);
void OLED_ShowChar(uchar x,uchar y,uchar chr);
void OLED_ShowNum(uchar x,uchar y,uint num,uchar len,uchar size2);
void OLED_ShowString(uchar x,uchar y, uchar *p);	 
void OLED_Set_Pos(uchar x, uchar y);
void OLED_ShowCHinese(uchar x,uchar y,uchar no);
void OLED_DrawBMP(uchar x0, uchar y0,uchar x1, uchar y1,uchar BMP[]);

#endif  
