#include "main.h"

/**
*is_digit - Function that helps find a digit
* @c: input
*
* Return: 1 , else 0
*/
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
*is_print - Function that checks if a character is printable.
* @c: input
* Return: 1 , else 0
*/
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
* append_hex - Function that appends ASSCI to buffer
* @buffer: Array
* @index: input
* @code: ASSCI CODE.
* Return: Always 3
*/
int append_hex(char code, char buffer[], int index)
{
	char aleph_tab[] = "0123456789ABCDEF";

	if (code < 0)
		code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = aleph_tab[code / 16];
	buffer[index] = aleph_tab[code % 16];

	return (3);
}
