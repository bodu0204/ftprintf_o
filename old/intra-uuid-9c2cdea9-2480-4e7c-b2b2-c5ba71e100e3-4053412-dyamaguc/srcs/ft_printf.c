/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:02:37 by daisukeyama       #+#    #+#             */
/*   Updated: 2022/03/17 00:37:45 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

ssize_t	ft_printu(unsigned int u)
{
	char	*num;
	int		i;

	i = 0;
	num = ft_u_itoa(u);
	i = ft_printstr(num);
	if (num == NULL)
		return (-1);
	free(num);
	return (i);
}

size_t	ft_print_else(const char str, va_list *ap)
{
	size_t	print_length;

	print_length = 0;
	if (str == 'c')
		print_length += ft_printchar(va_arg(*ap, int));
	else if (str == 's')
		print_length += ft_printstr((char *)va_arg(*ap, char *));
	else if (str == 'p')
		print_length += ft_print_ptr(va_arg(*ap, unsigned long long));
	else if (str == 'd')
		print_length += ft_printnbr(va_arg(*ap, int));
	else if (str == 'i')
		print_length += ft_printnbr(va_arg(*ap, int));
	else if (str == 'u')
		print_length += ft_printu(va_arg(*ap, unsigned int));
	else if (str == 'x')
		print_length += ft_small10to16(va_arg(*ap, unsigned int));
	else if (str == 'X')
		print_length += ft_big10to16(va_arg(*ap, unsigned int));
	else if (str == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			i;
	int			print_length;

	i = 0;
	print_length = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			print_length += ft_print_else(fmt[i + 1], &ap);
			i++;
		}
		else
			print_length += ft_printchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (print_length);
}
