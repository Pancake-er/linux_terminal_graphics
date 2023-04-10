#include <unistd.h>
#include <string.h>
#include "time_util.h"
#include "graphics.h"

void color_example_line(struct GraphicsHandles handles, int x, char* block) {
    graphics_add_pixel(handles, x, 0, BLK, block);
    graphics_add_pixel(handles, x + 1, 0, RED, block);
    graphics_add_pixel(handles, x + 2, 0, GRN, block);
    graphics_add_pixel(handles, x + 3, 0, YEL, block);
    graphics_add_pixel(handles, x + 4, 0, BLU, block);
    graphics_add_pixel(handles, x + 5, 0, MAG, block);
    graphics_add_pixel(handles, x + 6, 0, CYN, block);
    graphics_add_pixel(handles, x + 7, 0, WHT, block);
    graphics_add_pixel(handles, x + 8, 0, HBLK, block);
    graphics_add_pixel(handles, x + 9, 0, HRED, block);
    graphics_add_pixel(handles, x + 10, 0, HGRN, block);
    graphics_add_pixel(handles, x + 11, 0, HYEL, block);
    graphics_add_pixel(handles, x + 12, 0, HBLU, block);
    graphics_add_pixel(handles, x + 13, 0, HMAG, block);
    graphics_add_pixel(handles, x + 14, 0, HCYN, block);
    graphics_add_pixel(handles, x + 15, 0, HWHT, block);
}
int main() {
    struct GraphicsHandles handles = graphics_init();
    while (1) {
        color_example_line(handles, 0, FULL_BLOCK);
        color_example_line(handles, 16, DARK_BLOCK);
        color_example_line(handles, 32, MEDIUM_BLOCK);
        color_example_line(handles, 48, LIGHT_BLOCK);
        graphics_push(handles);
        /* Some delay should be added (on the push method) but it can be even
        less than here. */
        msleep(16);
    }
    graphics_free(handles);
    return 0;
}