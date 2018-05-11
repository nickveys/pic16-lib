/* delay20.h
**
** Functions available:
**    delayUS(x)
**      - Delay specified number of microseconds (<= 255).
**    delayMS(x)
**      - Delay specified number of milliseconds (<= 65535).
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision
**      - Set up rough timing
**    11/28/2002 - Nick Veys
**      - Re-done and tested timing, more accurate/versatile
**    01/27/2003 - Nick Veys
**      - Library design beginning, attempting to library-ize
**    02/04/2003 - Nick Veys
**      - Library done, code cleanup
**/

#include "defines.h"

#ifndef __DELAY20_H
#define __DELAY20_H

void delayUS(uchar x);
void delayMS(uint x);

#endif
