#include "main.h"
/**
 * handle_print - A function that prints an argument based on its type
 * @_format: Formatted string
 * @args: List of arguments
 * @ind: index
 * @buffer: Buffer array.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *_format, int *ind, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, result_chars = -1;
	_format_t _format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; _format_types[i]._format != '\0'; i++)
		if (_format[*ind] == _format_types[i]._format)
			return (_format_types[i].func(args, buffer, flags, width, precision, size));

	if (_format_types[i]._format == '\0')
	{
		if (_format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (_format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (_format[*ind] != ' ' && _format[*ind] != '%')
				--(*ind);
			if (_format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &_format[*ind], 1);
		return (unknow_len);
	}
	return (result_chars);
}
