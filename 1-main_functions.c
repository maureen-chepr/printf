#include "main.h"

/**
 * print_unsigned - A function that prints an unsigned number
 * @types: Argument types
 * @buffer: Buffer array
 * @flags: find flags
 * @width: find width
 * @precision: Specify precision
 * @size: Specify size
 * Return: Number of characters
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i =  BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - A function that prints an unsigned number in octal form
 * @types: Argument types
 * @buffer: Buffer array
 * @flags: find flags
 * @width: find width
 * @precision: Specify precision
 * @size: Specify size
 * Return: Number of characters
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i =  BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - A function that prints an
 * unsigned number in hexadecimal form
 * @types: Argument types
 * @buffer: Buffer array
 * @flags: find flags
 * @width: find width
 * @precision: Specify precision
 * @size: Specify size
 * Return: Number of characters
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - A function that prints an
 * unsigned number in upper hexadecimal form
 * @types: Argument types
 * @buffer: Buffer array
 * @flags: find flags
 * @width: find width
 * @precision: Specify precision
 * @size: Specify size
 * Return: Number of characters
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - A function that prints a hexadecimal number in lower or upper
 * @types: Argument types
 * @buffer: Buffer array
 * @flags: find flags
 * @width: find width
 * @precision: Specify precision
 * @size: Specify size
 * @map_to: Array of values to map the number to
 * @flag_ch: find active flags
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i =  BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
