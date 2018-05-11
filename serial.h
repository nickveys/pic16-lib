/* serial.h  --  Functions for using the UART on PICs that have them.
**        Defaults to ASYNC, 8N1, low speed
**
** Functions available:
**    SERIAL_CONFIG(baudrategenval)
**      - Sets up baud rate.
**    SERIAL_SEND(data)
**      - Send 8bit data.
**    SERIAL_RECIEVE()
**      - 
**    SERIAL_SEND16(data)
**      - Send 16bit data.
**    SERIAL_RECIEVE16()
**      - 
**
**  This library requires PIC_XTAL to be #define'd before inclusion.
**   the MHz and KHz suffixes may be used for a x1000 or x1.
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
**    05/06/2002 - Nick Veys
**      - Added most stuff, need broader MCU support, better TX delay.
**      - Reception not implemented, need good methodology first.
*/

#include "defines.h"

#ifndef __SERIAL_H
#define __SERIAL_H

#include <pic.h>

#if defined(_16F873) || defined(_16F874) || defined(_16F875) || \
    defined(_16F876) || defined(_16F877)
#else
#error Serial library not configured for this PIC.
#endif

void serialConfig(uchar baudrategenval);
void serialSend(uchar data);
uchar serialReceive();
void serialSend16(uint data);
uint serialReceive16();

#endif
