#include "main.h"
/**
* pr_size - Prints the size.
* @format: pointer
* @index: pointer
*
* Return: size
*/
int pr_size(const char *format, int *index)
{
	int i = *index + 1;
	int size = 0;

	if (format[i] == 'l')
		size = L_LONG;
	else if (format[curr_i] == 'h')
	size = H_SHORT;

	if (size == 0)
		*index = i - 1;
	else
		*index = i;

	return (size);
}

/**
* pr_width - Prints the width.
* @format: pointer
* @index: pointer
* @arg: arguments.
*
* Return: width.
*/
int pr_width(const char *format, int *index, va_list arg)
{
	int i, width = 0;

	for (i = *index + 1; format[i] != '\0'; i++)
	{
		if (is_digit(format[i]))
		{
			width *= 10;
			width += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;

	}
	*index = i - 1;

	return (width);
}

/**
* pr_precision - Prints the precision.
* @format: string
* @arg: arg
* @index: index
*
* Return: Precision.
*/
int pr_precision(const char *format, va_list arg, int *index)
{
	int i = *index + 1;
	int precision = -1;

	if (format[i] != '.')
		return (precision);

	precision = 0;

	for (i += 1; format[i] != '\0'; i++)
	{
		if (is_digit(format[i]))
		{
			precision *= 10;
			precision += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			precision = va_arg(arg, int);
			break;
		}
		else
			break;

		}

		*index = i - 1;

		return (precision);
}
