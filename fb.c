#include "io.h"
#include "fb.h"

unsigned short __fb_present_pos = 0x00000000;
/** fb_write_cell:
     *  Writes a character with the given foreground and background to position i
     *  in the framebuffer.
     *
     *  @param i  The location in the framebuffer
     *  @param c  The character
     *  @param fg The foreground color
     *  @param bg The background color
     */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
    {
        fb[i*2] = c;
        fb[i*2 + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
    }

    /** fb_move_cursor:
     *  Moves the cursor of the framebuffer to the given position
     *
     *  @param pos The new position of the cursor
     */
void fb_move_cursor(unsigned short pos)
    {
        outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
        outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
        outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
        outb(FB_DATA_PORT,    pos & 0x00FF);
    }

int write(char *buf, unsigned int len)
    {
        unsigned int i = 0;
        for ( i = 0; i < len; i++)
        {
            fb_write_cell(i, buf[i], FB_GREEN, FB_DARK_GREY);
        }
        return 0;
    }

void fb_clear(){
  
  unsigned int i=0;
  while(i<80*25*2) {
  	    fb_write_cell(2*i, ' ', FB_BLACK, FB_BLACK);
    	i=i+1;
  }
  return;
}
