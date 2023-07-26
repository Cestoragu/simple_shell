#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int _delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _alpha - checks for alphabetic character
 * @d: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _alpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @p: the string to be converted
 * Return: 0 if no numbers in string, otherwise converte number
 */

int _atoi(char *p)
{
	int n, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (n = 0; p[n] != '\0' && flag != 2; n++)
	{
		if (p[n] == '-')
			sign *= -1;

		if (p[n] >= '0' && p[n] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (p[n] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
