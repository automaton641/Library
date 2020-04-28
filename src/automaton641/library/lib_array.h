#pragma once

#include <automaton641/library/lib_includes.h>

struct lib_array;
typedef struct lib_array lib_array_t;


struct lib_array {
    unsigned char *data;
    size_t capacity;
    size_t size;
    size_t element_size;
};


lib_array_t *lib_array_create(size_t element_size);
void lib_array_add(lib_array_t *array, void *element);
void *lib_array_get(lib_array_t *array, size_t index);
void lib_array_destroy(lib_array_t *array);