#include "main.h"

/**
 * find_precision - A function that finds the precision
 * @format: A character string
 * @i: Parameter
 * @args: List of arguments
 * Return: Precision.
 */
int find_precision(const char *format, int *i, va_list args)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
