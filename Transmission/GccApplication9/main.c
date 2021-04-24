
#include <avr/io.h>
#include <util/delay.h>

void init(unsigned char UBBR_Value)
{
	
	UBRRH = (unsigned char) (UBBR_Value >> 8);
	UBRRL = (unsigned char) UBBR_Value;
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<< USBS) | (3<<UCSZ0);
	
}

int main()
{
	DDRB = 0xff;
	DDRA = 0x00;
	
	DDRD |= (1<<PIND1);
    DDRD &= ~(1<<PIND0);
	//PORTD |= 1 << PIND1;
	PORTD |= 1 << PIND0;
	
	init(25);
	while (1) 
    {
		PORTB = 0b00000001;
		if(bit_is_set(PINA,4))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='1';
			}
			_delay_ms(1000);
		}
		
		else if(bit_is_set(PINA,3))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='4';
			}
			_delay_ms(1000);
			
			
		}
		
		else if(bit_is_set(PINA,2))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='7';
			}
			_delay_ms(1000);
		}
	
		else if(bit_is_set(PINA,1))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='*';
			}
			_delay_ms(1000);
		}
			
		
		
		PORTB = 0b00000010;
		if(bit_is_set(PINA,4))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='2';
			}
			_delay_ms(1000);
		}
		
		else if(bit_is_set(PINA,3))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='5';
			}
			_delay_ms(1000);
		}
		else if(bit_is_set(PINA,2))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='8';
			}
			_delay_ms(1000);
		}
		
		else if(bit_is_set(PINA,1))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR =' ';
			}
			_delay_ms(1000);
		}
		
		
		
		PORTB = 0b00000100;
		if(bit_is_set(PINA,4))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='3';
			}
			_delay_ms(1000);
		}
		
		else if(bit_is_set(PINA,3))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='6';
			}
			_delay_ms(1000);
		}
		
		else if(bit_is_set(PINA,2))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR ='9';
			}
			_delay_ms(1000);
		}
		
		else if(bit_is_set(PINA,1))
		{
			while(!(UCSRA &(1<<UDRE)));
			{
				UDR = '#';
			}
			_delay_ms(1000);
		}
		
    }
}
	


