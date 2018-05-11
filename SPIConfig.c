/* SPIConfig.c  --  asdf
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
*/

#include <pic.h>
#include "spi.h"

void SPIConfig(uchar stat, uchar con)
{
  SSPEN = 0;		// disable SPI port for reconfiguration
  SSPSTAT = stat;	// set SSPSTAT
  SSPCON  = con;	// set SSPCON
  SSPEN = 1;		// re-enable SPI port
}
