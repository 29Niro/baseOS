#include "io.h"
#include "fb.h"
#include "serial_port.h"
#include "gdt.h"
#include "interrupt/interrupts.c"
#include "multiboot.h"


    void init()
    {
        init_gdt();
	interrupts_install_idt();
    }

    void run(unsigned int ebx){
	init();

	multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
        multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr; 
        unsigned int address_of_module = modules->mod_start;

	if(mbinfo->mods_count == 1){
		 char c[] = "Welcome";
       		 write(c, 9);

        	serial_write(SERIAL_COM1_BASE, c, 7);

		typedef void (*call_module_t)(void);
        	/* ... */
        	call_module_t start_program = (call_module_t) address_of_module;
        	start_program();
        	/* we'll never get here, unless the module code returns */
    	}
	else{
        char errorMsg[] = "Error: Number of modules loaded is not equal to 1.\n";
        unsigned int err_len = sizeof(errorMsg) / sizeof(errorMsg[0]);
        write(errorMsg, err_len);
        serial_write(SERIAL_COM1_BASE, errorMsg, err_len);
    	}
    }
