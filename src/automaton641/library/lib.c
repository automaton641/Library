#include <automaton641/library/lib.h>


int msleep(long msec)
{
    struct timespec ts;
    int res;
    if (msec < 0) {
        errno = EINVAL;
        return -1;
    }
    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;
    res = nanosleep(&ts, NULL);
    return res;
}

lib_widget_t *lib_widget_create(void *specialization, lib_widget_initialization initialization, lib_widget_draw draw) {
    lib_widget_t *widget = malloc(sizeof(lib_widget_t));
    widget->specialization = specialization;
    widget->draw = draw;
    widget->initialization = initialization;
    return widget;
}

void lib_automaton_display_initialization (lib_widget_t *widget, lib_application_t *application) {
    lib_automaton_display_t *display = widget->specialization;
    lib_automaton_t *automaton = display->automaton;
    (*automaton->initialization) (automaton);
    lib_automaton_start(automaton, application->window);
}



void lib_automaton_display_draw (lib_widget_t *widget, lib_application_t *application) {
    lib_automaton_display_t *display = widget->specialization;
    lib_automaton_t *automaton = display->automaton;
    lib_window_t *window = application->window;
    lib_color_t *color = window->color;
    int cell_size = display->cell_size;
    for (size_t y = 0; y < automaton->bidimensional->height; y++) {
        for (size_t x = 0; x < automaton->bidimensional->width; x++) {
            (*display->update_color) (color, automaton, x, y);
            lib_window_draw_quad(window, x * cell_size, y * cell_size, cell_size);
        }
    }
}






void exit_error(char *description) {
    printf("Error: %s\n", description);
    exit(EXIT_FAILURE);
}

lib_bidimensional_t *lib_bidimensional_create(size_t element_size, size_t width, size_t height) {
    lib_bidimensional_t *bidimensional = malloc(sizeof(lib_bidimensional_t));
    bidimensional->data = malloc(element_size*width*height);
    bidimensional->element_size = element_size;
    bidimensional->width = width;
    bidimensional->height = height;
}

void lib_bidimensional_destroy(lib_bidimensional_t *bidimensional) {
    free(bidimensional->data);
    free(bidimensional);
}

size_t lib_bidimensional_index(lib_bidimensional_t *bidimensional, size_t x, size_t y) {
    return y*bidimensional->width+x;
}


void *lib_bidimensional_get(lib_bidimensional_t *bidimensional, size_t x, size_t y) {
    size_t index = lib_bidimensional_index(bidimensional, x, y);
    return (void*)(bidimensional->data+index*bidimensional->element_size);
}

void lib_bidimensional_set(lib_bidimensional_t *bidimensional, void *element, size_t x, size_t y) {
    memcpy(lib_bidimensional_get(bidimensional, x, y), element, bidimensional->element_size);
}



void lib_array_add(lib_array_t *array, void *element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity*array->element_size);
    }
    memcpy(array->data+array->size*array->element_size, element, array->element_size);
    array->size++;
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



lib_application_t* lib_application_create() {
    lib_application_t *application = malloc(sizeof(lib_application_t));
    setlocale(LC_ALL, "");
    srand(time(NULL));   // Initialization, should only be called once.
    return application;
}

void lib_array_destroy(lib_array_t *array) {
    free(array->data);
    free(array);
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
        // positions          // texture coords
         1.0f,  1.0f, 0.0f,   1.0f, 1.0f,   // top right
         1.0f, -1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -1.0f, -1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
        -1.0f,  1.0f, 0.0f,   0.0f, 1.0f    // top left
    };
    unsigned int indices_array[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    window->vertex_array = array_copy_allocate(vertex_array, sizeof(vertex_array), sizeof(float));
    window->indices_array = array_copy_allocate(indices_array, sizeof(indices_array), sizeof(unsigned int));
    glGenBuffers(1, &window->vbo);
    gl_error("glGenBuffers");


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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    gl_error("glVertexAttribPointer");

    glEnableVertexAttribArray(0);
    gl_error("glEnableVertexAttribArray");

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    gl_error("glVertexAttribPointer");

    glEnableVertexAttribArray(1);
    gl_error("glEnableVertexAttribArray");

    glGenTextures(1, &window->texture);
    gl_error("glGenTextures");

    glActiveTexture(GL_TEXTURE0);
    gl_error("glActiveTexture");

    glBindTexture(GL_TEXTURE_2D, window->texture);
    gl_error("glBindTexture");

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, window->width, window->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, window->pixels);
    gl_error("glTexImage2D");

    glGenerateMipmap(GL_TEXTURE_2D);
    gl_error("glGenerateMipmap");

    GLint location = glGetUniformLocation(window->shader_program, "ourTexture");
    gl_error("glGetUniformLocation");

    glUniform1i(location, 0);
    gl_error("glUniform1i");

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    gl_error("glClearColor");

    printf("%s\n", glGetString(GL_RENDERER));
    printf("%s\n", glGetString(GL_VERSION));

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
    lib_widget_t *widget = window->widget;
    glfwShowWindow(inner);
    if (widget != NULL) {
        (*widget->initialization) (widget, application);
    }
    while (!glfwWindowShouldClose(inner))
    {
        if (window->should_draw) {
            if (widget != NULL) {
                (*widget->draw) (widget, application);
            }
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, window->width, window->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, window->pixels);
            gl_error("glTexImage2D");

            glGenerateMipmap(GL_TEXTURE_2D);
            gl_error("glGenerateMipmap");
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
