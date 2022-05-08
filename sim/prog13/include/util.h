#ifndef __UTIL__
#define __UTIL__
#include <stdint.h>
#include <stddef.h>
#include "type_def.h"

#define assert(x)                                                     \
    do {                                                              \
        if (!x) {                                                     \
            printf("Failed assertion '%s' at line %d of '%s'.\n", #x, \
                   __LINE__, __FILE__);                               \
            abort();                                                  \
        }                                                             \
    } while (0)


void *memset(void *ptr, int val, size_t len);
void *memcpy(void *ptr, void *src, size_t len);
uint64_t write_tohost(trapframe_t *ft);
uint64_t syscall(uint64_t sys_id, uint64_t arg);
void abort(void) __attribute__((noreturn));
int putchar(int ch);
int puts(const char *s);
double log_2(double x);
double log10(double x);
char *ftoa(double value);
char *itoa(uint64_t value, int base, int min_len, char fill_char);
int printf(const char *format, ...);
#endif
