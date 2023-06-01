#include "main.h"
/**
 * pull_print - Prints an argument based on its type
 * @format: string to print argument
 * @arg: arguments to print
 * @index: index
 * @buffer: array to handle print
 * @flag: Calculate flags
 * @width: width
 * @precision: specify precision
 * @size: size
 * Return: 1 or 2;
 */
int pull_print(const char *format, int *index, va_list arg, char buffer[],
	int flag, int width, int precision, int size)
{
	int i, f_len = 0, p_char = -1;

	UNUSED(precision);
	UNUSED(size);
	UNUSED(buffer), UNUSED(flag), UNUSED(width);
	format_t format_types[] = {
		{'c', pr_char},
		{'s', pr_string},
		{'%', pr_cent},
		{'i', pr_int}, {'d', pr_int},
		{'b', pr_bin},
		{'u', pr_uint},
		{'o', pr_octal},
		{'x', pr_hex},
		{'X', pr_HEX},
		{'p', pr_pointer},
		{'S', pr_String},
		{'r', pr_rev},
		{'R', pr_rot13},
		{'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*index] == format_types[i].format)
			return (format_types[i].f(arg));
	if (format_types[i].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		f_len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			f_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		f_len += write(1, &format[*index], 1);
		return (f_len);
	}
	return (p_char);
}
