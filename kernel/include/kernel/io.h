#ifndef _KERNEL_IO_H
#define _KERNEL_IO_H

void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);
#endif // INCLUDE_IO_H
