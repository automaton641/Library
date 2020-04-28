#pragma once

struct lib_window;
struct lib_window_attributes;
typedef struct lib_window_attributes lib_window_attributes_t;
typedef struct lib_window lib_window_t;

#include <automaton641/library/lib_includes.h>
#include<automaton641/library/lib_widget.h>
#include<automaton641/library/lib_color.h>


struct lib_window_attributes {
    char *title;
    int width;
    int height;
    bool resizable;
};

struct lib_window {
    lib_widget_t *widget;
    float *vertex_array;
    GLuint vbo;
    GLuint vao;
    GLuint ebo;
    GLuint texture;
    const GLFWvidmode* mode;
    GLFWwindow *inner;
    int width;
    int height;
    int frame_width;
    int frame_height;
    bool should_draw;
    lib_color_t *color;
    GLuint shader_program;
    unsigned int *indices_array;
    unsigned char *pixels;
};

lib_window_t* lib_window_create(lib_window_attributes_t *attributes);

void lib_window_draw_quad(lib_window_t *window, size_t x, size_t y, size_t size);

void lib_window_destroy(lib_window_t *window);
