#include <stdio.h>
#include  <limits.h>
#include <unistd.h>
#include "libft.h"

static void	ft_unsigned_to_char(long num)
{
	char	digits[11];
    int     i;

    if (num == 0)
        write (1, "0", 1);
	i = 0;
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
	}
}
void ft_put_unsigned(long n)
{
    if (n > 4294967295)
        write(1, "0", 1);
    if (n < 0)
        write(1, "4294967295", 10);
    else
        ft_unsigned_to_char(n);
}
/*
int main()
{
    ft_put_unsigned(UINT_MAX);
    printf("\n%u", UINT_MAX);
}
*/