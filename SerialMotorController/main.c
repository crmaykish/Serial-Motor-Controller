#include <avr/io.h>
#include "bitmacros.h"
#include "serial.h"
#include <stdio.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

int i = 0;

void setup() {
	serialInit();

	// Redirect stdout to the UART
	stdout = &uartOut;
}

// Read all sensors and output JSON over serial
void loop() {
	printf("Hello: %d\n", i);
	i++;
	_delay_ms(1000);
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}

