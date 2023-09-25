/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:30:25 by xili              #+#    #+#             */
/*   Updated: 2023/09/20 12:18:17 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTBPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stddef.h>

int	ft_print_char(int c);
int	ft_print_hex(unsigned int	num, char flag);
int	ft_print_int(int n);
int	ft_print_pointer(void *p);
int	ft_print_str(char *s);
int ft_print_unsigned(unsigned int n);
int ft_printf(char *s, ...);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
#endif
