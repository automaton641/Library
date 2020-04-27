#include <automaton641/library/lib_automaton.h>

void *lib_automaton_thread(void *argument)
{
    lib_window_automaton_pack_t *pack = argument;
    lib_automaton_t *automaton = pack->automaton;
    lib_window_t *window = pack->window;
    printf("%s\n", "Hello thread");
    struct timespec time;
    while (automaton->iterate) {
        //printf("%s\n", "iteration thread");
        msleep(automaton->iteration_time);
        (*automaton->iteration) (automaton); // callback to A
        window->should_draw = true;
    }
    printf("%s\n", "Goodbye thread");
    return NULL;
}

void lib_automaton_start(lib_automaton_t *automaton, lib_window_t *window) {
    lib_window_automaton_pack_t *pack = malloc(sizeof(lib_window_automaton_pack_t));
    pack->window = window;
    pack->automaton = automaton;
    int status = pthread_create(&automaton->thread_id, NULL, lib_automaton_thread, (void *)pack);
    if (status) {
        exit_error("pthread_create");
    }
}


lib_automaton_t *lib_automaton_create(lib_automaton_attributes_t *attributes) {
    lib_automaton_t *automaton = malloc(sizeof(lib_automaton_t));
    automaton->iteration_time = attributes->iteration_time;
    automaton->iteration = attributes->iteration;
    automaton->initialization = attributes->initialization;
    automaton->user_data = attributes->user_data;
    automaton->iterate = true;
    automaton->bidimensional = lib_bidimensional_create(attributes->element_size, attributes->width, attributes->height);
    return automaton;
}

void lib_automaton_destroy(lib_automaton_t *automaton) {
    lib_bidimensional_destroy(automaton->bidimensional);
    free(automaton);
}
