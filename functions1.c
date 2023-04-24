#include "main.h"

#define BUFFER_SIZE 1024
#define FLAG_HASH 1

typedef unsigned long int uint64_t;

/* Print an unsigned number in decimal notation */
int print_decimal_uint64_t(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	uint64_t num = va_arg(args, uint64_t);

	num = convert_size_uint64_t(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_uint64_t(0, i, buffer, flags, width, precision, size));
}

/* Print an unsigned number in octal notation */
int print_octal_uint64_t(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	uint64_t num = va_arg(args, uint64_t);
	uint64_t init_num = num;

	UNUSED(width);

	num = convert_size_uint64_t(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FLAG_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_uint64_t(0, i, buffer, flags, width, precision, size));
}

/* Print an unsigned number in hexadecimal notation */
int print_hexadecimal_uint64_t(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexadecimal_uint64_t_map(args, "0123456789abcdef",
		buffer, flags, 'x', width, precision, size));
}

/* Print an unsigned number in uppercase hexadecimal notation */
int print_hexadecimal_uppercase_uint64_t(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexadecimal_uint64_t_map(args, "0123456789ABCDEF",
		buffer, flags, 'X', width, precision, size));
}

/* Print an unsigned number in hexadecimal notation using a given map */
int print_hexadecimal_uint64_t_map(va_list args, char map[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	uint64_t num = va_arg(args, uint64_t);
	uint64_t init_num = num;

	UNUSED(width);

	num = convert_size_uint64_t(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\

