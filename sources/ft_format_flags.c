#include "ft_printf.h"

int		ft_isnt_flags(char c)
{
	return (c != '%' && c != 'c' && c != 's' && c != 'p' && c != 'd'
			&& c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'X'
			&& c != '.' && !(c >= '1' && c <= '9')
			&& c != '*' && c != 'l' && c != 'h');
}

int		ft_isnt_format(char c)
{
	return (c != '%' && c != 'c' && c != 's' && c != 'p' && c != 'd' &&
			c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'X');
}

void	ft_get_format_flags(char **str, int *flags)
{
	if (**str == '0')
	{
		*flags |= ZERO;
		(*str)++;
	}
	else if (**str == ' ')
	{
		*flags |= SPACE;
		(*str)++;
	}
	else if (**str == '+')
	{
		if (*flags & SPACE)
			*flags ^= SPACE;
		*flags |= MORE;
		(*str)++;
	}
	else if (**str == '-')
	{
		*flags |= LESS;
		(*str)++;
	}
	else if (**str == '#')
	{
		*flags |= HASH;
		(*str)++;
	}
}

int		ft_get_format_width(char **str)
{
	int width;

	width = 0;
	if (**str <= '9' && **str >= '0')
	{
		width = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
		return (width);
	}
	return (0);
}
