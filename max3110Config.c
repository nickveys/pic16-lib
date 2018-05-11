/* max3110Config.h  --  asdf
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

#include "spi.h"
#include "max3110.h"

char max3110Config(chipselect* cs, unsigned long baudrate, uchar xtal)
{
  max3110SetSPI();			// setup SPI port for MAX3110
  *(cs->port) &= ~cs->mask;	// select MAX3110
  SPISend(0xC4);			// set recieve interrupt (option?)
  if(xtal == 1)
  {
    switch(baudrate)
    {
      case 300:    SPISend(0b00001111); break;
      case 600:    SPISend(0b00001110); break;
      case 1200:   SPISend(0b00001101); break;
      case 2400:   SPISend(0b00001100); break;
      case 4800:   SPISend(0b00001011); break;
      case 9600:   SPISend(0b00001010); break;
      case 14400:  SPISend(0b00000011); break;
      case 19200:  SPISend(0b00001001); break;
      case 28800:  SPISend(0b00000010); break;
      case 38400:  SPISend(0b00001000); break;
      case 56700:  SPISend(0b00000001); break;
      case 115200: SPISend(0b00000000); break;
      default: return -1;	// error! :(
    }
    *(cs->port) |= cs->mask;	// de-select MAX3110
    return 0;
  }
  else if(xtal == 3)
  {
    switch(baudrate)
    {
      case 600:    SPISend(0b00001111); break;
      case 1200:   SPISend(0b00001110); break;
      case 2400:   SPISend(0b00001101); break;
      case 4800:   SPISend(0b00001100); break;
      case 9600:   SPISend(0b00001011); break;
      case 14400:  SPISend(0b00000100); break;
      case 19200:  SPISend(0b00001010); break;
      case 28800:  SPISend(0b00000011); break;
      case 38400:  SPISend(0b00001001); break;
      case 56700:  SPISend(0b00000010); break;
      case 115200: SPISend(0b00000001); break;
      case 230400: SPISend(0b00000000); break;
      default: return -1;	// error! :(
    }
    *(cs->port) |= cs->mask;	// de-select MAX3110
    return 0;
  }
  return -1;	// error! :(
}
