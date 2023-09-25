/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:11:23 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:12:00 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;

	i = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen((char *)src));
	d_len = ft_strlen((char *)dst);
	while (src[i] != '\0' && (size - 1 > d_len))
	{
		dst[d_len] = src[i];
		i++;
		d_len++;
	}
	dst[d_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
/*	
int	ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char dest[30] = "rrrrrr";	
	printf("my:%zu\n",ft_strlcat(dest,"lorem ipsum dolor sit amet", 7));
	printf("original%zu",strlcat(dest,"lorem ipsum dolor sit amet", 7));
}
*/
