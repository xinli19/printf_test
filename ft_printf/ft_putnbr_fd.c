/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:09:23 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 12:09:35 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	int_to_char(long num, char *digits, int negative, int fd)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		digits[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	if (negative == -1)
		write (fd, "-", 1);
	i = i - 1;
	while (i >= 0)
	{
		write(fd, &digits[i], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digits[13];
	long	num;
	int		negative;

	num = n;
	negative = 1;
	if (num < 0)
	{
		num = -num;
		negative = -1;
	}
	if (num == 0)
		write (fd, "0", 1);
	int_to_char(num, digits, negative, fd);
}
/*
#include <limits.h>
int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1);
	return (0);
}
*/
