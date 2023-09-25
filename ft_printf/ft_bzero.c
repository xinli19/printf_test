/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:58:23 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 10:58:29 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (n--)
		((unsigned char *)s)[i++] = '\0';
}
/*
#include <stdio.h>
#include <strings.h>
#include <limits.h>
//s: pointer pointed to the start of the memory
//n: bytes needed to be erase with '\0' semantisch besser als '0' zu verstehen.

int	main(void)
{
	// n = 0;
	printf("\ttest 1: Leerer Speicherbereich\n");
	char a[0];
	char b[0];
	int	i = 0; 
	ft_bzero(a,1);
	bzero(b,1);
	printf("%s,%s\n",a,b);

	printf("\ttest 2:Löschen von nur einem Byte \n");
	char c[11] = "Helloworld";
	char d[11] = "Helloworld";
	ft_bzero(c,1);
	bzero(d,1);
	for (i =0; i < 11; i++)
	{
		if (c[i] != d[i])
			printf("bug\n");
	}
	printf("%s,%s\n",c,d);


	printf("\ttest 3:Negative Größe\n");
	bzero(c,-1);
	//ft_bzero(d,-1);
	printf("%s,%s\n",c,d);

	return (0);
}
*/
