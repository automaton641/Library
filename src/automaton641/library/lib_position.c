#include <automaton641/library/lib_position.h>

lib_position_t *lib_position_create(int x, int y) {
    lib_position_t *position = malloc(sizeof(lib_position_t));
    position->x = x;
    position->y = y;
    return position;
}
