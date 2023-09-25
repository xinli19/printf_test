/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:59:18 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:01:02 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d > s && (s + n) > d)
		return (dest);
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
}
/*
#include <stdio.h>
#include <string.h>

	The  memcpy()  function  copies  n bytes from memory area src to memory
       area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
       memory areas do overlap.

1.check the overlap


int main() {
    char source[] = "Hello, World!";
    char dest1[20];
    char dest2[20];

    // Copy using your ft_memcpy
    ft_memcpy(dest1, source, sizeof(source));

    // Copy using standard memcpy
    memcpy(dest2, source, sizeof(source));

    // Compare the results
    if (strcmp(dest1, dest2) == 0) {
        printf("Both memcpy implementations produced identical results.\n");
    } else {
        printf("memcpy implementations produced different results.\n");
    }
    char buffer[20] = "Hello, World!";
    char buffer1[20] = "Hello, World!";
	// Copy the first 6 characters of the string to a
	// position within the string (overlapping)
    memcpy(buffer + 3, buffer, 6);

    // Print the result
    printf("Result (memcpy): %s\n", buffer);

    // Use your custom ft_memcpy to perform the same operation
    memmove(buffer1 + 3, buffer1, 6);

    // Print the result
    printf("Result (ft_memcpy): %s\n", buffer1);


    return 0;
}
*/
