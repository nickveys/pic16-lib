/* mcp2510.h  --  Functions for using the MCP2510 on PICs
**
**  Variables port and mask are the data port and bitmask to find
**   the MCP2510 chip-select line.  i.e. if the MCP2510 is on PORTA's
**   bit #4, port = &PORTA, mask = 0b00010000 = 0x10.  Recommend this
**   be defined in the main program code rather than stated every use.
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
**    02/04/2003 - Nick Veys
**      - Library conversion and code cleanup
*/

#include "chipselect.h"
#include "defines.h"

#ifndef __MCP2510_H
#define __MCP2510_H

#define RXF0SIDH	0x00	// Acceptance Filter 0 Std Identifier High
#define RXF0SIDL	0x01	// Acceptance Filter 0 Std Identifier Low
#define RXF0EID8	0x02	// Acceptance Filter 0 Ext Identifier High
#define RXF0EID0	0x03	// Acceptance Filter 0 Ext Identifier Low
#define RXF1SIDH	0x04	// Acceptance Filter 1 Std Identifier High
#define RXF1SIDL	0x05	// Acceptance Filter 1 Std Identifier Low
#define RXF1EID8	0x06	// Acceptance Filter 1 Ext Identifier High
#define RXF1EID0	0x07	// Acceptance Filter 1 Ext Identifier Low
#define RXF2SIDH	0x08	// Acceptance Filter 2 Std Identifier High
#define RXF2SIDL	0x09	// Acceptance Filter 2 Std Identifier Low
#define RXF2EID8	0x0A	// Acceptance Filter 2 Ext Identifier High
#define RXF2EID0	0x0B	// Acceptance Filter 2 Ext Identifier Low
#define BFPCTRL		0x0C	// RXnBF Pin Control and Status Register
#define TXRTSCTRL	0x0D	// TXnRTS Pin Control and Status Register
#define CANSTAT		0x0E	// CAN Status Register
#define CANCTRL		0x0F	// CAN Control Register

#define RXF3SIDH	0x10	// Acceptance Filter 3 Std Identifier High
#define RXF3SIDL	0x11	// Acceptance Filter 3 Std Identifier Low
#define RXF3EID8	0x12	// Acceptance Filter 3 Ext Identifier High
#define RXF3EID0	0x13	// Acceptance Filter 3 Ext Identifier Low
#define RXF4SIDH	0x14	// Acceptance Filter 4 Std Identifier High
#define RXF4SIDL	0x15	// Acceptance Filter 4 Std Identifier Low
#define RXF4EID8	0x16	// Acceptance Filter 4 Ext Identifier High
#define RXF4EID0	0x17	// Acceptance Filter 4 Ext Identifier Low
#define RXF5SIDH	0x18	// Acceptance Filter 5 Std Identifier High
#define RXF5SIDL	0x19	// Acceptance Filter 5 Std Identifier Low
#define RXF5EID8	0x1A	// Acceptance Filter 5 Ext Identifier High
#define RXF5EID0	0x1B	// Acceptance Filter 5 Ext Identifier Low
#define TEC			0x1C	// Transmitter error counter
#define REC			0x1D	// Reciever error counter

#define RXM0SIDH	0x20	// Acceptance Mask 0 Std Identifier High
#define RXM0SIDL	0x21	// Acceptance Mask 0 Std Identifier Low
#define RXM0EID8	0x22	// Acceptance Mask 0 Ext Identifier High
#define RXM0EID0	0x23	// Acceptance Mask 0 Ext Identifier Low
#define RXM1SIDH	0x24	// Acceptance Mask 1 Std Identifier High
#define RXM1SIDL	0x25	// Acceptance Mask 1 Std Identifier Low
#define RXM1EID8	0x26	// Acceptance Mask 1 Ext Identifier High
#define RXM1EID0	0x27	// Acceptance Mask 1 Ext Identifier Low
#define CNF3		0x28	// Configuration Register 3
#define CNF2		0x29	// Configuration Register 2
#define CNF1		0x2A	// Configuration Register 1
#define CANINTE		0x2B	// Interrupt Enable Register
#define CANINTF		0x2C	// Interrupt Flag Register
#define EFLG		0x2D	// Error flag register

