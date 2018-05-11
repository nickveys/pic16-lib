/* max7221Write.c  --  asdf
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

#include "spi.h"
#include "max7221.h"

void max7221Write(chipselect* cs, uchar reg, uchar val)
{
  max7221SetSPI();					// setup SPI port for MAX7221
  *(cs->port) &= ~cs->mask;			// select MAX7221
  SPISend16((uint)((reg<<8)+val));	// send value
  *(cs->port) |= cs->mask;			// de-select MAX7221
}
