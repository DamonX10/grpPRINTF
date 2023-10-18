#include "main.h"
/************************* PRINT_UNSIGNED_NUMBER *************************/
/**
 * print_unsigned - unsigned number
 * @args: arguments
 * @buffer: Buffer array handle print
 * @flags:  CalculatesActive flags
 * @width: getWidth
 * @precision: PrecisionSpecification
 * @length: LengthSpecifier
 * Return: chars printed.
 */
int print_unsigned(va_list args, char buffer[],
		int flags, int width, int precision, int length)
{
	int i = 0;
	unsigned long int num = va_arg(args, unsigned long int);
	char reversed[BUFF_SIZE];

	num = convert_size_unsgnd(num, length);
	if (num == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (num > 0)
		{
			reversed[i++] = (num % 10) + '0';
			num /= 10;
		}
		i--;
		while (i >= 0)
		{
			buffer[BUFF_SIZE - 2 - i] = reversed[i];
			i--;
		}
	}
	buffer[BUFF_SIZE - 1] = '\0';
	return (write_unsgnd(
    0,
    BUFF_SIZE - 2 - i,
    buffer,
    flags,
    width,
    precision,
    length
    ));

}
/************* PRINT_UNSIGNED_NUMBER_IN_OCTAL  ****************/
/**
 * print_octal - Prints unsigned number in octal notation
 * @args: arguments
 * @buffer: Buffer arrayTo handle print
 * @flags: Calculates activeFlags
 * @width: WidthSpecifier
 * @precision: PrecisionSpecifier
 * @length: LengthSpecifier
 * Return: chars printed
 */
int print_octal(va_list args, char buffer[],
		int flags, int width, int precision, int length)
{
	int i = 0;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;
	char reversed[BUFF_SIZE];
	num = convert_size_unsgnd(num, length);
	if (num == 0) {
		reversed[i++] = '0';
	} else {
		while (num > 0) {
			reversed[i++] = (num % 8) + '0';
			num /= 8;
		}
		if (flags & F_HASH && init_num != 0) {
			reversed[i++] = '0';
		}
	}
	i--;
	while (i >= 0) {
		buffer[BUFF_SIZE - 2 - i] = reversed[i];
		i--;
	}
	buffer[BUFF_SIZE - 1] = '\0';
	return write_unsgnd(0, BUFF_SIZE - 2 - i, buffer, flags, width, precision, length);
}
/************** PRINT_UNSIGNED_NUMBER_IN_HEXADECIMAL **************/
/* print_hexadecimal - Prints unsigned number hexadecimal notation
 * @types: arguments
 * @buffer: Buffer arrayTo handle print
 * @flags:  Calculates activeFlags
 * @width: getWidth
 * @precision: PrecisionSpecification
 * @size: SizeSpecifier
 * Return: chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/************* PRINT_UNSIGNED_NUMBER_IN_UPPER_HEXADECIMAL **************/
/* print_hexa_upper - Prints unsigned number in upperHexadecimal notation
 * @types: arguments
 * @buffer: Buffer arrayTo handle print
 * @flags:  CalculatesActive flags
 * @width: getWidth
 * @precision: PrecisionSpecification
 * @size: SizeSpecifier
 * Return: chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/************** PRINT_HEXX_NUM_IN_LOWER_OR_UPPER **************/
/* print_hexa - Prints hexadecimal number lower or upper
 * @types: arguments
 * @map_to: Array of values map the number
 * @buffer: Buffer array handle print
 * @flags:  CalculatesActive flags
 * @flag_ch: CalculatesActive flags
 * @width: getWidth
 * @precision: PrecisionSpecification
 * @size: SizeSpecifier
 * Return: Number chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
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
