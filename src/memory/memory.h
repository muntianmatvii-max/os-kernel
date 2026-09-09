#ifndef MEMORY_H
#define MEMORY_H

#include "../kernel.h"
#include <stdint.h>

void memory_init();
void *malloc(size_t size);
void free(void *ptr);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);

#endif // MEMORY_H
