#pragma once
#include <automaton641/library/lib_color.h>
#include <automaton641/library/lib_window.h>
#include <automaton641/library/lib_automaton.h>
#include <automaton641/library/lib_types.h>

struct lib_bidimensional {
    unsigned char *data;
    size_t element_size;
    size_t width;
    size_t height;
};


struct lib_array {
    unsigned char *data;
    size_t capacity;
    size_t size;
    size_t element_size;
};



struct lib_widget {
    lib_widget_initialization initialization;
    lib_widget_draw draw;
    void *specialization;
};



struct lib_application{
    lib_window_t *window;
};

struct lib_automaton_attributes {
    size_t element_size;
    size_t width;
    size_t height;
    int iteration_time;
    lib_automaton_iteration iteration;
    lib_automaton_initialization initialization;
    void *user_data;
};


struct lib_window_automaton_pack {
    lib_window_t *window;
    lib_automaton_t *automaton;
};

lib_widget_t *lib_widget_create(void *specialization, lib_widget_initialization initialization, lib_widget_draw draw);




lib_bidimensional_t *lib_bidimensional_create(size_t element_size, size_t width, size_t height);
size_t lib_bidimensional_index(lib_bidimensional_t *bidimensional, size_t x, size_t y);
void lib_bidimensional_set(lib_bidimensional_t *bidimensional, void *element, size_t x, size_t y);
void *lib_bidimensional_get(lib_bidimensional_t *bidimensional, size_t x, size_t y);
void lib_bidimensional_destroy(lib_bidimensional_t *bidimensional);




lib_array_t *lib_array_create(size_t element_size);
void lib_array_add(lib_array_t *array, void *element);
void lib_array_destroy(lib_array_t *array);

lib_application_t *lib_application_create();
void lib_application_destroy(lib_application_t *application);
int lib_application_run(lib_application_t *application);
lib_window_t *lib_application_add_window(lib_application_t *application, lib_window_attributes_t *attributes);



void exit_error(char *description);
