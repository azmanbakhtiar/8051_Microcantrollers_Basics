
#include<reg51.h>
#define lcd P0
sbit rs=P2^6;
sbit rw=P2^5;
sbit en=P2^7;

sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
sbit c4=P1^7;
                  
void lcd_init();
void cmd(unsigned char );
void dat(unsigned char );
lcd_string(unsigned char *);
void delay(unsigned int );
void keypad(void);
void main()
{
     cmd(0x38);
        cmd(0x0e);
        cmd(0x06);
	   lcd_string("Enter the key:");
	 cmd(0xc0);
		 cmd(0x14);
	  
    while(1) {
    
     
       
       	 keypad();
		
		
    }
}
void keypad()
{
    c1=c2=c3=c4=1;
    r1=0;r2=1;r3=1;r4=1;
    if(c1==0){
        while(c1==0);
        dat('7');
    } else if(c2==0) {
        while(c2==0);
        dat('8');
    } else if(c3==0) {
        while(c3==0);
        dat('9');
    } else if(c4==0) {
        while(c4==0);
        dat('/');
    }
    r1=1;r2=0;r3=1;r4=1;
    if(c1==0){
        while(c1==0);
        dat('4');
    } else if(c2==0) {
        while(c2==0);
        dat('5');
    } else if(c3==0) {
        while(c3==0);
        dat('6');
    } else if(c4==0) {
        while(c4==0);
        dat('*');
    }
    r1=1;r2=1;r3=0;r4=1;
    if(c1==0){
        while(c1==0);
        dat('1');
    } else if(c2==0) {
        while(c2==0);
        dat('2');
    } else if(c3==0) {
        while(c3==0);
        dat('3');
    } else if(c4==0) {
        while(c4==0);
        dat('-');
    }
    r1=1;r2=1;r3=1;r4=0;
    if(c1==0){
        while(c1==0);
        cmd(0x01);
    } else if(c2==0) {
        while(c2==0);
        dat('0');
    } else if(c3==0) {
        while(c3==0);
        dat('=');
    } else if(c4==0) {
        while(c4==0);
        dat('+');
    }
}

void cmd(unsigned char x)
{
        lcd=x;
        rs=0;
        rw=0;
        en=1;
        delay(1000);
        en=0;
}
void dat(unsigned char y)
{
        lcd=y;
        rs=1;
        rw=0;
        en=1;
        delay(1000);
        en=0;
}
lcd_string(unsigned char *s)
{
    while(*s)
        dat(*s++);
}
void delay(unsigned int z)
{
  unsigned int i;
  for(i=0;i<=z;i++);
}