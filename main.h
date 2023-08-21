#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_num(va_list ca, int l);
int print_str(va_list ca, int l);
int print_char(va_list ca, int l);

#endif
