#include <stdio.h>
#include  <limits.h>
#include <unistd.h>
#include "ft_printf.h"


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

int ft_put_unsigned(unsigned int n)
{
    int sum;

    sum = 0;
    if (n > 4294967295 || n == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    if (n < 0)
    {
        write(1, "4294967295", 10);
        return (10);
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
