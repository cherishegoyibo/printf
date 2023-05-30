#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int _putchar(char c);

int pr_char(va_list arg);
int pr_string(va_list arg);
int pr_cent(void);
int pr_int(va_list arg);
int pr_uint(va_list arg);
int pr_bin(va_list arg);
int pr_octal(va_list arg);
int pr_hex(va_list arg);
int pr_HEX(va_list arg);
int hex_comp(int i, char c);
int pr_rev(va_list arg);
int rot13(va_list arg);

int pr_num(va_list arg);
char *rev_str(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
unsigned int base_len(unsigned int n, int b);
void pr_base(char *c);

/**
 * struct format - structure to handle different format
 * @type: format
 * @f: function pointer
 */
typedef struct format
{
	char type;
	int (*f)(va_list);
} format_t;

#endif
