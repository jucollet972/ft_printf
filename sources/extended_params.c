/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:16:10 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/14 19:18:12 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char_ptr(va_list arg)
{
	char	*str;

	str = NULL;
	if (!(str = va_arg(arg, char*)))
		return (ft_strdup("(null)"));
	if (!(str = ft_strdup(str)))
		return (NULL);
	return (str);
}

char	*ft_integer(va_list arg, t_format *format)
{
	char	*str;
	int		integer;

	str = NULL;
	if (format->size & HH)
		return (ft_dec_hh_flag(arg));
	else if (format->size & H)
		return (ft_dec_h_flag(arg));
	else if (format->size & LL)
		return (ft_dec_ll_flag(arg));
	else if (format->size & L)
		return (ft_dec_l_flag(arg));
	integer = va_arg(arg, int);
	if (!(str = ft_itoa(integer)))
		return (NULL);
	return (str);
}

char	*ft_hexadecimal(va_list arg, t_format *format)
{
	char			*str;
	unsigned int	u_int;

	str = NULL;
	if (format->size & HH)
		return (ft_unsigned_hh_flag(arg, format));
	else if (format->size & H)
		return (ft_unsigned_h_flag(arg, format));
	else if (format->size & LL)
		return (ft_unsigned_ll_flag(arg, format));
	else if (format->size & L)
		return (ft_unsigned_l_flag(arg, format));
	u_int = va_arg(arg, unsigned int);
	if (!(str = ft_itoa_base(u_int, 16, 'x')))
		return (NULL);
	return (str);
}

char	*ft_hexadecimalupper(va_list arg, t_format *format)
{
	char			*str;
	unsigned int	u_int;

	str = NULL;
	if (format->size & HH)
		return (ft_unsigned_hh_flag(arg, format));
	else if (format->size & H)
		return (ft_unsigned_h_flag(arg, format));
	else if (format->size & LL)
		return (ft_unsigned_ll_flag(arg, format));
	else if (format->size & L)
		return (ft_unsigned_l_flag(arg, format));
	u_int = va_arg(arg, unsigned int);
	if (u_int == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (!(str = ft_itoa_base(u_int, 16, 'X')))
		return (NULL);
	return (str);
}

char	*ft_octal(va_list arg, t_format *format)
{
	char			*str;
	unsigned int	u_int;

	str = NULL;
	if (format->size & HH)
		return (ft_unsigned_hh_flag(arg, format));
	else if (format->size & H)
		return (ft_unsigned_h_flag(arg, format));
	else if (format->size & LL)
		return (ft_unsigned_ll_flag(arg, format));
	else if (format->size & L)
		return (ft_unsigned_l_flag(arg, format));
	u_int = va_arg(arg, unsigned int);
	if (u_int == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (!(str = ft_itoa_base(u_int, 8, ' ')))
		return (NULL);
	return (str);
}
