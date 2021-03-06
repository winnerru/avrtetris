MCU = atmega8
PROGRAMMER = usbasp

TARG = firmware

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRSIZE = avr-size

SRCS = routines.c display.c game.c main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -mmcu=$(MCU) -g -Wall -O3 -Werror -lm -mcall-prologues -std=c99
LDFLAGS = -mmcu=$(MCU) -g -Wall -O3 -Werror

all: $(TARG)

$(TARG): $(OBJS)
	$(CC) $(LDFLAGS) -o $@.elf  $(OBJS) -lm
	$(AVRSIZE) -C --mcu=$(MCU) $@.elf
	$(OBJCOPY) -O binary -R .eeprom -R .nwram  $@.elf $@.bin
	$(OBJCOPY) -O ihex -R .eeprom -R .nwram  $@.elf $@.hex

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

upload:
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -U flash:w:$(TARG).hex
# -U lfuse:w:0xe4:m -U hfuse:w:0xc9:m

clean:
	rm -f *.elf *.bin *.hex  $(OBJS) *.map
