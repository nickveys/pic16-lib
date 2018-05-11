/* mcp2510TransmitRemote.c
**
**  Updates: 
**    04/29/2002 - Nick Veys
**      - Inital Revision.
**    05/30/2002 - Nick Veys
**      - Added SPI_SETUP's to a few functions.
**      - Small documentation tweaks.
**    10/25/2002 - Nick Veys
**      - Added transmission routines.  NEED OPTIMIZATION!!
**    10/26/2002 - Nick Veys
**      - Optimized transmission routines. :)
**      - Added WRITE_SEQUENCE function.
*/

#include "spi.h"
#include "mcp2510.h"

void mcp2510TransmitRemote(chipselect* cs, uchar* id, uchar* eid)
{
  uchar status;			// storage for MCP2510's status byte
  uchar packet[5];		// storage for complete packet
  uchar messageSent = 0;

  packet[0] = ((id[0] & 0x07) << 5) + ((id[1] & 0xF8) >> 3);
  packet[1] = (((id[1] & 0x07) << 5) + (eid[0] & 0x03)) | 0x08;
  packet[2] = eid[1];
  packet[3] = eid[2];
  packet[4] = 0x40;

  status = mcp2510Status(cs);  // get status register

  while(!messageSent)
  {
    if(!(status & 0x02))				// TX0 is free
    {
      mcp2510WriteSequence(cs, TXB0SIDH, packet, 5);
      mcp2510RTS(cs, RTS0);
	  messageSent = 1;
    }
    else if(!(status & 0x10))			// TX1 is free
    {
      mcp2510WriteSequence(cs, TXB1SIDH, packet, 5);
      mcp2510RTS(cs, RTS1);
	  messageSent = 1;
    }
    else if(!(status & 0x40))			// TX2 is free
    {
      mcp2510WriteSequence(cs, TXB2SIDH, packet, 5);
      mcp2510RTS(cs, RTS2);
 	  messageSent = 1;
    }
  }
}