#define TXB0CTRL	0x30	// Transmit Buffer 0 Control Register
#define TXB0SIDH	0x31	// Transmit Buffer 0 Std Identifier High
#define TXB0SIDL	0x32	// Transmit Buffer 0 Std Identifier Low
#define TXB0EID8	0x33	// Transmit Buffer 0 Ext Identifier High
#define TXB0EID0	0x34	// Transmit Buffer 0 Ext Identifier Low
#define TXB0DLC		0x35	// Transmit Buffer 0 Data Length Code
#define TXB0D0		0x36	// Transmit Buffer 0 Data Byte 0
#define TXB0D1		0x37	// Transmit Buffer 0 Data Byte 1
#define TXB0D2		0x38	// Transmit Buffer 0 Data Byte 2
#define TXB0D3		0x39	// Transmit Buffer 0 Data Byte 3
#define TXB0D4		0x3A	// Transmit Buffer 0 Data Byte 4
#define TXB0D5		0x3B	// Transmit Buffer 0 Data Byte 5
#define TXB0D6		0x3C	// Transmit Buffer 0 Data Byte 6
#define TXB0D7		0x3D	// Transmit Buffer 0 Data Byte 7

#define TXB1CTRL	0x40	// Transmit Buffer 1 Control Register
#define TXB1SIDH	0x41	// Transmit Buffer 1 Std Identifier High
#define TXB1SIDL	0x42	// Transmit Buffer 1 Std Identifier Low
#define TXB1EID8	0x43	// Transmit Buffer 1 Ext Identifier High
#define TXB1EID0	0x44	// Transmit Buffer 1 Ext Identifier Low
#define TXB1DLC		0x45	// Transmit Buffer 1 Data Length Code
#define TXB1D0		0x46	// Transmit Buffer 1 Data Byte 0
#define TXB1D1		0x47	// Transmit Buffer 1 Data Byte 1
#define TXB1D2		0x48	// Transmit Buffer 1 Data Byte 2
#define TXB1D3		0x49	// Transmit Buffer 1 Data Byte 3
#define TXB1D4		0x4A	// Transmit Buffer 1 Data Byte 4
#define TXB1D5		0x4B	// Transmit Buffer 1 Data Byte 5
#define TXB1D6		0x4C	// Transmit Buffer 1 Data Byte 6
#define TXB1D7		0x4D	// Transmit Buffer 1 Data Byte 7

#define TXB2CTRL	0x50	// Transmit Buffer 2 Control Register
#define TXB2SIDH	0x51	// Transmit Buffer 2 Std Identifier High
#define TXB2SIDL	0x52	// Transmit Buffer 2 Std Identifier Low
#define TXB2EID8	0x53	// Transmit Buffer 2 Ext Identifier High
#define TXB2EID0	0x54	// Transmit Buffer 2 Ext Identifier Low
#define TXB2DLC		0x55	// Transmit Buffer 2 Data Length Code
#define TXB2D0		0x56	// Transmit Buffer 2 Data Byte 0
#define TXB2D1		0x57	// Transmit Buffer 2 Data Byte 1
#define TXB2D2		0x58	// Transmit Buffer 2 Data Byte 2
#define TXB2D3		0x59	// Transmit Buffer 2 Data Byte 3
#define TXB2D4		0x5A	// Transmit Buffer 2 Data Byte 4
#define TXB2D5		0x5B	// Transmit Buffer 2 Data Byte 5
#define TXB2D6		0x5C	// Transmit Buffer 2 Data Byte 6
#define TXB2D7		0x5D	// Transmit Buffer 2 Data Byte 7

