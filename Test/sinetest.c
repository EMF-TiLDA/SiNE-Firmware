#define F_CPU 8000000UL
#define USART_BAUDRATE 9600

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/eeprom.h>

#include "macros.h"
#include "sinetest.h"

int x;

void setup()
{
	bit_set(DDRA, SR_CLK_PIN);
	bit_set(DDRA, SR_CLR_PIN);
	bit_set(DDRA, SR_A_PIN);
	bit_set(DDRA, LED_C5_PIN);
	bit_clear(PORTA, LED_C5_PIN);
	bit_clear(SR_CLR_PORT, SR_CLR_PIN);
	_delay_ms(1);	
	bit_set(SR_CLR_PORT, SR_CLR_PIN);
	_delay_ms(1);
	bit_clear(SR_A_PORT, SR_A_PIN);
	for(x = 4; x > 0; x--)
	{
		bit_set(SR_CLK_PORT, SR_CLK_PIN);
		_delay_ms(1);	
		bit_clear(SR_CLK_PORT, SR_CLK_PIN);
		_delay_ms(1);
	}
	bit_set(SR_A_PORT, SR_A_PIN);
	for(x = 4; x > 0; x--)
	{
		bit_set(SR_CLK_PORT, SR_CLK_PIN);
		_delay_ms(1);	
		bit_clear(SR_CLK_PORT, SR_CLK_PIN);
		_delay_ms(1);
	}
}

void loop()
{
	
	_delay_ms(200);
}

/**
 * Main to allow arduino-style setup and main functions
 */
int main(void)
{
    setup();
    while (1)
    {
        loop();
    }
}
