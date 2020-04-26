#include <automaton641/library/lib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    lib_application_t *application = lib_application_create();
    lib_window_attributes_t attributes;
    attributes.title = "Hello world";
    attributes.width = 1024;
    attributes.height = 512;
    attributes.resizable = true;
    lib_application_add_window(application, &attributes);
    int status = lib_application_run(application);
    lib_application_destroy(application);
    return status;
}
