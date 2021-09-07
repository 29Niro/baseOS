#ifndef INCLUDE_SERIAL_PORT_H
#define INCLUDE_SERIAL_PORT_H


#include "io.h" /* io.h is implement in the section "Moving the cursor" */

#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */

#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

#define SERIAL_LINE_ENABLE_DLAB         0x80

void serial_configure_baud_rate(unsigned short com, unsigned short divisor) ;

void serial_configure_line(unsigned short com) ;

int serial_is_transmit_fifo_empty(unsigned short com) ;

int serial_write(unsigned short com, char *buf, unsigned int len) ;

#endif
