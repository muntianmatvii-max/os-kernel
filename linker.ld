OUTPUT_FORMAT(elf64-x86-64)
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS {
    . = 1M;
    
    .boot BLOCK(4K) : ALIGN(4K) {
        *(.multiboot)
        *(.boot)
    }
    
    .text BLOCK(4K) : ALIGN(4K) {
        *(.text)
        *(.text*)
    }
    
    .rodata BLOCK(4K) : ALIGN(4K) {
        *(.rodata)
        *(.rodata*)
    }
    
    .data BLOCK(4K) : ALIGN(4K) {
        *(.data)
        *(.data*)
    }
    
    .bss BLOCK(4K) : ALIGN(4K) {
        *(COMMON)
        *(.bss)
        *(.bss*)
    }
}
