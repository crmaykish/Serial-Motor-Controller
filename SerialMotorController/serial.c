// Reference: http://www.appelsiini.net/2011/simple-usart-with-avr-libc

#include "bitmacros.h"
#include <avr/io.h>
#include <stdio.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef BAUD
#define BAUD 9600
#endif

#define MYUBRR ((F_CPU / 16 / BAUD) - 1)

void serialInit() {
	// Set baud rate
	UBRR0H = (unsigned char) (MYUBRR >> 8);
	UBRR0L = (unsigned char) MYUBRR;

	// Enable transmit and receive
	UCSR0B = bitValue(RXEN0) | bitValue(TXEN0);

	// Set frame format: 8data, 2stop bit
	UCSR0C = bitValue(USBS0) | (3 << UCSZ00);
}

void serialTransmit(char b, FILE *stream) {
	while (!(UCSR0A & bitValue(UDRE0)));
	UDR0 = b;

	if (b == '\n') {
		serialTransmit('\r', stream);
	}
}