/* glk12232.h  --  Functions for using the GLK122-32 MO Graphical LCD.
**
**  Updates: 
**    05/06/2002 - Nick Veys
**      - Inital Revision.
**    05/30/2002 - Nick Veys
**      - Documentation additions.
**    12/08/2002 - Nick Veys
**      - Fixed graphic drawing routines.
*/

#include "defines.h"

#ifndef __GLK12232_H
#define __GLK12232_H

#define glk12232Send(x) serialSend(x)
void glk12232Command(uchar cmd);
#define glk12232Clear() glk12232Command(88)
void glk12232Font(uchar font);
void glk12232Backlight(uchar minutes, uchar on);
void glk12232Contrast(uchar contrast);
void glk12232InsertionPointPixel(uchar x, uchar y);
void glk12232InsertionPointRowColumn(uchar col, uchar row);
void glk12232SetDrawingColor(uchar color);
void glk12232DrawLine(uchar x1, uchar y1, uchar x2, uchar y2);
void glk12232ContinueLine(uchar x, uchar y);
void glk12232PutPixel(uchar x, uchar y);
void glk12232DrawOutlineRectangle(uchar color, uchar x1, uchar y1, uchar x2, uchar y2);
void glk12232DrawSolidRectangle(uchar color, uchar x1, uchar y1, uchar x2, uchar y2);

#define GLK_VERTICAL_BtoT 	0	// Vertical: Bottom to Top
#define GLK_VERTICAL_TtoB 	2	// Vertical: Top to Bottom
#define GLK_HORIZONTAL_LtoR	1	// Horizontal: Left to Right
#define GLK_HORIZONTAL_RtoL	3	// Horizontal: Right to Left

void glk12232InitBarGraph(uchar num, uchar type, uchar x1, uchar y1, uchar x2, uchar y2);
void glk12232WriteBarGraph(uchar num, uchar val);
void glk12232DisplayImage(uchar num, uchar x, uchar y);
#endif
