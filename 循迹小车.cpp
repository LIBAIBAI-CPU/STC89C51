#include<reg52.h>

/*===============================*\
  =��ֻ��һ���ṹ���
  =��Ҫʲô���������͸ľ���
  =�������Ĵ�����
  =���������
  =��������������
  =PWM��PID�� 
\*===============================*/


//�ó���ֱ�������ĸ����⴫����
//�ĸ����ӣ����ಢ��
//���ò��ٽ���ת���ѭ���� 
#define uint unsigned int
#define uchar unsigned char

sbit Infrared1= P3^0; //���⴫���� 
sbit Infrared2= P3^1;	
sbit Infrared3= P3^2;	
sbit Infrared4= P3^3;		

sbit LeftWheelForward =  P1^0; //���������ת 
sbit LeftWheelBack =  P1^1; //������ӷ�ת
sbit RightWheelForward = P1^2;//�ұ�������ת 
sbit RightWheelBack = P1^3;//�ұ����ӷ�ת 

int index; //���� 

int Judge();     //�жϷ��� 
void Action(int);   //ִ�� 
void Forward();  // ǰ�� 
void Stop();     // ֹͣ 

//ת��   ����Խ��ת��Ƕ�Խ��   eg��TurnLeft1 ת��Ƕ� < TurnLeft2 
void TurnLeft1(); // ��ת 
void TurnRight1();//��ת 
void TurnLeft2(); 
void TurnRight2(); 



void main()
{
	
    while(1)
    {	
		Action(Judge());
	}
}



int Judge()
{
	if(Infrared1 ==1  && Infrared2 ==0  && Infrared3 ==0 && Infrared4 ==0 )	index = 44;
	
	if(Infrared1 ==0  && Infrared2 ==1  && Infrared3 ==0 && Infrared4 ==0 )	index = 4;
	
	if(Infrared1 ==0  && Infrared2 ==0  && Infrared3 ==1 && Infrared4 ==0 )	index = 6;
	
	if(Infrared1 ==0  && Infrared2 ==0  && Infrared3 ==0 && Infrared4 ==1 )	index = 66;
	
	if(Infrared1 ==0  && Infrared2 ==0  && Infrared3 ==0 && Infrared4 ==0 )	index = 8;

	return index;			
}

void Action(int index)
{
	switch(index)
	{
		case 8:
			Forward();
		break;
		
		case 4:
 			TurnLeft1();
		break;
		
		case 6:
			TurnRight1();
		break;
		
		case 44:
 			TurnLeft2();
		break;
		
		case 66:
			TurnRight2();
		break;
		
		case 0:
			Stop();	
		break;
		
	}
}

void Forward()
{
	LeftWheelForward = 1;
	RightWheelForward = 1;
	LeftWheelBack = 0; 
	RightWheelBack = 0; 
} 
void Stop()
{ 
	LeftWheelForward = 0;
	RightWheelForward = 0;
	LeftWheelBack = 0; 
	RightWheelBack = 0; 
}
void TurnLeft1() 
{
	LeftWheelForward = 0;
	RightWheelForward = 1;
	LeftWheelBack = 0; 
	RightWheelBack = 0; 
}
void TurnRight1()
{
	LeftWheelForward = 1;
	RightWheelForward = 0;
	LeftWheelBack = 0; 
	RightWheelBack = 0; 
}
void TurnLeft2() 
{
	LeftWheelForward = 0;
	RightWheelForward = 1;
	LeftWheelBack = 1; 
	RightWheelBack = 0; 
}
void TurnRight2()
{
	LeftWheelForward = 1;
	RightWheelForward = 0;
	LeftWheelBack = 0; 
	RightWheelBack = 1; 
}


