#include <automaton641/library/lib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    lib_application_t *application = lib_application_create();
    printf("%s\n", "Hello GUI");
    lib_window_attributes_t window_attributes = {
        .title = "GUI",
        .width = 1600,
        .height = 900,
        .resizable = true
    };
    lib_window_t *window = lib_application_add_window(application, &window_attributes);
    window->widget = NULL;
    int status = lib_application_run(application);
    lib_application_destroy(application);
    return status;
}
