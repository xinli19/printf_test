#include <stdio.h>
#include  <limits.h>
#include <unistd.h>
#include "libftprintf.h"

static int	ft_unsigned_to_char(unsigned int num)
{
	char	digits[11];
    int     i;
    int     sum;

    i = 0;
    sum = 0;
    while (num > 0)
    {
		digits[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		write(1, &digits[i], 1);
		i--;
        sum++;
    }
    return (sum);
}

int ft_print_unsigned(unsigned int n)
{
    int sum;

    sum = 0;
    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    else
        sum = ft_unsigned_to_char(n);
    return (sum);
}
/*
int main()
{
    ft_put_unsigned(UINT_MAX);
    printf("\n%u", UINT_MAX);
}
*/
