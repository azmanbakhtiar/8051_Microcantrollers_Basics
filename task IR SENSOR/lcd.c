#include<reg51.h>
#include "lcd.h"
void lcd_init()
{
    lcmd(0x38);
    lcmd(0x0e);
    lcmd(0x06);
    lcmd(0x01);
    lcmd(0x80);
}
void lcmd(unsigned char a)
{
    lcd=a;
    rs=0;
    rw=0;
    ENABLE=1;
    signal_delay();
    ENABLE=0;
}
void dat(unsigned char b)
{
    lcd=b;
    rs=1;
    rw=0;
    ENABLE=1;
    signal_delay();
    ENABLE=0;
}
void string(char *s)
{
    while(*s) {
       dat(*s++);
     }
}
void signal_delay()
{
    unsigned int i;
    for(i=0;i<20000;i++);
}