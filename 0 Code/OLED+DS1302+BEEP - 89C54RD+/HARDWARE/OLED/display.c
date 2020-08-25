#include "display.h"


uchar l=1;//工具变量//应用于对初次进入正常显示时间页面或修改页面的oled清屏
uchar code *dis_week[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};


void Display() //oled显示函数
{
//********************************************************1**********************************************************//		
//********************************************************1**********************************************************//
	  if(KeyValue==0) //KM没被按下，正常显示时间-----+（闹钟）
			{
				
				if(l==1)//只执行一次 刚开机或刚从修改页面过来才可执行
					{
						OLED_Clear();
						l=0;
					}
				
				OLED_ShowString(0,0,"Time:"); 
				OLED_ShowNum(8,3,20,2,16);//年 //20XX	
				OLED_ShowNum(24,3,TIME[6],2,16);//年 //TIME[6]-year	
				OLED_ShowChar(40,3,'/');
				OLED_ShowNum(48,3,TIME[4],2,16);//月 //TIME[4]-month
				OLED_ShowChar(64,3,'/');
				OLED_ShowNum(72,3,TIME[3],2,16);//日 //TIME[3]-day
					
				OLED_ShowString(95,3,dis_week[TIME[5]]);//周 //TIME[5]-week
					
				if( NAO1[2]==1 || NAO2[2]==1 || NAO3[2]==1)
					{
						OLED_ShowCHinese(98,6,5);//alarm_bit /*特殊字符"闹钟"图案,5*/
					}
				else
					{
						OLED_ShowChar(98,6,' ');//显示' '字符 //alarm_bit-空白
						OLED_ShowChar(106,6,' ');
					}
				
//*******************************************闹钟*********************************************//
		//只有正常显示时间（主界面）时才有机会进入闹钟
	  //所以在修改闹钟或时间的页面设计检测到1分钟无操作时会自动退出到正常显示时间页面！						
						if( (TIME[2]==NAO1[0]) && (TIME[1]==NAO1[1]) && (TIME[0]<=1) && (NAO1[2]==1) )
						{                                           
							ring_bit=1;//开启闹钟响铃标志位
						}
						if( (TIME[2]==NAO2[0]) && (TIME[1]==NAO2[1]) && (TIME[0]<=1) && (NAO2[2]==1) )
						{                                           
							ring_bit=1;//开启闹钟响铃标志位
						}					
						if( (TIME[2]==NAO3[0]) && (TIME[1]==NAO3[1]) && (TIME[0]<=1) && (NAO3[2]==1) )
						{                                           
							ring_bit=1;//开启闹钟响铃标志位
						}
						
						OLED_ShowChar(24,6,':');
						OLED_ShowChar(48,6,':');
						if( ring_bit )   //闹钟!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
							{
								  //定时器1控制fq的取反频率--来控制数码管的闪烁频率
									if(fq==0)
									{
										OLED_ShowChar(8,6,' ');//显示' '字符//时-空白
										OLED_ShowChar(16,6,' ');
//										OLED_ShowChar(24,6,':');
										OLED_ShowChar(32,6,' ');//显示' '字符//分-空白
										OLED_ShowChar(40,6,' ');
//										OLED_ShowChar(48,6,':');
										OLED_ShowChar(56,6,' ');//显示' '字符//秒-空白
										OLED_ShowChar(64,6,' ');
									}
									else
									{
										OLED_ShowNum(8,6,TIME[2],2,16);//时 //TIME[2]-hour
//										OLED_ShowChar(24,6,':');
										OLED_ShowNum(32,6,TIME[1],2,16);//分 //TIME[1]-minute
//										OLED_ShowChar(48,6,':');
										OLED_ShowNum(56,6,TIME[0],2,16);//秒 //TIME[0]-second
									}
							}
						else  //正常显示时间
							{
								OLED_ShowNum(8,6,TIME[2],2,16);//时 //TIME[2]-hour
//								OLED_ShowChar(24,6,':');
								OLED_ShowNum(32,6,TIME[1],2,16);//分 //TIME[1]-minute
//								OLED_ShowChar(48,6,':');
								OLED_ShowNum(56,6,TIME[0],2,16);//秒 //TIME[0]-second
							}
			}
//********************************************************2**********************************************************//		
//********************************************************2**********************************************************//
	  if(KeyValue=='N')  //显示所设定闹钟：时-分，q所代表的数据闪烁，有两种频率
			{
				
				if(l==0)//只执行一次 刚从时间显示页面过来才可执行
					{
						OLED_Clear();
						l=1;
					}

				OLED_ShowString(15,0,"Modify Alarm"); 
					
				//定时器1控制fq的取反频率--来控制数码管的闪烁频率
				if(fq==1)  //全部显示
					{
							OLED_ShowNum(8,2,NAO1[0],2,16);//时
							OLED_ShowChar(24,2,':');
							OLED_ShowNum(32,2,NAO1[1],2,16);//分
							if(NAO1[2]==1)
								OLED_ShowString(95,2,"on"); 
							else
								OLED_ShowString(95,2,"off"); 
							
							OLED_ShowNum(8,4,NAO2[0],2,16);//时
							OLED_ShowChar(24,4,':');
							OLED_ShowNum(32,4,NAO2[1],2,16);//分
							if(NAO2[2]==1)
								OLED_ShowString(95,4,"on"); 
							else
								OLED_ShowString(95,4,"off"); 
							
							OLED_ShowNum(8,6,NAO3[0],2,16);//时
							OLED_ShowChar(24,6,':');
							OLED_ShowNum(32,6,NAO3[1],2,16);//分
							if(NAO3[2]==1)
								OLED_ShowString(95,6,"on"); 
							else
								OLED_ShowString(95,6,"off");
					}
				else  //fq==0  //q所代表的数据显示空白，其余显示正常数据
					{
						  OLED_ShowChar(24,2,':');
						  OLED_ShowChar(24,4,':');
						  OLED_ShowChar(24,6,':');
						
							if(q==1)//NAO1[0]-hour
								{
									OLED_ShowChar(8,2,' ');//显示' '字符//时-空白
									OLED_ShowChar(16,2,' ');
								}
							else
								{
									OLED_ShowNum(8,2,NAO1[0],2,16);//时
								}
							if(q==2)//NAO1[1]-minute
								{
									OLED_ShowChar(32,2,' ');//显示' '字符//分-空白
									OLED_ShowChar(40,2,' ');
								}
							else
								{
									OLED_ShowNum(32,2,NAO1[1],2,16);//分
								}
							if(q==3)//NAO1[2]-alarm_bit
								{
									OLED_ShowChar(95,2,' ');//显示' '字符//alarm_bit-空白
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
									OLED_ShowChar(8,4,' ');//显示' '字符//时-空白
									OLED_ShowChar(16,4,' ');
								}
							else
								{
									OLED_ShowNum(8,4,NAO2[0],2,16);//时
								}
							if(q==5)//NAO2[1]-minute
								{
									OLED_ShowChar(32,4,' ');//显示' '字符//分-空白
									OLED_ShowChar(40,4,' ');
								}
							else
								{
									OLED_ShowNum(32,4,NAO2[1],2,16);//分
								}
							if(q==6)//NAO2[2]-alarm_bit
								{
									OLED_ShowChar(95,4,' ');//显示' '字符//alarm_bit-空白
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
									OLED_ShowChar(8,6,' ');//显示' '字符//时-空白
									OLED_ShowChar(16,6,' ');
								}
							else
								{
									OLED_ShowNum(8,6,NAO3[0],2,16);//时
								}
							if(q==8)//NAO3[1]-minute
								{
									OLED_ShowChar(32,6,' ');//显示' '字符//分-空白
									OLED_ShowChar(40,6,' ');
								}
							else
								{
									OLED_ShowNum(32,6,NAO3[1],2,16);//分
								}
							if(q==9)//NAO3[2]-alarm_bit
								{
									OLED_ShowChar(95,6,' ');//显示' '字符//alarm_bit-空白
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
	if(KeyValue=='T')  //显示所设定时间：时-分，q所代表的数据闪烁，有两种频率
			{
				
				if(l==0)//只执行一次 刚从时间显示页面过来才可执行
					{
						OLED_Clear();
						l=1;
					}

				OLED_ShowString(0,0,"Modify Time"); 
					
				OLED_ShowString(95,3,dis_week[TIME[5]]);//周 //TIME[5]-week
					
				if( NAO1[2]==1 || NAO2[2]==1 || NAO3[2]==1)
					{
						OLED_ShowCHinese(98,6,5);//alarm_bit /*特殊字符"闹钟"图案,5*/
					}
				else
					{
						OLED_ShowChar(98,6,' ');//显示' '字符 //alarm_bit-空白
						OLED_ShowChar(106,6,' ');
					}
				
				//定时器1控制fq的取反频率--来控制数码管的闪烁频率
				if(fq==1)  //全部显示
					{
						OLED_ShowNum(8,3,20,2,16);//年 //20XX	
						OLED_ShowNum(24,3,TIME[6],2,16);//年 //TIME[6]-year
						OLED_ShowChar(40,3,'/');
						OLED_ShowNum(48,3,TIME[4],2,16);//月 //TIME[4]-month
						OLED_ShowChar(64,3,'/');
						OLED_ShowNum(72,3,TIME[3],2,16);//日 //TIME[3]-day
						
						OLED_ShowNum(8,6,TIME[2],2,16);//时 //TIME[2]-hour
						OLED_ShowChar(24,6,':');
						OLED_ShowNum(32,6,TIME[1],2,16);//分 //TIME[1]-minute
						OLED_ShowChar(48,6,':');
						OLED_ShowNum(56,6,TIME[0],2,16);//秒 //TIME[0]-second
					}
				else  //fq==0  //q所代表的数据显示空白，其余显示正常数据
					{
						OLED_ShowChar(40,3,'/');
						OLED_ShowChar(64,3,'/');
						OLED_ShowChar(24,6,':');
						OLED_ShowChar(48,6,':');

						if(q==1)//TIME[6]-year
							{
								OLED_ShowChar(8,3,' ');//显示' '字符//年-空白
								OLED_ShowChar(16,3,' ');
								OLED_ShowChar(24,3,' ');
								OLED_ShowChar(32,3,' ');
							}
						else
							{
								OLED_ShowNum(8,3,20,2,16);//年 //20XX	
								OLED_ShowNum(24,3,TIME[6],2,16);//年 //TIME[6]-year	
							}
						if(q==2)//TIME[4]-month
							{
								OLED_ShowChar(48,3,' ');//显示' '字符//月-空白
								OLED_ShowChar(56,3,' ');
							}
						else
							{
								OLED_ShowNum(48,3,TIME[4],2,16);//月 //TIME[4]-month
							}
						if(q==3)//TIME[3]-day
							{
								OLED_ShowChar(72,3,' ');//显示' '字符//日-空白
								OLED_ShowChar(80,3,' ');
							}
						else
							{
								OLED_ShowNum(72,3,TIME[3],2,16);//日 //TIME[3]-day
							}
						if(q==4)//TIME[2]-hour
							{
								OLED_ShowChar(8,6,' ');//显示' '字符//时-空白
								OLED_ShowChar(16,6,' ');
							}
						else
							{
								OLED_ShowNum(8,6,TIME[2],2,16);//时 //TIME[2]-hour
							}
						if(q==5)//TIME[1]-minute
							{
								OLED_ShowChar(32,6,' ');//显示' '字符//分-空白
								OLED_ShowChar(40,6,' ');
							}
						else
							{
								OLED_ShowNum(32,6,TIME[1],2,16);//分 //TIME[1]-minute
							}	
						if(q==6)//TIME[0]-second
							{
								OLED_ShowChar(56,6,' ');//显示' '字符//秒-空白
								OLED_ShowChar(64,6,' ');
							}
						else
							{
								OLED_ShowNum(56,6,TIME[0],2,16);//秒 //TIME[0]-second
							}
					}
			}
//******************************************************************************************************************//		
//******************************************************************************************************************//
}