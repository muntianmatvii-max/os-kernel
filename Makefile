# OS Kernel Makefile for x86_64

CC = gcc
AS = nasm
LD = ld

CFLAGS = -Wall -Wextra -ffreestanding -fno-pie -m64
ASFLAGS = -f elf64
LDFLAGS = -T linker.ld -nostdlib

SOURCES = $(wildcard src/**/*.c)
OBJECTS = $(SOURCES:.c=.o)
ASM_SOURCES = $(wildcard src/**/*.asm)
ASM_OBJECTS = $(ASM_SOURCES:.asm=.o)

KERNEL = kernel.elf
ISO = kernel.iso

.PHONY: all clean build iso

all: $(KERNEL)

$(KERNEL): $(OBJECTS) $(ASM_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

iso: $(KERNEL)
	mkdir -p iso/boot/grub
	cp $(KERNEL) iso/boot/
	cp grub.cfg iso/boot/grub/
	grub-mkrescue -o $(ISO) iso/

clean:
	rm -rf $(OBJECTS) $(ASM_OBJECTS) $(KERNEL) $(ISO) iso/

rebuild: clean all
