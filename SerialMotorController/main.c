#include <avr/io.h>
#include "bitmacros.h"
#include "serial.h"
#include <stdio.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define INPUT_BUFFER_SIZE 32

char command[INPUT_BUFFER_SIZE];

// PB3 and PB4 - 8 bit PWM
void setupTC0() {
	// Set output pins
	DDRB |= bitValue(PORTB3);
	DDRB |= bitValue(PORTB4);
	
	// Clear on Compare Match (non-inverting mode)
	TCCR0A |= bitValue(COM0A1) | bitValue(COM0B1);
	
	// Set to Fast PWM mode
	TCCR0A |= bitValue(WGM10);
	
	// Set the prescalar to none
	TCCR0B |= bitValue(CS00);
	
	// Set the duty cycle (0-255)
	OCR0A = 127;	// pin b 3
	OCR0B = 63;		// pin b 4
}

// PD4 and PD5 - 16 bit PWM
void setupTC1() {
	DDRD |= bitValue(PORTD4);
	DDRD |= bitValue(PORTD5);
	
	TCCR1A |= bitValue(COM1A1) | bitValue(COM1B1);
	
	TCCR1A |= bitValue(WGM10);
	
	TCCR1B |= bitValue(CS10);
	
	OCR1A = 127;
	OCR1B = 63;
}

// PD6 and PD7 - 8 bit PWM
void setupTC2() {
	DDRD |= bitValue(PORTD6);
	DDRD |= bitValue(PORTD7);
	
	TCCR2A |= bitValue(COM2A1) | bitValue(COM2B1);
	
	TCCR2A |= bitValue(WGM20);
	
	TCCR2B |= bitValue(CS20);
	
	OCR2A = 127;
	OCR2B = 63;
}

// PB6 and PB7 - 16 bit PWM
void setupTC3() {
	DDRB |= bitValue(PORTB6);
	DDRB |= bitValue(PORTB7);
	
	TCCR3A |= bitValue(COM3A1) | bitValue(COM3B1);
	
	TCCR3A |= bitValue(WGM30);
	
	TCCR3B |= bitValue(CS30);
	
	OCR3A = 127;
	OCR3B = 63;
}

void setup() {
	serialInit();

	// Redirect stdout to the UART
	stdout = &uartOut;
	
	// Redirect stdin to UART
	stdin = &uartIn;

	setupTC0();
	setupTC1();
	setupTC2();
	setupTC3();
}

void loop() {
	// Watch for input commands over serial
	while(fgets(command, INPUT_BUFFER_SIZE, stdin)) {
		printf("Executing: %s\n", command);
	}
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

