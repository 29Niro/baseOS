#include "isr.h"
#include "../io.h"
#include "string.h"
#include "../log.h"

#define PIC1            0x20    /* IO base address for master PIC */
#define PIC2            0xA0    /* IO base address for slave PIC */
#define PIC1_COMMAND    PIC1
#define PIC1_DATA       (PIC1+1)
#define PIC2_COMMAND    PIC2
#define PIC2_DATA       (PIC2+1)

#define PIC_EOI         0x20    /* End-of-interrupt command code */

isr_t interrupt_handlers[256];
const uint8_t TIME_INTERRUPT_NUMBER = 32;
const uint8_t KEYBOARD_INTERRUPT_NUMBER = 33;

/* Function to register interrupt handler with custom call back function */
void register_interrupt_handler(uint8_t n, isr_t handler) {
  interrupt_handlers[n] = handler;
}
