#include "ft_printf_bonus.h"
int	output_1(char	*s_blc[], size_t	*f_blc);
int	output_2(char	*s_blc[], size_t	*f_blc);
int	output_3(char	*s_blc[], size_t	*f_blc);

int	output(char	*s_blc[], size_t	*f_blc)
{
	int		i;
	int		len;
	char	*s;

	s = "                                ";
	len = 0;
	if (f_blc[DIRECTION] != _left)
	{
		while (f_blc[BLANK] > 0)
		{
			i = write(1, s, f_blc[BLANK]);
			if (i < 0)
				return (-1);
			len += i;
			f_blc[BLANK] -= i;
		}
	}
	i = output_1(s_blc, f_blc);
	if (i < 0)
		return (-1);
	return (i + len);
}

int	output_1(char	*s_blc[], size_t	*f_blc)
{
	int		i;
	int		len;
	char	*s;

	if (f_blc[SING] = DEFAULT_none)
		i = 0;
	else if (f_blc[SING] = SPASE_spase)
		i = write(1, " ", 1);
	else if (f_blc[SING] = PLUS_plus)
		i = write(1, "+", 1);
	else if (f_blc[SING] = _minus)
		i = write(1, "-", 1);
	else if (f_blc[SING] = ZEROX_0x)
		i = write(1, "0x", 2);
	else if (f_blc[SING] = _0X)
		i = write(1, "0X", 2);
	if (i < 0)
		return (-1);
	len = i;
	i = output_2(s_blc, f_blc);
	if (i < 0)
		return (-1);
	return (i + len);
}

int	output_2(char	*s_blc[], size_t	*f_blc)
{
	int		i;
	int		len;
	char	*s;

	s = "00000000000000000000000000000000";
	len = 0;
	while (f_blc[BLANK] > 0)
	{
		i = write(1, s, f_blc[BLANK]);
		if (i < 0)
			return (-1);
		len += i;
		f_blc[BLANK] -= i;
	}
	i = write(1, s_blc[CONTENTSTR], f_blc[CONTENTLEN]);
	if (i < 0)
		return (-1);
	len += i;
	i = output_3(s_blc, f_blc);
	if (i < 0)
		return (-1);
	return (i + len);
}

int	output_3(char	*s_blc[], size_t	*f_blc)
{
	int		i;
	int		len;
	char	*s;

	s = "                                ";
	len = 0;
	if (f_blc[DIRECTION] == _left)
	{
		while (f_blc[BLANK] > 0)
		{
			i = write(1, s, f_blc[BLANK]);
			if (i < 0)
				return (-1);
			len += i;
			f_blc[BLANK] -= i;
		}
	}
	i = write(1, s_blc[FMTSTR], f_blc[BLOCKLEN] - f_blc[ORDERLEN]);
	if (i < 0)
		return (-1);
	return (i + len);
}
