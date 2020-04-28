#pragma once

#include <automaton641/library/lib_includes.h>

void lib_exit_error(char *description);
void lib_gl_error(char *error);
int lib_msleep(long msec);
void* lib_copy_allocate(void *array, size_t size, size_t element_size);
char* lib_read_file(char *path);
GLuint lib_compile_shader(int shader_type, char *path);