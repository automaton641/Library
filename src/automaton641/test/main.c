#include <automaton641/library/lib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct test_automaton_data {
        int modulus;
        lib_bidimensional_t *back_dimension;
} test_automaton_data_t;

typedef struct test_cell {
    int level;
} test_cell_t;

void test_initialization(lib_automaton_t *automaton) {
    printf("%s\n", "test_initialization");
    lib_bidimensional_t *bidimensional = automaton->bidimensional;
    test_automaton_data_t *user_data = automaton->user_data;
    int modulus = user_data->modulus;
    size_t width = bidimensional->width;
    size_t height = bidimensional->height;
    user_data->back_dimension = lib_bidimensional_create(sizeof(test_cell_t*), width, height);
    lib_bidimensional_t *back_dimension = user_data->back_dimension;
    test_cell_t cell;
    cell.level = 0;
    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            lib_bidimensional_set(bidimensional, &cell, x, y);
            lib_bidimensional_set(back_dimension, &cell, x, y);
            //cell.level++;
            //cell.level %= user_data->modulus;
        }
    }
    test_cell_t *one = lib_bidimensional_get(bidimensional, 0, 0);
    one->level = 1;
    test_cell_t *two = lib_bidimensional_get(bidimensional, width-1, 0);
    two->level = 1;
    test_cell_t *three = lib_bidimensional_get(bidimensional, 0, height-1);
    three->level = 1;
    test_cell_t *four = lib_bidimensional_get(bidimensional, width-1, height-1);
    four->level = 1;
    //one->level = modulus - 1;
}

test_cell_t *test_get_left_cell(lib_bidimensional_t *bidimensional, size_t x, size_t y) {
    if (x == 0) {
        return NULL;
    }
    size_t locate_x = x - 1;
    return lib_bidimensional_get(bidimensional, locate_x, y);
}

test_cell_t *test_get_right_cell(lib_bidimensional_t *bidimensional, size_t x, size_t y) {
    if (x == bidimensional->width - 1) {
        return NULL;
    }
    size_t locate_x = x + 1;
    return lib_bidimensional_get(bidimensional, locate_x, y);
}

test_cell_t *test_get_up_cell(lib_bidimensional_t *bidimensional, size_t x, size_t y) {
    if (y == 0) {
        return NULL;
    }
    size_t locate_y = y - 1;
    return lib_bidimensional_get(bidimensional, x, locate_y);
}

test_cell_t *test_get_down_cell(lib_bidimensional_t *bidimensional, size_t x, size_t y) {
    if (y == bidimensional->height - 1) {
        return NULL;
    }
    size_t locate_y = y + 1;
    return lib_bidimensional_get(bidimensional, x, locate_y);
}

void test_add_cell(test_cell_t *cell, test_cell_t *other, int modulus) {
    if (other != NULL) {
        cell->level+=other->level;
        cell->level %= modulus;
    }
}

void test_backup(lib_bidimensional_t *bidimensional, lib_bidimensional_t *back_dimension) {
    size_t width = bidimensional->width;
    size_t height = bidimensional->height;
    test_cell_t *cell;
    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            cell = lib_bidimensional_get(bidimensional, x, y);
            lib_bidimensional_set(back_dimension, cell, x, y);
        }
    }
}

void test_iteration (lib_automaton_t *automaton) {
    //printf("%s\n", "test_iteration");
    lib_bidimensional_t *bidimensional = automaton->bidimensional;
    test_automaton_data_t *user_data = automaton->user_data;
    size_t width = bidimensional->width;
    size_t height = bidimensional->height;
    int modulus = user_data->modulus;
    lib_bidimensional_t *back_dimension = user_data->back_dimension;
    test_backup(bidimensional, back_dimension);
    test_cell_t *cell, *right_cell, *left_cell, *up_cell, *down_cell;
    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            cell = lib_bidimensional_get(bidimensional, x, y);
            right_cell = test_get_right_cell(back_dimension, x, y);
            left_cell = test_get_left_cell(back_dimension, x, y);
            up_cell = test_get_up_cell(back_dimension, x, y);
            down_cell = test_get_down_cell(back_dimension, x, y);
            test_add_cell(cell, right_cell, modulus);
            test_add_cell(cell, left_cell, modulus);
            test_add_cell(cell, up_cell, modulus);
            test_add_cell(cell, down_cell, modulus);
        }
    }
}

void test_update_color (lib_color_t *color, lib_automaton_t *automaton, size_t x, size_t y) {
    //printf("%s\n", "test_update_color");
    if (color == NULL) {
        lib_exit_error("color == NULL");
    }
    test_automaton_data_t *user_data = automaton->user_data;
    unsigned char red, green, blue;
    lib_bidimensional_t *bidimensional = automaton->bidimensional;
    test_cell_t *cell = lib_bidimensional_get(bidimensional, x, y);
    double normalized = (double)(cell->level)/(double)(user_data->modulus-1);
    double double_rgb =  normalized * 0xffffff;
    uint32_t rgb = double_rgb;
    red = rgb >> 16;
    blue = rgb >>8;
    green = rgb;
    lib_color_update(color, red, green, blue, color->alpha);

}

int main(int argc, char const *argv[]) {
    lib_application_t *application = lib_application_create();
    test_automaton_data_t automaton_data = {
        .modulus = 360
    };
    lib_automaton_attributes_t automaton_attributes = {
        .element_size = sizeof(test_cell_t),
        .width = 1600,
        .height = 900,
        .iteration_time = 0,
        .iteration = test_iteration,
        .initialization = test_initialization,
        .user_data = &automaton_data
    };
    lib_automaton_display_t *display = lib_automaton_display_create(&automaton_attributes);
    display->cell_size = 1;
    display->update_color = test_update_color;
    lib_window_attributes_t window_attributes = {
        .title = "Test",
        .width = automaton_attributes.width*display->cell_size,
        .height = automaton_attributes.height*display->cell_size,
        .resizable = false
    };
    lib_window_t *window = lib_application_add_window(application, &window_attributes);
    window->widget = display->widget;
    int status = lib_application_run(application);
    lib_application_destroy(application);
    return status;
}
