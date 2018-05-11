/* max3110Status.c  --  asdf
**
**  Variables port and mask are the data port and bitmask to find
**   the MAX3110 chip-select line.  i.e. if the MAX3110 is on PORTB's
**   bit #2, port = (unsigned char*) &PORTC, mask = 0b00000100 = 0x04.
**   Recommend this be defined in the main program code, not stated every use.
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.  Still need to get XTAL choices working.
**    05/01/2002 - Nick Veys
**      - Changed XTAL's to 18432 and 36864.
**    05/06/2002 - Nick Veys
**      - Documentation tweaks.
**    05/30/2002 - Nick Veys
**      - Documentation tweaks.
*/

#include "spi.h"
#include "max3110.h"

uint max3110Status(chipselect* cs)
{
  uint status;
  max3110SetSPI();				// setup SPI port for MAX3110
  *(cs->port) &= ~cs->mask;		// select MAX3110
  status = SPIReceive16();		// get status double-byte
  *(cs->port) |= cs->mask;		// de-select MAX3110
  return status;				// return the status
}
