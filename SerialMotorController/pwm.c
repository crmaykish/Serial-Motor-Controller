#include "bitmacros.h"
#include <avr/io.h>
#include <stdio.h>

// PB3 and PB4
void initTC0() {
	// Set output pins
	DDRB |= bitValue(PORTB3);
	DDRB |= bitValue(PORTB4);
	
	// Clear on Compare Match (non-inverting mode)
	TCCR0A |= bitValue(COM0A1) | bitValue(COM0B1);
	
	// Set to Fast PWM mode
	TCCR0A |= bitValue(WGM10);
	
	// Set the prescalar to none
	TCCR0B |= bitValue(CS00);
}

// PD4 and PD5
void initTC1() {
	// Set output pins
	DDRD |= bitValue(PORTD4);
	DDRD |= bitValue(PORTD5);
	
	// Clear on Compare Match (non-inverting mode)
	TCCR1A |= bitValue(COM1A1) | bitValue(COM1B1);
	
	// Set to Fast PWM mode
	TCCR1A |= bitValue(WGM10);
	
	// Set the prescalar to none
	TCCR1B |= bitValue(CS10);
}

// PD6 and PD7
void initTC2() {
	// Set output pins
	DDRD |= bitValue(PORTD6);
	DDRD |= bitValue(PORTD7);
	
	// Clear on Compare Match (non-inverting mode)
	TCCR2A |= bitValue(COM2A1) | bitValue(COM2B1);
	
	// Set to Fast PWM mode
	TCCR2A |= bitValue(WGM20);
	
	// Set the prescalar to none
	TCCR2B |= bitValue(CS20);
}

// PB6 and PB7
void initTC3() {
	// Set output pins
	DDRB |= bitValue(PORTB6);
	DDRB |= bitValue(PORTB7);
	
	// Clear on Compare Match (non-inverting mode)
	TCCR3A |= bitValue(COM3A1) | bitValue(COM3B1);
	
	// Set to Fast PWM mode
	TCCR3A |= bitValue(WGM30);
	
	// Set the prescalar to none
	TCCR3B |= bitValue(CS30);
}

// Initialize all PWM channels to 8-bit Fast PWM
void pwmInit() {
	initTC0();
	initTC1();
	initTC2();
	initTC3();
}