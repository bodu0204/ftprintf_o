/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:43:12 by daisukeyama       #+#    #+#             */
/*   Updated: 2022/03/17 00:22:27 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int				ft_big10to16(unsigned int n);

int				ft_small10to16(unsigned int n);

char			*ft_u_itoa(unsigned int n);

int				ft_print_ptr(unsigned long long ptr);

size_t			ft_print_else(const char str, va_list *ap);

int				ft_printf(const char *fmt, ...);

int				ft_countlength(long n);

int				ft_printpercent(void);

int				ft_printnbr(int n);

void			ft_putstr(char *str);

int				ft_printstr(char *str);

int				ft_printchar(int c);

ssize_t			ft_printu(unsigned int n);

#endif