# linux_terminal_graphics
## About

A simple library for Linux terminal block graphics. Written in C using ANSI escape codes.

## Getting Started

To get started with the example, you will need to have Make and GCC installed. First run `make`. Then run the compiled binary by `./example.out`.

## Quick Docs

`struct  GraphicsHandles  graphics_init();` - Takes no arguments. Returns initialized struct. Initializes everything needed for graphics.

 - The "canvas" will be the size of the terminal. 
 - If something is typed in the terminal, you need to clear it again.
 - You can get window width and height in columns and rows by accessing the window_width and window_height members of the struct respectively.

`void  graphics_add_pixel(struct  GraphicsHandles  handles,  int  x,  int  y,  char  *color)` - Takes initialized struct `handles`, adds a pixel to the buffer at `x` columns and `y` rows, with color `color` . Returns nothing.
 - `color` is one of the 16 ANSI escape codes for color. They can be found (and are defined) in include/color.h as either `CLR` or `HCLR` (CLR being the abbreviation for the color). You can pass one of these 16 macros.
 - The top left column and row is (0, 0).
 - Does not actually output anything to the screen yet.

 `void  graphics_push(struct  GraphicsHandles  handles);` - Takes initialized struct `handles`. Returns nothing. Flushes the pixel buffer to the standard output (file descriptor 1). This will actually print the added pixels.
 
`void  graphics_free(struct GraphicsHandles handles)` - Takes initialized struct `handles`. Returns nothing. Frees allocated memory. Should be called when done using graphics.
