#include<reg52.h>

/*==============================*\
  =蓝牙RXD接单片机的TXD（P3.1） 
  =蓝牙TXD接单片机的RXD（P3.0） 
*\==============================*/

#define uint unsigned int
#define uchar unsigned char

uchar a; //用来接收寄存器返回的值 

void main()
{
	RI=0;
	SM0=0;	 
	SM1=1;
	SCON = 0x50;   // 设定串行口工作方式  
	while(1)
	{
		if(RI==1)
		{
			a=SBUF;
			RI=0;
		}
		switch(a)
		{
			case 1: //如何如何;
			break; 
			case 2: //如何如何;
			break; 
		}
	}
}

