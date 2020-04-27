#include <automaton641/library/lib_automaton_display.h>

lib_automaton_display_t *lib_automaton_display_create(lib_automaton_attributes_t *automaton_attributes) {
    lib_automaton_display_t *display = malloc(sizeof(lib_automaton_display_t));
    display->widget = lib_widget_create(display, lib_automaton_display_initialization, lib_automaton_display_draw);
    display->automaton = lib_automaton_create(automaton_attributes);
    return display;
}
