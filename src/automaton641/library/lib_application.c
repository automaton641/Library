#include <automaton641/library/lib_application.h>
#include <automaton641/library/lib_widget.h>
#include <automaton641/library/lib.h>

lib_window_t *lib_application_add_window(lib_application_t *application, lib_window_attributes_t *attributes) {
    application->window = lib_window_create(attributes);
    glfwSetWindowUserPointer(application->window->inner, application);
    lib_application_setup_opengl(application);
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
            lib_gl_error("glTexImage2D");

            glGenerateMipmap(GL_TEXTURE_2D);
            lib_gl_error("glGenerateMipmap");
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            lib_gl_error("glDrawElements");
            glfwSwapBuffers(inner);
            window->should_draw = false;
        }
        glfwPollEvents();
    }
    return EXIT_SUCCESS;
}


lib_application_t* lib_application_create() {
    lib_application_t *application = malloc(sizeof(lib_application_t));
    setlocale(LC_ALL, "");
    srand(time(NULL));   // Initialization, should only be called once.
    return application;
}


void lib_application_setup_opengl(lib_application_t *application) {
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

    window->vertex_array = lib_copy_allocate(vertex_array, sizeof(vertex_array), sizeof(float));
    window->indices_array = lib_copy_allocate(indices_array, sizeof(indices_array), sizeof(unsigned int));
    glGenBuffers(1, &window->vbo);
    lib_gl_error("glGenBuffers");


    GLuint vertex_shader = lib_compile_shader(GL_VERTEX_SHADER, "./resources/shaders/vertex_shader");
    GLuint fragment_shader = lib_compile_shader(GL_FRAGMENT_SHADER, "./resources/shaders/fragment_shader");
    window->shader_program = glCreateProgram();
    glAttachShader(window->shader_program, vertex_shader);
    lib_gl_error("glAttachShader");

    glAttachShader(window->shader_program, fragment_shader);
    lib_gl_error("glAttachShader");

    glLinkProgram(window->shader_program);
    lib_gl_error("glLinkProgram");

    GLint success;
    char log[512];
    glGetProgramiv(window->shader_program, GL_LINK_STATUS, &success);
    lib_gl_error("glGetShaderiv");
    if(!success)
    {
        glGetProgramInfoLog(window->shader_program, 512, NULL, log);
        lib_gl_error("glGetProgramInfoLog");
        printf("%s\n", log);
        lib_exit_error("shader linking");
    }

    glUseProgram(window->shader_program);
    lib_gl_error("glUseProgram");

    glGenVertexArrays(1, &window->vao);
    lib_gl_error("glGenBuffers");

    glGenBuffers(1, &window->vbo);
    lib_gl_error("glGenBuffers");

    glGenBuffers(1, &window->ebo);
    lib_gl_error("glGenBuffers");

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(window->vao);
    lib_gl_error("glBindVertexArray");

    glBindBuffer(GL_ARRAY_BUFFER, window->vbo);
    lib_gl_error("glBindBuffer");

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_array), window->vertex_array, GL_STATIC_DRAW);
    lib_gl_error("glBufferData");

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, window->ebo);
    lib_gl_error("glBindBuffer");

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_array), window->indices_array, GL_STATIC_DRAW);
    lib_gl_error("glBufferData");

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    lib_gl_error("glVertexAttribPointer");

    glEnableVertexAttribArray(0);
    lib_gl_error("glEnableVertexAttribArray");

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    lib_gl_error("glVertexAttribPointer");

    glEnableVertexAttribArray(1);
    lib_gl_error("glEnableVertexAttribArray");

    glGenTextures(1, &window->texture);
    lib_gl_error("glGenTextures");

    glActiveTexture(GL_TEXTURE0);
    lib_gl_error("glActiveTexture");

    glBindTexture(GL_TEXTURE_2D, window->texture);
    lib_gl_error("glBindTexture");

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, window->width, window->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, window->pixels);
    lib_gl_error("glTexImage2D");

    glGenerateMipmap(GL_TEXTURE_2D);
    lib_gl_error("glGenerateMipmap");

    GLint location = glGetUniformLocation(window->shader_program, "ourTexture");
    lib_gl_error("glGetUniformLocation");

    glUniform1i(location, 0);
    lib_gl_error("glUniform1i");

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    lib_gl_error("glClearColor");

    printf("%s\n", glGetString(GL_RENDERER));
    printf("%s\n", glGetString(GL_VERSION));

}