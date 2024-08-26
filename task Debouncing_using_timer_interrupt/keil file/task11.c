#include<reg51.h>
#define Switch_released 0                        // Defining Switch_released
#define Switch_pressed 1                         // Defining Switch_pressed

sbit led_yellow=P2^0;                            // Pin declaration
sbit switch_k1 =P3^1;                            // Pin declaration
unsigned int k1_btn_state = 0;                   // Declaration of variable
unsigned int k1_press_counter=0;                 // Declaration of variable
unsigned int k1_release_counter=0;               // Declaration of variable
void timer_interupt_10ms()  interrupt 1          // Interrupt function
{  TH0=0xDC;                                     //initial value for 10ms
   TL0=0x00;
   if(k1_btn_state==0){                          // Using If & else statements
      if(switch_k1==Switch_pressed)
      {
      k1_press_counter++;
      if(k1_press_counter==10)
      {
				led_yellow=~led_yellow;
				k1_btn_state=1;
	 }
	  
   }
   else
      k1_press_counter=0;
     
   }
    
     if (k1_btn_state==1)
     {
	
	if(switch_k1==Switch_released)
	{
	k1_release_counter++;
	if(k1_release_counter==10)
	{
	   k1_btn_state=0;
	   }
	}
	else
	{
	   k1_release_counter=0;
	   }
	
	}
      
     }
 
   
 
void main(void)                        //Main Function
 {  TMOD=0x01;                           // Timer0 mode1
    TH0=0xDC;                          //initial value for 10ms
    TL0=0x00; 
     IE=0x8F;
    EA=1;
   led_yellow=0;
    TR0=1;                            // Start timer
  


   // Write your code here
   while (1);
 }