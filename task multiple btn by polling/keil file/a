#include<reg51.h>
sbit led=P2^0;
sbit btn=P3^1;
sbit led1=P2^1;
sbit btn1=P3^0;
sbit led2=P2^2;
sbit btn2=P3^2;
sbit led3=P2^3;
sbit btn3=P3^3;

void Delay();
void main()
  {
     btn=1; 
  
     btn1=1;  
  
     btn2=1;  
 
     btn3=1;  
  		
		 while(1)

	 {
		 	if(btn2==0)
		{  led1=~led1;
			Delay();
		}
		if(btn3==0)
		{ led=~led;
			Delay();
		}
		{
		if(btn==1)
    led2=~led2;                            //Your command goes here
			Delay();
     }
		  {
		if(btn1==1)
		
    led3=~led3;
		Delay();
  }
		
		
	 }		
	 }
  

  
	void Delay()
   {

     int i;
     TMOD = 0x01;      // Timer0 mode1

                for(i=0;i<200;i++)
                {

               TH0=0xF8;              //initial values for 1sec delay
                TL0=0xCC;
                TR0 = 1;               // timer0 start
            while (TF0 == 0);   // check overflow condition
                TR0 = 0;               // Stop Timer
                TF0 = 0;               // Clear flag
              }

}