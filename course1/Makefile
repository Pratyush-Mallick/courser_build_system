#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Make file to compile multiple files, link them together and create a final 
# output executable with the support for two platforms :
# 1) host environment 
# 2) embedded system MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build, compile-all
#
# Platform Overrides:
#      HOST/MSP432
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#Target File name
TARGET = c1m2

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
# Specific to MSP432
ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc 
	CFLAGS = -mcpu=$(CPU) -m$(ARCH)    \
                 -mfloat-abi=hard          \
                 -mfpu=fpv4-sp-d16         \
                 --specs=$(SPECS)
	SOURCES += interrupts_msp432p401r_gcc.c \
                   startup_msp432p401r_gcc.c \
                   system_msp432p401r.c

        LDFLAGS =  -T $(LINKER_FILE)
	CPPFLAGS = -DMSP432 
	SIZEUTIL = arm-none-eabi-size	

# Compiler Flags and Defines
# Specific to HOST
else ifeq ($(PLATFORM),HOST)
	CC = gcc
	CPPFLAGS = -DHOST 
	SIZEUTIL = size

endif
CFLAGS +=  -Wall -Werror=attributes -g -O0 -std=c99
LDFLAGS += -Wl,-Map=$(TARGET).map

OBJS := $(SOURCES:.c=.o)
DEPS := $(OBJS:.o=.d)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) $(CPPFLAGS)  -o $@
	$(CC) -MM $< $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -o $*.dep

%.i : %.c
	$(CC) -E $< $(CFLAGS) $(INCLUDES) $(CPPFLAGS)  -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(INCLUDES) $(CPPFLAGS)  -o $@


.PHONY: compile-all 
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< $(CFLAGS) $(SOURCES)

.PHONY: build
build: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(SOURCES)
	$(SIZEUTIL) -Bx $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET).out $(TARGET).map *.d *.dep *.i *.asm


