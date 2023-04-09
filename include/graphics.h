#ifndef GRAPHICS_INCLUDED
#define GRAPHICS_INCLUDED

#include <stdlib.h>
#include <time.h>

struct GraphicsHandles {
    size_t window_width;
    size_t window_height;
    size_t pixel_size;
    size_t clear_char_size;
    size_t pixel_buffer_size;
    char *pixel_buffer;
};
struct GraphicsHandles graphics_init();
void graphics_reset_pixel_buffer(struct GraphicsHandles handles);
void graphics_add_pixel(struct GraphicsHandles handles, int x, int y, 
    char *color);
void graphics_push(struct GraphicsHandles handles);
void graphics_free(struct GraphicsHandles handles);

#endif