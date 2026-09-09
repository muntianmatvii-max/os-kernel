#include "console.h"

#define VGA_MEMORY 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static uint16_t *vga_buffer = (uint16_t*)VGA_MEMORY;
static size_t x = 0;
static size_t y = 0;

static uint8_t make_color(enum vga_color fg, enum vga_color bg) {
    return fg | (bg << 4);
}

static uint16_t make_vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t)uc | ((uint16_t)color << 8);
}

void console_clear() {
    uint8_t color = make_color(COLOR_WHITE, COLOR_BLACK);
    for (size_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vga_buffer[i] = make_vga_entry(' ', color);
    }
    x = 0;
    y = 0;
}

void console_write(const char *data) {
    size_t datalen = 0;
    while (data[datalen]) datalen++;
    console_write_count(data, datalen);
}

void console_write_count(const char *data, size_t size) {
    uint8_t color = make_color(COLOR_WHITE, COLOR_BLACK);
    
    for (size_t i = 0; i < size; i++) {
        char c = data[i];
        
        if (c == '\n') {
            y++;
            x = 0;
        } else {
            vga_buffer[y * VGA_WIDTH + x] = make_vga_entry(c, color);
            x++;
        }
        
        if (x >= VGA_WIDTH) {
            x = 0;
            y++;
        }
        
        if (y >= VGA_HEIGHT) {
            y = VGA_HEIGHT - 1;
            // Scroll up
            for (size_t row = 0; row < VGA_HEIGHT - 1; row++) {
                for (size_t col = 0; col < VGA_WIDTH; col++) {
                    vga_buffer[row * VGA_WIDTH + col] = vga_buffer[(row + 1) * VGA_WIDTH + col];
                }
            }
            for (size_t col = 0; col < VGA_WIDTH; col++) {
                vga_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + col] = make_vga_entry(' ', color);
            }
        }
    }
}
