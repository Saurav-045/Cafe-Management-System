/*
 * GccApplication11.c
 *
 * Created: 15-04-2021 18:21:04
 * Author : acer
 */ 

#include <avr/io.h>
#include <util/delay.h>

void enable()
{
	PORTA |= 1<<2;
	_delay_ms(3);
	PORTA &= ~(1<<2);
}
void give_command(unsigned char cmd)
{
	DDRB = 0x00;
	PORTA |= 1<<1;
	PORTA &= ~(1<<0);
	while(PINB >= 0x80)
	{
		enable();
	}
	DDRB = 1;
	PORTB = cmd;
	PORTA &= ~(1<<0|1<<1);
	enable();
	PORTB = 0;
}
void receive_data(unsigned char receive)
{
	DDRB = 0x00;
	PORTA |= 1<<1;
	PORTA &= ~(1<<0);
	while(PINB >= 0x80)
	{
		enable();
	}
	DDRB = 1;
	PORTB = receive;
	PORTA |= 1<<0;
	PORTA &= ~(1<<1);
	enable();
	PORTB = 0;
	receive = '0';
}

void LCD_Init()
{
	give_command(0x01);
	_delay_ms(3);
	give_command(0b00111000);
	_delay_ms(3);
	give_command(0b00001110);
	_delay_ms(3);
	
}

void init(unsigned char UBBR_Value)

{
	
	UBRRH = (unsigned char) (UBBR_Value >> 8);
	UBRRL = (unsigned char) UBBR_Value;
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<< USBS) | (3<<UCSZ0);
}

int main(void)
{
	DDRA = 0b11111111;
	DDRD |= (1<<PIND0);
	DDRD &= ~(1<<PIND0);
	init(25);
	LCD_Init();
	unsigned char receiveData;
	
    while (1) 
    {
		while(!(UCSRA &(1<<RXC)));
		{
			receiveData = UDR;
			receive_data(receiveData);
			_delay_ms(200);
		}
    }
}

