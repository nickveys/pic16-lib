#include "spi.h"
#include "ade7756.h"
#include "delay20.h"

void ade7756GetRegister(chipselect* cs, uchar reg, uchar len, uchar* retval)
{
  uchar i;
  
  ade7756SetSPI();			// set SPI port for ADE7756
  *(cs->port) &= ~cs->mask;		// select ADE7756
  SPISend( 0 | reg );			// 000 + register
  for(i=0; i<len; i++) 
  {
    delayUS(10);			// delay for byte reads
    retval[i] = SPIReceive();
  }
  *(cs->port) |= cs->mask;		// de-select ADE7756
}
