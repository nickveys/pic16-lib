/* spi.h  --  Functions for using the SPI port on PICs that have them.
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
*/

#include "defines.h"

#ifndef __SPI_H
#define __SPI_H

void SPIConfig(uchar stat, uchar con);
void SPISend(uchar data);
uchar SPIReceive();
void SPISend16(uint data);
uint SPIReceive16();

#endif
