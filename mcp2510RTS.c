/* mcp2510RTS.c
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
**    05/30/2002 - Nick Veys
**      - Added SPI_SETUP's to a few functions.
**      - Small documentation tweaks.
**    10/25/2002 - Nick Veys
**      - Added transmission routines.  NEED OPTIMIZATION!!
**    10/26/2002 - Nick Veys
**      - Optimized transmission routines. :)
**      - Added WRITE_SEQUENCE function.
*/

#include "spi.h"
#include "mcp2510.h"

void mcp2510RTS(chipselect* cs, uchar rtsnum)
{
  mcp2510SetSPI();				// setup SPI port for MCP2510
  *(cs->port) &= ~cs->mask;		// select MCP2510
  SPISend(rtsnum);				// must be RTS0, RTS1 or RTS2
  *(cs->port) |= cs->mask;		// de-select MCP2510
}
