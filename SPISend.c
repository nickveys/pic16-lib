/* SPISend.c  --  asdf
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
*/

#include <pic.h>
#include "spi.h"

void SPISend(uchar data)
{
  SSPBUF = data;	// write out to buffer
  while(!SSPIF);	// wait for flag
  SSPIF = 0;		// clear flag
}
