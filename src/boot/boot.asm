MAGIC_NUMBER equ 0x1BADB002
FLAGS equ 0x0
CHECKSUM equ -(MAGIC_NUMBER + FLAGS)

section .multiboot
align 4
    dd MAGIC_NUMBER
    dd FLAGS
    dd CHECKSUM

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

section .text
global _start
_start:
    mov esp, stack_top
    
    ; Call the kernel main function
    extern kernel_main
    call kernel_main
    
    ; Halt the system
    cli
.hang:
    hlt
    jmp .hang
