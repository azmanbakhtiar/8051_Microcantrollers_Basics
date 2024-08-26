#include<reg51.h>
#include "main.h"

unsigned int indexx=0;
unsigned char temp_lsb=0,temp_msb=0;
unsigned char Unite,Ten,Hunderd,intpart,decpart;
char temp_f;
unsigned char temp_c;
sbit DQ= P3^7;
sbit buzzer_pin=P1^5;

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
  
	if(temp_c>=28)
	{
		buzzer_pin=0;
		delay1(2);
		buzzer_pin=1;
		delay1(2);
	}
	buzzer_pin=1;
	TH0=0xFC;
	TL0=0x18;
}

void main()
{
  lcd_init();
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
