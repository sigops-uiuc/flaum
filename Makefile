all: kernel.elf

kernel.elf: boot.o kernel.o
	ld.lld -T linker.ld -o kernel.elf -O2 -nostdlib boot.o kernel.o

kernel.o:
	clang --target=aarch64-elf -fpic -ffreestanding -c kernel.c -o kernel.o

boot.o:
	clang --target=aarch64-elf -fpic -ffreestanding -c boot.s -o boot.o

run: kernel.elf
	qemu-system-aarch64 -M raspi3 -serial stdio -kernel kernel.elf

clean:
	rm -f *.o *.elf
