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
 - If you resize the terminal, you will need to free the handles using the `graphics_free` method and reinitialize it to adjust.

`void  graphics_add_pixel(struct  GraphicsHandles  handles,  int  x,  int  y,  char  *color, char* block)` - Takes initialized struct `handles`, adds a pixel to the buffer at `x` columns and `y` rows, with color `color` and block type of `block`. Returns nothing.
 - `color` is one of the 16 ANSI escape codes for color. They are defined in include/graphics.h as either `CLR` or `HCLR` (CLR being the abbreviation for the color). You can pass one of these 16 macros.
 - `block` is one of the 4 block element unicodes. They are defined in include/graphics.h as `TYPE_BLOCK`. You can pass one of these 4 macros.
 - The top left column and row is (0, 0).
 - If you try and add a pixel outside of the screen the program will exit and error.
 - Does not actually output anything to the screen yet (look at `graphics_push`).

 `void  graphics_push(struct  GraphicsHandles  handles);` - Takes initialized struct `handles`. Returns nothing. Flushes the pixel buffer to the standard output (file descriptor 1). This will actually print the added pixels.
 - This method should have some delay put on it in a loop to prevent flickering, either by checking if enough time has passed or by delaying the whole loop like in the example. I have succsefully tested it with 10ms.
 
`void  graphics_free(struct GraphicsHandles handles)` - Takes initialized struct `handles`. Returns nothing. Frees allocated memory. Should be called when done using graphics.
