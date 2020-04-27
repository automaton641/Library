#include <automaton641/library/lib_color.h>

void lib_color_update(lib_color_t *color, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
    color->red = red;
    color->green = green;
    color->blue = blue;
    color->alpha = alpha;
}

lib_color_t *lib_color_create(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
    lib_color_t *color = malloc(sizeof(lib_color_t));
    color->red = red;
    color->green = green;
    color->blue = blue;
    color->alpha = alpha;
}
