#include "main.h"
/**
 * is_printable - Evaluates a char isPrintable
 * @c: Char toBe evaluated
 *
 * Return: 1 if c isPrintable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - ascci inHexadecimal To buffer
 * @buffer: ArrayOf chars.
 * @i: IndexAt which toBegin appending.
 * @ascii_code: ASSCI.
 * Return: =always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* hexaFormat code isAlways 2 digitsLong */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}
/**
 * is_digit - Checks if aChar is aDigit
 * @c: Char toBe evaluated
 *
 * Return: 1 if c is digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_number - Shows number to specified size
 * @num: Number toBe casted.
 * @size: Number ShowingThe type toBe casted.
 *
 * Return: Casted value of number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number toBe casted
 * @size: Number showingThe type to be casted
 *
 * Return: CastedValue of number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
