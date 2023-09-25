/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:20:08 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:21:11 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	h = (char *)big;
	n = (char *)little;
	i = 0;
	j = 0;
	if (!n[j])
		return (h);
	while (h[i + j] && n[j] && (i + j) < len)
	{
		if (h[i + j] == n[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	if (n[j] == '\0')
		return (&h[i]);
	else
		return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int 	main(void)
{ 
	printf("%s",ft_strnstr("lorem ipsum dolor sit amet","dolor",15));

const char *big = "Hello, World! This is a test.";
    const char *little = "World";

    // Test 1: Find "World" in "Hello, World!" up to 20 characters
    char *result1 = ft_strnstr(big, little, 20);
    //char *result2 = strnstr(big, little, 20);
    printf("Custom ft_strnstr result: %s\n", result1 ? result1 : "Not found");
    //printf("Original strnstr result: %s\n", result2 ? result2 : "Not found");

    // Test 2: Find "test" in "This is a test." up to 15 characters
    little = "test";
    result1 = ft_strnstr(big, little, 15);
    //result2 = strnstr(big, little, 15);
    printf("Custom ft_strnstr result: %s\n", result1 ? result1 : "Not found");
    //printf("Original strnstr result: %s\n", result2 ? result2 : "Not found");
/test 3: Try to find "test" in "This is a test." up to 5 characters (not found)
    result1 = ft_strnstr(big, little, 5);
    //result2 = strnstr(big, little, 5);
    printf("Custom ft_strnstr result: %s\n", result1 ? result1 : "Not found");
    //printf("Original strnstr result: %s\n", result2 ? result2 : "Not found");

}
*/
