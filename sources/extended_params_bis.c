/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_params_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:21:14 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/14 19:33:02 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_char(va_list arg, t_format *format)
{
	char	c;
	char	*str;

	str = NULL;
	c = va_arg(arg, unsigned int);
	if (c == 0)
		format->type |= CHARNULL;
	if (!(str = ft_strnew(1)))
		return (NULL);
	*str = c;
	return (str);
}

static char	*ft_percent(void)
{
	char	*str;

	str = ft_strdup("%");
	return (str);
}

static char	*ft_ptr_str(va_list arg)
{
	char			*str;
	unsigned long	u_int;

	str = NULL;
	u_int = va_arg(arg, unsigned long);
	if (!(str = ft_itoa_base(u_int, 16, 'x')))
		return (NULL);
	return (str);
}

char		*ft_get_type_string(va_list arg, t_format *format)
{
	if (format->type & STRING)
		return (ft_char_ptr(arg));
	else if (format->type & INTEGER)
		return (ft_integer(arg, format));
	else if (format->type & CHAR)
		return (ft_char(arg, format));
	else if (format->type & PERCENT)
		return (ft_percent());
	else if (format->type & UINT)
		return (ft_unsigned_int(arg, format));
	else if (format->type & UNHEXA)
		return (ft_hexadecimal(arg, format));
	else if (format->type & UNHEXAUP)
		return (ft_hexadecimalupper(arg, format));
	else if (format->type & OCTAL)
		return (ft_octal(arg, format));
	else if (format->type & POINTER)
		return (ft_ptr_str(arg));
	return (NULL);
}
