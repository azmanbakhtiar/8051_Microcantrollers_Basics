#include<reg51.h>
#define LED_D1 P2      // Port declaration
void delay_ms(unsigned int ms_count)
{
	unsigned int i,j;
	for(i=0; i<ms_count; i++)
	{
		for(j=0; j<1000; j++);
	}
} 
void main(void)
{
	
	while (1)
	{
		LED_D1 = 0x00;                  // Declare Port2 as an output
		LED_D1 = LED_D1 | ~0x01;       // turn the LED On---------> set bit#0  = LOW
		delay_ms(500);    // A Small delay
		LED_D1 = 0xFF;           // Turn the LED OFF n---------> set Port#2  = HIGH
		delay_ms(500);  // A sll delay
	}
}


		