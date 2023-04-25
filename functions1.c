#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_hexa - prints a hexadecimal number
 * @args: list of arguments
 * @map_to: string of characters to map to
 * @buffer: buffer to store output in
 * @flags: flags used to modify the output
 * @width: minimum width of the output
 * @precision: precision of the output
 * @length: length modifier for the output
 *
 * Return: number of characters printed
 */
int print_hexa(va_list args, char map_to[], char buffer[],
              __attribute__((unused))int flags,
              __attribute__((unused))int width,
              __attribute__((unused))int precision,
              __attribute__((unused))int length)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int i, shifter, count = 0;
    char temp;

    for (shifter = 28; shifter >= 0; shifter -= 4)
    {
        i = (n >> shifter) & 0xf;
        if (count == 0 && i == 0)
            continue;
        temp = map_to[i];
        buffer[count] = temp;
        count++;
    }
    if (count == 0)
    {
        buffer[count] = '0';
        count++;
    }
    buffer[count] = '\0';

    return (count);
}

/**
 * print_hexadecimal - prints a hexadecimal number
 * @args: list of arguments
 * @flags: flags used to modify the output
 * @width: minimum width of the output
 * @precision: precision of the output
 * @length: length modifier for the output
 *
 * Return: number of characters printed
 */
int print_hexadecimal(va_list args, int flags, int width,
                      int precision, int length)
{
    char buffer[100];
    int count;

    (void)flags;
    (void)width;
    (void)precision;
    (void)length;

    count = print_hexa(args, "0123456789abcdef", buffer, flags, width,
                       precision, length);

    printf("%s", buffer);

    return (count);
}

/**
 * print_hexadecimal_upper - prints an uppercase hexadecimal number
 * @args: list of arguments
 * @flags: flags used to modify the output
 * @width: minimum width of the output
 * @precision: precision of the output
 * @length: length modifier for the output
 *
 * Return: number of characters printed
 */
int print_hexadecimal_upper(va_list args, int flags, int width,
                            int precision, int length)
{
    char buffer[100];
    int count;

    (void)flags;
    (void)width;
    (void)precision;
    (void)length;

    count = print_hexa(args, "0123456789ABCDEF", buffer, flags, width,
                       precision, length);

    printf("%s", buffer);

    return (count);
}

