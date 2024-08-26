
#include "LCD.H"
#include "DS1820.H"
#include<reg51.h>
 
 
void DS1820 (void);
 
void main (void)
{
LCD_INI();
wrt_cmd(0x80);
wrt_string(T= );
while(1)
{
DS1820();
 
}
 
}
 
void DS1820 (void)
{
unsigned char tp,tpd,msb,nsb,lsb;
		ReadTemp(&MyTemp[0]);
 		if(MyTemp[1]==0xff)
		{
		wrt_cmd(0xc4);
		wrt_data("-");
		MyTemp[0]=~MyTemp[0];
		MyTemp[0]++;
		}
		else
		{
		wrt_cmd(0xc4);
		wrt_data(" ");
		}
		tp  = MyTemp[0] >
>
 1;
		tpd = (MyTemp[0] &1) ? 5:0;
		if(tp<10)
		{
		wrt_data(" ");
		wrt_data(" ");
		wrt_data(0x30 + tp);
		}
		else
		{
		if(tp<100)
		{
		lsb=tp%10;
		nsb=(tp/10)%10;
		msb=(tp/10)/10;
		if (msb!=0)
		wrt_data(0x30 +msb);
		else 	data_in(" ");
		if (nsb!=0)
		wrt_data(0x30 +nsb);
		else data_in(" ");
		wrt_data(0x30 +lsb);
		}
		else
		{
		lsb=tp%10;
		nsb=(tp/10)%10;
		msb=(tp/10)/10;
		wrt_data(0x30 +msb);
		wrt_data(0x30 + nsb);
		wrt_data(0x30 + lsb);
		}
		}
		wrt_data(".");
		wrt_data(0x30+tpd);
		data_in("C");
		wrt_data(0xdf);
 
}