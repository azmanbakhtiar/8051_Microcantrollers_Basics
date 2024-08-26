#include<reg51.h>
sbit led=P2^0;
sbit btn=P3^1;

void delay(unsigned int i);
void main(void)
{
btn=1;



if(btn==1)
{
led=~led;
delay(66.5);
}
else
{
led=0;
delay(66.5);
}


}
void delay(unsigned int i)
{
  unsigned int x,y;
  for(x=0;x<i;x++)
  for(y=0;y<1275;y++);
}