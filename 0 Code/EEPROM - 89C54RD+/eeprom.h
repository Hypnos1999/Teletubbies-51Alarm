#ifndef __EEPROM_H__
#define __EEPROM_H__


#include "reg52.h"
#include "intrins.h"


#ifndef uint 
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char
#endif	


/*Declare SFR associated with the IAP */
sfr IAP_DATA = 0xE2; //Flash data register
sfr IAP_ADDRH = 0xE3; //Flash address HIGH
sfr IAP_ADDRL = 0xE4; //Flash address LOW
sfr IAP_CMD = 0xE5; //Flash command register
sfr IAP_TRIG = 0xE6; //Flash command trigger
sfr IAP_CONTR = 0xE7; //Flash control register

/*Define ISP/IAP/EEPROM command*/
#define CMD_IDLE 0 //Stand-By
#define CMD_READ 1 //Byte-Read
#define CMD_PROGRAM 2 //Byte-Program
#define CMD_ERASE 3 //Sector-Erase

/*Define ISP/IAP/EEPROM operation const for IAP_CONTR*/
//#define ENABLE_IAP 0x80 //if SYSCLK<40MHz
#define ENABLE_IAP 0x81 //if SYSCLK<20MHz
//#define ENABLE_IAP x82 //if SYSCLK<10MHz
//#define ENABLE_IAP 0x83 //if SYSCLK<5MHz

//Start address for STC89C54xx EEPROM
#define IAP_ADDRESS 0x04000


//---申明外部函数---//
void Delay(uchar n);
//void IapIdle();
uchar IapReadByte(uint addr);
void IapProgramByte(uint addr, uchar dat);
void IapEraseSector(uint addr);

//---申明外部变量---//


#endif
