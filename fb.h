    #ifndef INCLUDE_FB_H
    #define INCLUDE_FB_H

    #include "io.h"

    /* The I/O ports */
    #define FB_COMMAND_PORT         0x3D4
    #define FB_DATA_PORT            0x3D5

    /* The I/O port commands */
    #define FB_HIGH_BYTE_COMMAND    14
    #define FB_LOW_BYTE_COMMAND     15

#define FB_BLACK     0
#define FB_BLUE      1
#define FB_GREEN     2
#define FB_RED       4
#define FB_DARK_GREY 8
#define FB_WHITE     15

    char *fb = (char *) 0x00B8000;

    void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);

    void fb_move_cursor(unsigned short pos);

    int write(char *buf, unsigned int len);

    void fb_clear();

    #endif
