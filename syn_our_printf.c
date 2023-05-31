#include "main.h"

/**
 * pull_print - prints va_list
 * @format: string
 * @index: index
 * @arg: argument
 * @buffer: array
 * @flag: print flag characters
 * @width: prints the width
 * @size: prints the size
 * @precision: prints the precision
 * Return: 1 or 2
 */
int pull_print(const char *format, int index, va_list arg, char buffer[],
		int flag, int width, int size, int precision)
{
	int i, len = 0, p_char = -1;
	format_t format_types[] = {
		{'c', pr_char}, {'s', pr_string},
		{'%', pr_cent}, {'b', pr_bin},
		{'i', pr_int},	{'o', pr_octal},
		{'d', pr_int},	{'u', pr_uint},
		{'x', pr_hex}, {'p', pr_pointer},
		{'X', pr_HEX}, {'S', pr_String},
		{'r', pr_rev}, {'R', rot13}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*index] == format_types[i].format)
			return (format_types[i].f(arg, buffer, flag, width, size));
	if (format_types[i].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		len += write(1, &format[*index], 1);
		return (len);
	}
	return (p_char);
}
