# Put your source files here (or *.c, etc)
SRCS=programs/nothing.c 

# Binaries will be generated with this name (.elf, .bin, .hex, etc)
PROJ_NAME=nothing


CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
LDFILE=stm32f401RE.ld

CFLAGS = -g -Wall -T$(LDFILE) 
CFLAGS = -mthumb -mcpu=cortex-m4 


.PHONY: proj

all: proj

proj: $(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ 
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

clean:
	rm -f *.o $(PROJ_NAME).elf $(PROJ_NAME).hex $(PROJ_NAME).bin

# Flash the STM32F4
burn: proj
	st-flash write $(PROJ_NAME).bin 0x8000000
