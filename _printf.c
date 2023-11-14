#include "main.h"
/**
 * printchar - mini function to handle %c
 *
 * @args: arguments to print
 * @count: count var
 *
 */

void printchar(va_list args, int *count)
{
	char chihajalekher = (char)va_arg(args, int);
	(*count)++;
	write(1, &chihajalekher, 1);
}
/**
 * printstring - mini function to hundle %s
 *
 * @args: arguments to print
 * @count: count var
 *
 */
void printstring(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		write(1, "(nill)", 6);
		(*count) += 6;
	}
	else
	{
		int strLen = strlen(str);

		write(1, str, strLen);
		(*count) += strLen;
	}
}
/**
 * print_int - mini function to handle %d and %i
 *
 * @args: arguments to print
 * @count: count var
 *
 * Return: Nothing (void)
 */
void print_int(va_list args, int *count)
{
	int num = va_arg(args, int);
	int num_digits = snprintf(NULL, 0, "%d", num);
	char *num_str = malloc(num_digits + 1);

	if (num_str == NULL)
		return;
	snprintf(num_str, num_digits + 1, "%d", num);
	write(1, num_str, num_digits);
	(*count) += num_digits;
	free(num_str);
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
	int i = 0, count = 0;
	int formatLen = strlen(format);
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
			return (-1);
	else
	{
		va_start(args, format);
		while ((i < formatLen) && (format[i] != '\0'))
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
					case 'd':
					case 'i':
						print_int(args, &count);
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
	}
	va_end(args);
	return (count);
}
