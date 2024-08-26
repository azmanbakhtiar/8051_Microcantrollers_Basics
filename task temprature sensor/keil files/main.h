#ifndef temp 
#define temp
//kcd
void lcd_init(void);
void lcd_write(unsigned char);
void LCD_Command (unsigned char);
void delay1(unsigned int);
void lcd_string(unsigned char *);

//DS18B20 temperature sensor & buzzer
void ow_reset(void);
unsigned char read_byte(void);
void write_byte(char);

void Read_Temperature(void);
void hex2lcd(unsigned char hex);

//SSD
void display_num_7seg(unsigned char);
void values_on_ssd(void);

// serial
void display_num_serial(unsigned int);
void serial_data(void);
#endif 