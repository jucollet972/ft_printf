/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:55:42 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/14 18:55:44 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_width_len(t_format *format, char *type_str, char *ref_str)
{
	int len;

	len = ft_strlen(type_str);
	if (len < format->width)
		len = format->width - len;
	else
		len = 0;
	(format->type & CHARNULL) ? len -= 1 : 0;
	((format->flags & MORE && *type_str != '-')
		|| (*type_str != '-' && *ref_str == '-')
		|| (format->flags & SPACE && *ref_str != '-')) ? len -= 1 : 0;
	(*ref_str != '0' && format->flags & HASH
		&& format->type & OCTAL) ? len -= 1 : 0;
	((*ref_str != '0' && format->flags & HASH && (format->type & UNHEXA
		|| format->type & UNHEXAUP)) || format->type & POINTER) ? len -= 2 : 0;
	return (len);
}

char	*ft_zero_width(t_format *format, char *type_str, char *ref_str)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	len = ft_get_width_len(format, type_str, ref_str);
	if (format->flags & LESS && len > 0)
		type_str = ft_get_less_option_str(type_str, format, len);
	else if (len > 0 && (format->flags & ZERO))
	{
		if (format->flags & ZERO && format->precision != 0)
			if (*type_str == '-')
			{
				tmp = type_str;
				type_str = ft_strsub(type_str, 1, ft_strlen(type_str + 1));
				ft_strdel(&tmp);
			}
		type_str = ft_cat_at_start(type_str, len, '0');
	}
	return (type_str);
}

char	*ft_space_width(char *type_str, t_format *format)
{
	int len;

	len = 0;
	if ((len = format->width - ft_strlen(type_str)) > 0)
	{
		if (format->type & CHARNULL)
			len -= 1;
		type_str = ft_cat_at_start(type_str, len, ' ');
	}
	return (type_str);
}
