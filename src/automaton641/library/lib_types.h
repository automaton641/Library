#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <pthread.h>

struct lib_widget;
struct lib_application_t;
struct lib_bidimensional;
struct lib_array;
struct lib_automaton_attributes;
struct lib_window_automaton_pack;
struct lib_color;

typedef struct lib_color lib_color_t;
typedef struct lib_application lib_application_t;
typedef struct lib_widget lib_widget_t;
typedef struct lib_bidimensional lib_bidimensional_t;
typedef struct lib_array lib_array_t;
typedef struct lib_automaton_attributes lib_automaton_attributes_t;
typedef struct lib_window_automaton_pack lib_window_automaton_pack_t;

typedef void(* lib_widget_initialization) (lib_widget_t *widget, lib_application_t *application);
typedef void(* lib_widget_draw) (lib_widget_t *widget, lib_application_t *application);
