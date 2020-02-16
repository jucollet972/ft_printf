/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:05:10 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/16 23:11:10 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_defined_format_char(char c)
{
	return (c == '.' || (c >= '1' && c <= '9') || c == 'l' || c == 'h' ||
			c == '-' || c == '+' || c == ' ' || c == '0' || c == '#');
}

int			ft_isnt_format(char c)
{
	return (c != '%' && c != 'c' && c != 's' && c != 'p' && c != 'd' &&
			c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'X');
}

static void	ft_get_format_flags_plus(char **str, int *flags)
{
	if (*flags & SPACE)
		*flags ^= SPACE;
	*flags |= MORE;
	(*str)++;
}

void		ft_get_format_flags(char **str, int *flags)
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
		ft_get_format_flags_plus(str, flags);
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

int			ft_get_format_width(char **str)
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
