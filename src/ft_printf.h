#ifndef FT_PRINTF_H
#define FT_PRINTF_H
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

enum
{
	DEFAULT_right,
	ZERO_right,
	_left,
};

enum
{
	Ec,
	Es,
	Ep,
	Ed,
	Ei,
	Eu,
	Ex,
	EX,
	Eper,
	Enone,
};

enum
{
	FMTSTR,
	CONTENTSTR,
	B_STR,
};

#define BUFFER 32
#endif
