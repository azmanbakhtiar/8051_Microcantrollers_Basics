#include<reg51.h>
#include "temprature.h"
#define LCD_data P0

sbit En=P2^7;
sbit Rs=P2^6;
sbit Wr=P2^5;

sbit r0=P1^0;
sbit r1=P1^1;
sbit r2=P1^2;
sbit r3=P1^3;
sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;
sbit c3=P1^7;


int get_num(char ch) ;
unsigned int indexx=0;
unsigned char temp_lsb=0,temp_msb=0;
unsigned char Unite,Ten,Hunderd,intpart,decpart;
char temp_f;
unsigned char temp_c;
sbit DQ= P3^7;
sbit buzzer_pin=P1^5;
unsigned char Unite1,Ten1,Hunderd1;
unsigned char j=0;
unsigned char z;
unsigned char serial_values[5]={0};
	unsigned int  k2,k1,p,ch1,ch2;
	char scan_key();

void ow_reset(void)
{
DQ = 1; //pull DQ line low
delay_18B20(8); // leave it low for 480us
DQ = 0; // allow line to return high
delay_18B20(65); // wait for presence
DQ=1;
delay_18B20(20);    
} // 

// delay
void delay_18B20(unsigned int ud){
    while(ud--); //
}

// READ_BYTE - reads a byte from the one-wire bus.
unsigned char read_byte(void)
{
    unsigned char i=0;
    unsigned char dat = 0;
    for (i=8;i>0;i--){
          DQ = 0;
          dat>>=1;
          DQ = 1;
          if(DQ)
          dat |= 0x80;
          delay_18B20(4);
    }
    return(dat);
}

// WRITE_BYTE - writes a byte to the one-wire bus.
void write_byte(char dat)
{
    unsigned char i=0;
    for (i=8; i>0; i--){
        DQ = 0;
        DQ = dat&0x01;
        delay_18B20(5);
        DQ = 1;
        dat>>=1;
    }
}

void Read_Temperature(void)
{
ow_reset();
write_byte(0xCC); //Skip ROM
write_byte(0x44); // Start Conversion
delay_18B20(10); 
ow_reset();
write_byte(0xCC); // Skip ROM
write_byte(0xBE); // Read Scratch Pad
delay_18B20(10);
	
temp_msb = read_byte(); // Sign byte + lsbit
temp_lsb = read_byte(); // Temp data plus lsb

temp_c = ((temp_lsb*256+temp_msb)>>4);
temp_f = (((int)temp_c)* 9)/5 + 32;

}
void hex2lcd(unsigned char z){

	Hunderd=(z/100) + 0x30; //hundred
	Ten=(z%100/10) + 0x30; //ten
	Unite=(z%10) + 0x30; //uni
	intpart = (int)z;
  decpart = (z - intpart) + 0x30;
	lcd_write(Hunderd);
	lcd_write(Ten);
	lcd_write(Unite);
	lcd_string(".");
	lcd_write(decpart);
}
void timer0_intrupt (void) interrupt 1   // called after 50 ms 
{
	indexx+=1;
	if(indexx==400)
	{
  LCD_Command(0x80);
	lcd_string("Temprature is:");
	LCD_Command(0xc0);
  Read_Temperature();
	hex2lcd(temp_c);

	lcd_string(" C");
	indexx=0;
	}
	display_num_7seg(temp_c);
	values_on_ssd();
  
	if(temp_c>=p)
	{
		buzzer_pin=0;
		delay1(2);
		buzzer_pin=1;
		
	}
	buzzer_pin=1;
	TH0=0xFC;
	TL0=0x18;
}

void main()
{

  lcd_init();
	lcd_string("Enter Thershold ");
		LCD_Command (0xC0);
	ch1=scan_key();
  k2=get_num(ch1);
	ch2=scan_key();
  k1=get_num(ch2);
	p=(k2*10)+k1;

	
	
	LCD_Command (0x38);
	while(1)
	{
	
	
	delay_18B20(65);
	IE=0x82; // enable timer 0 interrupt and serial interrupt

	TMOD = 0x21; // using timer0 in mode1 and timer1 in mode2
	SCON=0x50; // Asyncronous mode, 8-bit and 1-stop bit
	TH1=0xFD;
	TH0=0xFC;
	TL0=0x18;
	TR0=1;
	TR1=1;
while(1)
	{
	  display_num_serial(temp_c);
    serial_data();
//	
	}
}

}


