#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "../kernel.h"

void filesystem_init();
int filesystem_create_file(const char *name, uint32_t size);
int filesystem_find_file(const char *name);
int strcmp(const char *s1, const char *s2);

#endif // FILESYSTEM_H
