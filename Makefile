OBJECTS = loader.o kmain.o io.o gdt_asm.o idt.o interrupt_handler.o fb.o serial_port.o paging_enable.o interrupt/interrupts.o interrupt/keyboard.o interrupt/pic.o interrupt/isr.o memory/segments.o memory/gdt.o common/common.o page/paging.o heap/kheap.o
CC = gcc
CFLAGS = -m32 -nostdlib -fno-builtin -fno-stack-protector \
         -Wno-unused -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c -masm=intel
LDFLAGS = -T link.ld -m elf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

baseOS.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                              \
                -b boot/grub/stage2_eltorito    \
                -no-emul-boot                   \
                -boot-load-size 4               \
                -A os                           \
                -input-charset utf8             \
                -quiet                          \
                -boot-info-table                \
                -o baseOS.iso                   \
                iso

run: baseOS.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf baseOS.iso
