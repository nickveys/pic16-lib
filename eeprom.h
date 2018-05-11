/* eeprom.h  --  Functions for using EEPROM storage.
**
**  Updates: 
**    11/01/2002 - Nick Veys
**      - Inital Revision.
**    11/02/2002 - Nick Veys
**      - Working great.  Read/Write OK.
*/

#include "defines.h"

#ifndef __EEPROM_H
#define __EEPROM_H

uchar readEEPROM(uchar addr);
void writeEEPROM(uchar addr, uchar data);

#endif
