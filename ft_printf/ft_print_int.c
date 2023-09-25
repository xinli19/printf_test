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

int	ft_print_int(int n)
{
	char	*p;
	int 	sum;
	
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	p = ft_itoa(n);
	sum = ft_print_str(p);
	return (sum);
}
/*
#include <limits.h>
int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1);
	return (0);
}
*/
