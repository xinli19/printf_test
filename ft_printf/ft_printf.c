#include <stdarg.h>
#include "libft.h"

static int	ft_print_arg(va_list args, char c, int *printed_words)
{
	if (c == 'c')
		*printed_words += ft_print_char(va_arg(args, int));
	else if (c == 's')
		*printed_words += ft_print_str(va_arg(args, char *));	
	else if (c == 'd' || c == 'i')
		*printed_words += ft_print_int(va_arg(args, int));
	else if (c == 'p')
		*printed_words += ft_put_pointer(va_arg(args, unsigned int));
	else if (c == 'x')
		*printed_words += ft_print_hex(va_arg(args, unsigned int),'x');
	else if (c == 'X')
		*printed_words += ft_print_hex(va_arg(args, unsigned int), 'X');
	else if (c == 'u')
		*printed_words += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		*printed_words += ft_print_char('%');
}

int ft_printf(char *s, ...)
 {
/*
	1. control the input
*/

//if (!s || is_valid(s) == 0)
//		return (0);
/*
	2.  debug and do the make file and test it 
*/


	int		i;
	int		printed_words;
	va_list	args;

	i = 0;
	printed_words = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar_fd(s[i], 1);
		else if (s[i] == '%')
		{
			i += 1;
			ft_print_arg(args, s[i], &printed_words);
			i++;
		}
		i++;
	}
	va_end(args);
	return (printed_words);
 }
#include <limits.h>
int main()
{
	char test = 'a';
	char name[] = "amy";
	int age = 23;
	unsigned int u = UINT_MAX;
	char *p = name;
	int h = INT_MAX;

	ft_printf("test %c, my name is %s, and i am %d years old.let's check the pointer %p,  and unsigned %u,and the hex %x, big hex %X and the %u, test finished", test, name, age, p,u,h,h);
	return (0);
}
