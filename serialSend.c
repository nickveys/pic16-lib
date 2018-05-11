/* serialSend.c  --  asdf
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

void serialSend(uchar data)
{
  TXREG = data;	// Load buffer (initiates transfer)
  while(!TRMT);	// Poll for shift register empty
}
