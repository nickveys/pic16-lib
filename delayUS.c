/* delayUS.c
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision
**      - Set up rough timing
**    11/28/2002 - Nick Veys
**      - Re-done and tested timing, more accurate/versatile
**    01/27/2003 - Nick Veys
**      - Library design beginning, attempting to library-ize
**/

#include "delay20.h"

void delayUS(uchar x)
{
  while(x > 0){ x--; }
  asm("nop");
}
