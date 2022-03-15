#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
# include <stdio.h>/* test */
#define BUFFER 32

enum
{
	DIRECTION,
	BLANK,
	SING,
	ZERO,
	CONTENT,
	CONTENTLEN,
	ORDERLEN,
	BLOCKLEN,
	B_FMT,
};

enum
{
	DEFAULT_none,
	SPASE_spase,
	PLUS_plus,
	_minus,
	ZEROX_0x,
	_0X,
};

enum
{
	DEFAULT_right,
	ZERO_right,
	_left,
};

enum
{
	Enone,
	Ec,
	Es,
	Ep,
	Ed,
	Ei,
	Eu,
	Ex,
	EX,
	Eper,
};

enum
{
	FMTSTR,
	CONTENTSTR,
	B_STR,
};

typedef struct s_block
{
	int		direct;
	size_t	spase;
	char	sing[3];
	size_t	zero;
	char	*nums;
	size_t	numl;
	char	type;
	char	*fmts;
	size_t	fmtl;
	size_t	odrl;
	char	buf[BUFFER];
}	t_block;

int		ft_printf(const char	*fmt, ...);
int		block(const char	*s, const char	*e, va_list	ap);
int		mkblc(const char	*blc, char	*s_blc[], size_t	*f_blc, va_list	ap);
void	adjust(char	*s_blc[], size_t	*f_blc);
int		each_len(const char	*block, size_t	*f_blc);
void	itosx(char	*str, unsigned long int	n);
void	itosu(char	*str, unsigned int	n);
void	itosd(char	*str, int	n, size_t	*f_blc);
int		output(char	*s_blc[], size_t	*f_blc);
int		set_sing(const char	*block, size_t	*f_blc);
int		set_len(const char	*block, size_t	*f_blc);
int		set_esc(char	c, size_t	s, size_t	d, size_t	*f_blc);
void	strupper(char	*s);
#endif
