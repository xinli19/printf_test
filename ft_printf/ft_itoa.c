/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:04:58 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 12:05:31 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	set_arr(char *digits, long num, int negative, int length)
{
	if (negative == -1)
	{
		digits[length + 1] = '\0';
		digits[0] = '-';
		while (length > 0)
		{
			digits[length] = num % 10 + '0';
			num = num / 10;
			length--;
		}
	}
	else
	{
		digits[length] = '\0';
		length = length - 1;
		while (length >= 0)
		{
			digits[length] = num % 10 + '0';
			num = num / 10;
			length--;
		}
	}
}

char	*ft_itoa(int n)
{
	long	num;
	int		negative;
	int		length;
	char	*digits;

	negative = 1;
	num = n;
	if (num < 0)
	{
		num = -num;
		negative = -1;
	}
	length = find_length(num);
	if (negative == 1)
		digits = (char *)malloc(length + 1);
	else
		digits = (char *)malloc(length + 2);
	if (digits == NULL)
		return (NULL);
	set_arr(digits, num, negative, length);
	return (digits);
}
/*
#include <stdio.h>
#include <limits.h>
int	 main(void)
{
	printf("%s",ft_itoa(0));
	return (0);
}
*/
