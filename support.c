#include "main.h"

/**
 * pr_num - prints numbers
 * @arg: arguments
 * Return: number of arguments
 */
int pr_num(va_list arg)
{
	int n, i, len;
	unsigned int num;

	n = va_arg(arg, int);
	i = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / i > 9; )
		i *= 10;

	for (; i != 0; )
	{
		len += _putchar('0' + num / i);
		num %= i;
		i /= 10;
	}

	return (len);
}
