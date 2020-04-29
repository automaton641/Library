#include <automaton641/library/lib_container.h>


void lib_container_display_draw (lib_widget_t *widget, lib_application_t *application) {

}

void lib_container_display_initialization (lib_widget_t *widget, lib_application_t *application) {
    
}


lib_container_t *lib_container_create(lib_container_type_t type) {
    lib_container_t *container = malloc(sizeof(lib_container_t));
    container->type = type;
    container->widget = lib_widget_create(container, lib_container_display_initialization, lib_container_display_draw);
    return container;
}