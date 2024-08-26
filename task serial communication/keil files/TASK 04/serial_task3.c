

#include<STC89xxx.h>
#include<stdio.h>
#include<string.h>


#define LCD_Port P0				/* P2 port as data_port */
sbit rs=P2^6;							/* Register select pin */
sbit rw=P2^5;							/* Read/Write pin */
sbit en=P2^7;							/* Enable pin */

unsigned char i;
unsigned char y;
unsigned char k;


unsigned char hour[2];
unsigned char Mints[2];
unsigned char sec[2];
unsigned char colon;
unsigned char Mystring[8];



																								/* Function to provide delay Approx 1ms with 12 Mhz crystal*/
void delay(unsigned int count)    		
{
     int i,j;
     for(i=0;i<count;i++)
     for(j=0;j<114;j++);
}

void LCD_Command (char cmnd)										/* LCD16x2 command funtion */
{
	LCD_Port =cmnd;	/* Send upper nibble */
	rs=0;																					/* Command reg. */
	rw=0;																					/* Write operation */
	en=1; 
	delay(1);
	en=0;
	delay(2);
}

void LCD_Char (char char_data)  										/* 	LCD_data write function */
{

	LCD_Port =char_data;/*  Send upper nibble */
	rs=1;  																						/*	Data reg.*/
	rw=0;  																						/*Write operation*/
	en=1;  
	delay(1);
	en=0;
	delay(2);
}

void LCD_String (char *str)					/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  					/* Send each character of string till the NULL */
	{
		LCD_Char (str[i]); 							/* Call LCD_data write */
	}
}

void LCD_String_xy (char row, char pos, char *str)  /* Send string to LCD function */
{
	if (row == 0)
	LCD_Command((pos & 0x0F)|0x80);
	else if (row == 1)
	LCD_Command((pos & 0x0F)|0xC0);
	LCD_String(str);  																/* Call LCD string function */
}

void LCD_Init (void)								/* LCD Initialize function */
{
	delay(20);												/* LCD Power ON Initialization time >15ms */
	delay(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Command (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);	/* Display ON Cursor OFF */
	LCD_Command (0x06);	/* Auto Increment cursor */
	LCD_Command (0x01);	/* clear display */
	LCD_Command (0x80);	/* cursor at home position */
}
void main()
{
	int w,x,y,z;
LCD_Init();	

	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	PCON=0x00;
	TR1=1;
	while(1)
	{ 
	
	for(i=0;i<8;i++)
		{while(RI==0);
			RI=0;
			Mystring[i]=SBUF;
		}

		
		for(x=0,y=0,z=0,w=0; w<2,x<2,y<2,z<2;w++,x++,y++,z++)
		{
			hour[w]=Mystring[z];
			Mints[x]=Mystring[z+3];
			sec[y]=Mystring[z+6];
			colon=Mystring[(z*3)+2];
		}
		
		
		for(i=0;i<1;i++)
		{
			LCD_Command(0x01);
			LCD_Command(0x80);
				LCD_Char(hour[i]);
				LCD_Char(hour[i+1]);
				LCD_Char(colon);
				LCD_Char(Mints[i]);
				LCD_Char(Mints[i+1]);
				LCD_Char(colon);
				LCD_Char(sec[i]);
				LCD_Char(sec[i+1]);
			
		}
				
		}	
	}
