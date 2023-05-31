#include "main.h"

/**
* pr_String - Prints non-printable characters
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
* @flag: handle flags
*
* Return: Number of chars printed.
*/
int pr_pointer(va_list arg, char buffer[], int flag)
{
	char extra = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1;
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
		len++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra = '+', len++;
	else if (flag & F_SPACE)
	extra =  ' ', len++;

	ind++;

	return (wr_pointer(buffer, ind, len, width, flag, padd, extra, padd_start));
}
