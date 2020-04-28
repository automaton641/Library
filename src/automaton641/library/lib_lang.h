#pragma once

typedef struct lib_lang_interpreter lib_lang_interpreter_t;
typedef struct lib_lang_code_block lib_lang_code_block_t;

typedef enum lib_function_field_class {declare, put, call} lib_function_field_class_t; 

#include <automaton641/library/lib_includes.h>
#include <automaton641/library/lib_array.h>
#include <automaton641/library/lib_string.h>

struct lib_lang_code_block {
    lib_string_t name;
    lib_array_t code_blocks;
};

struct lib_lang_interpreter
{
    lib_string_t main_program;
    lib_array_t *tokens;
    lib_array_t *function_names;
    lib_lang_code_block_t *main_block;
    lib_string_t name_function;
    lib_string_t name_structure;
    lib_string_t name_put;
    lib_string_t name_declare;
    lib_string_t name_print_line;
};

void lib_lang_run(char *path);

void lib_lang_add_tokens(lib_lang_interpreter_t *interpreter, lib_string_t program);
void lib_lang_process_tokens(lib_lang_interpreter_t *interpreter);

void lib_lang_exit_error(lib_string_t description);
lib_string_t lib_lang_get_token(lib_lang_interpreter_t *interpreter, size_t index);
bool lib_lang_process_block(lib_lang_interpreter_t *interpreter, size_t *token_index);
bool lib_lang_token_is_block(lib_lang_interpreter_t *interpreter, size_t *token_index);