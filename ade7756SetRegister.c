#include "spi.h"
#include "ade7756.h"
#include "delay20.h"

void ade7756SetRegister(chipselect* cs, uchar reg, uchar* val, uchar len)
{
  uchar i;
  
  ade7756SetSPI();				// set SPI port for ADE7756
  *(cs->port) &= ~cs->mask;			// select ADE7756
  SPISend( 0x80 | reg );			// 100 + register
  for(i=0; i<len; i++) 
  {
    delayUS(10);
    SPISend(val[i]);
  }
  *(cs->port) |= cs->mask;			// de-select ADE7756
}
