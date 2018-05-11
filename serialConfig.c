/* serialConfig.h  --  asdf
**        Defaults to ASYNC, 8N1, low speed
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
**    05/06/2002 - Nick Veys
**      - Added most stuff, need broader MCU support, better TX delay.
**      - Reception not implemented, need good methodology first.
*/

#include <pic.h>
#include "serial.h"

void serialConfig(uchar baudrategenval)
{
  TXEN = 0;		// disable serial transmission
  SPEN = 0;		// serial port disabled
  SPBRG = baudrategenval;	// set baud rate generator
  SPEN = 1;		// serial port enabled
  TXEN = 1;		// enable serial transmission
}
