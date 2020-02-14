/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_less_option_str.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 23:02:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 23:03:55 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
