#include "main.h"

void pr_buffer(char buffer[], int *b_index);

/**
 * _printf - prints formatted output
 * @format: pointer
 *
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	int i, print = 0, pr_char = 0;
	int flag, width, precision, size, b_index = 0, index = 0;
	va_list arg;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[b_index++] = format[i];
			if (b_index == BUFF_SIZE)
				pr_buffer(buffer, &b_index);
			pr_char++;
		}
		else
		{
			pr_buffer(buffer, &b_index);
			flag = pr_flag(format, &index);
			width = pr_width(format, &index, arg);
			precision = pr_precision;
			size = pr_size;
			++i;
			print = syn_print(format, buffer, arg, &i, flag, \width, precision, size);
			if (print == -1)
				return (-1);
			pr_char += print;
		}
	}

	pr_buffer(buffer, &b_index);

	va_end(arg);

	return (pr_char);
}

/**
 * pr_buffer - print buffer
 * @buffer: array
 * @b_index: index
 */
void pr_buffer(char buffer[], int *b_index)
{
	*b_index = 0;

	if (*b_index > 0)
		write(1, &buffer[0], *b_index);
}

