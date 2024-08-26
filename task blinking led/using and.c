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
	LED_D1 = 0xFF;
	while (1)
	{
		LED_D1 = LED_D1 & ~0x01;       // turn the led On
		delay_ms(500);    // A Small delay
		LED_D1 = 0xFF;           // Turn the LED OFF
		delay_ms(500);  // A sll delay
	}
}


		