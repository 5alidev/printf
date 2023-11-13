#include "main.h"
/**
 * _printf - function that produces output according to a format.
 *
 * @format: format of value to print
 *
 * Return:length of value
 */
int _printf(const char *format, ...)
{
	char chiHaja;
	int i = 0, count = 0;
	int formatLen = strlen(format);
	char *str = NULL;
	va_list args;

	va_start(args, format);
	while (i < formatLen)
	{
		count++;
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					chiHaja = (char)va_arg(args, int);
					write(1, &chiHaja, 1);
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						write(1, str, 1);
						str++;
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					break;
			}
			i++;
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
