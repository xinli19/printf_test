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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stddef.h>
# include <stdarg.h>

void	ft_print_arg(va_list args, char c, int *printed_words);
int ft_printf(char *s, ...);
int	ft_print_char(int c);
int	ft_print_hex(unsigned int	num, char flag);
int	ft_print_int(int n);
int	ft_print_pointer(void *p);
int	ft_print_str(char *s);
int ft_print_unsigned(unsigned int n);
int ft_printf(char *s, ...);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
