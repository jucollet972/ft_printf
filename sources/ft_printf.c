/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 23:06:50 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 17:27:49 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_format *init_format(void)
{
	t_format *format;

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

int ft_jump_format(char *str)
{
	int index;

	index = 0;
	while (str[index] && ft_isnt_format(str[index]))
		index++;
	if (!str[index])
		return (index);
	else
		return (index + 1);
}

char *ft_cat_at_start(char *type_str, int len, int to_cat)
{
	char *str;

	str = NULL;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_memset(str, to_cat, len);
	str = ft_strjoinfree(str, type_str, 3);
	return (str);
}

int ft_disp_charnull(t_format *format, int len, char *format_string, char *temp)
{
	len += ft_strlen(temp);
	write(1, temp, ft_strlen(temp));
	if (format->flags & LESS)
	{
		write(1, "\0", 1);
		write(1, format_string, ft_strlen(format_string));
	}
	else
	{
		write(1, format_string, ft_strlen(format_string));
		write(1, "\0", 1);
	}
	len += ft_strlen(format_string);
	len += 1;
	*temp = 0;
	ft_strdel(&format_string);
	return (len);
}

int ft_endl_charnull(t_format *format, char *ref, char *format_string, char *temp)
{
	int len;

	len  = 0;
	ft_strdel(&temp);
	temp = ft_strsub(ref, 0, ft_strlen(ref));
	len += ft_strlen(temp);
	write(1, temp, ft_strlen(temp));
	free(temp);
	free(format);
	return (len);
}

int ft_constuct_str(char *ref, va_list arg)
{
	int      len;
	char     *format_string;
	char     *temp;
	int      end_str;
	int      index;
	t_format *format;

	len = 0;
	index = 0;
	temp = ft_strdup("");
	format = NULL;
	while ((end_str = ft_strchr_index(ref + index, '%')) > 0)
	{
		if (!(temp = ft_strjoinfree(temp, ft_strsub(ref, index, end_str - 1), 3)))
			return (-1);
		index += end_str;
		if (format)
			free(format);
		if (!(format = ft_get_format_info(ref + index)))
		{
			free(temp);
			return (-1);
		}
		index += ft_jump_format(ref + index);
		format_string = ft_format_string(arg, format);
		if (format->type & CHARNULL)
			len = ft_disp_charnull(format, len, format_string, temp);
		else if (!(temp = ft_strjoinfree(temp, format_string, 3)))
		{
			free(format);
			return (-1);
		}
	}
	if (format && format->type & CHARNULL)
		return ((len += ft_endl_charnull(format, ref + index, format_string, temp)));
	else if (!(temp = ft_strjoinfree(temp, ft_strsub(ref, index, ft_strlen(ref + index)), 3)))
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

int ft_printf(const char *str, ...)
{
	va_list  arg;
	unsigned long long len;

	if (!str)
		return (-1);
	va_start(arg, str);
	if (!(len = ft_constuct_str((char *)str, arg)))
		return (0);
	va_end(arg);
	//printf("  %d", len);
	//sleep(5);
	return (len);
}
