#include<reg51.h>
sbit led=P2^0;
void delay(unsigned int);

void timer0(void) interrupt 1
{
	unsigned char count;
count++;
if (count==110)
{	
	led=~led;
	count=0;
}	
}
	void main(void)
{
	unsigned int z;
	led=0;
  TMOD = 0x02;    // Timer 0 Mode 2
  TH0= -84;     //initial value for 1ms
  IE=0x82;
  TR0 = 1;     // timer start
	while(1)
	{}
}

