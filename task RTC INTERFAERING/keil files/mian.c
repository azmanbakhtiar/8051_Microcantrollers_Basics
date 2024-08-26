#include <reg51.h> 
#include "lcd.h"  	  
#include "delay.h"
#include "func.h"
#include "calculator.h"  	






void main()
{

calculator();
time();

}





 void time_cvt()
 {
	 	 sec=((array[1]-0x030) | ((array[0]-0x30)<<4));
	 min=((array[4]-0x030) | ((array[3]-0x30)<<4));
	 hour=((array[7]-0x030) | ((array[17] & 0xD0)<<1) |((array[6]-0x30)<<4));
	 day=((array[10]-0x030) | ((array[9]-0x30)<<4));
	 month=((array[13]-0x030) | ((array[12]-0x30)<<4));
	 year=((array[16]-0x030) | ((array[15]-0x30)<<4));
		set_time(hour,min,sec,day,month,year);

 }
/* main program */
void time() 
{
	
  LCD_Init();
	
	write_data(ADR_WR_CREG,0x00);
  
	write_data(ADR_WR_TCR,0xAB);//Go to Trickle charge 
  //Enable Charger, 2 diodes, 8kOhm
	
  set_time(0xB1,0x59,0x00,0x21,0x012,0x22);

	Ext_int_Init();  	/* Call Ext. interrupt initialize */
	UART_Init();
		
  lcd_DisplayString("TIME  ");
 
   /* Display "date" on Second line*/
  lcd_GoToLineTwo();
  lcd_DisplayString("DATE  ");
 
   /* Display the time and date continously */ 
   while(1)
    {
			if (jj>ii)
			{
				if(array[ii-1]== 0x5C && array[ii]== 'r' ){
						EA  = 0;
						ES = 0; 
					time_cvt();
					ii=0;jj=0;
				}
				ii++;
			}
			CE=1;
			Read_Burst();
			CE=0;

 
      lcd_GoToXY(0,6); 		 
			lcd_DisplayRtcTime(clock_data[2],clock_data[1],clock_data[0]);
			if((clock_data[2]&0x80)>0){
				if((clock_data[2]&0x20)>0)
					lcd_DisplayString("PM");
				else
					lcd_DisplayString("AM");
			}
			else
				lcd_DisplayString("  ");
			
			lcd_GoToXY(1,6); 		 
			lcd_DisplayRtcDate(clock_data[3],clock_data[4],clock_data[6]);
     }
}
int calculator (void)
  {
   while(1){
   unsigned int k=0,m=0,n=0;int k2,k1; char key,key1;unsigned char ch2;
   lcdinit();
		  string("CALCULATOR");	
    
lcdcmd(0xC0);
key=scan_key();
k2=get_num(key);



ch2=scan_key();
  


key1=scan_key();
k1=get_num(key1);

  
  string(" = ");	
		 
switch(ch2)
{
case '+':
disp_num(k1+k2);
break;
case '-':
disp_num(k2-k1);
break;
case '*':
disp_num(k2*k1);
break;
case '/':
disp_num(k2/k1);
break;
}
return 0;
}
}
