#include <stdbool.h>
#include <sys/types.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct lib_array {
    unsigned char *data;
    size_t capacity;
    size_t size;
    size_t element_size;
} lib_array_t;

typedef struct lib_window_t {
    float *vertex_array;
    GLuint vbo;
    GLuint vao;
    GLuint ebo;

    GLFWwindow *inner;
    int width;
    int height;
    bool should_draw;
    GLuint shader_program;
    unsigned int *indices_array;
} lib_window_t;

typedef struct lib_application{
    lib_window_t *window;
} lib_application_t;

typedef struct lib_window_attributes {
    char *title;
    int width;
    int height;
    bool resizable;
} lib_window_attributes_t;

lib_array_t *lib_array_create(size_t element_size);
void lib_array_add(lib_array_t *array, void *element);
void lib_array_destroy(lib_array_t *array);


lib_application_t *lib_application_create();
void lib_application_destroy(lib_application_t *application);
int lib_application_run(lib_application_t *application);

lib_window_t* lib_window_create(lib_window_attributes_t *attributes);
void lib_window_destroy(lib_window_t *window);



lib_window_t *lib_application_add_window(lib_application_t *application, lib_window_attributes_t *attributes);
