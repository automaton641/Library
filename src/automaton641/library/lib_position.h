#pragma once

typedef struct lib_position lib_position_t;

#include <automaton641/library/lib_includes.h>

struct lib_position {
    int x;
    int y;
};

lib_position_t *lib_position_create(int x, int y);