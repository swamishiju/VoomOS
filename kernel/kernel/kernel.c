#include <stdio.h>
#include <stdlib.h>
#include <kernel/io.h>

void kernel_main(void);

void kernel_main(void) {
  unsigned char last = 0x0, in_byte;
  while (1){
    in_byte = inb(0x60);
    if (in_byte != last){
      printf("            %x          ",in_byte);
      last = in_byte;
    }
  printf("%b %b\n",inb(0x60),inb(0x64));
  }
}
