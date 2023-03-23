#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "mem_util.h"
#include "colors.h"
#include "graphics.h"

struct GraphicsHandles graphics_init() {

    struct GraphicsHandles handles;
    struct winsize window_info;
    ioctl(0, TIOCGWINSZ, &window_info);
    handles.window_width = window_info.ws_col;
    handles.window_height = window_info.ws_row;
    /* Pixel size does not include '\0'. All the color escape codes are the 
    same length, so I just use black here. */
    handles.pixel_size = strlen(BLK) + strlen("█");

    // No '\0' because write() is used instead of printf().
    handles.pixel_buffer_size = handles.pixel_size * handles.window_width 
        * handles.window_height;
    handles.pixel_buffer = malloc_or_die(handles.pixel_buffer_size);

    graphics_reset_pixel_buffer(handles);

    // Hide the cursor.
    write(1, "\033[?25l", strlen("\033[?25l"));

    system("clear");

    return handles;
}
void graphics_reset_pixel_buffer(struct GraphicsHandles handles) {
    for (int i = 0; i < handles.pixel_buffer_size; i 
        += handles.pixel_size) {

        /* "(Escape code for black)█", so no concat necessary as with macro. 
        '\0' is not copied. */
        memcpy(handles.pixel_buffer + i, "\33[0;30m█", 
            handles.pixel_size);
    }
}
void graphics_add_pixel(struct GraphicsHandles handles, int x, int y, 
    char *color) {

    memcpy(handles.pixel_buffer + (x + y * handles.window_width) 
        * handles.pixel_size, color, strlen(BLK));
}
void graphics_push(struct GraphicsHandles handles) {
    write(1, handles.pixel_buffer, handles.pixel_buffer_size);
    // Resets cursor to (0, 0).
    write(1, "\33[0;0H", strlen("\33[0;0H"));
    graphics_reset_pixel_buffer(handles);
}
void graphics_free(struct GraphicsHandles handles) {
    free(handles.pixel_buffer);
    handles.pixel_buffer = NULL;
}