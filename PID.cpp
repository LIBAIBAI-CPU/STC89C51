#include <reg52.h>
#include <string.h>             //C������memset����ͷ�ļ�
#define unsigned int uint

/*====================================================*\
  =	The PID (���������֡�΢��) 
  =	��һ�㳣��pid�㷨�Ļ����ܹ���û�д���������� 
  =	����double sensor (void) �����벿�� 
  =	����actuator(double rDelta)��������� 
\*====================================================*/

//����PID�ṹ���������� 
typedef struct PID 
{ 
	double SetPoint;      // �趨Ŀ��	Desired value 
	double Proportion;    // ��������	Proportional Const 
	double Integral;      // ���ֳ���	Integral Const 
	double Derivative;    // ΢�ֳ���	Derivative Const 
	double LastError;     // 	Error[-1]  
	
	double PrevError;    // 	Error[-2] 
	double SumError;    //  	Sums of Errors 
} PID; 



/*=============*\
  =	 ��������
\*=============*/
void PIDInit (PID *pp) ;						//PID��ʼ��
double PIDCalc( PID *pp, double NextPoint );    //PID����
double sensor (void); 							// ��������
void actuator(double Gogogo); 					// �������  




/*======================= 
Main Program   ������
========================*/ 
void main(void) 
{ 
	PID sPID; // ����һ��PID�������͵ı��� 
	double rOut; // PID ��Ӧ��������� (Output) 
	double rIn; // PID ��練������    (Input) 
	PIDInit ( &sPID ); // ��ʼ��
	sPID.Proportion = 0.5; // ����P��I��D����   ����Ŀ�����     
	sPID.Integral = 0.5;    //��ʱ����Ծ��ǵ����⼸��
	sPID.Derivative = 0.0; 
	sPID.SetPoint = 100.0; 


	//��ʼ��ģ���� 
	for (;;) {  
	rIn = sensor (); // ��ȡ���� 
	rOut = PIDCalc ( &sPID,rIn ); // ��ʼ�����Ǽ��� 
	actuator ( rOut ); // ��Ӧ��� 
}
}



void actuator(double Gogogo) // ������� 
{
	
} 
double sensor (void) // �������� 
{ 
	return 100.0; 
} 

/*========= 
PID���� 
=========*/ 
double PIDCalc( PID *pp, double NextPoint ) 
{ 
	double dError, Error; 
	Error = pp->SetPoint - NextPoint;           // ƫ�� 
	pp->SumError += Error;                   // ���� 
	dError = Error - pp->LastError;             // ��ǰ΢�� 
	pp->PrevError = pp->LastError; 
	pp->LastError = Error; 
	return (pp->Proportion * Error // ������ 
				+ pp->Integral * pp->SumError // ������ 
					+ pp->Derivative * dError // ΢���� 
	); 
} 


/*======================================= 
Initialize PID Structure  PID������ʼ��
=======================================*/ 
void PIDInit (PID *pp) 
{ 
	memset ( pp,0,sizeof(PID)); 
	
} 


