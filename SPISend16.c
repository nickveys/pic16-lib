/* SPISend16.c  --  asdf
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
*/

#include "spi.h"

void SPISend16(uint data)
{
  SPISend((uchar)((data & 0xFF00) >> 8));
  SPISend((uchar)(data & 0x00FF));
}
