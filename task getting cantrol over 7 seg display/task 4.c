#include<reg51.h>
sbit A=P2^4;
sbit b=P2^3;
sbit C=P2^2;
unsigned int input[]={1,4,0,0,0,0,0,8};
//0x00,0x80,0x04,0xC0,0x02,0x0A,0x06,0x0E
unsigned int kk[]={0x03,0x0D,0x08,0x04,0x00,0X02};
 char z;
unsigned int message[] = {0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,};
unsigned char x;
unsigned int i;
int	array[]={1,2,3,4,5};
void delay(void);
void fun(unsigned char);

void main (void)
{
	while(1)
	{

       A=1 ; b=1 ; C=1;
	   
	     fun(0);
	      A=1 ; b=1 ; C=0;
	     
	     fun(1);
		  A=1 ; b=0 ; C=1;
	   
	     fun(2);
	      A=1 ; b=0 ; C=0;
	     
	     fun(3);
		  A=0 ; b=1 ; C=1;
	   
	     fun(4);
	      A=0 ; b=1 ; C=0;
	     
	     fun(5);
		  A=0 ; b=0 ; C=1;
	   
	     fun(6);
	      A=0 ; b=0 ; C=0;
	     
	     fun(7);
	}
	}
void delay(void)
{

	for( i=0;i<500;i++);
		for( i=0;i<10000;i++);

}
void fun(unsigned char x)
{
	z=x;

{
 if(input[x]==1)
    {
	
     
	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[1];
		       	delay();
		
	      }
    }
 if(input[x]==0)
    {
	

	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[0];
		       	delay();
		
	      }
    }
 if(input[x]==2)
    {
	
	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[2];
		       	delay();
		
	      }
    }
 if(input[x]==3)
    {
	
  
	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[3];
		       	delay();
		
	      }
    }
 if(input[x]==4)
    {
	
	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[4];
		       	delay();
		
	      }
    }
 if(input[x]==5)
    {

	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[5];
		       	delay();
		
	      }
    }
 if(input[x]==6)
    {
	

 	for(z=0;z<10;z++)
		    {
          P0=message[6];
		       	delay();
		
	      }
    }
 if(input[x]==7)
    {
	

	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[7];
		       	delay();
		
	      }
    }
 if(input[x]==8)
    {
	
   
	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[8];
		       	delay();
		
	      }
    }
 if(input[x]==9)
    {
	

	     
	     	for(z=0;z<10;z++)
		    {
          P0=message[9];
		       	delay();
		
	      }
    }
	}
//kk[0];
}
