/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:17:13 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 12:17:21 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = (void *)malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	while (i < (size * nmemb))
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}
/*
//malloc is not initialized but calloc is set the memory to zero
If nmemb or size is 0, then calloc() returns either NULL,
 or a unique pointer value that can later be successfully passed to free().
#include <string.h>
#include <stdio.h>
int	main(void)
{

	char	*str_calloc = NULL;
	int		length = 0;
	int	bug = 0;
	int	j = 0;
	{
		.wq
length = strlen(test1[i]) + 1;
		str_calloc = (char*)ft_calloc(length, sizeof(*str_calloc));
		for (j = 0; j < length; j++)
		{
			if (str_calloc[j++])
			{
				bug = 1;
				break ;
			}
		}
		if (bug == 1)
			printf("!!bug appears:%s,%d,%d\n",test1[i],j,length);
		else
			printf("test %d: all good :)\n",i);
		free(str_calloc);
		str_calloc = NULL;
	}
	printf("\n");


//	printf("%s",(char *)ft_calloc(2,3));
}*/
