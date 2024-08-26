#ifndef Main_H
#define Main_H

// EEPROM
void save();
void start();
void stop();
void aknowledge();
void send_byte(unsigned char);
unsigned char Read();
unsigned char read_byte();
void delay(unsigned int);

//SSD
void display_num_7seg(unsigned char);
void timer_init();

#endif