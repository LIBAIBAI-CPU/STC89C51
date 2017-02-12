#include<reg52.h>

/*===============================*\
  =这只是一个结构框架
  =需要什么往里面塞和改就行
  =比如更多的传感器
  =更多的轮子
  =更多样的弯道情况
  =PWM、PID等 
\*===============================*/


//该程序直接适用四个红外传感器
//四个轮子，两侧并联
//采用差速进行转弯的循迹车 
#define uint unsigned int
#define uchar unsigned char

sbit Infrared1= P3^0; //红外传感器 
sbit Infrared2= P3^1;	
sbit Infrared3= P3^2;	
sbit Infrared4= P3^3;		

sbit LeftWheelForward =  P1^0; //左边轮子正转 
sbit LeftWheelBack =  P1^1; //左边轮子反转
sbit RightWheelForward = P1^2;//右边轮子正转 
sbit RightWheelBack = P1^3;//右边轮子反转 

int index; //索引 

int Judge();     //判断方向 
void Action(int);   //执行 
void Forward();  // 前进 
void Stop();     // 停止 

//转向   数字越大转向角度越大   eg：TurnLeft1 转向角度 < TurnLeft2 
void TurnLeft1(); // 左转 
void TurnRight1();//右转 
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


