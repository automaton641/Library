#pragma once

#include <automaton641/library/lib_includes.h>
#include <automaton641/library/lib_window.h>
#include <automaton641/library/lib_bidimensional.h>


struct lib_automaton;
struct lib_automaton_attributes;
struct lib_window_automaton_pack;

typedef struct lib_automaton_attributes lib_automaton_attributes_t;
typedef struct lib_window_automaton_pack lib_window_automaton_pack_t;
typedef struct lib_automaton lib_automaton_t;

typedef void(* lib_automaton_initialization) (lib_automaton_t *automaton);
typedef void(* lib_automaton_iteration) (lib_automaton_t *automaton);


lib_automaton_t *lib_automaton_create(lib_automaton_attributes_t *attributes);
void lib_automaton_start(lib_automaton_t *automaton, lib_window_t *window);
void lib_automaton_destroy(lib_automaton_t *automaton);



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


struct lib_automaton {
    lib_bidimensional_t *bidimensional;
    lib_automaton_iteration iteration;
    bool iterate;
    int iteration_time;
    pthread_t thread_id;
    lib_automaton_initialization initialization;
    void *user_data;
};


