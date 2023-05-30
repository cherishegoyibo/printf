#include "main.h"

/**
* pr_String – Prints non printable
* @arg: argument
* @buffer: array
*
* Return: numbers printed
*/
int pr_String(va_list arg, char buffer[])
{
	int i = 0, extra = 0;
	char *str = va_arg(arg, char *);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_print(str[i]))
			buffer[i + extra] = str[i];
		else
			extra += append_hex(str[i], buffer, i + extra);
		i++;
	}
	buffer[i + extra] = '\0';
	return (write(1, buffer, i + extra));
}

/**
* pr_pointer - Prints pointer
* @arg: arguments
* @buffer: array
* @flags: handle flags
*
* Return: Number of chars printed.
*/
int pr_pointer(va_list arg, char buffer[], int flags)
{
	char extra = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long p;
	char aleph_tab[] = "0123456789abcdef";
	void *address = va_arg(arg, void *);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';

	p = (unsigned long)address;
	while (p > 0)
	{
		buffer[ind--] = aleph_tab[p % 16];
		p /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra = '+', length++;
	else if (flags & F_SPACE)
	extra =  ' ', length++;

	ind++;
	return (write(1, &buffer[i], BUFF_SIZE - i - 1));
}
