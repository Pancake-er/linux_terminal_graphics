#include <unistd.h>
#include <string.h>
#include "time_util.h"
#include "graphics.h"
#include "colors.h"

int main() {
    struct GraphicsHandles handles = graphics_init();
    int x = 0;
    while (1) {
        if (x == handles.window_width * handles.window_height - 1 - 15) {
            x = 0;
        }
        graphics_add_pixel(handles, x, 0, BLK);
        graphics_add_pixel(handles, x + 1, 0, RED);
        graphics_add_pixel(handles, x + 2, 0, GRN);
        graphics_add_pixel(handles, x + 3, 0, YEL);
        graphics_add_pixel(handles, x + 4, 0, BLU);
        graphics_add_pixel(handles, x + 5, 0, MAG);
        graphics_add_pixel(handles, x + 6, 0, CYN);
        graphics_add_pixel(handles, x + 7, 0, WHT);
        graphics_add_pixel(handles, x + 8, 0, HBLK);
        graphics_add_pixel(handles, x + 9, 0, HRED);
        graphics_add_pixel(handles, x + 10, 0, HGRN);
        graphics_add_pixel(handles, x + 11, 0, HYEL);
        graphics_add_pixel(handles, x + 12, 0, HBLU);
        graphics_add_pixel(handles, x + 13, 0, HMAG);
        graphics_add_pixel(handles, x + 14, 0, HCYN);
        graphics_add_pixel(handles, x + 15, 0, HWHT);
        graphics_push(handles);
        x++;
        /* Some delay should be added (for the push method) but it can be even
        less than here. */
        msleep(100);
    }
    graphics_free(handles);
    return 0;
}