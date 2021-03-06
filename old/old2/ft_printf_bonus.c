#include "ft_printf_bonus.h"

int	ft_printf(const char	*fmt, ...)
{
	va_list	ap;
	int		i;

	if (!fmt)
		return (-1);
	if (!*fmt)
		return (0);
	va_start(ap, fmt);
	i = block(fmt, fmt + ft_strlen(fmt) - 1, ap);
	va_end(ap);
	return (i);
}

int	block(const char	*s, const char	*e, va_list	ap)
{
	size_t	f_blc[B_FMT];
	char	*s_blc[B_STR];
	char	con[BUFFER];
	int		putlen;
	int		i;

	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	ft_bzero(f_blc, sizeof(f_blc));
	putlen = 0;
	ft_bzero(con, sizeof(con));
	s_blc[CONTENTSTR] = con;
	while (e > s && *e != '%')
	{
		e--;
		f_blc[BLOCKLEN]++;
	}
	f_blc[BLOCKLEN]++;
	if (mkblc(e, s_blc, f_blc, ap))
	{/* test */
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	///* test */printf("\n");
	///* test */for (size_t ii = 0; ii < B_FMT; ii++)
	///* test */{
	///* test */	printf("f_blc[%zu] = %zu, ", ii, f_blc[ii]);
	///* test */}
	return (-1);
	}/* test */
	if (e > s)
		putlen = block(s, e - 1, ap);
	if (putlen == -1)
		return (-1);
	///* test */printf("\n");
	///* test */for (size_t ii = 0; ii < B_FMT; ii++)
	///* test */{
	///* test */	printf("f_blc[%zu] = %zu, ", ii, f_blc[ii]);
	///* test */}
	i = output(s_blc, f_blc);
	if (i == -1)
		return (-1);
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	return (putlen + i);
}

int	mkblc(const char	*blc, char	*s_blc[], size_t	*f_blc, va_list	ap)
{
	if (each_len(blc, f_blc))
	{/* test */
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	///* test */printf("\n");
	///* test */for (size_t ii = 0; ii < B_FMT; ii++)
	///* test */{
	///* test */	printf("f_blc[%zu] = %zu, ", ii, f_blc[ii]);
	///* test */}
	return (1);
	}/* test */
	s_blc[FMTSTR] = (char *)blc + f_blc[ORDERLEN];
	if (f_blc[CONTENT] == Ec)
		s_blc[CONTENTSTR][0] = va_arg(ap, int);
	else if (f_blc[CONTENT] == Es)
		s_blc[CONTENTSTR] = va_arg(ap, char *);
	else if (f_blc[CONTENT] == Ep)
		itosx(s_blc[CONTENTSTR], (unsigned long int)va_arg(ap, void *));
	else if (f_blc[CONTENT] == Ex || f_blc[CONTENT] == EX)
		itosx(s_blc[CONTENTSTR], va_arg(ap, unsigned int));
	else if (f_blc[CONTENT] == Ed || f_blc[CONTENT] == Ei)
		itosd(s_blc[CONTENTSTR], va_arg(ap, int), f_blc);
	else if (f_blc[CONTENT] == Eu)
		itosu(s_blc[CONTENTSTR], va_arg(ap, unsigned int));
	else if (f_blc[CONTENT] == Eper)
		s_blc[CONTENTSTR][0] = '%';
	adjust(s_blc, f_blc);
	if (f_blc[DIRECTION] == ZERO_right)
	{
		f_blc[ZERO] += f_blc[BLANK];
		f_blc[BLANK] = 0;
	}
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	return (0);
}

void	adjust(char	*s_blc[], size_t	*f_blc)
{
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	f_blc[CONTENTLEN] = ft_strlen(s_blc[CONTENTSTR]);
	if (f_blc[ZERO] < f_blc[CONTENTLEN])
	{
		if (f_blc[BLANK] + f_blc[ZERO] < f_blc[CONTENTLEN])
			f_blc[BLANK] = 0;
		else
			f_blc[BLANK] -= f_blc[CONTENTLEN] - f_blc[ZERO];
		f_blc[ZERO] = 0;
	}
	else
		f_blc[ZERO] -= f_blc[CONTENTLEN];
	if (f_blc[CONTENT] == Ep)
		f_blc[SING] = ZEROX_0x;
	if (f_blc[CONTENT] == EX)
		strupper(s_blc[CONTENTSTR]);
	if (f_blc[CONTENT] == EX && f_blc[SING] == ZEROX_0x)
		f_blc[SING] = _0X;
	if (f_blc[CONTENT] == Ex && !ft_memcmp(s_blc[CONTENTSTR], "0", 2))
		f_blc[SING] = DEFAULT_none;
	if (f_blc[CONTENT] == EX && !ft_memcmp(s_blc[CONTENTSTR], "0", 2))
		f_blc[SING] = DEFAULT_none;
	if (f_blc[CONTENT] == Eper)
		f_blc[SING] = DEFAULT_none;
	return ;
}

int	each_len(const char	*block, size_t	*f_blc)
{
	if (*block != '%')
		return (0);
	f_blc[ORDERLEN]++;
	if (set_sing(block, f_blc))
	{/* test */
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	///* test */printf("\n");
	///* test */for (size_t ii = 0; ii < B_FMT; ii++)
	///* test */{
	///* test */	printf("f_blc[%zu] = %zu, ", ii, f_blc[ii]);
	///* test */}
	return (1);
	}/* test */
	if (set_len(block, f_blc))
	{/* test */
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	///* test */printf("\n");
	///* test */for (size_t ii = 0; ii < B_FMT; ii++)
	///* test */{
	///* test */	printf("f_blc[%zu] = %zu, ", ii, f_blc[ii]);
	///* test */}
	return (1);
	}/* test */
	if (set_esc(block[f_blc[ORDERLEN]], f_blc[SING], f_blc[DIRECTION], f_blc))
	{/* test */
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	///* test */printf("\n");
	///* test */for (size_t ii = 0; ii < B_FMT; ii++)
	///* test */{
	///* test */	printf("f_blc[%zu] = %zu, ", ii, f_blc[ii]);
	///* test */}
	return (1);
	}/* test */
	/* test */printf("YES-%d\n",__LINE__); fflush(stdin);
	return (0);
}
