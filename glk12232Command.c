/* glk12232.h  --  Functions for using the GLK122-32 MO Graphical LCD.
**
**  Updates: 
**    05/06/2002 - Nick Veys
**      - Inital Revision.
**    05/30/2002 - Nick Veys
**      - Documentation additions.
**    12/08/2002 - Nick Veys
**      - Fixed graphic drawing routines.
*/

#include "serial.h"
#include "glk12232.h"

void glk12232Command(uchar cmd)
{
  glk12232Send(254);			// prefix w/254
  glk12232Send(cmd);			// send the command
}
