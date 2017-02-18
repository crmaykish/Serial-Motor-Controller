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

void motorSpeed(char* motor, int speed) {
	if (speed > 255 || speed < -255) {
		printf("Speed out of range\n");
		return;
	}
	
	// Front-Left
	if (strcmp(motor, "FL") == 0) {
		// TC3
		OCR3A = 0;
		OCR3B = 0;
		
		if (speed >= 0) {
			OCR3A = speed;
		}
		else {
			OCR3B = -speed;
		}
	}
	// Front-Right
	else if (strcmp(motor, "FR") == 0) {
		// TC0
		OCR0A = 0;
		OCR0B = 0;
		
		if (speed >= 0) {
			OCR0A = speed;
		}
		else {
			OCR0B = -speed;
		}
	}
	// Back-Left
	else if (strcmp(motor, "BL") == 0) {
		// TC2
		OCR2A = 0;
		OCR2B = 0;
		
		if (speed >= 0) {
			OCR2A = speed;
		}
		else {
			OCR2B = -speed;
		}
	}
	// Back-Right
	else if (strcmp(motor, "BR") == 0) {
		// TC1
		OCR1A = 0;
		OCR1B = 0;
		
		if (speed >= 0) {
			OCR1A = speed;
		}
		else {
			OCR1B = -speed;
		}
	}
	else {
		printf("Invalid motor\n");
		return;
	}
	
	printf("Setting %s to %d\n", motor, speed);
}

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
}

// PD4 and PD5 - 16 bit PWM
void setupTC1() {
	DDRD |= bitValue(PORTD4);
	DDRD |= bitValue(PORTD5);
	
	TCCR1A |= bitValue(COM1A1) | bitValue(COM1B1);
	
	TCCR1A |= bitValue(WGM10);
	
	TCCR1B |= bitValue(CS10);
}

// PD6 and PD7 - 8 bit PWM
void setupTC2() {
	DDRD |= bitValue(PORTD6);
	DDRD |= bitValue(PORTD7);
	
	TCCR2A |= bitValue(COM2A1) | bitValue(COM2B1);
	
	TCCR2A |= bitValue(WGM20);
	
	TCCR2B |= bitValue(CS20);
}

// PB6 and PB7 - 16 bit PWM
void setupTC3() {
	DDRB |= bitValue(PORTB6);
	DDRB |= bitValue(PORTB7);
	
	TCCR3A |= bitValue(COM3A1) | bitValue(COM3B1);
	
	TCCR3A |= bitValue(WGM30);
	
	TCCR3B |= bitValue(CS30);
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
		char* motor = strtok(command, ":");
		int speed = atoi(strtok(NULL, "!"));
		
		motorSpeed(motor, speed);
	}
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

