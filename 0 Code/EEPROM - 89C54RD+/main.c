#include "reg52.h"
#include "intrins.h"

#include "eeprom.h"
#include "bmp.h"


typedef unsigned int u16;	  
typedef unsigned char u8;


sbit LED=P3^6;//����ָʾ����Ƿ���ȷд��EEPROM


u16 NAO1[3]={8,30,0}; // hour minute alarm_bit
u16 NAO2[3]={12,00,0}; // hour minute alarm_bit
u16 NAO3[3]={18,30,1}; // hour minute alarm_bit


void main()
{
	u16 i=0;
	u8 k=0;
	u8 n=0;
	
	LED=1;
	Delay(5);
	LED=0;
	Delay(5);
	LED=1;
	Delay(5);
	LED=0;
	Delay(10);
	
	//д��ͼƬ
	for(n=0;n<4;n++)
	 {
			IapEraseSector(IAP_ADDRESS+(n*512)); //Erase current sector
			for (i=0; i<512; i++) //Check whether all sector data is FF
			{
				if (IapReadByte(IAP_ADDRESS+(n*512)+i) != 0xff)
					goto Error; //If error, break
			}
			Delay(10);
			for (i=0; i<512; i++)  //Program 512 bytes data into data flash
			{
				if( (n==0) || (n==1) )IapProgramByte(IAP_ADDRESS+(n*512)+i, BMP1[(n*512)+i]);
				if( (n==2) || (n==3) )IapProgramByte(IAP_ADDRESS+(n*512)+i, BMP2[((n%2)*512)+i]);
			}
			Delay(10);
			for (i=0; i<512; i++) //Verify 512 bytes data//��֤�Ƿ���ȷд��
			{
				if( (n==0) || (n==1) )
				{
					if (IapReadByte(IAP_ADDRESS+(n*512)+i) != BMP1[(n*512)+i])
						goto Error; //If error, break
				}
				if( (n==2) || (n==3) )
				{
					if (IapReadByte(IAP_ADDRESS+(n*512)+i) != BMP2[((n%2)*512)+i])
						goto Error; //If error, break
				}
			}
	 }
	 
	//д������
	IapEraseSector(IAP_ADDRESS+(4*512)); //Erase current sector//������5����
	for (i=0; i<512; i++) //Check whether all sector data is FF
	{
		if (IapReadByte(IAP_ADDRESS+(4*512)+i) != 0xff)
			goto Error; //If error, break
	}
	Delay(10);
	for (i=0; i<3; i++)  //Program 3 bytes data into data flash//������ NAO1[3] �� hour minute alarm_bit ����д��eeprom
	{
		IapProgramByte(IAP_ADDRESS+(4*512)+k, (u8)NAO1[i]);
		k++;
	}
	for (i=0; i<3; i++)  //Program 3 bytes data into data flash//������ NAO2[3] �� hour minute alarm_bit ����д��eeprom
	{
		IapProgramByte(IAP_ADDRESS+(4*512)+k, (u8)NAO2[i]);
		k++;
	}
	for (i=0; i<3; i++)  //Program 3 bytes data into data flash//������ NAO3[3] �� hour minute alarm_bit ����д��eeprom
	{
		IapProgramByte(IAP_ADDRESS+(4*512)+k, (u8)NAO3[i]);
		k++;
	}				
	Delay(10);
	k=0;
	for (i=0; i<3; i++) //Verify 3 bytes data//��֤�Ƿ���ȷд��
	{
		if (IapReadByte(IAP_ADDRESS+(4*512)+k) != (u8)NAO1[i])
			goto Error; //If error, break
		k++;
	}
	for (i=0; i<3; i++) //Verify 3 bytes data//��֤�Ƿ���ȷд��
	{
		if (IapReadByte(IAP_ADDRESS+(4*512)+k) != (u8)NAO2[i])
			goto Error; //If error, break
		k++;
	}
	for (i=0; i<3; i++) //Verify 3 bytes data//��֤�Ƿ���ȷд��
	{
		if (IapReadByte(IAP_ADDRESS+(4*512)+k) != (u8)NAO3[i])
			goto Error; //If error, break
		k++;
	}
	
	LED=1;
	while(1);
	 
	Error:
	while (1);
}
