/* chipselect.h  --  Chipselect struct.
**
**  Updates: 
**    04/03/2003 - Nick Veys
**      - Inital Revision.
*/

#include "defines.h"

#ifndef __CHIPSELECT_H
#define __CHIPSELECT_H

typedef struct
{
  uchar* port;
  uchar mask;
} chipselect;

#endif
