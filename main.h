#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int process_specifier(char spec, va_list args);
int _putchar(char c);

#endif
