/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_less_option_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:04:13 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/14 19:04:15 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_less_option_str(char *type_str, t_format *format, int len)
{
	char *str;
	char *tmp;

	str = NULL;
	tmp = NULL;
	if (format->flags & ZERO && !(format->type & INTEGER)
	&& !(format->type & OCTAL) && !(format->flags & HASH))
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		tmp = ft_memset(str, '0', len);
		str = ft_strjoin(type_str, str);
		ft_strdel(&tmp);
	}
	else
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		tmp = ft_memset(str, ' ', len);
		str = ft_strjoin(type_str, str);
		ft_strdel(&tmp);
	}
	ft_strdel(&type_str);
	return (str);
}
