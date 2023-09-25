/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:06:44 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:06:51 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if ((unsigned char *)src < (unsigned char *)dest)
	{
		while (n > i)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (n-- > 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char src[] = "lorem ipsum dolor sit amet";
	char	*p;
	p = src + 1;
	printf("%s\n",p);
	
	printf("my function: %s\n",(char *)ft_memmove(src, p, 8));
	printf("original function: %s",(char *)memmove(src, p, 8));
		return (0);
}
*/
