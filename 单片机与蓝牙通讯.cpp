#include<reg52.h>

/*==============================*\
  =����RXD�ӵ�Ƭ����TXD��P3.1�� 
  =����TXD�ӵ�Ƭ����RXD��P3.0�� 
*\==============================*/

#define uint unsigned int
#define uchar unsigned char

uchar a; //�������ռĴ������ص�ֵ 

void main()
{
	RI=0;
	SM0=0;	 
	SM1=1;
	SCON = 0x50;   // �趨���пڹ�����ʽ  
	while(1)
	{
		if(RI==1)
		{
			a=SBUF;
			RI=0;
		}
		switch(a)
		{
			case 1: //������;
			break; 
			case 2: //������;
			break; 
		}
	}
}

