#pragma once

typedef struct lib_size lib_size_t;

#include <automaton641/library/lib_includes.h>

struct lib_size {
    int width;
    int height;
};

lib_size_t *lib_size_create(int width, int height);