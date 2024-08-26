// the #ifndef prevents the file from being included more than once
#ifndef __LCD_H__   
#define __LCD_H__
 #define  ADR_WR_CREG    0x8E  //Control Register Write
#define  ADR_RD_CREG    0x8F  //Control Register Read
#define  ADR_WR_TCR     0x90  //Trickle Charge Register Write
#define  ADR_RD_TCR     0x91  //Trickle Charge Register Read
#define  ADR_WR_BURST   0xBE  //Burst Write
#define  ADR_RD_BURST   0xBF  //Burst Read

#define  ADR_WR_SEC    0x80  //Seconds Write
#define  ADR_RD_SEC    0x81  //Seconds Read
#define  ADR_WR_MIN    0x82  //Mins Write
#define  ADR_RD_MIN    0x83  //...
#define  ADR_WR_HR    0x84
#define  ADR_RD_HR    0x85
#define  ADR_WR_DATE    0x86
#define  ADR_RD_DATE    0x87
#define  ADR_WR_MON    0x88
#define  ADR_RD_MON    0x89
#define  ADR_WR_DAY    0x8A
#define  ADR_RD_DAY    0x8B
#define  ADR_WR_YR    0x8C
#define  ADR_RD_YR    0x8D 
void lcdcmd(unsigned char);

 void lcddata(unsigned char);
void MSDelay(unsigned int);
void disp_num(float num);
int get_num(char ch);
void lcdinit();
char scan_key(void);
void	string (char *str)	;



int clock_data[8];
int temp_byte[8];
int temp;
int x;
unsigned int i;
unsigned int j;
char array[32];
char jj=0,ii=0,kk=0;

unsigned char sec,min,hour,day,month,year;
void time();
int calculator();
void LCD_Init();
void lcd_WriteCmd( char cmd);
void lcd_Writedata( char a);
void lcd_DisplayString(char *string_ptr);
void lcd_DisplayNumber(unsigned int num);
void lcd_ScrollMessage(char *msg_ptr);
void lcd_DisplayRtcTime(char hour,char min,char sec);
void lcd_DisplayRtcDate(char day,char month,char year);
void lcd_Clear();
void lcd_GoToLineOne();
void lcd_GoToLineTwo();
void lcd_GoToXY(char row, char col);
 
#endif 