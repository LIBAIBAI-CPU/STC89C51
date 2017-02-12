#include "STC12C5A.H"

/*==============*\
  =PWM0 P1.3��� 
  =PWM1 P1.4��� 
*\==============*/

#define uchar unsigned char
#define uint  unsigned int

void PWM_Init();				//PWM��ʼ�� 
void PWM_Set(uchar x,uchar y); //ֱ������ռ�ձ�
void PWM_Change(int ChangeX,ChangeY); // change: 0X0CԼ5%,0X05Լ2%,����x��ֵ����PWM0,����Y����PWM1 
 
void main()
{
	while(1)
	{
		PWM_Init();		
		PWM_Change(5,-8);
	
	}
	
} 

void PWM_Change(int ChangeX,ChangeY) // change: 0X0CԼ5%,0X05Լ2% 
{     
	CCAP0L += ChangeX;    
	CCAP0H += ChangeX; 
	CCAP1L += ChangeY;    
	CCAP1H += ChangeY;      
}

void PWM_Set(uchar x,uchar y)  //ֱ������ռ�ձ�
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
	CMOD = 0X02;     		//0X00:��ϵͳʱ��/12 Ϊʱ��Դ,0X02:ϵͳʱ��/2,0x08:ϵͳʱ��    
	PWM_Set(0X80,0X80);		//��ʼռ�ձ�,0XC0:ռ�ȿ�Ϊ25%,0X80:ռ�ձ�50%,0X40:ռ�ձ�Ϊ75%   
	CCAPM0 = 0X42;  		//0X42:8λPWM�����ж�;0X53:8λPWM���,�½��ز����ж�   
	CCAPM1 = 0X42; 			//0X63:�����ز����ж�; 0X73:�����ز����ж�  	
	CR = 1;         		//����PCA������
}    
