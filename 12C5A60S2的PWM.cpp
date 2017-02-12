#include "STC12C5A.H"

/*==============*\
  =PWM0 P1.3输出 
  =PWM1 P1.4输出 
*\==============*/

#define uchar unsigned char
#define uint  unsigned int

void PWM_Init();				//PWM初始化 
void PWM_Set(uchar x,uchar y); //直接设置占空比
void PWM_Change(int ChangeX,ChangeY); // change: 0X0C约5%,0X05约2%,更改x的值调整PWM0,更改Y调整PWM1 
 
void main()
{
	while(1)
	{
		PWM_Init();		
		PWM_Change(5,-8);
	
	}
	
} 

void PWM_Change(int ChangeX,ChangeY) // change: 0X0C约5%,0X05约2% 
{     
	CCAP0L += ChangeX;    
	CCAP0H += ChangeX; 
	CCAP1L += ChangeY;    
	CCAP1H += ChangeY;      
}

void PWM_Set(uchar x,uchar y)  //直接设置占空比
{       
	CCAP0L = x;    
	CCAP0H = x; 
	CCAP1L = y;    
	CCAP1H = y; 
}


void PWM_Init() 
{     
	CCON = 0X00;    
	CH = 0;     
	CL = 0;     
	CMOD = 0X02;     		//0X00:以系统时钟/12 为时钟源,0X02:系统时钟/2,0x08:系统时钟    
	PWM_Set(0X80,0X80);		//起始占空比,0XC0:占比空为25%,0X80:占空比50%,0X40:占空比为75%   
	CCAPM0 = 0X42;  		//0X42:8位PWM，无中断;0X53:8位PWM输出,下降沿产生中断   
	CCAPM1 = 0X42; 			//0X63:上升沿产生中断; 0X73:跳变沿产生中断  	
	CR = 1;         		//开启PCA计数器
}    
