#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_PLUS 1
#define F_SPACE 2
#define F_HASH 4
#define F_ZERO 8
#define F_MINUS 16
#define L_LONG 1
#define H_SHORT 2

int _printf(const char *format, ...);
int _putchar(char c);
int pull_print(const char *format, int *index, va_list arg, char buffer[],
		int flag, int width, int precision, int size);

int pr_char(va_list arg);
int pr_string(va_list arg);
int pr_cent(va_list arg);
int pr_int(va_list arg);
int pr_uint(va_list arg);
int pr_bin(va_list arg);
int pr_octal(va_list arg);
int pr_hex(va_list arg);
int pr_HEX(va_list arg);
int pr_rev(va_list arg);
int pr_rot13(va_list arg);
int pr_String(va_list arg, char buffer[]);
int pr_pointer(va_list arg, char buffer[], int flag);

int pr_flag(const char *format, int *index);
int pr_size(const char *format, int *index);
int pr_width(const char *format, int *index, va_list arg);
int pr_precision(const char *format, va_list arg, int *index);
int hex_comp(int i, char c);
int pr_num(va_list arg);
int pr_unsign_num(unsigned int n);
char *rev_str(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
unsigned int base_len(unsigned int n, int b);
void pr_base(char *c);
void pr_buffer(char buffer[], int *b_index);
int is_digit(char c);
int is_print(char c);
int append_hex(char code, char buffer[], int index);
int wr_pointer(char buffer[], int index, int len, int width,
		int flag, char padd, char extra, int padd_start);

/**
 * struct format - structure to handle different format
 * @format: format
 * @f: function pointer
 */
struct format
{
	char format;
	int (*f)(va_list);
};
typedef struct format format_t;

#endif
