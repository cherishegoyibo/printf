#include "main.h"

/**
 * wr_pointer - prints memory address
 * @buffer: array
 * @ind: index
 * @len: lenght specifier
 * @width: width specifier
 * @flag: flags
 * @padd: padding character
 * @extra: character extra
 * @padd_start: padding starts here
 *
 * Return: number printed
 */
int wr_pointer(char buffer[], int ind, int len, int width,
		int flag, char padd, char extra, int padd_start)
{
	int i;

	if (width > len)

	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag && F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra)
				buffer[--ind] = extra;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra)
				buffer[--ind] = extra;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
			else if (!(flag & F_MINUS) && padd == '0')
			{
				if (extra)
					buffer[--padd_start] = extra;
				buffer[1] = '0';
				buffer[2] = 'x';
				return (write(1, &buffer[padd_start], i - padd_start) +
						write(1, &buffer[ind], len - (1 - padd_start) - 2));
			}
		}
		buffer[--ind] = 'x';
		buffer[--ind] = '0';
		if (extra)
			buffer[--ind] = extra;
		return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
	}
}
