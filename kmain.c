#include "io.h"
#include "fb.h"
#include "serial_port.h"
#include "gdt.h"
#include "interrupts/interrupts.c"

#define POSITION 0
#define PORT 0x3F8

    void init()
    {
        init_gdt();
	interrupts_install_idt();
    }

    void run(){
	init();

        char c[] = "Welcome";
        write(c, 9);

        serial_write(SERIAL_COM1_BASE, c, 7);
    }
