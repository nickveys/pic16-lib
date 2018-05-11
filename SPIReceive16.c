/* SPIReceive16.c  --  adsf
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
*/

#include "spi.h"

uint SPIReceive16()
{
  return((uint)(SPIReceive() << 8) + SPIReceive());
}
