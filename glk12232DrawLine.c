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

void glk12232DrawLine(uchar x1, uchar y1, uchar x2, uchar y2)
{
  glk12232Command(108);		// draw line command
  glk12232Send(x1);			// from (x1, y1)
  glk12232Send(y1);
  glk12232Send(x2);			// to (x2, y2)
  glk12232Send(y2);
}
