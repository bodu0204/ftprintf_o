#include "mk_ft_printf_bonus.h"
void	adjust1(t_block	*b);

void	adjust(t_block	*b)
{
	if (b->type == 's' && !(b->nums))
	{
		b->nums = b->buf;
		ft_strlcpy(b->nums, "(null)", BUFFER);
	}
	if (b->type == 'p')
		ft_strlcpy(b->sing, "0x", 3);
	if (b->type == 'X')
		strupper(2, b->nums, b->sing);
	if ((b->type == '%') \
	|| ((b->type == 'X' || b->type == 'x' ) && !ft_memcmp(b->nums, "0", 2)))
		ft_bzero(b->sing, 3);
	adjust1(b);
	return ;
}

void	adjust1(t_block	*b)
{
	b->numl = ft_strlen(b->nums);
	if (b->type == 'c')
		b->numl = 1;
	b->singl = ft_strlen(b->sing);
	if (b->zero < b->numl + b->singl)
	{
		if (b->spase + b->zero < b->numl + b->singl)
			b->spase = 0;
		else
			b->spase -= b->numl + b->singl - b->zero;
		b->zero = 0;
	}
	else
		b->zero -= b->numl + b->singl;
	if (b->direct == ZERO_right)
	{
		b->zero += b->spase;
		b->spase = 0;
	}
	return ;
}
