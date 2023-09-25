/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:07:33 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:11:07 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)src);
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest1[10];
    char dest2[10];
    const char *source = "Hello, World!";
    size_t size1, size2;

    // Test 1: Normal case
    size1 = strlcpy(dest1, source, sizeof(dest1));
    size2 = ft_strlcpy(dest2, source, sizeof(dest2));
    printf("Original strlcpy: Copied %zu characters: %s\n", size1, dest1);
    printf("Custom ft_strlcpy: Copied %zu characters: %s\n", size2, dest2);
    
    // Test 2: Destination size is 0
    size1 = strlcpy(dest1, source, 0);
    size2 = ft_strlcpy(dest2, source, 0);
    printf("Original strlcpy: Copied %zu characters: %s\n", size1, dest1);
    printf("Custom ft_strlcpy: Copied %zu characters: %s\n", size2, dest2);
    
    return 0;    
}
*/
