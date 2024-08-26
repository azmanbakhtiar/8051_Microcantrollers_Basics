#include<reg51.h>
sbit led=P2^0;
void delay(unsigned int i);
void main(void)
{
led=0xFF;
delay(66.5);
led=0x00;
delay(66.5);
}
void delay(unsigned int i)
{
  unsigned int x,y;
  for(x=0;x<i;x++)
  for(y=0;y<1275;y++);
}