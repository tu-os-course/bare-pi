CC=arm-none-eabi-gcc
CFLAGS=-Wall -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -ffreestanding -std=gnu99 -c
ASSEMBLER=$(CC) $(CFLAGS)
LINKER=arm-none-eabi-gcc -ffreestanding -O2 -nostdlib
SRC=src

.SUFFIXES: .S .o .c .list

all: kernel.img

.S.o:
	$(ASSEMBLER) -o $@ $^

.c.list:
	$(CC) $(CFLAGS) -S -o $@ $^

kernel.img: $(SRC)/boot.o $(SRC)/kernel.o
	$(LINKER) -T $(SRC)/linker.ld -o kernel.elf $(SRC)/boot.o $(SRC)/kernel.o
	arm-none-eabi-objcopy kernel.elf -O binary $@

clean:
	-cd src && rm -rf *.o
	-rm *.elf *.img
