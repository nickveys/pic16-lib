/* max3110Write.c
**
**  Writes 1 byte to the MAX3110's output buffer.  Checks to
**   make sure the buffer is free before transmitting.
**
**  Updates: 
**    05/30/2002 - Nick Veys
**      - Documentation tweaks.
**    02/14/2003 - Nick Veys
**      - Update for modularization.
*/

#include "spi.h"
#include "max3110.h"

void max3110Write(chipselect* cs, uchar c)
{
  max3110SetSPI();				// setup SPI port for MAX3110
  while(!(max3110Status(cs) & 0x4000));	// wait for Tx buffer to be free
  *(cs->port) &= ~cs->mask;		// select MAX3110
  SPISend(0x80);				// write data command
  SPISend(c);					// send the data
  *(cs->port) |= cs->mask;		// de-select MAX3110
}
