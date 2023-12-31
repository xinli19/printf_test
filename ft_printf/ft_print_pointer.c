#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	find_length(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	set_hex_arr(char *digits, unsigned long num, int length)
{
	unsigned long	temp;

	digits[length] = '\0';
	length = length - 1;
	while (length >= 0)
	{
		temp = num % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		digits[length] = temp;
		num = num / 16;
		length--;
	}
}

static int	ft_put_hexstr(char *s)
{
	int	sum;

	sum = 0;
	if (ft_strlen(s) == 2)
	{
		write(1, "0x", 2);
		sum = 2;
	}
	if (*s == 48)
	{
		write(1, &(*s), 1);
		write(1, "x", 1);
		s++;
		sum = 2;
	}
	while (*s == 48)
		s++;
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
		sum++;
	}
	return (sum);
}

static void	ft_arr_tolower(char *digits)
{
	while (*digits)
	{
		if (*digits <= 90 && *digits >= 65)
			*digits += 32;
		else
			digits++;
	}
}

int	ft_print_pointer(void *p)
{
	unsigned long	address;
	int				length;
	char			*digits;
	int				sum;

	address = (unsigned long)p;
	if (address == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		length = find_length(address);
		digits = (char *)malloc(length + 1);
		if (!digits)
			return (0);
		set_hex_arr(digits, address, length);
		ft_arr_tolower(digits);
		sum = ft_put_hexstr(digits);
		free(digits);
		return (sum);
	}
}
/*
int main()
{
    char *te= NULL;
   printf("\n%d\n",ft_putpointer(te));
    printf("\n%d\n",printf("%p",te));
    return (0);
}
*/