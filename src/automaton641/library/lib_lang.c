#include <automaton641/library/lib_lang.h>
#include <automaton641/library/lib.h>
#include <string.h>

void lib_lang_add_tokens(lib_lang_interpreter_t *interpreter, lib_string_t program) {
    size_t program_index = 0;
    bool iterate = true;
    while (iterate)
    {
        unsigned char character;
        lib_array_t *token = lib_array_create(sizeof(unsigned char));
        character = program[program_index++];
        while (character != 0 && character != ' ' && character != '\n' && character != 9) {
            lib_array_add(token, &character);
            character = program[program_index++];
        }
        if (character == 0)
        {
            iterate = false;
        } 
        if (token->size > 0) {
            character = 0;
            lib_array_add(token, &character);
            lib_string_t token_string = lib_copy_allocate(token->data, token->size, sizeof(unsigned char));
            lib_array_add(interpreter->tokens, &token_string);
        }
        lib_array_destroy(token);
    }
}

lib_string_t lib_lang_get_token(lib_lang_interpreter_t *interpreter, size_t index) {
    return *(lib_string_t*)lib_array_get(interpreter->tokens, index);
}

lib_string_t lib_lang_get_name(lib_lang_interpreter_t *interpreter, size_t index) {
    return *(lib_string_t*)lib_array_get(interpreter->function_names, index);
}

bool lib_lang_token_equals(lib_lang_interpreter_t *interpreter, size_t *index, lib_string_t string) {
    return strcmp(lib_lang_get_token(interpreter, *index), string) == 0;
}

void lib_lang_exit_error(lib_string_t description) {
    printf("%s\n", "LANG");
    lib_exit_error(description);
}

bool lib_lang_is_function(lib_lang_interpreter_t *interpreter, lib_string_t name) {
    size_t index = 0;
    lib_array_t *names = interpreter->function_names;
    bool status;
    while (true)
    {
        if (index == names->size) {
            return false;
        }
        lib_string_t other = lib_lang_get_name(interpreter, index);
        status = strcmp(name, other);
        if (status == 0) {
            return true;
        }
        index++;
    }
}

bool lib_lang_token_is_function(lib_lang_interpreter_t *interpreter, size_t *token_index) {
    bool status = lib_lang_token_is_block(interpreter, token_index);
    if (status) {
        return false;
    }
    status = lib_lang_token_is_block(interpreter, token_index);
    if (status) {
        return false;
    }
    lib_string_t name = lib_lang_get_token(interpreter, *token_index);
    status = lib_lang_is_function(interpreter, name);
    return status;
}

bool lib_lang_token_is_block(lib_lang_interpreter_t *interpreter, size_t *token_index) {
    return lib_lang_token_equals(interpreter, token_index, "(");
}

bool lib_lang_token_is_ending(lib_lang_interpreter_t *interpreter, size_t *token_index) {
    return lib_lang_token_equals(interpreter, token_index, ")");
}

bool lib_lang_token_is_string(lib_lang_interpreter_t *interpreter, size_t *token_index) {
    return false;
}

bool lib_lang_process_function(lib_lang_interpreter_t *interpreter, size_t *token_index) {
    printf("%s: %li\n", "function name found at token", *token_index);
    if (lib_lang_token_equals(interpreter, token_index, interpreter->name_declare)) {
        
    } else if (lib_lang_token_equals(interpreter, token_index, interpreter->name_function)) {

    } else if (lib_lang_token_equals(interpreter, token_index, interpreter->name_print_line)) {

    } else if (lib_lang_token_equals(interpreter, token_index, interpreter->name_put)) {

    } else if (lib_lang_token_equals(interpreter, token_index, interpreter->name_structure)) {

    } else {

    }
    return false;
    
}


bool lib_lang_process_block(lib_lang_interpreter_t *interpreter, size_t *token_index) {
    printf("%s: %li\n", "code block found at token", *token_index);
    (*token_index) += 1;
    if (interpreter->tokens->size == *token_index)
    {
        lib_lang_exit_error("more expected");
    }
    bool iterate = true;
    while (iterate)
    {
        if (lib_lang_token_is_function(interpreter, token_index)) {
            iterate = lib_lang_process_function(interpreter, token_index);
        } else {
            lib_lang_exit_error("function name expected");
        }
    }
    return true;
}


void lib_lang_process_tokens(lib_lang_interpreter_t *interpreter) {
    size_t token_index_value = 0;
    size_t *token_index = &token_index_value;
    lib_array_t *tokens = interpreter->tokens;
    if (tokens->size == *token_index)
    {
        lib_lang_exit_error("more expected");
    }
    bool iterate = true;
    while (iterate)
    {
        if (lib_lang_token_is_block(interpreter, token_index)) {
            iterate = lib_lang_process_block(interpreter, token_index);
        } else {
            return;
        }
    }
}

void lib_lang_run(char *path) {
    lib_lang_interpreter_t *interpreter = malloc(sizeof(lib_lang_interpreter_t));
    lib_string_t main_program = lib_read_file(path);
    printf("%s\n", main_program);
    interpreter->tokens = lib_array_create(sizeof(char*));
    interpreter->function_names = lib_array_create(sizeof(char*));
    lib_lang_add_tokens(interpreter, main_program);
    interpreter->name_function = "function";
    interpreter->name_structure = "structure";
    interpreter->name_put = "put";
    interpreter->name_declare = "declare";
    interpreter->name_print_line = "print_line";
    lib_array_add(interpreter->function_names, &interpreter->name_function);
    lib_array_add(interpreter->function_names, &interpreter->name_structure);
    lib_array_add(interpreter->function_names, &interpreter->name_put);
    lib_array_add(interpreter->function_names, &interpreter->name_declare);
    lib_array_add(interpreter->function_names, &interpreter->name_print_line);
    lib_lang_process_tokens(interpreter);
}