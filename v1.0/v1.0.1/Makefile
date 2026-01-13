# Makefile
CC = gcc
ASM = nasm
LD = ld
CFLAGS = -m32 -ffreestanding -fno-builtin -fno-stack-protector -nostdlib -Wall -Wextra -fno-pic -fno-pie
ASMFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T linker.ld -nostdlib -static

# 目标文件
OBJS = kernel_entry.o kernel.o screen.o

# 默认目标
all: os-image

# 引导扇区
boot.bin: boot.asm
	$(ASM) -f bin boot.asm -o boot.bin

kernel_entry.o: kernel_entry.asm
	$(ASM) $(ASMFLAGS) kernel_entry.asm -o kernel_entry.o

kernel.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o

screen.o: screen.c
	$(CC) $(CFLAGS) -c screen.c -o screen.o

kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o kernel.bin $(OBJS)

os-image: boot.bin kernel.bin
	dd if=/dev/zero of=os-image bs=512 count=2880 
	dd if=boot.bin of=os-image conv=notrunc       
	dd if=kernel.bin of=os-image bs=512 seek=1 conv=notrunc  


run: os-image
	qemu-system-i386 -drive format=raw,file=os-image -monitor stdio

clean:
	rm -f *.o *.bin os-image

debug: os-image
	qemu-system-i386 -s -S -drive format=raw,file=os-image &
	gdb -ex "target remote localhost:1234" -ex "symbol-file kernel.bin"