/* serialSend16.c  --  asdf
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

void serialSend16(uint data)
{
  serialSend((uchar)((data & 0xFF00) >> 8));
  serialSend((uchar)(data & 0x00FF));
}
