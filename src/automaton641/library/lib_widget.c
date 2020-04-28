#include <automaton641/library/lib_widget.h>

lib_widget_t *lib_widget_create(void *specialization, lib_widget_initialization initialization, lib_widget_draw draw) {
    lib_widget_t *widget = malloc(sizeof(lib_widget_t));
    widget->specialization = specialization;
    widget->draw = draw;
    widget->initialization = initialization;
    return widget;
}