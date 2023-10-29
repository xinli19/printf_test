#include "ft_printf.h"

void	ft_print_arg(va_list args, char c, int *printed_words)
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
		*printed_words += ft_print_hex(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		*printed_words += ft_print_hex(va_arg(args, unsigned int), 'X');
	else if (c == 'u')
		*printed_words += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		*printed_words += ft_print_char('%');
}

void	check_flag(int flag, int *printed_words)
{
	if (flag == 0)
		*printed_words = -1;
	else if (flag != 0)
		*printed_words += ft_print_char('%');
}

int	co(char *s, int *i, int *printed_words)
{
	int		flag;

	flag = 0;
	if (s[(*i)] == '\0')
	{
		check_flag(flag, printed_words);
		return (0);
	}
	else if (s[(*i)] == ' ')
	{
		if (ft_strchr("csdipxXu%", s[(*i) + 1]))
			(*i)++;
		flag++;
		return (1);
	}
	else if (s[(*i)] != '%' && !(ft_strchr("csdipxXu%", s[(*i)])))
	{
		*printed_words += ft_print_char('%');
		*printed_words += ft_print_char(s[(*i)]);
		flag++;
	}
	else if (ft_strchr("csdipxXu%", s[(*i)]))
		return (1);
}

int	ft_printf(char *s, ...)
 {
	int		i;
	int		printed_words;
	va_list	args;

	i = 0;
	printed_words = 0;
	if (s == NULL)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			printed_words += ft_print_char(s[i]);
		else if (s[i++] == '%')
		{
			if (!co(s, &i, &printed_words))
				break ;
			else
				ft_print_arg(args, s[i], &printed_words);
		}
		i++;
	}	
	va_end(args);
	return (printed_words);
}

