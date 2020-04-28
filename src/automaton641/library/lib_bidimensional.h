#pragma once

#include <automaton641/library/lib_includes.h>

struct lib_bidimensional;
typedef struct lib_bidimensional lib_bidimensional_t;
struct lib_bidimensional {
    unsigned char *data;
    size_t element_size;
    size_t width;
    size_t height;
};


lib_bidimensional_t *lib_bidimensional_create(size_t element_size, size_t width, size_t height);
size_t lib_bidimensional_index(lib_bidimensional_t *bidimensional, size_t x, size_t y);
void lib_bidimensional_set(lib_bidimensional_t *bidimensional, void *element, size_t x, size_t y);
void *lib_bidimensional_get(lib_bidimensional_t *bidimensional, size_t x, size_t y);
void lib_bidimensional_destroy(lib_bidimensional_t *bidimensional);