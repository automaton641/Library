#include <automaton641/library/lib.h>

int main(int argc, char const *argv[])
{
    lib_application_t *application = lib_application_create();
    printf("%s\n", "Hello Game");
    lib_window_attributes_t window_attributes = {
        .title = "Game",
        .width = 1600,
        .height = 900,
        .resizable = true
    };
    lib_window_t *window = lib_application_add_window(application, &window_attributes);
    lib_container_t *container = lib_container_create(VERTICAL);
    window->widget = container->widget;
    int status = lib_application_run(application);
    lib_application_destroy(application);
    return status;
}


