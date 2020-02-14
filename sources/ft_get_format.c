#include "ft_printf.h"

int			ft_get_format_precision(char **str)
{
	int precision;

	precision = 0;
	if (**str == '.')
	{
		(*str)++;
		if (*(*str) && *(*str) >= '0' && *(*str) <= '9')
		{
			precision = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
			return (precision);
		}
		else
			return (0);
	}
	return (-1);
}

static void	ft_get_format_size_h(char **str, int *size)
{
	*size = *size | H;
	*str += 1;
}

int			ft_get_format_size(char **str)
{
	int size;

	size = 0;
	if (**str == 'h' && *(*str + 1) == 'h')
	{
		size = size | HH;
		(*str) += 2;
	}
	else if (**str == 'h')
		ft_get_format_size_h(str, &size);
	else if (**str == 'l' && *(*str + 1) == 'l')
	{
		size = size | LL;
		(*str) += 2;
	}
	else if (**str == 'l')
	{
		size = size | L;
		(*str) += 1;
	}
	else
		return (0);
	return (size);
}

int			ft_get_format_type(char **str)
{
	int type;

	type = 0;
	(**str == '%') ? type = type | PERCENT : 0;
	(**str == 'c') ? type = type | CHAR : 0;
	(**str == 's') ? type = type | STRING : 0;
	(**str == 'p') ? type = type | POINTER : 0;
	(**str == 'd' || **str == 'i') ? type = type | INTEGER : 0;
	(**str == 'o') ? type = type | OCTAL : 0;
	(**str == 'u') ? type = type | UINT : 0;
	(**str == 'x') ? type = type | UNHEXA : 0;
	(**str == 'X') ? type = type | UNHEXAUP : 0;
	(*str)++;
	return (type);
}
