#pragma once

struct lib_application_t;
typedef struct lib_application lib_application_t;

#include <automaton641/library/lib_includes.h>
#include <automaton641/library/lib_window.h>

struct lib_application{
    lib_window_t *window;
};

lib_application_t *lib_application_create();
void lib_application_destroy(lib_application_t *application);
int lib_application_run(lib_application_t *application);
lib_window_t *lib_application_add_window(lib_application_t *application, lib_window_attributes_t *attributes);
void lib_application_setup_opengl(lib_application_t *application);
