
#define lcd P0
sbit IR=P3^2;
sbit rs=P2^6; //register select
sbit rw=P2^5; //RW
sbit ENABLE=P2^7; //ENABLEable
sbit led = P2^0;


void lcd_init();
void lcmd(unsigned char);
void dat(unsigned char);
void signal_delay();
void string(char *s);