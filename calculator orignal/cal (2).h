#define lcd P0
sbit r0 = P1^0;
sbit r1 = P1^1;
sbit r2 = P1^2;
sbit r3 = P1^3;
sbit c0 = P1^4;
sbit c1 = P1^5;
sbit c2 = P1^6;
sbit c3 = P1^7;
sbit rs = P2^6;
sbit rw = P2^5;
sbit en = P2^7;
char scan_key();
void delay(unsigned char);
void send_num(unsigned int);
void calculate();

int r0w_scan();
void lcd_initt();
void lcd_cmd(unsigned char);
void lcd_dat(unsigned char);
void msdelay(unsigned char);
void lcd_stringg(unsigned char *);

//lcd initialization
void calcbody();