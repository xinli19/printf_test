/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:21:23 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 12:06:13 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip(char *s, long *i, int *is_negative)
{
	while (s[*i] == '\t' || s[*i] == '\n' || s[*i] == '\v' || s[*i] == '\f'
		|| s[*i] == '\r' || s[*i] == ' ' )
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			*is_negative = 1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	long	i;
	long	result;
	int		is_negative;
	char	*s;

	result = 0;
	is_negative = 0;
	i = 0;
	s = (char *)nptr;
	skip(s, &i, &is_negative);
	while (s[i] >= '0' && s[i] <= '9')
		result = result * 10 + (s[i++] - '0');
	if (result == 0)
		return (0);
	if (is_negative == 1)
		return (-result);
	else
		return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// - num
	printf("the original atoi:%d\n",ft_atoi("\t\n\r\v\f     469 \n"));
	printf("my atoi:%d\n",ft_atoi("-1"));
	printf("the original atoi:%d\n",atoi("--"));
        printf("my atoi:%d\n",ft_atoi("--"));
 	printf("the original atoi:%d\n",atoi(""));
        printf("my atoi:%d\n",ft_atoi(""));
  	printf("the original atoi:%d\n",atoi("1a"));
        printf("my atoi:%d\n",ft_atoi("1a"));
	printf("the original atoi:%d\n",atoi("aa1"));
        printf("my atoi:%d\n",ft_atoi("aa1"));
  	printf("the original atoi:%d\n",atoi("  -2147483648"));
        printf("my atoi:%d\n",ft_atoi("  -2147483648"));
 	printf("the original atoi:%d\n",atoi("  2147483647"));
        printf("my atoi:%d\n",ft_atoi("  2147483647"));
 	printf("the original atoi:%d\n",atoi("     "));
        printf("my atoi:%d\n",ft_atoi("    "));
	printf("%d\n",ft_atoi("0  95"));
}
*/
