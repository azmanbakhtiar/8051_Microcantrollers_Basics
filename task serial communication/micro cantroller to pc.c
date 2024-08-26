#include<reg51.h>
sbit rs=P2^6;
sbit rw=P2^5;
sbit en=P2^7;
unsigned int i;

void delay(unsigned int time)  //Time delay function
{
unsigned int i,j;
for(i=0;i<time;i++)
for(j=0;j<5;j++);
}

             //Function for sending values to the command register of LCD
void lcdcmd(unsigned char value)  
{
P0=value;
rs = 0;
    rw = 0;
    en = 1;
delay(50);
en=0;
delay(50);

}
             //Function for sending values to the data register of LCD
void display(unsigned char value)  
{
P0=value;
rs = 1;
rw = 0;
en = 1;
delay(500);
en=0;
delay(50);

}
             //function to initialize the registers and pins of LCD
             //always use with every lcd of hitachi
void lcdint(void)         
{
P1=0x00;    //Port 1 is used as output port             
P2=0x03;    //Port 3 higher bits from 2 to 7 are used as output and lower two bits are used to activate UART 
     delay(15000);
     display(0x30);
     delay(4500);
     display(0x30);
     delay(300);
     display(0x30);
     delay(650);
lcdcmd(0x38);
delay(50);
lcdcmd(0x0F);
delay(50);
lcdcmd(0x01);
delay(50);
lcdcmd(0x06);
delay(50);
lcdcmd(0x80);
delay(50);
}

void main()
{
char data1,count=0;
lcdint();
TMOD=0x20; // Timer1 Mode2 8 bit auto reload
TH1=0xFD; // 9600 bps
SCON=0x50; // 8 Data bit, 1 start bit, 1 stop bit 
TR1=1; // Timer1 ON
while(1)
{

while(SBUF!=0x0D)//Checking if enter key is pressed
{

while(RI==0);
{
data1=SBUF;
count++;
if(count=1)
{
RI=0;
display(data1);
delay(50);
data1=SBUF;
RI=0;
delay(50);
}
else if(count>5)
{
lcdcmd(0x0C);	

count++;

RI=0;
display(data1);
delay(50);
data1=SBUF;
RI=0;

delay(50);
	count=0;
}
}
}
}
}
