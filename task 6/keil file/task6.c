#include<reg51.h>
sbit led=P2^0;
sbit btn=P3^1;

	void Delay();
void main()
  {
   IE=0x84;                    // Activating both the interrupts EX0 and EX1
   while(1)
	 {	
		Delay();
	 };
  }
                        //Your command goes here
  
void extr1(void) interrupt 2    //Subroutine EX1 with Interrupt Number '1'
  {
		if(btn==1)
		{
    led=~led;
			Delay();
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