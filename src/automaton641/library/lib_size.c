#include <automaton641/library/lib_size.h>

lib_size_t *lib_position_create(int width, int height) {
    lib_size_t *size = malloc(sizeof(lib_size_t));
    size->width = width;
    size->height = height;
    return size;
}