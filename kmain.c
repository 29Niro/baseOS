#include "io.h"
#include "fb.h"
#include "serial_port.h"
#include "gdt.h"
#include "interrupt/interrupts.c"



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
