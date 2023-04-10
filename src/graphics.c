#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "mem_util.h"
#include "graphics.h"

struct GraphicsHandles graphics_init() {
    struct GraphicsHandles handles;

    struct winsize window_info;
    ioctl(0, TIOCGWINSZ, &window_info);
    handles.window_width = window_info.ws_col;
    handles.window_height = window_info.ws_row;

    /* Pixel size does not include '\0'. All the color escape codes and block 
    characters are the same length, so I just use black and █ here. */
    handles.pixel_size = strlen(BLK) + strlen("█");
    handles.clear_char_size = strlen("\33[0;0H");
    // No '\0' because write() is used instead of printf().
    handles.pixel_buffer_size = handles.pixel_size * handles.window_width 
        * handles.window_height + handles.clear_char_size;

    handles.pixel_buffer = malloc_or_die(handles.pixel_buffer_size);

    // Character that resets the cursor to (0, 0). Is never overwritten.
    memcpy(handles.pixel_buffer + handles.pixel_buffer_size 
        - handles.clear_char_size, "\33[0;0H", handles.clear_char_size);

    graphics_reset_pixel_buffer(handles);

    // Hide the cursor.
    write(1, "\033[?25l", strlen("\033[?25l"));

    system("clear");

    return handles;
}
void graphics_reset_pixel_buffer(struct GraphicsHandles handles) {
    for (int i = 0; i < handles.pixel_buffer_size - handles.clear_char_size; i 
        += handles.pixel_size) {

        /* "(Escape code for black)█", so no concat necessary as with macro. 
        '\0' is not copied. */
        memcpy(handles.pixel_buffer + i, "\33[0;30m█", handles.pixel_size);
    }
}
void graphics_add_pixel(struct GraphicsHandles handles, int x, int y, 
    char *color, char *block) {

    size_t position = x + y * handles.window_width;
    if (position < handles.window_width * handles.window_height) {
        memcpy(handles.pixel_buffer + position * handles.pixel_size, 
            color, strlen(BLK));
        memcpy(handles.pixel_buffer + position * handles.pixel_size 
            + strlen(BLK), block, strlen(FULL_BLOCK));
    }
    else {
        fprintf(stderr, "\e[0;30mError: pixel position out of bounds\n");
        fflush(stderr);
        exit(EXIT_FAILURE);
    }
}
void graphics_push(struct GraphicsHandles handles) {
    write(1, handles.pixel_buffer, handles.pixel_buffer_size);
    graphics_reset_pixel_buffer(handles);
}
void graphics_free(struct GraphicsHandles handles) {
    free(handles.pixel_buffer);
    handles.pixel_buffer = NULL;
}