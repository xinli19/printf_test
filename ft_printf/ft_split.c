/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:27:55 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 20:28:36 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_outer(char *s, char c)
{
	int	count;
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

static void	*free_stuff(char **s, int index)
{
	int	i;

	i = index;
	while (i >= 0)
		free(s[i--]);
	free(s);
	return (NULL);
}

static char	*set_arr(char *s, int start, int end)
{
	int		i;
	char	*arr;
	int		size;

	i = 0;
	size = end - start + 1;
	arr = (char *)malloc(size * sizeof(char));
	if (!arr)
		return (NULL);
	while (start < end)
		arr[i++] = s[start++];
	arr[i] = '\0';
	return (arr);
}

static char	**split_arr(char const *s, char c, char **array)
{
	size_t	i;
	size_t	j;
	int		ind;

	i = 0;
	j = 0;
	ind = -1;
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] != c && ind < 0)
			ind = i;
		else if ((s[i] == c || i == ft_strlen((char *)s)) && ind >= 0)
		{
			array[j++] = set_arr((char *)s, ind, i);
			if (!array[j - 1])
				return (free_stuff(array, j - 1));
			ind = -1;
		}
		i++;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = malloc((count_outer((char *)s, c) + 1) * sizeof(char *));
	if (array == NULL || !s)
	{
		free(array);
		return (NULL);
	}
	return (split_arr(s, c, array));
}
