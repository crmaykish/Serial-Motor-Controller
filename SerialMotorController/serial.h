#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdio.h>

void serialInit();
void serialTransmit(char b, FILE *stream);
void serialReceive(FILE *stream);

FILE uartOut = FDEV_SETUP_STREAM(serialTransmit, NULL, _FDEV_SETUP_WRITE);
FILE uartIn = FDEV_SETUP_STREAM(NULL, serialReceive, _FDEV_SETUP_READ);

#endif /* SERIAL_H_ */