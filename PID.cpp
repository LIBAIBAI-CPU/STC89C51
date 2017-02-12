#include <reg52.h>
#include <string.h>             //C语言中memset函数头文件
#define unsigned int uint

/*====================================================*\
  =	The PID (比例、积分、微分) 
  =	是一般常用pid算法的基本架构，没有处理输入输出 
  =	函数double sensor (void) 是输入部分 
  =	函数actuator(double rDelta)是输出部分 
\*====================================================*/

//构建PID结构体数据类型 
typedef struct PID 
{ 
	double SetPoint;      // 设定目标	Desired value 
	double Proportion;    // 比例常数	Proportional Const 
	double Integral;      // 积分常数	Integral Const 
	double Derivative;    // 微分常数	Derivative Const 
	double LastError;     // 	Error[-1]  
	
	double PrevError;    // 	Error[-2] 
	double SumError;    //  	Sums of Errors 
} PID; 



/*=============*\
  =	 函数声明
\*=============*/
void PIDInit (PID *pp) ;						//PID初始化
double PIDCalc( PID *pp, double NextPoint );    //PID计算
double sensor (void); 							// 输入数据
void actuator(double Gogogo); 					// 输出数据  




/*======================= 
Main Program   主程序
========================*/ 
void main(void) 
{ 
	PID sPID; // 定义一个PID数据类型的变量 
	double rOut; // PID 响应并对外输出 (Output) 
	double rIn; // PID 外界反馈输入    (Input) 
	PIDInit ( &sPID ); // 初始化
	sPID.Proportion = 0.5; // 设置P、I、D参数   设置目标参数     
	sPID.Integral = 0.5;    //到时候调试就是调节这几个
	sPID.Derivative = 0.0; 
	sPID.SetPoint = 100.0; 


	//开始建模处理 
	for (;;) {  
	rIn = sensor (); // 读取输入 
	rOut = PIDCalc ( &sPID,rIn ); // 开始咔咔咔计算 
	actuator ( rOut ); // 响应输出 
}
}



void actuator(double Gogogo) // 输出数据 
{
	
} 
double sensor (void) // 输入数据 
{ 
	return 100.0; 
} 

/*========= 
PID计算 
=========*/ 
double PIDCalc( PID *pp, double NextPoint ) 
{ 
	double dError, Error; 
	Error = pp->SetPoint - NextPoint;           // 偏差 
	pp->SumError += Error;                   // 积分 
	dError = Error - pp->LastError;             // 当前微分 
	pp->PrevError = pp->LastError; 
	pp->LastError = Error; 
	return (pp->Proportion * Error // 比例项 
				+ pp->Integral * pp->SumError // 积分项 
					+ pp->Derivative * dError // 微分项 
	); 
} 


/*======================================= 
Initialize PID Structure  PID参数初始化
=======================================*/ 
void PIDInit (PID *pp) 
{ 
	memset ( pp,0,sizeof(PID)); 
	
} 


