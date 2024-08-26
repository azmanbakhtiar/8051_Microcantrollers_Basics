#include<STC89xxx.h>
#include<stdio.h>
void delay(unsigned count);
unsigned int i=0;
unsigned int u=0;
unsigned int j=0;
void main()
	
{
	unsigned char Mystring[]="HELLO WORLD\\r";
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
	for(u=0;u<14;u++)
	{
	SBUF=Mystring[u];
	while(TI==0);
	TI=0;
		
	
}
	delay(200);
	}

void delay(unsigned int count)
{
	for(i=0;i<count;i++)
	for(j=0;j<114;j++);
	
}