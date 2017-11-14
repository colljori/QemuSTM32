# This file is part of not much, if not nothing
# Copyright (C) 2017  Frédéric Pétrot
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.



# output name
OUTPUT = test


# Assume binutils-arm-none-eabi package installed (debian name)
CROSS_COMPILE=arm-none-eabi-
CC=$(CROSS_COMPILE)gcc
AS=$(CROSS_COMPILE)as
LD=$(CROSS_COMPILE)ld
OC=$(CROSS_COMPILE)objcopy
OD=$(CROSS_COMPILE)objdump
ECHO = echo

LIB_DIR= ../../lib

SRC = $(wildcard $(LIB_DIR)/src/*.c) 
SRC += start.c

ASRC = vectors.s

INCLUDE_DIR=$(LIB_DIR)/include

# flags
CC_FLAGS= -mcpu=cortex-m4 -mthumb -g  -I$(INCLUDE_DIR)
AS_FLAGS= -mcpu=cortex-m4 -mthumb -g
OBC_FLAGS = -O binary


# sources converted to objs
OBJ = $(SRC:%.c=%.o) $(ASRC:%.s=%.o)


# generate elf and bin
all: $(OUTPUT).elf $(OUTPUT).bin 

# generate elf file from objs
$(OUTPUT).elf: ldscript.ld $(OBJ) 
	@ $(ECHO) ---------------------    Linking   ---------------------
	$(LD) -T $< $(filter-out $<,$^) -o $@

# generate bin file
$(OUTPUT).bin: $(OUTPUT).elf
	@ $(ECHO) ---------------------    Copying   ---------------------
	$(OC) $(OC_FLAGS) $< $@


# compile all C-sources
%.o : %.c
	@ $(ECHO) --------------------- Compiling $< ---------------------
	$(CC) -c $(CC_FLAGS) $< -o $@

# compile all Assembly sources
%.o : %.s
	@ $(ECHO) --------------------- Compiling $< ---------------------
	$(AS) $(AS_FLAGS) $< -o $@


# cleanser xD
clean:
	rm -f $(OBJ)  $(OUTPUT).bin $(OUTPUT).elf vectors.o
