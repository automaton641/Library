#include <automaton641/library/lib_widget.h>

lib_widget_t *lib_widget_create(void *specialization, lib_widget_initialization initialization, lib_widget_draw draw) {
    lib_widget_t *widget = malloc(sizeof(lib_widget_t));
    widget->specialization = specialization;
    widget->draw = draw;
    widget->initialization = initialization;
    widget->padding = 8;
    widget->border = 8;
    widget->margin = 8;
    widget->proportion = 1.0;
    widget->grow_ratio = 1.0;
    return widget;
}