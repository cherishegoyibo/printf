#include "main.h"

int hex_comp(int, char);

/**
 * pr_bin - convert to binary
 * @arg: argument
 *
 * Return: number printer
 */
int pr_bin(va_list arg)
{
	unsigned int num;
	int i, len;
	char *str, *_str;

	num = va_arg(arg, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	len = base_len(num, 2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}

	str[i] = '\0';
	_str = rev_str(str);
	if (_str == NULL)
		return (-1);
	pr_base(_str);
	free(str);
	free(_str);

	return (len);
}

/**
 * pr_octal - print in base 8
 * @arg: argument
 *
 * Return: number printed
 */
int pr_octal(va_list arg)
{
	unsigned int i;
	int len;
	char *str, *_str;

	i = va_arg(arg, unsigned int);

	if (i == 0)
		return (_putchar('0'));
	if (i < 1)
		return (-1);
	len = base_len(i, 8);

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	for (len = 0; i > 0; len++)
	{
		str[len] = (i % 8) + 48;
		i /= 8;
	}
	str[len] = '\0';
	_str = rev_str(str);
	if (_str == NULL)
		return (-1);

	pr_base(_str);
	free(str);
	free(_str);

	return (len);
}

/**
 * pr_hex - print in base 16 lowercase
 * @arg: argument
 * Return: number printed
 */
int pr_hex(va_list arg)
{
	unsigned int num;
	int len, i;
	char *str, *_str

	num = va_arg(arg, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		i = num % 16;
		if (i > 9)
		{
			i = hex_comp(i, 'x');
			str[len] = i;
		}
		else
			str[len] = i + 48;
		num /= 16;
	}
	str[len] = '\0';
	_str = rev_str(str);
	if (_str == NULL)
		return (-1);
	pr_base(_str);
	free(str);
	free(_str);
	return (len);
}

/**
 * pr_HEX - print in base 16 uppercase
 * @arg: argument
 * Return: number printed
 */
int pr_HEX(va_list arg)
{
	unsigned int num;
	int len, i;
	char *str, *_str

	num = va_arg(arg, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	len = base_len(num, 16);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		i = num % 16;
		if (i > 9)
		{
			i = hex_comp(i, 'X');
			str[len] = i;
		}
		else
			str[len] = i + 48;
		num = num / 16;
	}
	str[len] = '\0';
	_str = rev_str(str);
	if (_str == NULL)
		return (-1);
	pr_base(_str);
	free(str);
	free(_str);
	return (len);
}

/**
 * hex_comp - Finds hex function.
 * @i: input
 * @c: character input
 * Return: 0
 */
int hex_comp(int i, char c)
{
	char *hex = "abcdef";
	char *HEX = "ABCDEF";

	i = i - 10;
	if (x == 'x')
		return (hex[i]);
	else
		return (HEX[i]);
	return (0);

}
