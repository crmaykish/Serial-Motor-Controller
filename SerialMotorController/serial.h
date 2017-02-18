#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdio.h>

void serialInit();
void serialTransmit(char b, FILE *stream);

FILE uartOut = FDEV_SETUP_STREAM(serialTransmit, NULL, _FDEV_SETUP_WRITE);

#endif /* SERIAL_H_ */