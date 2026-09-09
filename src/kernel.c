#include "kernel.h"
#include "console.h"
#include "memory.h"
#include "filesystem.h"

void kernel_main() {
    console_clear();
    console_write("Welcome to OS Kernel x86_64\n");
    console_write("================================\n\n");
    
    // Initialize memory management
    memory_init();
    console_write("[OK] Memory management initialized\n");
    
    // Initialize file system
    filesystem_init();
    console_write("[OK] File system initialized\n");
    
    console_write("\nKernel is running...\n");
    
    // Halt
    while(1) {
        asm("hlt");
    }
}
