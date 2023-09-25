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

static void	ft_put_hexstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] == 48)
		{
			write(1, &s[i], 1);
			write(1,"x", 1);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
}
static void	ft_arr_tolower(char *digits)
{
	while(*digits)
	{
		if (*digits <= 90 && *digits >= 65)
			*digits += 32;
		else
		digits++;
	}
}
void	ft_putpointer(unsigned long num)
{
	int		length;
	char	*digits;

	length = find_length(num);
	digits = (char *)malloc(length + 1);
	if (digits == NULL)
		return ;
	set_hex_arr(digits, num, length);
	ft_arr_tolower(digits);
	ft_put_hexstr(digits);
	//return (digits);
}
/*
int main()
{
    char test[] = "hello";
    ft_putpointer((unsigned long)test);
    printf("\n%p",test);
    return (0);
}*/