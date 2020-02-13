/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_accurate_string.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 22:59:56 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 23:00:04 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_octa_unhexa(const t_format *format, char *type_str, int len)
{
	char	*str;

	if (format->precision == 0 &&
			!(format->type & OCTAL) &&
			(ft_strcmp(type_str, "0") == 0))
	{
		str = ft_strsub(type_str, 0, format->precision);
		ft_strdel(&type_str);
	}
	else if (format->precision <= 0 && (format->type & OCTAL) &&
			!(format->flags & HASH) && (ft_strcmp(type_str, "0") == 0))
	{
		str = ft_strdup("");
		ft_strdel(&type_str);
	}
	else if (format->precision > len)
		str = ft_cat_at_start(type_str, format->precision - len, '0');
	else
	{
		str = ft_strsub(type_str, 0, len);
		ft_strdel(&type_str);
	}
	return (str);
}

static char	*ft_pointer(t_format *format, char *type_str, char *str)
{
	int		len;

	if (format->precision <= 0 && *type_str == '0')
	{
		ft_strdel(&type_str);
		str = ft_strdup("");
	}
	else if (format->precision > (len = (ft_strlen(type_str))))
	{
		while (format->precision-- > len)
			str = ft_strjoinfree("0", str, 2);
	}
	else
	{
		str = ft_strdup(type_str);
		ft_strdel(&type_str);
	}
	return (str);
}

static int	ft_init_accurate(t_format *format, char *type_str, char **str)
{
	*str = NULL;
	if (type_str)
		*str = type_str;
	if (format->flags & ZERO)
		format->flags ^= ZERO;
	return (ft_strlen(type_str));
}

char		*ft_accurate_string(char *type_str, t_format *format)
{
	char	*str;
	int		len;

	len = ft_init_accurate(format, type_str, &str);
	if (format->type & INTEGER || format->type & UINT)
	{
		if (format->precision <= 0 && (ft_strcmp(type_str, "0") == 0))
			str = ft_strdup("");
		else
			str = ft_integer_accurate_str(type_str, format);
		ft_strdel(&type_str);
	}
	else if (format->type & OCTAL ||
			format->type & UNHEXA || format->type & UNHEXAUP)
	{
		if (OCTAL & format->type && format->flags & HASH && *type_str != '0')
			len += 1;
		str = ft_octa_unhexa(format, type_str, len);
	}
	else if (format->type & POINTER)
		str = ft_pointer(format, type_str, str);
	else
		str = ft_strsub(type_str, 0, format->precision);
	return (str);
}
