/* glk12232Backlight.c
**
**  Sets the backlight on the GLK12232.  
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

void glk12232Backlight(uchar minutes, uchar on)
{
  if(on)	// should it be on?
  {
    glk12232Command(66);	// backlight command
    glk12232Send(minutes);	// duration in minutes
  }
  else glk12232Command(70);	// otherwise turn off
}
