#include "main.h"

/**
 * _putchar - writes character c to stdout
 * @c: character to print
 *
 * Return: 1, else -1 and error is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}