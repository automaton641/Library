#include <automaton641/library/lib_general.h>
#include <automaton641/library/lib_array.h>

int lib_msleep(long msec)
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

void lib_exit_error(char *description) {
    printf("Error: %s\n", description);
    exit(EXIT_FAILURE);
}

void lib_gl_error(char *error) {
     switch (glGetError())  {
         case GL_NO_ERROR:
         return;
         case GL_INVALID_ENUM:
         printf("%s\n", error);
         lib_exit_error("GL_INVALID_ENUM");

         case GL_INVALID_VALUE:
         printf("%s\n", error);
         lib_exit_error("GL_INVALID_VALUE");

         case GL_INVALID_OPERATION:
         printf("%s\n", error);
         lib_exit_error("GL_INVALID_OPERATION");

         case GL_INVALID_FRAMEBUFFER_OPERATION:
         printf("%s\n", error);
         lib_exit_error("GL_INVALID_FRAMEBUFFER_OPERATION");

         case GL_OUT_OF_MEMORY:
         printf("%s\n", error);
         lib_exit_error("GL_OUT_OF_MEMORY");

         case GL_STACK_UNDERFLOW:
         printf("%s\n", error);
         lib_exit_error("GL_STACK_UNDERFLOW");

         case GL_STACK_OVERFLOW:
         printf("%s\n", error);
         lib_exit_error("GL_STACK_OVERFLOW");
     }

}

void* lib_copy_allocate(void *array, size_t size, size_t element_size) {
    void *location = malloc(element_size*size);
    memcpy(location, array, element_size*size);
    return location;
}

char* lib_read_file(char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        lib_exit_error("file == NULL");
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

    char *file_string = lib_copy_allocate(string_array->data, string_array->size, sizeof(char));
    lib_array_destroy(string_array);
    return file_string;
}

GLuint lib_compile_shader(int shader_type, char *path) {
    GLuint shader;
    shader = glCreateShader(shader_type);
    lib_gl_error("glCreateShader");

    char *shader_source = lib_read_file(path);
    glShaderSource(shader, 1, (const GLchar * const*)&shader_source, NULL);
    lib_gl_error("glShaderSource");

    glCompileShader(shader);
    lib_gl_error("glCompileShader");

    GLint success;
    char log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    lib_gl_error("glGetShaderiv");
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, log);
        lib_gl_error("glGetShaderInfoLog");
        printf("%s\n", log);
        if (shader_type == GL_VERTEX_SHADER) {
            lib_exit_error("shader compilation GL_VERTEX_SHADER");
        }
        if (shader_type == GL_FRAGMENT_SHADER) {
            lib_exit_error("shader compilation GL_FRAGMENT_SHADER");
        }
    }
    //free(shader_source);
    return shader;
}
