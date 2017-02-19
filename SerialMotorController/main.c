#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "bitmacros.h"
#include "serial.h"
#include "pwm.h"
#include "pins.h"
#include "motors.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define INPUT_BUFFER_SIZE 32

char command[INPUT_BUFFER_SIZE];

void setup() {
	serialInit();
	pwmInit();

	// Redirect stdout to the UART
	stdout = &uartOut;
	
	// Redirect stdin to UART
	stdin = &uartIn;
}

void loop() {
	// Watch for input commands over serial
	while(fgets(command, INPUT_BUFFER_SIZE, stdin)) {
		// Tokenize input commands
		char* motor = strtok(command, ":");
		int speed = atoi(strtok(NULL, "!"));
		
		// Update motor speed
		motorCommand(motor, speed);
	}
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

