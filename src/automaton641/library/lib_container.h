#pragma once
typedef enum lib_container_type {HORIZONTAL, VERTICAL} lib_container_type_t; 
typedef struct lib_container lib_container_t;
#include <automaton641/library/lib_includes.h>
#include <automaton641/library/lib_widget.h>
struct lib_container {
    lib_widget_t *widget;
    lib_container_type_t type;
};

lib_container_t *lib_container_create(lib_container_type_t type);