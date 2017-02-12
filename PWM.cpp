#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
 
sbit d = P1^1;//  PWM输出的引脚 

uchar time,a;

void main()
{
    EA=1;  //允许全局中断 
    TR0=1; //启动定时器 0  
	ET0=1;//ET0定时计数器0溢出中断允许
	
	
    while(1)
    {
		a = 1 ; //过度用而已，可以根据逻辑删掉 
	}
 
}





void time0() interrupt 1 //中断 
{
    TR0=0;
    TH0=0xff;
    TL0=0xf7;
    TR0=1;
 
    time++;
    if(time>=100) time=0;//1khz

   if(a == 1) 
    {
	    if(time<=95)    //95表示占空比95%，调节这个即可调节PWM占空比 
	    d=1;
        else 
		d=0;
	}
}





