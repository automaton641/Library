#include <automaton641/library/lib_automaton_display.h>
#include <automaton641/library/lib_window.h>
#include <automaton641/library/lib_application.h>

lib_automaton_display_t *lib_automaton_display_create(lib_automaton_attributes_t *automaton_attributes) {
    lib_automaton_display_t *display = malloc(sizeof(lib_automaton_display_t));
    display->widget = lib_widget_create(display, lib_automaton_display_initialization, lib_automaton_display_draw);
    display->automaton = lib_automaton_create(automaton_attributes);
    return display;
}

void lib_automaton_display_initialization (lib_widget_t *widget, lib_application_t *application) {
    lib_automaton_display_t *display = widget->specialization;
    lib_automaton_t *automaton = display->automaton;
    (*automaton->initialization) (automaton);
    lib_automaton_start(automaton, application->window);
}



void lib_automaton_display_draw (lib_widget_t *widget, lib_application_t *application) {
    lib_automaton_display_t *display = widget->specialization;
    lib_automaton_t *automaton = display->automaton;
    lib_window_t *window = application->window;
    lib_color_t *color = window->color;
    int cell_size = display->cell_size;
    for (size_t y = 0; y < automaton->bidimensional->height; y++) {
        for (size_t x = 0; x < automaton->bidimensional->width; x++) {
            (*display->update_color) (color, automaton, x, y);
            lib_window_draw_quad(window, x * cell_size, y * cell_size, cell_size);
        }
    }
}
