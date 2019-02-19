SRCS = main.c stm32f10x_it.c startup_stm32f10x_md.s 
HEADERS = stm32f10x_it.h stm32f10x_conf.x

########################## USER FILES BELOW ##########################
SRCS += 
HEADERS += 
########################## USER FILES ABOVE ##########################

PROJ_NAME = main

vpath %.c User
vpath %.a Lib
vpath %.s Startup 
vpath %.h User

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS  = -g -O2 -Wall -Tstm32_flash.ld 
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m3 -mthumb-interwork
CFLAGS += -DUSE_STDPERIPH_DRIVER
CFLAGS += -DSTM32F10X_MD

CFLAGS += -ILib/inc -ICMSIS -IUser -lc

OBJS = $(SRCS:.c=.o)

.PHONY: lib proj

all: lib proj

lib:
	$(MAKE) -C Lib 

proj: $(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ -LLib -lstm32periLib
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

SRCS : HEADERS
HEADERS:

.PHONY: clean

clean:
	rm -f *.o *.elf *.hex *.bin
