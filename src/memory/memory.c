#include "memory.h"

#define HEAP_START 0x100000
#define HEAP_SIZE  0x100000

static void *heap_ptr = (void *)HEAP_START;
static size_t heap_used = 0;

void memory_init() {
    heap_ptr = (void *)HEAP_START;
    heap_used = 0;
}

void *malloc(size_t size) {
    if (heap_used + size > HEAP_SIZE) {
        return NULL;
    }
    
    void *ptr = (void *)((uintptr_t)HEAP_START + heap_used);
    heap_used += size;
    
    return ptr;
}

void free(void *ptr) {
    (void)ptr;
    // Simple allocator - no free implementation yet
}

void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *d = (uint8_t *)dest;
    const uint8_t *s = (const uint8_t *)src;
    
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    
    return dest;
}

void *memset(void *s, int c, size_t n) {
    uint8_t *ptr = (uint8_t *)s;
    
    for (size_t i = 0; i < n; i++) {
        ptr[i] = (uint8_t)c;
    }
    
    return s;
}
