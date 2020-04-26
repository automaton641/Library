#include <stdbool.h>
#include <sys/types.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <pthread.h>


struct lib_automaton;
struct lib_widget;
struct lib_application_t;
typedef struct lib_application lib_application_t;
typedef struct lib_widget lib_widget_t;
typedef struct lib_automaton lib_automaton_t;
typedef void(* lib_automaton_iteration) (lib_automaton_t *automaton);
typedef void(* lib_widget_initialization) (lib_widget_t *widget, lib_application_t *application);
typedef void(* lib_widget_draw) (lib_widget_t *widget, lib_application_t *application);

typedef struct lib_bidimensional {
    unsigned char *data;
    size_t element_size;
    size_t width;
    size_t height;
} lib_bidimensional_t;

struct lib_automaton {
    lib_bidimensional_t *bidimensional;
    lib_automaton_iteration iteration;
    bool iterate;
    int iteration_time;
    pthread_t thread_id;
};


typedef struct lib_array {
    unsigned char *data;
    size_t capacity;
    size_t size;
    size_t element_size;
} lib_array_t;

typedef struct lib_color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} lib_color_t;

struct lib_widget {
    lib_widget_initialization initialization;
    lib_widget_draw draw;
    void *specialization;
};

typedef struct lib_window_t {
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
} lib_window_t;

struct lib_application{
    lib_window_t *window;
};

typedef struct lib_window_attributes {
    char *title;
    int width;
    int height;
    bool resizable;
} lib_window_attributes_t;

typedef struct lib_automaton_attributes {
    size_t element_size;
    size_t width;
    size_t height;
    int iteration_time;
    lib_automaton_iteration iteration;
} lib_automaton_attributes_t;

typedef struct lib_automaton_display {
    lib_widget_t *widget;
    lib_automaton_t *automaton;
    int cell_size;
} lib_automaton_display_t;

lib_widget_t *lib_widget_create(void *specialization, lib_widget_initialization initialization, lib_widget_draw draw);

lib_automaton_display_t *lib_automaton_display_create(lib_automaton_attributes_t *automaton_attributes);

lib_color_t *lib_color_create(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);

lib_bidimensional_t *lib_bidimensional_create(size_t element_size, size_t width, size_t height);
size_t lib_bidimensional_index(lib_bidimensional_t *bidimensional, size_t x, size_t y);
void lib_bidimensional_set(lib_bidimensional_t *bidimensional, void *element, size_t x, size_t y);
void *lib_bidimensional_get(lib_bidimensional_t *bidimensional, size_t x, size_t y);
void lib_bidimensional_destroy(lib_bidimensional_t *bidimensional);

lib_automaton_t *lib_automaton_create(lib_automaton_attributes_t *attributes);
void lib_automaton_start(lib_automaton_t *automaton);
void lib_automaton_destroy(lib_automaton_t *automaton);


lib_array_t *lib_array_create(size_t element_size);
void lib_array_add(lib_array_t *array, void *element);
void lib_array_destroy(lib_array_t *array);

lib_application_t *lib_application_create();
void lib_application_destroy(lib_application_t *application);
int lib_application_run(lib_application_t *application);
lib_window_t *lib_application_add_window(lib_application_t *application, lib_window_attributes_t *attributes);

lib_window_t* lib_window_create(lib_window_attributes_t *attributes);
void lib_window_destroy(lib_window_t *window);

void exit_error(char *description);
