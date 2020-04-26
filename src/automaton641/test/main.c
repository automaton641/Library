#include <automaton641/library/lib.h>
#include <stdio.h>

typedef struct test_cell {
    int level;
} test_cell_t;

void test_iteration (lib_automaton_t *automaton) {
    printf("%s\n", "iteration");
}


int main(int argc, char const *argv[]) {
    lib_application_t *application = lib_application_create();
    lib_window_attributes_t window_attributes = {
        .title = "Hello world",
        .width = 1024,
        .height = 512,
        .resizable = false
    };
    lib_window_t *window = lib_application_add_window(application, &window_attributes);
    lib_automaton_attributes_t automaton_attributes = {
        .element_size = sizeof(test_cell_t),
        .width = 8,
        .height = 4,
        .iteration_time = 500,
        .iteration = test_iteration
    };
    lib_automaton_display_t *display = lib_automaton_display_create(&automaton_attributes);
    display->cell_size = 16;
    window->widget = display->widget;
    int status = lib_application_run(application);
    lib_application_destroy(application);
    return status;
}
