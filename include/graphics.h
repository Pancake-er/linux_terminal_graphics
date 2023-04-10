#ifndef GRAPHICS_INCLUDED
#define GRAPHICS_INCLUDED

#include <stdlib.h>
#include <time.h>

#define FULL_BLOCK "█"
#define DARK_BLOCK "▓"
#define MEDIUM_BLOCK "▒"
#define LIGHT_BLOCK "░"

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

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
    char *color, char *block);
void graphics_push(struct GraphicsHandles handles);
void graphics_free(struct GraphicsHandles handles);

#endif