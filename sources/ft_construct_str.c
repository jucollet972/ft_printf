/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 08:51:21 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/15 08:54:15 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_disp_charnull(t_format *form, int len, char *from_str, char *tmp)
{
	len += ft_strlen(tmp);
	write(1, tmp, ft_strlen(tmp));
	if (form->flags & LESS)
	{
		write(1, "\0", 1);
		write(1, from_str, ft_strlen(from_str));
	}
	else
	{
		write(1, from_str, ft_strlen(from_str));
		write(1, "\0", 1);
	}
	len += ft_strlen(from_str);
	len += 1;
	*tmp = 0;
	ft_strdel(&from_str);
	return (len);
}

static int	ft_endl_charnull(t_format *format, char *ref, char *temp)
{
	int		len;

	len = 0;
	ft_strdel(&temp);
	temp = ft_strsub(ref, 0, ft_strlen(ref));
	len += ft_strlen(temp);
	write(1, temp, ft_strlen(temp));
	free(temp);
	free(format);
	return (len);
}

static char	*ft_start_str_error_ret(void *var)
{
	free(var);
	return (NULL);
}

static char	*ft_start_string(char **ref, va_list arg, int *len, t_format **form)
{
	char	*format_string;
	char	*temp;
	int		end_str;

	temp = ft_strdup("");
	format_string = NULL;
	end_str = 0;
	while ((end_str = ft_strchr_index(*ref, '%')) > 0)
	{
		if (!(temp = ft_strjoinfree(temp, ft_strsub(*ref, 0, end_str - 1), 3)))
			return (NULL);
		*ref += end_str;
		if (*form)
			free(*form);
		if (!(*form = ft_get_format_info(*ref)))
			return (ft_start_str_error_ret(temp));
		*ref += ft_jump_format(*ref);
		format_string = ft_format_string(arg, *form);
		if ((*form)->type & CHARNULL)
			*len = ft_disp_charnull(*form, *len, format_string, temp);
		else if (!(temp = ft_strjoinfree(temp, format_string, 3)))
			return (ft_start_str_error_ret(*form));
	}
	return (temp);
}

int			ft_constuct_str(char *ref, va_list arg)
{
	char		*temp;
	int			len;
	t_format	*format;

	len = 0;
	format = init_format();
	temp = NULL;
	if (!(temp = ft_start_string(&ref, arg, &len, &format)))
		return (-1);
	if (format && format->type & CHARNULL)
		return ((len += ft_endl_charnull(format, ref, temp)));
	else if (!(temp =
					ft_strjoinfree(temp, ft_strsub(ref, 0, ft_strlen(ref)), 3)))
	{
		free(format);
		return (-1);
	}
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	free(format);
	return (len);
}
