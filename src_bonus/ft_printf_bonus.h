#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "debug.h"/* test */
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
	char	buf[BUFFER];
}	t_block;

#endif
