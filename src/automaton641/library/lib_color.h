#pragma once
struct lib_color;
typedef struct lib_color lib_color_t;

#include <automaton641/library/lib_includes.h>

struct lib_color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
};

lib_color_t *lib_color_create(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
void lib_color_update(lib_color_t *color, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
