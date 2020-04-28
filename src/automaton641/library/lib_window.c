#include <automaton641/library/lib_window.h>
#include <automaton641/library/lib.h>

void set_pixel_color(lib_window_t *window, size_t x, size_t y) {
    unsigned char *pixels = window->pixels;
    int width = window->width;
    int height = window->height;
    lib_color_t *color = window->color;
    pixels[(height- 1 - y) * width * 4 + x * 4] = color->red;
    pixels[(height- 1 - y) * width * 4 + x * 4 + 1] = color->green;
    pixels[(height- 1 - y) * width * 4 + x * 4 + 2] = color->blue;
    pixels[(height- 1 - y) * width * 4 + x * 4 + 3] = color->alpha;
}

void lib_window_draw_quad(lib_window_t *window, size_t x, size_t y, size_t size) {
    for (size_t py = y; py < y+size; py++) {
        for (size_t px = x; px < x+size; px++) {
            set_pixel_color(window, px, py);
        }
    }
}

void set_random_pixel_color(lib_window_t *window, size_t x, size_t y) {
    unsigned char *pixels = window->pixels;
    int width = window->width;
    int height = window->height;
    pixels[(height- 1 - y) * width * 4 + x * 4] = (unsigned char)rand();
    pixels[(height- 1 - y) * width * 4 + x * 4 + 1] = (unsigned char)rand();
    pixels[(height- 1 - y) * width * 4 + x * 4 + 2] = (unsigned char)rand();
    pixels[(height- 1 - y) * width * 4 + x * 4 + 3] = 255;
}

void clear_pixels(lib_window_t *window) {
    for (size_t y = 0; y < window->height; y++) {
        for (size_t x = 0; x < window->width; x++) {
            set_pixel_color(window, x, y);
        }
    }
}

void create_pixels(lib_window_t *window) {
    window->pixels = malloc(sizeof(unsigned char) * window->width * window->height * 4);
    clear_pixels(window);
}

void reallocate_pixels(lib_window_t *window) {
    window->pixels = realloc(window->pixels, sizeof(unsigned char) * window->width * window->height * 4);
    clear_pixels(window);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    lib_application_t *application = glfwGetWindowUserPointer(window);
    lib_window_t *lib_window = application->window;
    lib_window->width = width;
    lib_window->height = height;
    glViewport(0, 0, width, height);
    lib_window->should_draw = true;
    reallocate_pixels(lib_window);

}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

lib_window_t* lib_window_create(lib_window_attributes_t *attributes) {
    if (!glfwInit())
    {
        lib_exit_error("glfwInit");
    }
    glfwSetErrorCallback(error_callback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    if (attributes->resizable) {
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    } else {
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }
    lib_window_t *window = malloc(sizeof(lib_window_t));
    window->inner = glfwCreateWindow(attributes->width, attributes->height, attributes->title, NULL, NULL);
    if (!window->inner)
    {
        lib_exit_error("glfwCreateWindow");
    }

    window->should_draw = true;
    glfwMakeContextCurrent(window->inner);
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    glfwGetFramebufferSize(window->inner, &window->width, &window->height);

    glViewport(0, 0, window->width, window->height);
    glfwSwapInterval(1);
    glfwSetFramebufferSizeCallback(window->inner, framebuffer_size_callback);
    window->mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    printf("%s: %i\n", "window->mode->width", window->mode->width);
    printf("%s: %i\n", "window->mode->height", window->mode->height);
    int left;
	int top;
	int right;
	int bottom;
    glfwGetWindowFrameSize(window->inner, &left, &top, &right, &bottom);
    /*
    printf("%s: %i\n", "left", left);
    printf("%s: %i\n", "top", top);
    printf("%s: %i\n", "right", right);
    printf("%s: %i\n", "bottom", bottom);
    */
    window->frame_width = window->width + left + right;
    window->frame_height = window->height + bottom + top;
    //printf("%s: %i\n", "window->frame_width", window->frame_width);
    //printf("%s: %i\n", "window->frame_height", window->frame_height);
    int x = window->mode->width/2-window->frame_width/2;
    int y = window->mode->height/2-window->frame_height/2;
    //printf("%s: %i\n", "x", x);
    //printf("%s: %i\n", "window->mode->height/2", window->mode->height/2);
    //printf("%s: %i\n", "window->frame_height/2", window->frame_height/2);
    //printf("%s: %i\n", "y", y);
    glfwSetWindowPos(window->inner, x, y);
    window->color = lib_color_create(0, 255, 0, 255);
    create_pixels(window);
    window->widget = NULL;
    return window;
}

void lib_window_destroy(lib_window_t *window) {
    glfwDestroyWindow(window->inner);
    free(window->vertex_array);
    free(window->indices_array);
    glDeleteVertexArrays(1, &window->vao);
    glDeleteBuffers(1, &window->vbo);
    glDeleteBuffers(1, &window->ebo);
    free(window);
}
