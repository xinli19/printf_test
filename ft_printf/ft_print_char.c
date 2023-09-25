/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:08:03 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 12:08:20 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	char	ch;

	if (c >= 32 && c <= 127)
	{
		ch = (char)c;
		write(1, &ch, 1);
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
	int a = 2;
	int b = 30;
	int c = 0;
	c = printf("%c", b);
	//ft_printchar(b, &a);
	printf("%d", c);
}
*/