#include <stdio.h>
#include <string.h>
#include <limits.h>
static void passt_da_des_eh(int a, int b)
{
	if (a == b)
		printf("\e[38;2;0;255;0mPASST\e[0m\n\n");
	else
		printf("\e[38;2;255;0;0mPASST NET: %d != %d\e[0m\n\n", a, b);
}
/*
int main(void)
{
	char *format;
	char *string;
	char character;
	int num;
	int lft;
	int lorig;

	lft=printf("%%w%%w%%w%\n");
	lorig=ft_printf("%%w%%w%%w%\n");
	printf("%d, %d\n",lft,lorig);

		printf("   single %%:\n");
	lft = ft_printf("'   %");
	printf("|\n");
	lorig = printf("'   %");
	printf("|\n");
	passt_da_des_eh(lft, lorig);


	lft = ft_printf("%w%w%d", 42);
	printf("|\n");
	lorig = printf("%w%w%d", 42);
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	// ft_printf(format, 1, 2, 3);  

	// PAUL TESTS
	printf("   single %%:\n");
	lft = ft_printf("'   %");
	printf("|\n");
	lorig = printf("'   %");
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	puts("=== Character: %c ===");
	format = "%c\n";
	character = 'A';
	lft = ft_printf(format, character);
	lorig = printf(format, character);
	passt_da_des_eh(lft, lorig);
	character = 'B';
	lft = ft_printf(format, character);
	lorig = printf(format, character);
	passt_da_des_eh(lft, lorig);

	puts("=== String: %s ===");
	format = "%s\n";
	string = NULL;
	lft = ft_printf(format, string);
	lorig = printf(format, string);
	passt_da_des_eh(lft, lorig);
	string = "Hello I am a String";
	lft = ft_printf(format, string);
	lorig = printf(format, string);
	passt_da_des_eh(lft, lorig);

	puts("\n=== Integer: %d ===");
	format = "%d\n";
	num = 0;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = 42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = -42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = 2147483647;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = -2147483648;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);

	puts("\n=== Hexa lower-Cased: %x ===");
	format = "%x\n";
	num = 0;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = 42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = -42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = 2147483647;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = -2147483648;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);

	puts("\n=== Hexa UPPER-CASED: %X ===");
	format = "%X\n";
	num = 0;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = 42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = -42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = 2147483647;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	num = -2147483648;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);

	puts("\n=== Multiple-Options (%d%s%X) ===");
	format = "%d%s%X\n";
	string = ": ";
	num = 0;
	lft = ft_printf(format, num, string, num);
	lorig = printf(format, num, string, num);
	passt_da_des_eh(lft, lorig);
	num = 42;
	lft = ft_printf(format, num, string, num);
	lorig = printf(format, num, string, num);
	passt_da_des_eh(lft, lorig);
	num = -42;
	lft = ft_printf(format, num, string, num);
	lorig = printf(format, num, string, num);
	passt_da_des_eh(lft, lorig);
	num = 2147483647;
	lft = ft_printf(format, num, string, num);
	lorig = printf(format, num, string, num);
	passt_da_des_eh(lft, lorig);
	num = -2147483648;
	lft = ft_printf(format, num, string, num);
	lorig = printf(format, num, string, num);
	passt_da_des_eh(lft, lorig);

	puts("\n=== Percent: %% ===");
	format = "%%\n";
	lft = ft_printf(format);
	lorig = printf("%%\n");
	passt_da_des_eh(lft, lorig);

	puts("\n=== Pointer: %p ===");
	format = "%p\n";
	string = NULL;
	lft = ft_printf(format, string);
	lorig = printf(format, string);
	passt_da_des_eh(lft, lorig);
	string = "Im a pointer";
	lft = ft_printf(format, string);
	lorig = printf(format, string);
	passt_da_des_eh(lft, lorig);
	puts("\n=== Not supported Option and normal text: %y ===");
	format = "Im not supported %y\n";
	lft = ft_printf(format, string);
	lorig = printf(format, string);
	passt_da_des_eh(lft, lorig);
	puts("\n=== Custom Tests ===");
	format = "%d%d\n";
	num = 42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	format = NULL;
	num = 42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	format = "%c %s %p %d %i %u %x %X %%\n";
	num = 42;
	char c = '4';
	string = "printf";
	lft = ft_printf(format, c, string, string, num, num, num, num, num);
	lorig = printf(format, c, string, string, num, num, num, num, num);
	passt_da_des_eh(lft, lorig);

	puts("\n === Check max Pointer ===");
	format = "%p\n";
	lft = ft_printf(format, 18446744073709551615ULL);
	lorig = printf(format, 18446744073709551615ULL);
	passt_da_des_eh(lft, lorig);

	// GREX TESTS

	printf("   single %%:\n");
	lft = ft_printf("'   %");
	printf("|\n");
	lorig = printf("'   %");
	printf("|\n");
	passt_da_des_eh(lft, lorig);

	lft = ft_printf(" %c,%c,%c,%s", '0', 0, '1', "Hello");
	printf("|\n");
	lorig = printf(" %c,%c,%c,%s", '0', 0, '1', "Hello");
	printf("|\n");
	passt_da_des_eh(lft, lorig);

	ft_printf("char test \n");
	lft = ft_printf(" %c,%c,%c,", '0', 22, '1');
	printf("|\n");
	lorig = printf(" %c,%c,%c,", '0', 22, '1');
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	ft_printf("char test 8\n");
	lft = ft_printf("%c,%c,%c,", '2', '1', 0);
	printf("|\n");
	lorig = printf("%c,%c,%c,", '2', '1', 0);
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	ft_printf("char test 9\n");
	lft = ft_printf("%c,%c,%c,", 0, '1', '2');
	printf("|\n");
	lorig = printf("%c,%c,%c,", 0, '1', '2');
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	ft_printf("str test 10\n");
	lft = ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	printf("|\n");
	lorig = printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	lft = ft_printf(" %s", "äöü~!\"§$%&()=ß²³{[]}@<|>éÈê°\0asd");
	printf("|\n");
	lorig = printf(" %s", "äöü~!\"§$%&()=ß²³{[]}@<|>éÈê°\0asd");
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	ft_printf("nullpointer p test 9\n");
	lft = ft_printf(" %p %p ", 0, 0);
	printf("|\n");
	lorig = printf(" %p %p ", 0, 0);
	printf("|\n");
	passt_da_des_eh(lft, lorig);

	ft_printf("mix test\n");
	lft = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
	printf("|\n");
	lorig = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	printf("test fvvvvvvvvvvvvvvvvvlag skip\n");
	lft = ft_printf(" % c", '0');
	printf("|\n");
	lorig = printf(" % c", '0');
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	printf("NULL test:\n");
	lft = ft_printf(NULL);
	printf("|\n");
	lorig = printf(NULL);
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	lft = ft_printf(NULL, 42);
	printf("|\n");
	lorig = printf(NULL, 42);
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	lft = ft_printf(NULL);
	printf("|\n");
	lorig = printf(NULL);
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	

	puts("test arg failures");
	char *bla = "%d%d\n";
	printf("strlen bla: %zu\n", strlen(bla));
	format = "%d%d\n";
	num = 42;
	lft = ft_printf(format, num);
	lorig = printf(format, num);
	passt_da_des_eh(lft, lorig);
	lft = ft_printf(bla, num);
	lorig = printf(bla, num);
	passt_da_des_eh(lft, lorig);
	lft = ft_printf(format, 42);
	lorig = printf(format, 42);
	passt_da_des_eh(lft, lorig);
	lft = ft_printf(bla, 42);
	lorig = printf(bla, 42);
	passt_da_des_eh(lft, lorig);

	lft = ft_printf("int %d, %d\n", 42);
	printf("|\n");
	lorig = printf("int %d, %d\n", 42);
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	lft = ft_printf("%d%d\n", 42);
	printf("|\n");
	lorig = printf("%d%d\n", 42);
	printf("|\n");
	passt_da_des_eh(lft, lorig);
	int foo = 42;
	lft = ft_printf("%d%d\n", foo);
	printf("|\n");
	lorig = printf("%d%d\n", foo);
	printf("|\n");
	passt_da_des_eh(lft, lorig);

	lft = ft_printf(bla, foo);
	printf("|\n");
	lorig = printf(bla, foo);
	printf("|\n");
	passt_da_des_eh(lft, lorig);

	

	ft_printf("1: %s", "");
		ft_printf("2: %s", (char *)NULL);
		ft_printf("3: %s", "some string with %s hehe");
		ft_printf("4: %s", "can it handle \t and \n?");
		ft_printf("5: %sx", "{} al$#@@@^&$$^#^@@^$*((&");
		ft_printf("6: %s%s%s", "And ", "some", "joined");
		ft_printf("7: %ss%ss%ss", "And ", "some other", "joined");
		printf("\n\n");
	
		printf("1: %s", "");
		printf("2: %s", (char *)NULL);
	printf("3: %s", "some string with %s hehe");
		printf("4: %s", "can it handle \t and \n?");
		printf("5: %sx", "{} al$#@@@^&$$^#^@@^$*((&");
		printf("6: %s%s%s", "And ", "some", "joined");
		printf("7: %ss%ss%ss", "And ", "some other", "joined");
		printf("\n\n");
	ft_printf("1:%p", "");
		ft_printf("\n2:%p", NULL);
		ft_printf("\n3:%p", (void *)-14523);
		ft_printf("0x%p-", (void *)ULONG_MAX);
		ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
		printf("\n\n");
	printf("1:%p", "");
		printf("\n2:%p", NULL);
		printf("\n3:%p", (void *)-14523);
		printf("0x%p-", (void *)ULONG_MAX);
		printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
		printf("\n\n");
	printf("mine___________________________");
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
		printf("\n\n");
	printf("original________________________");
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
		printf("\n\n");

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
			printf("\n\n");
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
		
			printf("\n\n");
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

			printf("\n\n");
		ft_printf("%u", 0);
		ft_printf("%u", -10);
		ft_printf("%u", -200000);
		ft_printf("%u", -6000023);
		ft_printf("%u", 10);
		ft_printf("%u", 10000);
		printf("dgs%xxx", 10);
		printf("%x%xx%x", 1, 2, -3);
		printf("\n");
			printf("\n\n");

		ft_printf("%x", 0);
		ft_printf("%x", -10);
		ft_printf("%x", -200000);
		ft_printf("%x", -6000023);
		ft_printf("%x", 10);
		ft_printf("%x", 100023);
		ft_printf("%u", INT_MAX);
		ft_printf("%u", INT_MIN);
		ft_printf("%u", UINT_MAX);
		ft_printf("dgs%uxx", 10);
		ft_printf("%u%uu%u", 1, 2, -3);
	
	printf("%x", 0);
		printf("dgs%xxx", 10);
		printf("%x%xx%x", 1, 2, -3);

		ft_printf("%x", 0);
		ft_printf("%x", -10);
		ft_printf("%x", -200000);
		ft_printf("%x", -6000023);
		ft_printf("%x", 10);
		ft_printf("%x", 1);
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
			printf("\n\n");

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
			printf("\n\n");

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
			printf("\n\n");

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
*/