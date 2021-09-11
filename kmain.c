#include "serial_port.h"
#include "interrupt/interrupts.h"
#include "multiboot.h"
#include "page/paging.h"
#include "memory/segments.h"


    void init(u32int kernelPhysicalStart, u32int kernelPhysicalEnd)
    {
	segments_install_gdt();
	interrupts_install_idt();
   	init_paging(kernelPhysicalStart, kernelPhysicalEnd);
    }

    void run(unsigned int ebx, u32int kernel_physical_start, u32int kernel_physical_end){
	init(kernel_physical_start, kernel_physical_end);

	multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
        multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr; 
        unsigned int address_of_module = modules->mod_start;

	if(mbinfo->mods_count == 1){
		 char c[] = "Welcome";
       		 //write(c, 9);

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
        //write(errorMsg, err_len);
        serial_write(SERIAL_COM1_BASE, errorMsg, err_len);
    	}

    }
