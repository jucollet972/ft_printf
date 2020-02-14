/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:58:37 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/14 19:02:17 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_put_hash_flag(t_format *format, char *type_str, char *ref_str)
{
	if ((format->type & UNHEXA && format->flags & HASH && *ref_str != '0')
			|| format->type & POINTER)
		type_str = ft_strjoinfree("0x", type_str, 2);
	else if (format->type & UNHEXAUP && format->flags & HASH && *ref_str != '0')
		type_str = ft_strjoinfree("0X", type_str, 2);
	else if (format->type & OCTAL && format->flags & HASH && *ref_str != '0')
		type_str = ft_strjoinfree("0", type_str, 2);
	return (type_str);
}

t_format	*ft_flags_cancel(t_format *format)
{
	if (format->flags & ZERO && format->flags & LESS)
		format->flags = format->flags ^ ZERO;
	if (format->type & STRING)
	{
		(format->flags & SPACE) ? format->flags ^= SPACE : 0;
		(format->flags & MORE) ? format->flags ^= MORE : 0;
	}
	return (format);
}

char		*ft_put_sign(char *type_str, char *ref_str, t_format *format)
{
	if (format->type & INTEGER || (format->type & POINTER))
	{
		if (format->flags & MORE && *ref_str != '-')
			type_str = ft_cat_at_start(type_str, 1, '+');
		else if (*ref_str == '-' && *type_str != '-')
			type_str = ft_cat_at_start(type_str, 1, '-');
		else if (format->flags & SPACE && *ref_str != '-')
			type_str = ft_cat_at_start(type_str, 1, ' ');
	}
	return (type_str);
}

char		*ft_formatstr_null_case(char *ref_str)
{
	ft_strdel(&ref_str);
	return (ft_strdup(""));
}

char		*ft_format_string(va_list arg, t_format *format)
{
	char	*type_str;
	char	*ref_str;

	if (!(type_str = ft_get_type_string(arg, format)))
		type_str = ft_strdup("");
	ref_str = ft_strdup(type_str);
	format = ft_flags_cancel(format);
	if (type_str == NULL)
		return (ft_formatstr_null_case(ref_str));
	if (format->precision >= 0 && !(format->type & PERCENT))
		type_str = ft_accurate_string(type_str, format);
	type_str = ft_zero_width(format, type_str, ref_str);
	type_str = ft_put_hash_flag(format, type_str, ref_str);
	type_str = ft_put_sign(type_str, ref_str, format);
	type_str = ft_space_width(type_str, ref_str, format);
	ft_strdel(&ref_str);
	return (type_str);
}
