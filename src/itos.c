#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

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

void	itosx(char	*str, unsigned long int	n)
{
	char				*num;
	unsigned long int	nn;
	int					i;

	if (n == 0)
	{
		*str = '0';
		return ;
	}
	num = "0123456789abcdef";
	nn = 1;
	while (n / nn > 16)
		nn *= 16;
	while (nn > 0)
	{
		i = n / nn;
		*str = *(num + i);
		str++;
		n -= i * nn;
		nn /= 16;
	}
	return ;
}

void	itosu(char	*str, unsigned int	n)
{
	char			*num;
	unsigned int	nn;
	int				i;

	if (n == 0)
	{
		*str = '0';
		return ;
	}
	num = "0123456789";
	nn = 1;
	while (n / nn > 10)
		nn *= 10;
	while (nn > 0)
	{
		i = n / nn;
		*str = *(num + i);
		str++;
		n -= i * nn;
		nn /= 10;
	}
	return ;
}

void	itosd(char	*str, int	n, size_t	*f_blc)
{
	int	nn;

	if (n == 0)
	{
		*str = '0';
		return ;
	}
	if (n < 0)
		f_blc[SING] = _minus;
	else
		n *= -1;
	nn = 1;
	while (n / nn < -10)
		nn *= 10;
	while (nn > 0)
	{
		*str = '0' - (n / nn);
		n += (*str - '0') * nn;
		str++;
		nn /= 10;
	}
	return ;
}
