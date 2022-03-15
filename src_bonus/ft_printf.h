#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# define STMSIZE 1024
# define BUFFER 32
# define FLUSH 1024
# define CLEAN 1025
enum
{
	Eerror,
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

typedef struct s_num
{
	size_t	f_spase;
	char	sing[3];
	size_t	zero;
	char	mum[BUFFER];
	size_t	b_spase;
	int		type;
}	t_mum;
int		my_putchar(int	c);
size_t	my_putchars(int	c, size_t	i);
size_t	my_putstr(const char	*str, size_t	i);

#endif
