#include <automaton641/library/lib_bidimensional.h>


lib_bidimensional_t *lib_bidimensional_create(size_t element_size, size_t width, size_t height) {
    lib_bidimensional_t *bidimensional = malloc(sizeof(lib_bidimensional_t));
    bidimensional->data = malloc(element_size*width*height);
    bidimensional->element_size = element_size;
    bidimensional->width = width;
    bidimensional->height = height;
}

void lib_bidimensional_destroy(lib_bidimensional_t *bidimensional) {
    free(bidimensional->data);
    free(bidimensional);
}

size_t lib_bidimensional_index(lib_bidimensional_t *bidimensional, size_t x, size_t y) {
    return y*bidimensional->width+x;
}


void *lib_bidimensional_get(lib_bidimensional_t *bidimensional, size_t x, size_t y) {
    size_t index = lib_bidimensional_index(bidimensional, x, y);
    return (void*)(bidimensional->data+index*bidimensional->element_size);
}

void lib_bidimensional_set(lib_bidimensional_t *bidimensional, void *element, size_t x, size_t y) {
    memcpy(lib_bidimensional_get(bidimensional, x, y), element, bidimensional->element_size);
}
