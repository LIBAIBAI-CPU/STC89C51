#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
 
sbit d = P1^1;//  PWM��������� 

uchar time,a;

void main()
{
    EA=1;  //����ȫ���ж� 
    TR0=1; //������ʱ�� 0  
	ET0=1;//ET0��ʱ������0����ж�����
	
	
    while(1)
    {
		a = 1 ; //�����ö��ѣ����Ը����߼�ɾ�� 
	}
 
}





void time0() interrupt 1 //�ж� 
{
    TR0=0;
    TH0=0xff;
    TL0=0xf7;
    TR0=1;
 
    time++;
    if(time>=100) time=0;//1khz

   if(a == 1) 
    {
	    if(time<=95)    //95��ʾռ�ձ�95%������������ɵ���PWMռ�ձ� 
	    d=1;
        else 
		d=0;
	}
}





