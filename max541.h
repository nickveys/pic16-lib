/* max541.h  --  Functions for using the MAX541 16-bit DAC
**
**  Updates: 
**    12/07/2002 - Nick Veys
**      - Inital Revision.
*/

#include "chipselect.h"
#include "defines.h"

#ifndef __MAX541_H
#define __MAX541_H

#define max541SetSPI() SPIConfig(0x40, 0x01)

void max541SetValue(chipselect* cs, uint val);

#endif
