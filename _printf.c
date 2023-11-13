#include "main.h"
/**
 * printchar - function that produces output according to a format.
 *
 * @args: format of value to print
 *
 */

void printchar(va_list args, int *count)
{
        char chihajalekher = (char)va_arg(args, int);
	(*count)++;
        write(1, &chihajalekher, 1);
}
/**
 * printstring - function that produces output according to a format.
 *
 * @args: format of value to print
 * @count: dakchi sheh
 *
 */

void printstring(va_list args, int *count)
{
        char *str = va_arg(args, char *);

        if (str == NULL)
        {
                str = "(null)";
        }
        while (*str)
        {
                write(1, str, 1);
                str++;
		(*count)++;
        }
}


/**
 * _printf - function that produces output according to a format.
 *
 * @format: format of value to print
 *
 * Return:length of value
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int formatLen = strlen(format);
	va_list args;

	va_start(args, format);
	while (i < formatLen)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					printchar(args, &count);
					break;
				case 's':
					printstring(args, &count);
					break;
				case '%':
					count++;
					write(1, "%", 1);
					break;
			}
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