void lcd_init()
{
	delay1(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Command (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Command (0x0E);	/* Display ON Cursor blinking */
	LCD_Command (0x06);	/* Auto Increment cursor */
	LCD_Command (0x01);	/* clear display */
	LCD_Command (0x80);	/* cursor at home position */

}
void lcd_string(unsigned char *lcd_data)
{
   while(*lcd_data)
   {
   lcd_write(*lcd_data++);
   }

}

void LCD_Command (unsigned char cmd)	
{
	LCD_data= cmd;
	Rs=0;				/* command reg. */
	Wr=0;				/* Write operation */
	En=1; 
	delay1(1);
	En=0;
	delay1(5);
}
void lcd_write(unsigned char lcd_data)
{
LCD_data=lcd_data;
Rs=1;
Wr=0;
En=1;
delay1(1);
En=0;

}
void delay1(unsigned int count)  /* Function to provide delay Approx 1ms */
{
	int i,j;
	for(i=0;i<count;i++)
	for(j=0;j<112;j++);
}



unsigned char index=0;
unsigned int select[]  =  {0x0C,0x08,0x04,0x00};
unsigned int message[] = {0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
unsigned char values[4];

void display_num_7seg(unsigned char num)
{
 int i=3;
 while(num!=0)
 {
  values[i]=num%10;
	 num=num/10;
	 i--;
 }
 
 }
void values_on_ssd(void)
 {
  switch(values[index])
	{
		case 0:
		   {
			 P2=select[index];
			 P0=message[0];		 
			 }
	     break;
		case 1:
		   {
			 P2=select[index];
			 P0=message[1];		 
			 }
	     break;
		case 2:
		   {
			 P2=select[index];
			 P0=message[2];		 
			 }
	     break;
		case 3:
		   {
			  P2=select[index];
			 P0=message[3];		 
			 }
	     break;
		case 4:
		   {
			 P2=select[index];
			 P0=message[4];		 
			 }
	     break;
		case 5:
		   {
			  P2=select[index];
			 P0=message[5];		 
			 }
	     break;
		case 6:
		   {
			  P2=select[index];
			 P0=message[6];		 
			 }
	     break;
		case 7:
		   {
			 P2=select[index];
			 P0=message[7];		 
			 }
	     break;
		case 8:
		   {
			 P2=select[index];
			 P0=message[8];		 
			 }
	     break;
		case 9:
		   {
			 P2=select[index];
			 P0=message[9];		 
			 }
	     break;
	default:
		break;
	}
 index+=1;
	if(index > 3)
					{
						index=0;
					}
				}


	
void display_num_serial(unsigned int z)
{
	Hunderd1=(z/100) + 0x30; //hundred
	Ten1=(z%100/10) + 0x30; //ten
	Unite1=(z%10) + 0x30; //unit
	serial_values[0]= Hunderd1;
	serial_values[1]= Ten1;
	serial_values[2]= Unite1;
	serial_values[3]='\n';
 }
void serial_data(void)
	{
	 for(z=0;z<6;z++)
	 {
	 SBUF=serial_values[z];
		 while(TI==0);
		  TI=0;
	    delay1(100);
	 }


//	while(arr[i]!='\0')
//{
//  SBUF=arr[i];
//	while (TI==0);
//	TI=0;	
//	i++;
//}
//delay1(100);
//i=0;
 }

char scan_key()
{
unsigned char c;
c='s';
while(!(c=='0' && c=='1' &&  c=='2' && c=='3' && c=='4' && c=='5' && c=='6' && c=='7' && c=='8'
 && c=='9' && c=='+' && c=='-' && c=='=' && c=='$' && c=='*' && c=='/' ))
{
r0=0;r1=1;r2=1;r3=1;
if(c0==0 && r0==0 ){lcddata('/');MSDelay(10000);return c='/';}
    if(c1==0 && r0==0){ lcddata('*');MSDelay(10000);return c= '*';}
if(c2==0 && r0==0){ lcddata('-');MSDelay(10000);return c= '-';}
if(c3==0 && r0==0){ lcddata('+');MSDelay(10000);return c= '+';}
  
r0=1;r1=0;r2=1;r3=1;

if(c0==0 && r1==0){ lcddata('=');MSDelay(10000);return c= '=';}
    if(c1==0 && r1==0){ lcddata('9');MSDelay(10000);return c= '9';}
if(c2==0 && r1==0){ lcddata('6');MSDelay(10000);return c= '6';}
if(c3==0 && r1==0){ lcddata('3');MSDelay(10000);return c= '3';}

r0=1;r1=1;r2=0;r3=1;

if(c0==0 && r2==0){ lcddata('0');MSDelay(10000);return c= '0';}
    if(c1==0 && r2==0){ lcddata('8');MSDelay(10000);return c= '8';}
if(c2==0 && r2==0){ lcddata('5');MSDelay(10000);return c= '5';}
if(c3==0 && r2==0){ lcddata('2');MSDelay(10000);return c= '2';}

r0=1;r1=1;r2=1;r3=0;

if(c0==0 && r3==0){ lcddata('*');MSDelay(10000);return c= '*';}
    if(c1==0 && r3==0){ lcddata('7');MSDelay(10000);return c= '7';}
if(c2==0 && r3==0){ lcddata('4');MSDelay(10000);return c= '4';}
if(c3==0 && r3==0){ lcddata('1');MSDelay(10000);return c= '1';}
}
return 0;
}
void MSDelay(unsigned int itime)
  {
    unsigned int i, j;
    for(i=0;i< itime;i++)           
      for(j=0;j<5;j++);       
  }
void lcdcmd(unsigned char value)
  {
    P0 = value;      
    Rs = 0;
    Wr = 0;
    En = 1;            
    MSDelay(50);
    En = 0;
MSDelay(50);
    
  }
void lcddata(unsigned char value)
  {
   P0 = value;  
    Rs = 1;
    Wr = 0;
    
		En = 1;          
    MSDelay(50);
    En = 0;
    MSDelay(50);
  }

int get_num(char ch)         //convert char into int
{
switch(ch)
{
case '0': return 0; break;
case '1': return 1; break;
case '2': return 2; break;
case '3': return 3; break;
case '4': return 4; break;
case '5': return 5; break;
case '6': return 6; break;
case '7': return 7; break;
case '8': return 8; break;
case '9': return 9; break;
}
return 0;
}


