/* max541SetValue.c
**
**  Updates: 
**    12/07/2002 - Nick Veys
**      - Inital Revision.
**    04/03/2003 - Nick Veys
**      - Updated to use chipselect
*/

#include "spi.h"
#include "max541.h"

void max541SetValue(chipselect* cs, uint val)
{
  max541SetSPI();				// setup SPI port for MAX541
  *(cs->port) &= ~cs->mask;		// select MAX541
  SPISend16(val);				// send the value
  *(cs->port) |= cs->mask;		// de-select MAX541
}
