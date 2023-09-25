/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:14:45 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:16:17 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	chr;
	char	*ptr;

	i = 0;
	str = (char *)s;
	chr = (char) c;
	ptr = NULL;
	while (str[i])
	{
		if (str[i] == chr)
		{
			ptr = &str[i];
			i++;
		}
		else
			i++;
	}
	if (str[i] == '\0' && chr == '\0')
		return (&str[i]);
	else
		return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	char a[6] = "";
	int	b = 100;
//	printf("%s\n",strrchr(a,b));
	printf("%s",ft_strrchr(a,0));
	return (0);
}
*/
