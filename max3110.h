/* max3110.h  --  Functions for using the MAX3110 on PICs
**
**  Variables port and mask are the data port and bitmask to find
**   the MAX3110 chip-select line.  i.e. if the MAX3110 is on PORTB's
**   bit #2, port = (unsigned char*) &PORTC, mask = 0b00000100 = 0x04.
**   Recommend this be defined in the main program code, not stated every use.
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.  Still need to get XTAL choices working.
**    05/01/2002 - Nick Veys
**      - Changed XTAL's to 18432 and 36864.
**    05/06/2002 - Nick Veys
**      - Documentation tweaks.
**    05/30/2002 - Nick Veys
**      - Documentation tweaks.
*/

#include "chipselect.h"
#include "defines.h"

#ifndef __MAX3110_H
#define __MAX3110_H

#define max3110SetSPI() SPIConfig(0x40, 0x01)

char max3110Config(chipselect* cs, unsigned long baudrate, uchar xtal); // wait 20us after using
uint max3110Status(chipselect* cs);
void max3110Write(chipselect* cs, uchar c);
uchar max3110Read(chipselect* cs);

#endif
