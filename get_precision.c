#include "main.h"
/**
<<<<<<< HEAD
 * get_precision - Calculates thePrecision forPrinting
 * @format: FormattedString inWhich toPrint theArguments
 * @i: List arguments to bePrinted.
 * @list: listOf arguments.
=======
 * to_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
>>>>>>> 1c8b9320a59c23a4a305459c7e97e0a77ac23e73
 *
 * Return: Precision....maybe
 */
int to_precision(const char *format, int *i, va_list list)
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
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
