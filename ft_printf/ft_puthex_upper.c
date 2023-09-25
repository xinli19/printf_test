#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
static int	find_length(long n)
{
	int	i;

	i = 0;
	while (n == 0)
	{
		i = 1;
		return (i);
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	set_hex_arr(char *digits, long num, int length)
{
	long temp;

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

void	ft_put_hexstr(char *s, int is_negative)
{
	int	i;

	i = 0;
    if (is_negative == 1)
        write(1, "-", 1);
    while (s[i] == 48)
        i++;
    while (s[i])
    {
		write(1, &s[i], 1);
		i++;
    }
}

void	ft_puthex_upper(unsigned  num)
{
	int		length;
	char	*digits;
    int     is_negative;

    is_negative = 0;
    if (num == 0)
    {
        write(1, "0", 1);
        return;
    }
    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }
    length = find_length(num);
    digits = (char *)malloc(length + 1);
    if (digits == NULL)
		return ;
	set_hex_arr(digits, num, length);
	ft_put_hexstr(digits, is_negative);
}
/*#include <limits.h>
int main(void)
{
    ft_puthex_upper(INT_MAX);
    printf("\n%X", INT_MAX);
    return (0);
}*/