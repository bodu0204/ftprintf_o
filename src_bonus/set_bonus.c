#include "ft_printf_bonus.h"
void	read_sing(t_block	*b, int	*i);

int	set_sing(t_block	*b)
{
	int	i[5];

	ft_bzero(i, sizeof(i));
	read_sing(b, i);
	if (i[0] * i[1])
		return (1);
	if (i[2] * i[3] || i[3] * i[4] || i[4] * i[2])
		return (1);
	if (i[0])
		b->direct = _left;
	else if (i[1])
		b->direct = ZERO_right;
	else
		b->direct = DEFAULT_right;
	if (i[2])
		ft_strlcpy(b->sing, "0x", 3);
	else if (i[3])
		ft_strlcpy(b->sing, "+", 3);
	else if (i[4])
		ft_strlcpy(b->sing, " ", 3);
	else
		t_bzero(b->sing, 3);
	return (0);
}

int	set_len(t_block	*b)
{
	size_t	i;

	f_blc[BLANK] = ft_atoi(block + f_blc[ORDERLEN]);
	while (ft_isdigit(block[f_blc[ORDERLEN]]))
		f_blc[ORDERLEN]++;
	if (block[f_blc[ORDERLEN]] == '.')
		f_blc[ORDERLEN]++;
	i = f_blc[ORDERLEN];
	f_blc[ZERO] = ft_atoi(block + f_blc[ORDERLEN]);
	while (ft_isdigit(block[f_blc[ORDERLEN]]))
		f_blc[ORDERLEN]++;
	if (i != f_blc[ORDERLEN] && block[f_blc[ORDERLEN]] == 'c')
		return (1);
	if (block[f_blc[ORDERLEN]] != 's' || block[f_blc[ORDERLEN]] != '%')
	{
		if (f_blc[BLANK] < f_blc[ZERO])
			f_blc[BLANK] = 0;
		else
			f_blc[BLANK] -= f_blc[ZERO];
	}
	else
		f_blc[ZERO] = 0;
	return (0);
}

int	set_esc(t_block	*b)
{
	b->type = *(b->fmts);
	if ((b->type == 'c' && !*(b->sing) && b->direct != ZERO_right) \
	|| (b->type == 's' && !*(b->sing) && b->direct != ZERO_right) \
	|| (b->type == 'p' && !*(b->sing)) \
	|| (b->type == 'd' && ft_strncmp("0x", b->sing ,3)) \
	|| (b->type == 'i' && ft_strncmp("0x", b->sing ,3)) \
	|| (b->type == 'u' && !*(b->sing)) \
	|| (b->type == 'x' && (!*(b->sing) || !ft_strncmp("0x", b->sing ,3))) \
	|| (b->type == 'X' && (!*(b->sing) || !ft_strncmp("0x", b->sing ,3))) \
	|| (b->type == '%'))
		b->fmts++;
	else
		return (1);
	return (0);
}

void	read_sing(t_block	*b, int	*i)
{
	while (1)
	{
		if (*(b->fmts) == '-')
			i[0] = 1;
		else if (*(b->fmts) == '0')
			i[1] = 1;
		else if (*(b->fmts) == '#')
			i[2] = 1;
		else if (*(b->fmts) == '+')
			i[3] = 1;
		else if (*(b->fmts) == ' ')
			i[4] = 1;
		else
			break ;
		b->fmts++;
	}
	return ;
}

void	strupper(char	*s)
{
	while(*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
	return ;
}
