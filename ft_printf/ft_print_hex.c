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

static void	set_hex_arr(char *digits, long num, int length,char flag)
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
	if (flag == 'x')
	{
		while(*digits)
		{
			if (*digits <= 90 && *digits >= 65)
				*digits += 32;
			else
				digits++;
		}
	}
}

static int	ft_put_hexstr(char *s)
{
	int	i;
	int sum;

	i = 0;
	sum = 0;
	while (s[i] == 48)
		i++;
    while (s[i])
    {
		write(1, &s[i], 1);
		i++;
		sum++;
	}
	return (sum);
}

int	ft_print_hex(unsigned int	num, char flag)
{
	int		length;
	char	*digits;
	int 	sum;

	if (num == 0)
	{
        write(1, "0", 1);
        return (1);
    }
    length = find_length(num);
    digits = (char *)malloc(length + 1);
    if (digits == NULL)
		return (0);
	set_hex_arr(digits, num, length, flag);
	sum = ft_put_hexstr(digits);
	return (sum);
}
/*

#include <limits.h>
int main(void)
{
    ft_print_hex(INT_MAX, 'x');
    printf("\n%x", INT_MAX);
    return (0);
}
*/