CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar 

vpath %.c src ../CMSIS
vpath %.h inc

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m3 -mthumb-interwork
CFLAGS += -ffreestanding -nostdlib

CFLAGS += -Iinc -I../CMSIS -I../User

CFLAGS += -DUSE_STDPERIPH_DRIVER
CFLAGS += -DSTM32F10X_MD

SRCS = misc.c stm32f10x_adc.c stm32f10x_bkp.c stm32f10x_can.c \
		stm32f10x_cec.c stm32f10x_crc.c stm32f10x_dac.c \
		stm32f10x_dbgmcu.c stm32f10x_dma.c stm32f10x_exti.c \
		stm32f10x_flash.c stm32f10x_fsmc.c stm32f10x_gpio.c \
		stm32f10x_i2c.c stm32f10x_iwdg.c stm32f10x_pwr.c \
		stm32f10x_rcc.c stm32f10x_rtc.c stm32f10x_sdio.c \
		stm32f10x_spi.c stm32f10x_tim.c stm32f10x_usart.c \
		stm32f10x_wwdg.c
SRCS += core_cm3.c system_stm32f10x.c

OBJS = $(SRCS:.c=.o)

all: libstm32periLib.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libstm32periLib.a : $(OBJS)
	$(AR) -r $@ $(OBJS)

.PHONY: clean 

clean: 
	rm -f $(OBJS)
