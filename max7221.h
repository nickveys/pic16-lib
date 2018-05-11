/* max7221.h  --  Functions for using the MAX7221 LED Display Controller
**
** Functions available:
**    MAX7221_SETSPI()
**      - Sets up SPI port for use w/the MAX7221.
**    MAX7221_WRITE(port, mask, register, value)
**      - Write a value to a register.
**    MAX7221_DECODE(port, mask, decode)
**      - Sets decode-mode.
**    MAX7221_INTENSITY(port, mask, intensity)
**      - Sets intensity of segments.
**    MAX7221_SCAN_LIMIT(port, mask, limit)
**      - Sets scan limit of display.
**    MAX7221_DISPLAY_TEST(port, mask, on)
**      - Sets display into or out of test mode.
**    MAX7221_ENABLE(port, mask)
**      - Enables display.
**    MAX7221_DISABLE(port, mask)
**      - Disables display.
**    MAX7221_INITIALIZE(port, mask, intensity, limit, decode)
**      - Sets up MAX7221 with intensity, limit and decode settings.  REQUIRED!
**
**  Variables port and mask are the data port and bitmask to find
**   the MAX7221 chip-select line.  i.e. if the MAX7221 is on PORTB's
**   bit #7, port = (unsigned char*) &PORTC, mask = 0b10000000 = 0x80.
**   Recommend this be defined in the main program code, not stated every use.
**
**  Updates: 
**    11/11/2002 - Nick Veys
**      - Inital Revision.  Should be complete.
*/

#include "chipselect.h"
#include "defines.h"

#ifndef __MAX7221_H
#define __MAX7221_H

#define DIGIT_0			0x01			// Register Addresses
#define DIGIT_1			0x02
#define DIGIT_2			0x03
#define DIGIT_3			0x04
#define DIGIT_4			0x05
#define DIGIT_5			0x06
#define DIGIT_6			0x07
#define DIGIT_7			0x08
#define DECODE_MODE		0x09
#define INTENSITY		0x0A
#define SCAN_LIMIT		0x0B
#define SHUTDOWN		0x0C
#define DISPLAY_TEST	0x0F

#define max7221SetSPI() SPIConfig(0x40, 0x01)		// SPI Configuration for MAX7221

void max7221Write(chipselect* cs, uchar reg, uchar val);
#define max7221Decode(cs, decode) max7221Write(cs, DECODE_MODE, decode)
#define max7221Intensity(cs, intensity) max7221Write(cs, INTENSITY, intensity)
#define max7221ScanLimit(cs, limit) max7221Write(cs, SCAN_LIMIT, limit)
#define max7221DisplayTest(cs, on) max7221Write(cs, DISPLAY_TEST, on)
#define max7221Enable(cs) max7221Write(cs, SHUTDOWN, 1)
#define max7221Disable(cs) max7221Write(cs, SHUTDOWN, 0)
void max7221Initialize(chipselect* cs, uchar intensity, uchar limit, uchar decode);

#endif
