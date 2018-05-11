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

void glk12232Font(uchar font)
{
  glk12232Command(49);		// font command
  glk12232Send(font);		// send fontnum
}
