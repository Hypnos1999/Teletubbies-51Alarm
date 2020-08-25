#include "display.h"


uchar l=1;//���߱���//Ӧ���ڶԳ��ν���������ʾʱ��ҳ����޸�ҳ���oled����
uchar code *dis_week[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};


void Display() //oled��ʾ����
{
//********************************************************1**********************************************************//		
//********************************************************1**********************************************************//
	  if(KeyValue==0) //KMû�����£�������ʾʱ��-----+�����ӣ�
			{
				
				if(l==1)//ִֻ��һ�� �տ�����մ��޸�ҳ������ſ�ִ��
					{
						OLED_Clear();
						l=0;
					}
				
				OLED_ShowString(0,0,"Time:"); 
				OLED_ShowNum(8,3,20,2,16);//�� //20XX	
				OLED_ShowNum(24,3,TIME[6],2,16);//�� //TIME[6]-year	
				OLED_ShowChar(40,3,'/');
				OLED_ShowNum(48,3,TIME[4],2,16);//�� //TIME[4]-month
				OLED_ShowChar(64,3,'/');
				OLED_ShowNum(72,3,TIME[3],2,16);//�� //TIME[3]-day
					
				OLED_ShowString(95,3,dis_week[TIME[5]]);//�� //TIME[5]-week
					
				if( NAO1[2]==1 || NAO2[2]==1 || NAO3[2]==1)
					{
						OLED_ShowCHinese(98,6,5);//alarm_bit /*�����ַ�"����"ͼ��,5*/
					}
				else
					{
						OLED_ShowChar(98,6,' ');//��ʾ' '�ַ� //alarm_bit-�հ�
						OLED_ShowChar(106,6,' ');
					}
				
//*******************************************����*********************************************//
		//ֻ��������ʾʱ�䣨�����棩ʱ���л����������
	  //�������޸����ӻ�ʱ���ҳ����Ƽ�⵽1�����޲���ʱ���Զ��˳���������ʾʱ��ҳ�棡						
						if( (TIME[2]==NAO1[0]) && (TIME[1]==NAO1[1]) && (TIME[0]<=1) && (NAO1[2]==1) )
						{                                           
							ring_bit=1;//�������������־λ
						}
						if( (TIME[2]==NAO2[0]) && (TIME[1]==NAO2[1]) && (TIME[0]<=1) && (NAO2[2]==1) )
						{                                           
							ring_bit=1;//�������������־λ
						}					
						if( (TIME[2]==NAO3[0]) && (TIME[1]==NAO3[1]) && (TIME[0]<=1) && (NAO3[2]==1) )
						{                                           
							ring_bit=1;//�������������־λ
						}
						
						OLED_ShowChar(24,6,':');
						OLED_ShowChar(48,6,':');
						if( ring_bit )   //����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
							{
								  //��ʱ��1����fq��ȡ��Ƶ��--����������ܵ���˸Ƶ��
									if(fq==0)
									{
										OLED_ShowChar(8,6,' ');//��ʾ' '�ַ�//ʱ-�հ�
										OLED_ShowChar(16,6,' ');
//										OLED_ShowChar(24,6,':');
										OLED_ShowChar(32,6,' ');//��ʾ' '�ַ�//��-�հ�
										OLED_ShowChar(40,6,' ');
//										OLED_ShowChar(48,6,':');
										OLED_ShowChar(56,6,' ');//��ʾ' '�ַ�//��-�հ�
										OLED_ShowChar(64,6,' ');
									}
									else
									{
										OLED_ShowNum(8,6,TIME[2],2,16);//ʱ //TIME[2]-hour
//										OLED_ShowChar(24,6,':');
										OLED_ShowNum(32,6,TIME[1],2,16);//�� //TIME[1]-minute
//										OLED_ShowChar(48,6,':');
										OLED_ShowNum(56,6,TIME[0],2,16);//�� //TIME[0]-second
									}
							}
						else  //������ʾʱ��
							{
								OLED_ShowNum(8,6,TIME[2],2,16);//ʱ //TIME[2]-hour
//								OLED_ShowChar(24,6,':');
								OLED_ShowNum(32,6,TIME[1],2,16);//�� //TIME[1]-minute
//								OLED_ShowChar(48,6,':');
								OLED_ShowNum(56,6,TIME[0],2,16);//�� //TIME[0]-second
							}
			}
//********************************************************2**********************************************************//		
//********************************************************2**********************************************************//
	  if(KeyValue=='N')  //��ʾ���趨���ӣ�ʱ-�֣�q�������������˸��������Ƶ��
			{
				
				if(l==0)//ִֻ��һ�� �մ�ʱ����ʾҳ������ſ�ִ��
					{
						OLED_Clear();
						l=1;
					}

				OLED_ShowString(15,0,"Modify Alarm"); 
					
				//��ʱ��1����fq��ȡ��Ƶ��--����������ܵ���˸Ƶ��
				if(fq==1)  //ȫ����ʾ
					{
							OLED_ShowNum(8,2,NAO1[0],2,16);//ʱ
							OLED_ShowChar(24,2,':');
							OLED_ShowNum(32,2,NAO1[1],2,16);//��
							if(NAO1[2]==1)
								OLED_ShowString(95,2,"on"); 
							else
								OLED_ShowString(95,2,"off"); 
							
							OLED_ShowNum(8,4,NAO2[0],2,16);//ʱ
							OLED_ShowChar(24,4,':');
							OLED_ShowNum(32,4,NAO2[1],2,16);//��
							if(NAO2[2]==1)
								OLED_ShowString(95,4,"on"); 
							else
								OLED_ShowString(95,4,"off"); 
							
							OLED_ShowNum(8,6,NAO3[0],2,16);//ʱ
							OLED_ShowChar(24,6,':');
							OLED_ShowNum(32,6,NAO3[1],2,16);//��
							if(NAO3[2]==1)
								OLED_ShowString(95,6,"on"); 
							else
								OLED_ShowString(95,6,"off");
					}
				else  //fq==0  //q�������������ʾ�հף�������ʾ��������
					{
						  OLED_ShowChar(24,2,':');
						  OLED_ShowChar(24,4,':');
						  OLED_ShowChar(24,6,':');
						
							if(q==1)//NAO1[0]-hour
								{
									OLED_ShowChar(8,2,' ');//��ʾ' '�ַ�//ʱ-�հ�
									OLED_ShowChar(16,2,' ');
								}
							else
								{
									OLED_ShowNum(8,2,NAO1[0],2,16);//ʱ
								}
							if(q==2)//NAO1[1]-minute
								{
									OLED_ShowChar(32,2,' ');//��ʾ' '�ַ�//��-�հ�
									OLED_ShowChar(40,2,' ');
								}
							else
								{
									OLED_ShowNum(32,2,NAO1[1],2,16);//��
								}
							if(q==3)//NAO1[2]-alarm_bit
								{
									OLED_ShowChar(95,2,' ');//��ʾ' '�ַ�//alarm_bit-�հ�
									OLED_ShowChar(103,2,' ');
									OLED_ShowChar(111,2,' ');
								}
							else
								{
									if(NAO1[2]==1)
										OLED_ShowString(95,2,"on"); 
									else
										OLED_ShowString(95,2,"off"); 
								}
							if(q==4)//NAO2[0]-hour
								{
									OLED_ShowChar(8,4,' ');//��ʾ' '�ַ�//ʱ-�հ�
									OLED_ShowChar(16,4,' ');
								}
							else
								{
									OLED_ShowNum(8,4,NAO2[0],2,16);//ʱ
								}
							if(q==5)//NAO2[1]-minute
								{
									OLED_ShowChar(32,4,' ');//��ʾ' '�ַ�//��-�հ�
									OLED_ShowChar(40,4,' ');
								}
							else
								{
									OLED_ShowNum(32,4,NAO2[1],2,16);//��
								}
							if(q==6)//NAO2[2]-alarm_bit
								{
									OLED_ShowChar(95,4,' ');//��ʾ' '�ַ�//alarm_bit-�հ�
									OLED_ShowChar(103,4,' ');
									OLED_ShowChar(111,4,' ');
								}
							else
								{
									if(NAO2[2]==1)
										OLED_ShowString(95,4,"on"); 
									else
										OLED_ShowString(95,4,"off"); 
								}
							if(q==7)//NAO3[0]-hour
								{
									OLED_ShowChar(8,6,' ');//��ʾ' '�ַ�//ʱ-�հ�
									OLED_ShowChar(16,6,' ');
								}
							else
								{
									OLED_ShowNum(8,6,NAO3[0],2,16);//ʱ
								}
							if(q==8)//NAO3[1]-minute
								{
									OLED_ShowChar(32,6,' ');//��ʾ' '�ַ�//��-�հ�
									OLED_ShowChar(40,6,' ');
								}
							else
								{
									OLED_ShowNum(32,6,NAO3[1],2,16);//��
								}
							if(q==9)//NAO3[2]-alarm_bit
								{
									OLED_ShowChar(95,6,' ');//��ʾ' '�ַ�//alarm_bit-�հ�
									OLED_ShowChar(103,6,' ');
									OLED_ShowChar(111,6,' ');
								}
							else
								{
									if(NAO3[2]==1)
										OLED_ShowString(95,6,"on"); 
									else
										OLED_ShowString(95,6,"off"); 
								}
					}
		  }
//********************************************************3**********************************************************//		
//********************************************************3**********************************************************//
	if(KeyValue=='T')  //��ʾ���趨ʱ�䣺ʱ-�֣�q�������������˸��������Ƶ��
			{
				
				if(l==0)//ִֻ��һ�� �մ�ʱ����ʾҳ������ſ�ִ��
					{
						OLED_Clear();
						l=1;
					}

				OLED_ShowString(0,0,"Modify Time"); 
					
				OLED_ShowString(95,3,dis_week[TIME[5]]);//�� //TIME[5]-week
					
				if( NAO1[2]==1 || NAO2[2]==1 || NAO3[2]==1)
					{
						OLED_ShowCHinese(98,6,5);//alarm_bit /*�����ַ�"����"ͼ��,5*/
					}
				else
					{
						OLED_ShowChar(98,6,' ');//��ʾ' '�ַ� //alarm_bit-�հ�
						OLED_ShowChar(106,6,' ');
					}
				
				//��ʱ��1����fq��ȡ��Ƶ��--����������ܵ���˸Ƶ��
				if(fq==1)  //ȫ����ʾ
					{
						OLED_ShowNum(8,3,20,2,16);//�� //20XX	
						OLED_ShowNum(24,3,TIME[6],2,16);//�� //TIME[6]-year
						OLED_ShowChar(40,3,'/');
						OLED_ShowNum(48,3,TIME[4],2,16);//�� //TIME[4]-month
						OLED_ShowChar(64,3,'/');
						OLED_ShowNum(72,3,TIME[3],2,16);//�� //TIME[3]-day
						
						OLED_ShowNum(8,6,TIME[2],2,16);//ʱ //TIME[2]-hour
						OLED_ShowChar(24,6,':');
						OLED_ShowNum(32,6,TIME[1],2,16);//�� //TIME[1]-minute
						OLED_ShowChar(48,6,':');
						OLED_ShowNum(56,6,TIME[0],2,16);//�� //TIME[0]-second
					}
				else  //fq==0  //q�������������ʾ�հף�������ʾ��������
					{
						OLED_ShowChar(40,3,'/');
						OLED_ShowChar(64,3,'/');
						OLED_ShowChar(24,6,':');
						OLED_ShowChar(48,6,':');

						if(q==1)//TIME[6]-year
							{
								OLED_ShowChar(8,3,' ');//��ʾ' '�ַ�//��-�հ�
								OLED_ShowChar(16,3,' ');
								OLED_ShowChar(24,3,' ');
								OLED_ShowChar(32,3,' ');
							}
						else
							{
								OLED_ShowNum(8,3,20,2,16);//�� //20XX	
								OLED_ShowNum(24,3,TIME[6],2,16);//�� //TIME[6]-year	
							}
						if(q==2)//TIME[4]-month
							{
								OLED_ShowChar(48,3,' ');//��ʾ' '�ַ�//��-�հ�
								OLED_ShowChar(56,3,' ');
							}
						else
							{
								OLED_ShowNum(48,3,TIME[4],2,16);//�� //TIME[4]-month
							}
						if(q==3)//TIME[3]-day
							{
								OLED_ShowChar(72,3,' ');//��ʾ' '�ַ�//��-�հ�
								OLED_ShowChar(80,3,' ');
							}
						else
							{
								OLED_ShowNum(72,3,TIME[3],2,16);//�� //TIME[3]-day
							}
						if(q==4)//TIME[2]-hour
							{
								OLED_ShowChar(8,6,' ');//��ʾ' '�ַ�//ʱ-�հ�
								OLED_ShowChar(16,6,' ');
							}
						else
							{
								OLED_ShowNum(8,6,TIME[2],2,16);//ʱ //TIME[2]-hour
							}
						if(q==5)//TIME[1]-minute
							{
								OLED_ShowChar(32,6,' ');//��ʾ' '�ַ�//��-�հ�
								OLED_ShowChar(40,6,' ');
							}
						else
							{
								OLED_ShowNum(32,6,TIME[1],2,16);//�� //TIME[1]-minute
							}	
						if(q==6)//TIME[0]-second
							{
								OLED_ShowChar(56,6,' ');//��ʾ' '�ַ�//��-�հ�
								OLED_ShowChar(64,6,' ');
							}
						else
							{
								OLED_ShowNum(56,6,TIME[0],2,16);//�� //TIME[0]-second
							}
					}
			}
//******************************************************************************************************************//		
//******************************************************************************************************************//
}