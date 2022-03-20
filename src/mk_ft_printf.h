/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_ft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:48 by blyu              #+#    #+#             */
/*   Updated: 2022/03/20 17:42:05 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MK_FT_PRINTF_H
# define MK_FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFFER 32

enum
{
	DEFAULT_right,
	ZERO_right,
	_left,
};

enum
{
	DEFAULT_no_dot,
	_yes_dot,
};

typedef struct s_block
{
	int		direct;
	size_t	spase;
	char	sing[3];
	size_t	singl;
	size_t	zero;
	int		dot;
	char	*nums;
	size_t	numl;
	char	type;
	char	*fmts;
	size_t	fmtl;
	char	buf[BUFFER];
}	t_block;

typedef struct s_rtn
{
	size_t	prtl;
	char	*prt;
}	t_rtn;

t_rtn	block(const char	*fmt, size_t	len, va_list	ap);
int		mkblc(t_block	*b, va_list	ap);
int		each_len(t_block	*b);
void	adjust(t_block	*b);
int		set_sing(t_block	*b);
int		set_len(t_block	*b);
int		set_type(t_block	*b);
void	itosx(char	*str, unsigned long int	n);
void	itosu(char	*str, unsigned int	n);
void	itosd(char	*str, int	n, char	*sig);
void	mkput(char	*buf, t_block	*b);
size_t	blclen(t_block	*b);
void	strupper(int	i, ...);
#endif
