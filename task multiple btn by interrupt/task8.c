#include<reg51.h>
sbit led=P2^0;
sbit led1=P2^1;
sbit led2=P2^2;
sbit led3=P2^3;
sbit btn=P3^3;
sbit btn1=P3^2;
	void Delay();
void main()
  {
   IE=0x85;                    // Activating both the interrupts EX0 and EX1
   while(1)
	 {		if(btn1==1)
		
    led1=~led1;
		Delay();
	 };
  }
                        //Your command goes here
  
void extr0(void) interrupt 0     //Subroutine EX0 with interrupt number '0'
  {
		if(btn==1)
    led=~led;                            //Your command goes here
	
  }
void extr1(void) interrupt 2    //Subroutine EX1 with Interrupt Number '1'
  {
		
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