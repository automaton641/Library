#include <automaton641/library/lib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void exit_error(char *description) {
    printf("Error: %s\n", description);
    exit(EXIT_FAILURE);
}

lib_application_t* lib_application_create() {
    lib_application_t *application = malloc(sizeof(lib_application_t));
    return application;
}

void lib_array_destroy(lib_array_t *array) {
    free(array->data);
    free(array);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    lib_application_t *application = glfwGetWindowUserPointer(window);
    application->window->width = width;
    application->window->height = height;
    glViewport(0, 0, width, height);
}

lib_window_t* lib_window_create(lib_window_attributes_t *attributes) {
    if (!glfwInit())
    {
        exit_error("glfwInit");
    }
    glfwSetErrorCallback(error_callback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    if (attributes->resizable) {
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    } else {
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }
    lib_window_t *window = malloc(sizeof(lib_window_t));
    window->inner = glfwCreateWindow(attributes->width, attributes->height, attributes->title, NULL, NULL);
    if (!window->inner)
    {
        exit_error("glfwCreateWindow");
    }
    window->should_draw = true;
    glfwMakeContextCurrent(window->inner);
    glfwGetFramebufferSize(window->inner, &window->width, &window->height);
    glViewport(0, 0, window->width, window->height);
    glfwSwapInterval(1);
    glfwSetFramebufferSizeCallback(window->inner, framebuffer_size_callback);
    return window;
}

void lib_window_destroy(lib_window_t *window) {
    glfwDestroyWindow(window->inner);
    free(window);
}

lib_window_t *lib_application_add_window(lib_application_t *application, lib_window_attributes_t *attributes) {
    application->window = lib_window_create(attributes);
    glfwSetWindowUserPointer(application->window->inner, application);
    return application->window;
}

void lib_application_destroy(lib_application_t *application) {
    lib_window_destroy(application->window);
    glfwTerminate();
    free(application);
}

int lib_application_run(lib_application_t *application) {
    glfwShowWindow(application->window->inner);
    while (!glfwWindowShouldClose(application->window->inner))
    {
        if (application->window->should_draw) {

            glfwSwapBuffers(application->window->inner);
            application->window->should_draw = false;
        }
        glfwPollEvents();
    }
    return EXIT_SUCCESS;
}

lib_array_t *lib_array_create(size_t element_size) {
    lib_array_t *array = malloc(sizeof(lib_array_t));
    array->element_size = element_size;
    array->capacity = 16;
    array->size = 0;
    array->data = malloc(array->capacity*element_size);
    return array;
}

void lib_array_add(lib_array_t *array, void *element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity*array->element_size);
    }
    memcpy(array->data+array->size*array->element_size, element, array->element_size);
    array->size++;
}
