#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List of arguments
 * Return: Number of chars printed.
 */
int print_pointer(va_list args)
{
	char buffer[BUFF_SIZE] = {'\0'};
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	ind++;

	return (write_pointer(buffer, ind, length,
		0, 0, padd, extra_c, 1));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @args: List of arguments
 * Return: Number of chars printed
 */
int print_non_printable(va_list args)
{
	char buffer[BUFF_SIZE] = {'\0'};
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @args: List of arguments
 * Return: Numbers of chars printed
 */
int print_reverse(va_list args)
{
	char *str;
	int i, count = 0;

	str = va_arg(args, char *);

	if (str == NULL)
		str = ")Null(";

	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}

	return (count);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @args: List of arguments
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list args)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
		}
	}
}
