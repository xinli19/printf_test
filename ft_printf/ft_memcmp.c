/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:19:21 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:19:47 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*str1;
	unsigned const char	*str2;

	i = 0;
	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	if ((!str1 && !str2) || n == 0)
		return (0);
	if (!str1 || !str2)
		return ((int)(str1[i] - str2[i]));
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		else
			i++;
	}
	return (0);
}
/*
int	main(void)
{
	char a[5] = "abszf";
	char b[5] = "abdcf";
	char c[0];
	printf("%d\n",memcmp(a,c,2));
	printf("%d\n",ft_memcmp(a,c,2));
	printf("%d\n",memcmp(a,c,2));


	printf("%d\n",ft_memcmp(a,b,2));
	printf("%d\n", memcmp(a,b,2));
	return (0);
}
*/
