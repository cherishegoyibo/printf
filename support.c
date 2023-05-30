#include "main.h"

/**
 * pr_num - prints numbers
 * @arg: arguments
 * Return: number of arguments
 */
int pr_num(va_list arg)
{
	int n, i, len;
	unsigned int num;

	n = va_arg(arg, int);
	i = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / i > 9; )
		i *= 10;

	for (; i != 0; )
	{
		len += _putchar('0' + num / i);
		num %= i;
		i /= 10;
	}

	return (len);
}

/**
* rev_str - reverse string
* @s: input
*
* Return: pointer
*/
char *rev_str(char *s)
{
int len, i;
char *dest;
char temp;

if (s == NULL || *s == &#39;\0&#39;)
return (s);

for (len = 0; s[len] != &#39;\0&#39;; len++);

dest = malloc(sizeof(char) * (len + 1));
if (dest == NULL)
return (NULL);
_memcpy(dest, s, len);
for (i = 0; i &lt; len; i++, len--)
{
temp = dest[len - 1];
dest[len - 1] = dest[i];
dest[i] = temp;
}
return (dest);
}

/**
* _memcpy - copy memory
* @dest: input
* @src: input
* @n: number of bytes
*
* Return: pointer
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

for (i = 0; i &lt; n; i++)
dest[i] = src[i];
dest[i] = &#39;\0&#39;;

return (dest);
}

/**
* base_len - calculate base lenght
* @n: input
* @b: base input
*
* Return: lenght
*/
unsigned int base_len(unsigned int n, int b)
{
unsigned int i;

for (i = 0; n &gt; 0; i++)

n = n / b;
return (i);
}

/**
* pr_base - print base number
* @c: string input
*
*/
void pr_base(char *c)
{
int i;
for (i = 0; c[i] != &#39;\0&#39;; i++)
_putchar(str[i]);
}
