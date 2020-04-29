#pragma once

struct lib_widget;
typedef struct lib_widget lib_widget_t;

#include <automaton641/library/lib_includes.h>
#include <automaton641/library/lib_application.h>

typedef void(* lib_widget_draw) (lib_widget_t *widget, lib_application_t *application);
typedef void(* lib_widget_initialization) (lib_widget_t *widget, lib_application_t *application);
lib_widget_t *lib_widget_create(void *specialization, lib_widget_initialization initialization, lib_widget_draw draw);


struct lib_widget {
    lib_widget_initialization initialization;
    lib_widget_draw draw;
    double padding;
    double border;
    double margin;
    double proportion;
    double grow_ratio;
    void *specialization;
};