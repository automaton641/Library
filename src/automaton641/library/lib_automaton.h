#pragma once

#include <automaton641/library/lib_types.h>

struct lib_automaton;
typedef struct lib_automaton lib_automaton_t;

typedef void(* lib_automaton_initialization) (lib_automaton_t *automaton);
typedef void(* lib_automaton_iteration) (lib_automaton_t *automaton);

struct lib_automaton {
    lib_bidimensional_t *bidimensional;
    lib_automaton_iteration iteration;
    bool iterate;
    int iteration_time;
    pthread_t thread_id;
    lib_automaton_initialization initialization;
    void *user_data;
};

lib_automaton_t *lib_automaton_create(lib_automaton_attributes_t *attributes);
void lib_automaton_start(lib_automaton_t *automaton, lib_window_t *window);
void lib_automaton_destroy(lib_automaton_t *automaton);
