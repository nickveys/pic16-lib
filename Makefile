PIC = 16F876
CC = picc
CFLAGS = -$(PIC) -O -Zg
LIBR = libr
LFLAGS = r

all: delay20.lib eeprom.lib spi.lib serial.lib \
     mcp2510.lib max541.lib max3110.lib max7221.lib \
     glk12232.lib ade7756.lib \
     clean

DELAY20SRC = delayUS.c delayMS.c
DELAY20OBJ = delayUS.obj delayMS.obj

delay20.lib: delay20.h $(DELAY20SRC)
	$(CC) $(CFLAGS) -C $(DELAY20SRC)
	$(LIBR) $(LFLAGS) delay20.lib $(DELAY20OBJ)

EEPROMSRC = readEEPROM.c writeEEPROM.c
EEPROMOBJ = readEEPROM.obj writeEEPROM.obj

eeprom.lib: eeprom.h
	$(CC) $(CFLAGS) -C $(EEPROMSRC)
	$(LIBR) $(LFLAGS) eeprom.lib $(EEPROMOBJ)

SPISRC = SPIConfig.c SPIReceive16.c SPIReceive.c \
         SPISend16.c SPISend.c
SPIOBJ = SPIConfig.obj SPIReceive16.obj SPIReceive.obj \
         SPISend16.obj SPISend.obj

spi.lib: spi.h
	$(CC) $(CFLAGS) -C $(SPISRC)
	$(LIBR) $(LFLAGS) spi.lib $(SPIOBJ)

SERIALSRC = serialConfig.c serialReceive16.c \
            serialReceive.c serialSend16.c serialSend.c

SERIALOBJ = serialConfig.obj serialReceive16.obj \
            serialReceive.obj serialSend16.obj serialSend.obj

serial.lib: serial.h $(SERIALSRC)
	$(CC) $(CFLAGS) -C $(SERIALSRC)
	$(LIBR) $(LFLAGS) serial.lib $(SERIALOBJ)

MCP2510SRC = mcp2510BitModify.c mcp2510Read.c \
             mcp2510ReadSequence.c mcp2510Reset.c \
             mcp2510RTS.c mcp2510Status.c \
             mcp2510TransmitExtended.c mcp2510TransmitRemote.c \
             mcp2510TransmitStandard.c mcp2510Write.c \
             mcp2510WriteSequence.c
MCP2510OBJ = mcp2510BitModify.obj mcp2510Read.obj \
             mcp2510ReadSequence.obj mcp2510Reset.obj \
             mcp2510RTS.obj mcp2510Status.obj \
             mcp2510TransmitExtended.obj mcp2510TransmitRemote.obj \
             mcp2510TransmitStandard.obj mcp2510Write.obj \
             mcp2510WriteSequence.obj

mcp2510.lib: mcp2510.h $(MCP2510SRC) $(SPISRC)
	$(CC) $(CFLAGS) -C $(MCP2510SRC)
	$(LIBR) $(LFLAGS) mcp2510.lib $(MCP2510OBJ) $(SPIOBJ)

MAX541SRC = max541SetValue.c
MAX541OBJ = max541SetValue.obj

max541.lib: max541.h $(MAX541SRC) $(SPISRC)
	$(CC) $(CFLAGS) -C $(MAX541SRC)
	$(LIBR) $(LFLAGS) max541.lib $(MAX541OBJ) $(SPIOBJ)

MAX3110SRC = max3110Config.c max3110Read.c \
             max3110Status.c max3110Write.c
MAX3110OBJ = max3110Config.obj max3110Read.obj \
             max3110Status.obj max3110Write.obj

max3110.lib: max3110.h $(MAX3110SRC) $(SPISRC)
	$(CC) $(CFLAGS) -C $(MAX3110SRC)
	$(LIBR) $(LFLAGS) max3110.lib $(MAX3110OBJ) $(SPIOBJ)

MAX7221SRC = max7221Write.c max7221Initialize.c
MAX7221OBJ = max7221Write.obj max7221Initialize.obj

max7221.lib: max7221.h $(MAX7221SRC) $(SPISRC)
	$(CC) $(CFLAGS) -C $(MAX7221SRC)
	$(LIBR) $(LFLAGS) max7221.lib $(MAX7221OBJ) $(SPIOBJ)

GLK12232SRC = glk12232Backlight.c glk12232Command.c \
              glk12232ContinueLine.c glk12232Contrast.c \
              glk12232DisplayImage.c glk12232DrawLine.c \
              glk12232DrawOutlineRectangle.c \
              glk12232DrawSolidRectangle.c \
              glk12232Font.c glk12232InitBarGraph.c \
              glk12232InsertionPointPixel.c \
              glk12232InsertionPointRowColumn.c \
              glk12232PutPixel.c glk12232SetDrawingColor.c \
              glk12232WriteBarGraph.c
GLK12232OBJ = glk12232Backlight.obj glk12232Command.obj \
              glk12232ContinueLine.obj glk12232Contrast.obj \
              glk12232DisplayImage.obj glk12232DrawLine.obj \
              glk12232DrawOutlineRectangle.obj \
              glk12232DrawSolidRectangle.obj \
              glk12232Font.obj glk12232InitBarGraph.obj \
              glk12232InsertionPointPixel.obj \
              glk12232InsertionPointRowColumn.obj \
              glk12232PutPixel.obj glk12232SetDrawingColor.obj \
              glk12232WriteBarGraph.obj

glk12232.lib: glk12232.h $(GLK12232SRC) $(SERIALSRC)
	$(CC) $(CFLAGS) -C $(GLK12232SRC)
	$(LIBR) $(LFLAGS) glk12232.lib $(GLK12232OBJ) $(SERIALOBJ)

ADE7756SRC = ade7756GetRegister.c ade7756SetRegister.c
ADE7756OBJ = ade7756GetRegister.obj ade7756SetRegister.obj

ade7756.lib: ade7756.h $(ADE7756SRC) $(SPISRC) $(DELAY20SRC)
	$(CC) $(CFLAGS) -C $(ADE7756SRC)
	$(LIBR) $(LFLAGS) ade7756.lib $(ADE7756OBJ) $(SPIOBJ) $(DELAY20OBJ)

clean:
	rm -f *.obj
	rm -f *.lst

realclean: clean
	rm -f *.lib
