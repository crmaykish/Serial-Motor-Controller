#ifndef PINS_H_
#define PINS_H_

#include <avr/io.h>

#define FL_FORWARD		OCR3A
#define FL_REVERSE		OCR3B

#define FR_FORWARD		OCR0A
#define FR_REVERSE		OCR0B

#define BL_FORWARD		OCR2A
#define BL_REVERSE		OCR2B

#define BR_FORWARD		OCR1A
#define BR_REVERSE		OCR1B

#endif /* PINS_H_ */