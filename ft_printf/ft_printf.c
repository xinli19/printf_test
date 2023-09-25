#include <stdarg.h>
#include "libftprintf.h"

static void	ft_print_arg(va_list args, char c, int *printed_words)
{
	if (c == 'c')
		*printed_words += ft_print_char(va_arg(args, int));
	else if (c == 's')
		*printed_words += ft_print_str(va_arg(args, char *));	
	else if (c == 'd' || c == 'i')
		*printed_words += ft_print_int(va_arg(args, int));
	else if (c == 'p')
		*printed_words += ft_print_pointer(va_arg(args, void *));
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
	int		i;
	int		printed_words;
	va_list	args;
	const char format[8] = "csdipxXu";;

	i = 0;
	printed_words = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			printed_words += ft_print_char(s[i]);
		else if (s[i] == '%')
		{
			i += 1;
			if (s[i] == '%'|| ft_strchr(format, s[i]) == NULL)
					printed_words += ft_print_char(s[i]);
			else if (ft_strchr(format,s[i]) != NULL)
					ft_print_arg(args, s[i], &printed_words);
		}
		i++;
	}
	va_end(args);
	return (printed_words);
 }
 
#include <stdio.h>
#include <limits.h>
int main()
{
	ft_printf("1: %s", "");
		ft_printf("2: %s", (char *)NULL);
		ft_printf("3: %s", "some string with %s hehe");
		ft_printf("4: %s", "can it handle \t and \n?");
		ft_printf("5: %sx", "{} al$#@@@^&$$^#^@@^$*((&");
		ft_printf("6: %s%s%s", "And ", "some", "joined");
		ft_printf("7: %ss%ss%ss", "And ", "some other", "joined");
		printf("\n");
		printf("1: %s", "");
		printf("2: %s", (char *)NULL);
	printf("3: %s", "some string with %s hehe");
		printf("4: %s", "can it handle \t and \n?");
		printf("5: %sx", "{} al$#@@@^&$$^#^@@^$*((&");
		printf("6: %s%s%s", "And ", "some", "joined");
		printf("7: %ss%ss%ss", "And ", "some other", "joined");
	

	ft_printf("1:%p", "");
		ft_printf("\n2:%p", NULL);
		ft_printf("\n3:%p", (void *)-14523);
		ft_printf("0x%p-", (void *)ULONG_MAX);
		ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
		printf("\n");
	printf("1:%p", "");
		printf("\n2:%p", NULL);
		printf("\n3:%p", (void *)-14523);
		printf("0x%p-", (void *)ULONG_MAX);
		printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	ft_printf("%d", 0);
		ft_printf("%d", -10);
		ft_printf("%d", -200000);
		ft_printf("%d", -6000023);
		ft_printf("%d", 10);
		ft_printf("%d", 10000);
		ft_printf("%d", 100023);
		ft_printf("%d", INT_MAX);
		ft_printf("%d", INT_MIN);
		ft_printf("dgs%dxx", 10);
		ft_printf("%d%dd%d", 1, 2, -3);
		printf("\n");
		printf("%d", 0);
		printf("%d", -10);
		printf("%d", -200000);
		printf("%d", -6000023);
		printf("%d", 10);
		printf("%d", 10000);
		printf("%d", 100023);
		printf("%d", INT_MAX);
		printf("%d", INT_MIN);
		printf("dgs%dxx", 10);
		printf("%d%dd%d", 1, 2, -3);
		printf("\n");
		ft_printf("%i", 0);
		ft_printf("%i", -10);
		ft_printf("%i", -200000);
		ft_printf("%i", -6000023);
		ft_printf("%i", 10);
		ft_printf("%i", 10000);
		ft_printf("%i", 100023);
		ft_printf("%i", INT_MAX);
		ft_printf("%i", INT_MIN);
		ft_printf("dgs%ixx", 10);
		ft_printf("%i%ii%i", 1, 2, -3);
		printf("\n");
		printf("%i", 0);
		printf("%i", -10);
		printf("%i", -200000);
		printf("%i", -6000023);
		printf("%i", 10);
		printf("%i", 10000);
		printf("%i", 100023);
		printf("%i", INT_MAX);
		printf("%i", INT_MIN);
		printf("dgs%ixx", 10);
		printf("%i%ii%i", 1, 2, -3);
		
		printf("%u", 0);
		printf("%u", -10);
		printf("%u", -200000);
		printf("%u", -6000023);
		printf("%u", 10);
		printf("%u", 10000);
		printf("%u", 100023);
		printf("%u", INT_MAX);
		printf("%u", INT_MIN);
		printf("%u", UINT_MAX);
		printf("dgs%uxx", 10);
		printf("%u%uu%u", 1, 2, -3);
		printf("\n");
		ft_printf("%u", 0);
		ft_printf("%u", -10);
		ft_printf("%u", -200000);
		ft_printf("%u", -6000023);
		ft_printf("%u", 10);
		ft_printf("%u", 10000);
		ft_printf("%u", 100023);
		ft_printf("%u", INT_MAX);
		ft_printf("%u", INT_MIN);
		ft_printf("%u", UINT_MAX);
		ft_printf("dgs%uxx", 10);
		ft_printf("%u%uu%u", 1, 2, -3);
	
	printf("%x", 0);
		printf("%x", -10);
		printf("%x", -200000);
		printf("%x", -6000023);
		printf("%x", 10);
		printf("%x", 10000);
		printf("%x", 100023);
		printf("%x", 0xabcdef);
		printf("%x", 0x7fedcba1);
		printf("%x", INT_MAX);
		printf("%x", INT_MIN);
		printf("%x", UINT_MAX);
		printf("dgs%xxx", 10);
		printf("%x%xx%x", 1, 2, -3);
		printf("\n");
		ft_printf("%x", 0);
		ft_printf("%x", -10);
		ft_printf("%x", -200000);
		ft_printf("%x", -6000023);
		ft_printf("%x", 10);
		ft_printf("%x", 10000);
		ft_printf("%x", 100023);
		ft_printf("%x", 0xabcdef);
		ft_printf("%x", 0x7fedcba1);
		ft_printf("%x", INT_MAX);
		ft_printf("%x", INT_MIN);
		ft_printf("%x", UINT_MAX);
		ft_printf("dgs%xxx", 10);
		ft_printf("%x%xx%x", 1, 2, -3);
		printf("%X", 0);
		printf("%X", -10);
		printf("%X", -200000);
		printf("%X", -6000023);
		printf("%X", 10);
		printf("%X", 10000);
		printf("%X", 100023);
		printf("%X", 0xabcdef);
		printf("%X", 0x7fedcba1);
		printf("%X", INT_MAX);
		printf("%X", INT_MIN);
		printf("%X", UINT_MAX);
		printf("dgs%Xxx", 10);
		printf("%X%Xx%X", 1, 2, -3);
		printf("\n");
		ft_printf("%X", 0);
		ft_printf("%X", -10);
		ft_printf("%X", -200000);
		ft_printf("%X", -6000023);
		ft_printf("%X", 10);
		ft_printf("%X", 10000);
		ft_printf("%X", 100023);
		ft_printf("%X", 0xabcdef);
		ft_printf("%X", 0x7fedcba1);
		ft_printf("%X", INT_MAX);
		ft_printf("%X", INT_MIN);
		ft_printf("%X", UINT_MAX);
		ft_printf("dgs%Xxx", 10);
		ft_printf("%X%Xx%X", 1, 2, -3);
	return (0);
}

