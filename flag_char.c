#include "main.h"

/**
 * pr_flag - print flag characters
 * @format: pointer
 * @index: input
 *
 * Return: flag
 */
int pr_flag(const char *format, int *index)
{
	int new_i, j;
	int flag = 0;
	const char FLAG_CH[] = {'+', ' ', '#', '0', '-', '\0'};
	const int FLAG [] = {F_PLUS, F_SPACE, F_HASH, F_ZERO, F_MINUS, 0};

	for (new_i = *index + 1; format[new_i] != '\0'; new_i++)
	{
		for (j = 0; FLAG_CH[j] != '\0'; j++)
			if (format[new_i] == FLAG_CH[j])
			{
				flag |= FLAG[j];
				break;
			}

		if (FLAG_CH[j] == 0)
			break;
	}

	*index = new_i - 1;

	return (flag);
}
