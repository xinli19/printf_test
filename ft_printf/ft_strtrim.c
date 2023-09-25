/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:49:53 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:56:06 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(char *s1, char *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	get_end(char *s1, char *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i <= len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*trimmed;
	int		len;
	int		size;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	len = ft_strlen(s1);
	i = get_start((char *)s1, (char *)set, len);
	j = get_end((char *)s1, (char *)set, len);
	if (i >= j)
		return (ft_strdup(""));
	size = j - i + 1;
	trimmed = (char *) malloc(size);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, &s1[i], size);
	return (trimmed);
}
/*
#include <stdio.h>
int	main()
{
	char *s1 = "\t   \n\n\n  \n\n\t    Ges e d!\t\t\t\n  \t\t\t\t  ";

	printf("%s",ft_strtrim(s1,"\t \n"));
}
*/
