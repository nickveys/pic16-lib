/* writeEEPROM.c  --  Functions for writing to EEPROM storage.
**
**  Updates: 
**    11/01/2002 - Nick Veys
**      - Inital Revision.
*/

#include <pic.h>
#include "eeprom.h"

void writeEEPROM(uchar addr, uchar data)
{
  static bit _GIE;	// GIE holder

  while(WR);		// wait for previous write to complete

  EEADR = addr;		// load EEPROM address
  EEDATA = data;	// load EEPROM data
  EEPGD = 0;		// we're writing to DATA memory
  WREN = 1;			// enable EEPROM writes

  _GIE = GIE;		// store interrupt status
  GIE = 0;			// disable interrupts

  EECON2 = 0x55;	// required for
  EECON2 = 0xAA;	// EEPROM write

  WR = 1;			// initiate the write
  WREN = 0;			// disable writes

  GIE = _GIE;		// set to previous value
}
