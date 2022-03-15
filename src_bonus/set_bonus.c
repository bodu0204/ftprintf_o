#include "ft_printf_bonus.h"
void	read_sing(const char	*block, size_t	*f_blc, size_t	*i);

int	set_sing(const char	*block, size_t	*f_blc)
{
	size_t	i[5];

	ft_bzero(i, sizeof(i));
	read_sing(block, f_blc, i);
	if (i[0] * i[1])
	{/* test */
	/* test */printf("YES-set-%d\n",__LINE__);
	///* test */printf("\n");
	///* test */for (size_t ii = 0; ii < B_FMT; ii++)
	///* test */{
	///* test */	printf("f_blc[%zu] = %zu, ", ii, f_blc[ii]);
	///* test */}
	return (1);
	}/* test */
	if (i[2] * i[3] || i[3] * i[4] || i[4] * i[2])
	{/* test */
	/* test */printf("YES-set-%d\n",__LINE__);
	///* test */printf("\n");
	///* test */for (size_t ii = 0; ii < B_FMT; ii++)
	///* test */{
	///* test */	printf("f_blc[%zu] = %zu, ", ii, f_blc[ii]);
	///* test */}
	return (1);
	}/* test */
		/* test */write(1,"yes\n", 5);
	if (i[0])
		f_blc[DIRECTION] = _left;
	else if (i[1])
		f_blc[DIRECTION] = ZERO_right;
	else
		f_blc[DIRECTION] = DEFAULT_right;
	if (i[2])
		f_blc[SING] = ZEROX_0x;
	else if (i[3])
		f_blc[SING] = PLUS_plus;
	else if (i[4])
		f_blc[SING] = SPASE_spase;
	else
		f_blc[SING] = DEFAULT_none;
	return (0);
}

int	set_len(const char	*block, size_t	*f_blc)
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

int	set_esc(char	c, size_t	s, size_t	d, size_t	*f_blc)
{
	if (c == 'c' && s == DEFAULT_none && d != ZERO_right)
		f_blc[CONTENT] = Ec;
	else if (c == 's' && s == DEFAULT_none && d != ZERO_right)
		f_blc[CONTENT] = Es;
	else if (c == 'p' && s == DEFAULT_none)
		f_blc[CONTENT] = Ep;
	else if (c == 'd' && s != ZEROX_0x)
		f_blc[CONTENT] = Ed;
	else if (c == 'i' && s != ZEROX_0x)
		f_blc[CONTENT] = Ei;
	else if (c == 'u' && s == DEFAULT_none)
		f_blc[CONTENT] = Eu;
	else if (c == 'x' && (s == DEFAULT_none || s == ZEROX_0x))
		f_blc[CONTENT] = Ex;
	else if (c == 'X' && (s == DEFAULT_none || s == ZEROX_0x))
		f_blc[CONTENT] = EX;
	else if (c == '%')
		f_blc[CONTENT] = Eper;
	else
		return (1);
	f_blc[ORDERLEN]++;
	return (0);
}

void	read_sing(const char	*block, size_t	*f_blc, size_t	*i)
{
	while (1)
	{
		if (block[f_blc[ORDERLEN]] == '-')
			i[0]++;
		else if (block[f_blc[ORDERLEN]] == '0')
			i[1]++;
		else if (block[f_blc[ORDERLEN]] == '#')
			i[2]++;
		else if (block[f_blc[ORDERLEN]] == '+')
			i[3]++;
		else if (block[f_blc[ORDERLEN]] == ' ')
			i[4]++;
		else
			break ;
		f_blc[ORDERLEN]++;
	}
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
