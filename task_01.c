#include "main.h"

/**
 * pr_char - print character
 * @arg: arguments
 *
 * Return: number of characters
 */
int pr_char(va_list arg)
{
	_putchar(va_arg(arg, int));

	return (1);
}

/**
 * pr_string - Print string
 * @arg: arguments
 *
 * Return: number of characters
 */
int pr_string(va_list arg)
{
	char *p;
	int plen;

	p = va_arg(arg, char*);
	if (p == NULL)
		p = "(null)";
	for (plen = 0; p[plen] != '\0'; plen++)
		_putchar(p[plen]);

	return (plen);
}

/**
 * pr_cent - print percent symbol %
 *
 * Return: number of characters
 */
int pr_cent(void)
{
	_putchar('%');

	return (1);
}

/**
 * pr_int - print integer
 * @arg: arguments
 *
 * Return: number of characters
 */
int pr_int(va_list arg)
{
	int i;

	i = pr_num(arg);

	return (i);
}

/**
 * pr_uint - print unsigned integer
 * @arg: arguments
 *
 * Return: number printed
 */
int pr_uint(va_list arg)
{
	unsigned int i;

	i = va_arg(arg, unsigned int);

	if (i == 0)
		return (pr_unsign_num(i));

	if (i < 1)
		return (-1);

	return (pr_unsign_num(i));
}
