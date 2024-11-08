#include <stdlib.h>
#include <kernel/tty.h>

uintptr_t __stack_chk_guard;

__attribute__((no_stack_protector))
void stack_chk_init(void){
  __stack_chk_guard = 0x12120121;
  terminal_writestring("Stack Smash Protector enabled\n");
}

void __stack_chk_fail(void){
  // TODO: Proper kernel panic
	abort(); 
	// panic("Stack smashing detected");
}

