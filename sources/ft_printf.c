/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:07:02 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/15 09:09:21 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*init_format(void)
{
	t_format	*format;

	format = NULL;
	if (!(format = (t_format*)malloc(sizeof(t_format))))
		return (NULL);
	format->flags = 0;
	format->width = 0;
	format->precision = -1;
	format->size = 0;
	format->type = 0;
	return (format);
}

char		*ft_cat_at_start(char *type_str, int len, int to_cat)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_memset(str, to_cat, len);
	str = ft_strjoinfree(str, type_str, 3);
	return (str);
}

int			ft_printf(const char *str, ...)
{
	va_list				arg;
	unsigned long long	len;

	if (!str)
		return (-1);
	va_start(arg, str);
	if (!(len = ft_constuct_str((char *)str, arg)))
		return (0);
	va_end(arg);
	return (len);
}
