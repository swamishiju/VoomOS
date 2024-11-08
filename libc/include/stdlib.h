#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>
#include <stdbool.h>
#include <stdint.h>


__attribute__((__noreturn__))
void abort(void);
int atoi(const char* a);
char* itoa(int integer, char* buffer, int base);

__attribute__((noreturn))
void __stack_chk_fail(void);

__attribute__((no_stack_protector))
void stack_chk_init(void);

#endif
