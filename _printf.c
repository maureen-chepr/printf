#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - A function that produces output according to a format
 * @format: Character string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, result = 0, result_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index ==  BUFFER_SIZE)
				print_buffer(buffer, &buff_index);
			result_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = find_flags(format, &i);
			width = find_width(format, &i, args);
			precision = find_precision(format, &i, args);
			size = find_size(format, &i);
			++i;
			result = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (result == -1)
				return (-1);
			result_chars += printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(args);

	return (result_chars);
}

/**
 * print_buffer - A function that prints the contents of the buffer
 * @buffer: Buffer array
 * @buff_index: Index to add next character
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
