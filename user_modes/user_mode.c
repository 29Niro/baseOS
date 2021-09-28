#include "user_mode.h"

void switch_to_user_mode()
{
   // Set up a stack structure for switching to user mode.
   asm volatile("  \
     cli; \
     mov $0x23, %ax; \
     mov %ax, %ds; \
     mov %ax, %es; \
     mov %ax, %fs; \
     mov %ax, %gs; \
                   \
     mov %esp, %eax; \
     push $0x23; \
     push %eax; \
     pushf; \
     push $0x1B; \
     push $1f; \
     iret; \
   1: \
     ");
} 
