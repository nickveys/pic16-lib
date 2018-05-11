/* readEEPROM.c  --  Functions for reading EEPROM storage.
**
**  Updates: 
**    11/01/2002 - Nick Veys
**      - Inital Revision.
*/

#include <pic.h>
#include "eeprom.h"

unsigned char readEEPROM(uchar addr)
{
  EEADR = addr;		// load EEPROM address
  EEPGD = 0;		// we're reading DATA memory
  RD = 1;			// initiate the read (1 cycle)
  return(EEDATA);	// return the result
}
