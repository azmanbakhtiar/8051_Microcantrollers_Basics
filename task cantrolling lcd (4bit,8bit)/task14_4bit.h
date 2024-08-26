#include<reg51.h>

sbit rs=P2^6;
sbit rw=P2^5;
sbit en=P2^7;


/* Function to provide delay Approx 1ms with 11.0592 Mhz crystal*/
void delay(unsigned int count)    		
{
     int i,j;
     for(i=0;i<count;i++)
     for(j=0;j<112;j++);
}

void LCD_Command (char cmnd)	/* LCD16x2 command funtion */
{
	P0 =(P0 & 0x0F) | (cmnd & 0xF0);/* Send upper nibble */
	rs=0;			/* Command reg. */
	rw=0;			/* Write operation */
	en=1; 
	delay(1);
	en=0;
	delay(2);
	
	P0 = (P0 & 0x0F) | (cmnd << 4);/* Send lower nibble */
	en=1;			/* Enable pulse */
	delay(1);
	en=0;
	delay(5);
}

void LCD_Char (char char_data)  /* LCD data write function */
{
	P0 =(P0 & 0x0F) | (char_data & 0xF0);/* Send upper nibble */
	rs=1;  			/*Data reg.*/
	rw=0;  			/*Write operation*/
	en=1;  
	delay(1);
	en=0;
	delay(2);

	P0 = (P0 & 0x0F) | (char_data << 4);/* Send lower nibble */
	en=1;  			/* Enable pulse */
	delay(1);
	en=0;
	delay(5);

}

void LCD_String (char *str)	/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);  /* Call LCD data write */
	}
}

void LCD_String_xy (char row, char pos, char *str)  /* Send string to LCD function */
{
	if (row == 0)
	LCD_Command((pos & 0x0F)|0x80);
	else if (row == 1)
	LCD_Command((pos & 0x0F)|0xC0);
	LCD_String(str);  	/* Call LCD string function */
}

void LCD_Init (void)		/* LCD Initialize function */
{
	delay(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Command (0x02);	/* 4bit mode */
	LCD_Command (0x28);	/* Initialization of 16X2 LCD in 4bit mode */
	LCD_Command (0x0C);	/* Display ON Cursor OFF */
	LCD_Command (0x06);	/* Auto Increment cursor */
	LCD_Command (0x01);	/* clear display */
	LCD_Command (0x80);	/* cursor at home position */
}

