#include <automaton641/library/lib_array.h>

void lib_array_add(lib_array_t *array, void *element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity*array->element_size);
    }
    memcpy(array->data+array->size*array->element_size, element, array->element_size);
    array->size++;
}

void lib_array_destroy(lib_array_t *array) {
    free(array->data);
    free(array);
}

lib_array_t *lib_array_create(size_t element_size) {
    lib_array_t *array = malloc(sizeof(lib_array_t));
    array->element_size = element_size;
    array->capacity = 16;
    array->size = 0;
    array->data = malloc(array->capacity*element_size);
    return array;
}

void *lib_array_get(lib_array_t *array, size_t index) {
    return (void*)(array->data+index*array->element_size);
}