#include <automaton641/library/lib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


void exit_error(char *description) {
    printf("Error: %s\n", description);
    exit(EXIT_FAILURE);
}

void gl_error(char *error) {
     switch (glGetError())  {
         case GL_NO_ERROR:
         return;

         case GL_INVALID_ENUM:
         printf("%s\n", error);
         exit_error("GL_INVALID_ENUM");

         case GL_INVALID_VALUE:
         printf("%s\n", error);
         exit_error("GL_INVALID_VALUE");

         case GL_INVALID_OPERATION:
         printf("%s\n", error);
         exit_error("GL_INVALID_OPERATION");

         case GL_INVALID_FRAMEBUFFER_OPERATION:
         printf("%s\n", error);
         exit_error("GL_INVALID_FRAMEBUFFER_OPERATION");

         case GL_OUT_OF_MEMORY:
         printf("%s\n", error);
         exit_error("GL_OUT_OF_MEMORY");

         case GL_STACK_UNDERFLOW:
         printf("%s\n", error);
         exit_error("GL_STACK_UNDERFLOW");

         case GL_STACK_OVERFLOW:
         printf("%s\n", error);
         exit_error("GL_STACK_OVERFLOW");
     }

}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

lib_application_t* lib_application_create() {
    lib_application_t *application = malloc(sizeof(lib_application_t));
    setlocale(LC_ALL, "");
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
    application->window->should_draw = true;
}

lib_window_t* lib_window_create(lib_window_attributes_t *attributes) {
    if (!glfwInit())
    {
        exit_error("glfwInit");
    }
    glfwSetErrorCallback(error_callback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
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
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    glfwGetFramebufferSize(window->inner, &window->width, &window->height);
    printf("%s: %i\n", "window->width", window->width);
    printf("%s: %i\n", "window->height", window->height);

    glViewport(0, 0, window->width, window->height);
    glfwSwapInterval(1);
    glfwSetFramebufferSizeCallback(window->inner, framebuffer_size_callback);
    return window;
}

void lib_window_destroy(lib_window_t *window) {
    glfwDestroyWindow(window->inner);
    free(window->vertex_array);
    free(window->indices_array);
    glDeleteVertexArrays(1, &window->vao);
    glDeleteBuffers(1, &window->vbo);
    glDeleteBuffers(1, &window->ebo);
    free(window);
}


void* array_copy_allocate(void *array, size_t size, size_t element_size) {
    void *location = malloc(element_size*size);
    memcpy(location, array, element_size*size);
    return location;
}

char* read_file(char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        exit_error("file == NULL");
    }
    char character;
    lib_array_t *string_array = lib_array_create(sizeof(char));
    character = getc(file);
    while (character != EOF) {
      lib_array_add(string_array, &character);
      character = getc(file);
    }
    character = '\0';
    lib_array_add(string_array, &character);

    char *file_string = array_copy_allocate(string_array->data, string_array->size, sizeof(char));
    lib_array_destroy(string_array);
    return file_string;
}

GLuint compile_shader(int shader_type, char *path) {
    GLuint shader;
    shader = glCreateShader(shader_type);
    gl_error("glCreateShader");

    char *shader_source = read_file(path);
    glShaderSource(shader, 1, (const GLchar * const*)&shader_source, NULL);
    gl_error("glShaderSource");

    glCompileShader(shader);
    gl_error("glCompileShader");

    GLint success;
    char log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    gl_error("glGetShaderiv");
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, log);
        gl_error("glGetShaderInfoLog");
        printf("%s\n", log);
        if (shader_type == GL_VERTEX_SHADER) {
            exit_error("shader compilation GL_VERTEX_SHADER");
        }
        if (shader_type == GL_FRAGMENT_SHADER) {
            exit_error("shader compilation GL_FRAGMENT_SHADER");
        }
    }
    //free(shader_source);
    return shader;
}


void setup_opengl(lib_application_t *application) {
    lib_window_t *window = application->window;
    float vertex_array[] = {
         1.0f,  1.0f, 0.0f,  // top right
         1.0f, -1.0f, 0.0f,  // bottom right
        -1.0f, -1.0f, 0.0f,  // bottom left
        -1.0f,  1.0f, 0.0f   // top left
    };
    unsigned int indices_array[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    window->vertex_array = array_copy_allocate(vertex_array, 12, sizeof(float));
    window->indices_array = array_copy_allocate(indices_array, 6, sizeof(unsigned int));
    glGenBuffers(1, &window->vbo);
    gl_error("glGenBuffers");
    printf("hello\n");


    GLuint vertex_shader = compile_shader(GL_VERTEX_SHADER, "./resources/shaders/vertex_shader");
    GLuint fragment_shader = compile_shader(GL_FRAGMENT_SHADER, "./resources/shaders/fragment_shader");
    window->shader_program = glCreateProgram();
    glAttachShader(window->shader_program, vertex_shader);
    gl_error("glAttachShader");

    glAttachShader(window->shader_program, fragment_shader);
    gl_error("glAttachShader");

    glLinkProgram(window->shader_program);
    gl_error("glLinkProgram");

    GLint success;
    char log[512];
    glGetProgramiv(window->shader_program, GL_LINK_STATUS, &success);
    gl_error("glGetShaderiv");
    if(!success)
    {
        glGetProgramInfoLog(window->shader_program, 512, NULL, log);
        gl_error("glGetProgramInfoLog");
        printf("%s\n", log);
        exit_error("shader linking");
    }

    glUseProgram(window->shader_program);
    gl_error("glUseProgram");

    glGenVertexArrays(1, &window->vao);
    gl_error("glGenBuffers");

    glGenBuffers(1, &window->vbo);
    gl_error("glGenBuffers");

    glGenBuffers(1, &window->ebo);
    gl_error("glGenBuffers");

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(window->vao);
    gl_error("glBindVertexArray");

    glBindBuffer(GL_ARRAY_BUFFER, window->vbo);
    gl_error("glBindBuffer");

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_array), window->vertex_array, GL_STATIC_DRAW);
    gl_error("glBufferData");

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, window->ebo);
    gl_error("glBindBuffer");

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_array), window->indices_array, GL_STATIC_DRAW);
    gl_error("glBufferData");

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    gl_error("glVertexAttribPointer");

    glEnableVertexAttribArray(0);
    gl_error("glEnableVertexAttribArray");

}

lib_window_t *lib_application_add_window(lib_application_t *application, lib_window_attributes_t *attributes) {
    application->window = lib_window_create(attributes);
    glfwSetWindowUserPointer(application->window->inner, application);
    setup_opengl(application);
    return application->window;
}

void lib_application_destroy(lib_application_t *application) {
    lib_window_destroy(application->window);
    glfwTerminate();
    free(application);
}

int lib_application_run(lib_application_t *application) {
    lib_window_t *window = application->window;
    GLFWwindow *inner = window->inner;
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    gl_error("glClearColor");
    printf("%s\n", glGetString(GL_RENDERER));
    printf("%s\n", glGetString(GL_VERSION));
    glfwShowWindow(inner);
    while (!glfwWindowShouldClose(inner))
    {
        if (window->should_draw) {
            glClear(GL_COLOR_BUFFER_BIT);
            gl_error("glClear");
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            gl_error("glDrawElements");
            glfwSwapBuffers(inner);
            window->should_draw = false;
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
