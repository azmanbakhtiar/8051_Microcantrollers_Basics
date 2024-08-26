#include<reg51.h>

void delay(unsigned int i);
void main(void)
{
P2=0xAA;
delay(66.5);
P2=0x55;
delay(66.5);
}
void delay(unsigned int i)
{
  unsigned int x,y;
  for(x=0;x<i;x++)
  for(y=0;y<1275;y++);
}