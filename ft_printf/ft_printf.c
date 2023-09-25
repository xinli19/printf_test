#include <stdarg.h>
#include "libft.h"

void	check_input(va_list args,char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);	
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args,int), 1);
	else if (c == 'p')
		ft_putpointer(va_arg(args, long));
	else if (c == 'x')
		ft_puthex_lower(va_arg(args, int));
	else if (c == 'X')
		ft_puthex_upper(va_arg(args, int));
	else if (c == 'u')
		ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

void ft_printf(char *s, ...)
 {
/*
	1. control the input
*/

//if (!s || is_valid(s) == 0)
//		return ;
/*
	2. do the while loop of the va_lst
*/


	int	i;

	va_list	args;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar_fd(s[i], 1);
		else if (s[i] == '%')
		{
			i += 1;
			check_input(args, s[i]);
			i++;
		}
		i++;
	}
	va_end(args);
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