#define RXB0CTRL	0x60	// Recieve Buffer 0 Control Register
#define RXB0SIDH	0x61	// Recieve Buffer 0 Std Identifier High
#define RXB0SIDL	0x62	// Recieve Buffer 0 Std Identifier Low
#define RXB0EID8	0x63	// Recieve Buffer 0 Ext Identifier High
#define RXB0EID0	0x64	// Recieve Buffer 0 Ext Identifier Low
#define RXB0DLC		0x65	// Recieve Buffer 0 Data Length Code
#define RXB0D0		0x66	// Recieve Buffer 0 Data Byte 0
#define RXB0D1		0x67	// Recieve Buffer 0 Data Byte 1
#define RXB0D2		0x68	// Recieve Buffer 0 Data Byte 2
#define RXB0D3		0x69	// Recieve Buffer 0 Data Byte 3
#define RXB0D4		0x6A	// Recieve Buffer 0 Data Byte 4
#define RXB0D5		0x6B	// Recieve Buffer 0 Data Byte 5
#define RXB0D6		0x6C	// Recieve Buffer 0 Data Byte 6
#define RXB0D7		0x6D	// Recieve Buffer 0 Data Byte 7

#define RXB1CTRL	0x70	// Recieve Buffer 1 Control Register
#define RXB1SIDH	0x71	// Recieve Buffer 1 Std Identifier High
#define RXB1SIDL	0x72	// Recieve Buffer 1 Std Identifier Low
#define RXB1EID8	0x73	// Recieve Buffer 1 Ext Identifier High
#define RXB1EID0	0x74	// Recieve Buffer 1 Ext Identifier Low
#define RXB1DLC		0x75	// Recieve Buffer 1 Data Length Code
#define RXB1D0		0x76	// Recieve Buffer 1 Data Byte 0
#define RXB1D1		0x77	// Recieve Buffer 1 Data Byte 1
#define RXB1D2		0x78	// Recieve Buffer 1 Data Byte 2
#define RXB1D3		0x79	// Recieve Buffer 1 Data Byte 3
#define RXB1D4		0x7A	// Recieve Buffer 1 Data Byte 4
#define RXB1D5		0x7B	// Recieve Buffer 1 Data Byte 5
#define RXB1D6		0x7C	// Recieve Buffer 1 Data Byte 6
#define RXB1D7		0x7D	// Recieve Buffer 1 Data Byte 7

#define RTS0 0x81	// Request-to-send Commands
#define RTS1 0x82
#define RTS2 0x84

#define CMD_WRITE		0x02	// Write Command
#define CMD_READ		0x03	// Read Command
#define CMD_BITMODIFY	0x05	// Bit-modify Command
#define CMD_READSTATUS	0xA0	// Read Status Command
#define CMD_RESET		0xC0	// Reset Command

#define mcp2510SetSPI() SPIConfig(0x00, 0x10)

uchar mcp2510Status(chipselect* cs);
void mcp2510Write(chipselect* cs, uchar addr, uchar data);
void mcp2510WriteSequence(chipselect* cs, uchar st_addr, uchar* data, uchar len);
uchar mcp2510Read(chipselect* cs, uchar addr);
void mcp2510ReadSequence(chipselect* cs, uchar st_addr, uchar* dest, uchar len);
void mcp2510RTS(chipselect* cs, uchar rtsnum);
void mcp2510BitModify(chipselect* cs, uchar addr, uchar bitmask, uchar data);
void mcp2510Reset(chipselect* cs); // wait 50us
void mcp2510TransmitStandard(chipselect* cs, uchar* id, uchar dlc, uchar* data);
void mcp2510TransmitExtended(chipselect* cs, uchar* id, uchar* eid, uchar dlc, uchar* data);
void mcp2510TransmitRemote(chipselect* cs, uchar* id, uchar* eid);

#endif
