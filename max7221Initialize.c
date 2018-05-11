/* max7221Initialize.c  --  asdf
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

void max7221Initialize(chipselect* cs, uchar intensity, uchar limit, uchar decode)
{
  max7221Disable(cs);				// disable display
  max7221Intensity(cs, intensity);	// set intensity
  max7221ScanLimit(cs, limit);		// set scan limit
  max7221Decode(cs, decode);		// set decode values
  max7221Enable(cs);				// enable display
}
