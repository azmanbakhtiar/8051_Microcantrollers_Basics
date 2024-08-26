#include <reg51.h>
void delay(unsigned int time);           //Delay function declaration
unsigned int x=0;                        // Variable declaration
unsigned int y=0;                        // Variable declaration
sbit k1=P3^1;                            // Pin declaration
sbit k2=P3^0;                            // Pin declaration
sbit k3=P3^2;                            // Pin declaration
sbit k4=P3^3;                            // Pin declaration
sbit led1=P2^0;                          // Pin declaration
sbit led2=P2^1;                          // Pin declaration
sbit led3=P2^2;                          // Pin declaration
sbit led4=P2^3;                          // Pin declaration
void main (void)                         // MAin function
{
	while(1)                               // Infinite while loop
	{
	if(k1==0)
      {
				
	     led1=~led1;
				delay(60);
	    }
	    else
	    {
	        led1=1;
	       }
	

	if(k2==0)
      {
				
	     led2=~led2;
				delay(60);
	    }
	    else
	    {
	        led2=1;
	       }
			
	
	if(k3==0)
      {
				
	     led3=~led3;
				delay(60);
	    }
	    else
	    {
	        led3=1;
	       }
			 
				 
	if(k4==0)
      {
				
	     led4=~led4;
				delay(60);
	    }
	    else
	    {
	        led4=1;
	       }
			 
			 }
		 }

void delay(unsigned int time)                  // Delay function
{
   for(x=0; x<time; x++)
      for(y=0; y<1114; y++);	
}