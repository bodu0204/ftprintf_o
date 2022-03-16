#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#define BUFFER 32

enum
{
	DEFAULT_right,
	ZERO_right,
	_left,
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
	char	buf[BUFFER];
}	t_block;

char*	block(const char	*fmt, size_t	len, va_list	ap);
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
void	strupper(char	*s);
size_t	charset(char	*buf, char	c, size_t	l);
#endif
