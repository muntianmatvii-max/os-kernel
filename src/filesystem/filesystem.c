#include "filesystem.h"
#include "../memory/memory.h"

#define MAX_FILES 256
#define MAX_FILENAME 64

typedef struct {
    char name[MAX_FILENAME];
    uint32_t size;
    uint32_t inode;
    uint8_t type; // 0 = file, 1 = directory
} file_entry_t;

static file_entry_t file_table[MAX_FILES];
static uint32_t file_count = 0;

void filesystem_init() {
    memset(file_table, 0, sizeof(file_table));
    file_count = 0;
    
    // Create root directory
    file_table[0].type = 1; // directory
    file_table[0].inode = 0;
    memcpy(file_table[0].name, "root", 5);
    file_count = 1;
}

int filesystem_create_file(const char *name, uint32_t size) {
    if (file_count >= MAX_FILES) {
        return -1; // No space
    }
    
    // Check if file already exists
    for (uint32_t i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].name, name) == 0) {
            return -1; // File exists
        }
    }
    
    file_table[file_count].type = 0; // file
    file_table[file_count].size = size;
    file_table[file_count].inode = file_count;
    memcpy(file_table[file_count].name, name, MAX_FILENAME);
    
    file_count++;
    return file_count - 1;
}

int filesystem_find_file(const char *name) {
    for (uint32_t i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (int)((unsigned char)*s1 - (unsigned char)*s2);
}
