#pragma once

struct lib_automaton_display;
typedef struct lib_automaton_display lib_automaton_display_t;

#include <automaton641/library/lib_includes.h>
#include <automaton641/library/lib_widget.h>
#include <automaton641/library/lib_automaton.h>
#include <automaton641/library/lib_color.h>



typedef void(* lib_automaton_display_update_color) (lib_color_t *color, lib_automaton_t *automaton, size_t x, size_t y);
struct lib_automaton_display {
    lib_widget_t *widget;
    lib_automaton_t *automaton;
    int cell_size;
    lib_automaton_display_update_color update_color;
};
lib_automaton_display_t *lib_automaton_display_create(lib_automaton_attributes_t *automaton_attributes);
void lib_automaton_display_initialization (lib_widget_t *widget, lib_application_t *application);
void lib_automaton_display_draw (lib_widget_t *widget, lib_application_t *application);