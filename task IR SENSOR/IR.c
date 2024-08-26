#include<reg51.h>
#include "lcd.h"

void main()
{
    lcd_init();
    string(" AZMAN BAKHTIAR ");
    while(1)
			{
     if(IR == 0) {
					  led=0;
            lcmd(0xc0);
            string("signal Detected");
            signal_delay();
					 signal_delay();
        } else {
					 led=1;
            lcmd(0xc0);
            string("      ");
        }
    }
}
