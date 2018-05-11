/* SPIReceive.c  --  Functions for using the SPI port on PICs that have them.
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
*/

#include <pic.h>
#include "spi.h"

unsigned char SPIReceive()
{
  SSPBUF = 0;
  while(!SSPIF);
  SSPIF = 0;
  return SSPBUF;
}
