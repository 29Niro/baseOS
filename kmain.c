#include "io.h"
#include "fb.h"
#include "serial_port.h"
#include "gdt.h"

    void init()
    {
        init_gdt();
    }

    void run(){
        char c[] = "Welcome";
        write(c, 9);

        serial_write(SERIAL_COM1_BASE, c, 7);
    }
