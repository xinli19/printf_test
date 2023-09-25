/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:34:04 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:49:40 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;	
	char	*s;

	i = 0;
	j = 0;
	k = 0;
	s = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (s == NULL)
		return (NULL);
	if (!s2[j])
	{
		while (s1[i])
			s[k++] = s1[i++];
	}
	while (s2[j])
	{
		while (s1[i])
			s[k++] = s1[i++];
		s[k++] = s2[j++];
	}
	s[k] = '\0';
	return (s);
}
/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	printf("%s",ft_strjoin((char *)av[1],(char *)av[2]));
	return (0);
}
*/
