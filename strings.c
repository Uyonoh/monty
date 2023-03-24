#include "monty.h"

/**
 * str_toint - convert string to int
 * @str: string
 *
 * Return: int
 */

int str_toint(char *str)
{
	int n;
	int c;
	int i;
	int len;

	i = 0;
	n = 0;
	len = _strlen(str) - 1;

	if (str == NULL)
	{
		return (0);
	}
	for (; len >= 0; len--, i++)
	{
		if (str[len] >= 48 && str[len] <= 57)
		{
			c = str[len] - 48;
			n += c * (_pow(10, i));
		}

	}
	return (n);
}

/**
 * int_tostr - convert int to string
 * @n: int number
 *
 * Return: string
 */

char *int_tostr(int n)
{
	int string_buffer;
	char *str;

	string_buffer = STRING_BUFFER;
	str = malloc(sizeof(char) * string_buffer);

	get_num(n, str, 0);
	return (str);
}

/**
 * get_num - get first digit in a number(recursive)
 * @n: number
 * @str: string to store numbers
 * @index: string index
 *
 * Return: void
 */

void get_num(int n, char *str, int index)
{
	int i;
	int x;
	int r;
	int l;
	int num;

	i = 0;
	num = n;
	while (n > 10)
	{
		n /= 10;
		i++;
	}

	x = _pow(10, i);
	r = num - (x * n);

	str[index] = n + '0';

	l = ilen(num) - ilen(r);
	if (l > 1)
	{
		for (; l > 1; l--)
		{
			index++;
			str[index] = '0';
		}
	}


	if (r != 0)
	{
		get_num(r, str, index + 1);
	}
}

/**
 * _pow - get the power of a num to another
 * @n: base
 * @e: exponent
 *
 * Return: n^e
 */

int _pow(int n, int e)
{
	int i;

	if (e == 0)
	{
		return (1);
	}

	i = n;
	for (; e > 1; e--)
	{
		n *= i;
	}
	return (n);
}

/**
 * ilen - gets the length of an integer
 * @n: integer to be checked
 *
 * Return: length of integer
  */

int ilen(int n)
{
	int i;

	i = 0;

	if (n == 0)
		i = 1;

	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}


/**
 * _strlen - gets length of string
 * @str: string
 *
 * Return: (int)length of string
 */

int _strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
