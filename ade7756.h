/* ade7756.h  --  Functions for using the ADE7756 Energy Meter.
**
**  Updates: 
**    10/05/2002 - Nick Veys
**      - Inital Revision.
*/

#include "chipselect.h"
#include "defines.h"

#ifndef __ADE7756_H
#define __ADE7756_H

#define WAVEFORM	0x01
#define AENERGY		0x02
#define RSTENERGY	0x03
#define STATUS		0x04
#define RSTSTATUS	0x05
#define MODE		0x06
#define CFDIV		0x07
#define CH1OS		0x08
#define CH2OS		0x09
#define GAIN		0x0A
#define APGAIN		0x0B
#define PHCAL		0x0C
#define APOS		0x0D
#define ZXTOUT		0x0E
#define SAGCYC		0x0F
#define IRQEN		0x10
#define SAGLVL		0x11
#define TEMP		0x12

//#define ade7756SetSPI() SPIConfig(0x00, 0x00)
#define ade7756SetSPI() SPIConfig(0x00, 0x01)

void ade7756SetRegister(chipselect* cs, uchar reg, uchar* val, uchar len);
void ade7756Set8Register(chipselect* cs, uchar reg, char val);
void ade7756Set16Register(chipselect* cs, uchar reg, int val);

void ade7756GetRegister(chipselect* cs, uchar reg, uchar len, uchar* retval);

#endif
