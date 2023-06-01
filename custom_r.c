#include "main.h"

/**
 * pr_rev - prints reversed string
 * @arg:vargument
 *
 * Return: number printed
 */
int pr_rev(va_list arg)
{
	int len;
	char *str, *_str;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);

	_str = rev_str(str);
	if (_str == NULL)
		return (-1);
	for (len = 0; _str[len] != '\0'; len++)
		_putchar(_str[len]);

	free(_str);
	return (len);
}

/**
 * pr_rot13 - prints rot13'ed strings
 * @arg: argument
 *
 * Return: rot13 string
 */
int pr_rot13(va_list arg)
{
	int i, j;
	char *str;
	char aleph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot_tab[] = "NOPQRSTUYWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j <= 52; j++)
		{
			if (str[i] == aleph[j])
			{
				_putchar(rot_tab[j]);
				break;
			}
		}
	}

	return (i);
}
