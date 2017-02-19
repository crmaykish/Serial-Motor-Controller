#include <inttypes.h>
#include "pins.h"
#include "motors.h"

// Set motor speed and direction
// Takes a motor code (FL, FR, BL, BR) and a speed from -255 to 255
// Negative speed indicates reverse
void motorCommand(char* motor, int speed) {
	if (speed > MOTOR_SPEED_MAX || speed < -MOTOR_SPEED_MAX) {
		printf("Speed out of range: %d\n", speed);
		return;
	}
	
	// Front-Left
	if (strcmp(motor, "FL") == 0) {
		FL_FORWARD = speed >= 0 ? speed : 0;
		FL_REVERSE = speed < 0 ? -speed : 0;
	}
	// Front-Right
	else if (strcmp(motor, "FR") == 0) {
		FR_FORWARD = speed >= 0 ? speed : 0;
		FR_REVERSE = speed < 0 ? -speed : 0;
	}
	// Back-Left
	else if (strcmp(motor, "BL") == 0) {
		BL_FORWARD = speed >= 0 ? speed : 0;
		BL_REVERSE = speed < 0 ? -speed : 0;
	}
	// Back-Right
	else if (strcmp(motor, "BR") == 0) {
		BR_FORWARD = speed >= 0 ? speed : 0;
		BR_REVERSE = speed < 0 ? -speed : 0;
	}
	else {
		printf("Invalid motor: %s\n", motor);
		return;
	}
	
	printf("Setting %s to %d\n", motor, speed);
}