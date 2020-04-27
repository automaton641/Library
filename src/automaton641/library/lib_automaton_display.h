#pragma once
#include <automaton641/library/lib_types.h>

struct lib_automaton_display;
typedef struct lib_automaton_display lib_automaton_display_t;


struct lib_automaton_display {
    lib_widget_t *widget;
    lib_automaton_t *automaton;
    int cell_size;
    lib_automaton_display_update_color update_color;
};

typedef void(* lib_automaton_display_update_color) (lib_color_t *color, lib_automaton_t *automaton, size_t x, size_t y);

lib_automaton_display_t *lib_automaton_display_create(lib_automaton_attributes_t *automaton_attributes);
