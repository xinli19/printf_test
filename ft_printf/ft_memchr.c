/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:18:24 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 11:19:00 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*str;
	unsigned char		c_char;

	if (n == 0)
		return (NULL);
	i = 0;
	str = (unsigned const char *)s;
	c_char = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c_char)
			return ((void *)&str[i]);
		else
			i++;
	}
	return (NULL);
}
/*
//eThe  memchr() function scans the initial n bytes of the memory 
 to by s for the first instance of c.  
//Both c and the bytes of the memory area pointed to
//by s are interpreted as unsigned char.
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char arr[] = "hello world";
	char data[0];
	char *result = (char *)ft_memchr(data,'p',sizeof(data));
	printf("%s\n",(char *)ft_memchr(data,'p',sizeof(data)));
	printf("%s\n",result);
}
*/
