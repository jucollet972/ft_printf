/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 23:06:50 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 17:06:52 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_format *init_format(void)
{
	t_format *format;

	format = NULL;
	if (!(format = malloc(sizeof(t_format))))
		return (NULL);
	format->flags = 0;
	format->width = 0;
	format->precision = -1;
	format->size = 0;
	format->type = 0;
	return (format);
}

t_format *ft_get_format_info(char *str)
{
	t_format *format;
	char     *temp;

	format = NULL;
	temp = str;
	if (!(format = init_format()))
		return (NULL);
	while (*str && ft_isnt_format(*str))
	{
		if (*str == '#' || *str == '0' || *str == '-' || *str == '+' || *str == ' ')
			ft_get_format_flags(&str, &format->flags);
		else if (*str >= '0' && *str <= '9')
			format->width = ft_get_format_width(&str);
		else if (*str == '.')
			format->precision = ft_get_format_precision(&str);
		else if (*str == 'l' || *str == 'h')
			format->size = ft_get_format_size(&str);
		else
			str++;
	}
	format->type = ft_get_format_type(&str);
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

char *ft_char_ptr(va_list arg)
{
	char *str;

	str = NULL;
	if (!(str = va_arg(arg, char*)))
		return (ft_strdup("(null)"));
	if (!(str = ft_strdup(str)))
		return (NULL);
	return (str);
}

char *ft_dec_hh_flag(va_list arg)
{
	char *str;
	signed char signed_c;

	str = NULL;
	signed_c = va_arg(arg, int);
	if (!(str = ft_itoa(signed_c)))
		return (NULL);
	return (str);
}

char *ft_dec_h_flag(va_list arg)
{
	char *str;
	short int short_int;

	str = NULL;
	short_int = va_arg(arg, int);
	if (!(str = ft_itoa(short_int)))
		return (NULL);
	return (str);
}

char *ft_dec_ll_flag(va_list arg)
{
	unsigned long long ll;
	char *str;

	str = NULL;
	ll = va_arg(arg, long long);
	if (!(str = ft_itoa_ll(ll)))
		return (NULL);
	return (str);
}

char *ft_dec_l_flag(va_list arg)
{
	long l;
	char *str;

	str = NULL;
	l = va_arg(arg, long);
	if(!(str = ft_itoa_ll(l)))
		return (NULL);
	return (str);
}

char *ft_unsigned_hh_flag(va_list arg, t_format *format)
{
	char *str;
	unsigned char u_char;

	str = NULL;
	u_char = va_arg(arg, int);
	if (format->type & UNHEXA)
		str = ft_itoa_base(u_char, 16, 'x');
	else if (format->type & UNHEXAUP)
		str = ft_itoa_base(u_char, 16, 'X');
	else if (format->type & OCTAL)
		str = ft_itoa_base(u_char, 8, ' ');
	else if (!(str = ft_itoa_ull(u_char)))
		return (NULL);
	return (str);
}


char *ft_unsigned_h_flag(va_list arg, t_format *format)
{
	char *str;
	unsigned short u_short;

	str = NULL;
	u_short = va_arg(arg, int);
	if (format->type & UNHEXA)
		str = ft_itoa_base(u_short, 16, 'x');
	else if (format->type & UNHEXAUP)
		str = ft_itoa_base(u_short, 16, 'X');
	else if (format->type & OCTAL)
		str = ft_itoa_base(u_short, 8, ' ');
	else if (!(str = ft_itoa_ull(u_short)))
		return (NULL);
	return (str);
}

char *ft_unsigned_ll_flag(va_list arg, t_format *format)
{
	unsigned long long u_ll;
	char *str;

	str = NULL;
	u_ll = va_arg(arg, unsigned long long);
	if (format->type & UNHEXA)
		str = ft_itoa_base(u_ll, 16, 'x');
	else if (format->type & UNHEXAUP)
		str = ft_itoa_base(u_ll, 16, 'X');
	else if (format->type & OCTAL)
		str = ft_itoa_base(u_ll, 8, ' ');
	else if (!(str = ft_itoa_ull(u_ll)))
		return (NULL);
	return (str);
}

char *ft_unsigned_l_flag(va_list arg, t_format *format)
{
	unsigned long u_l;
	char *str;

	str = NULL;
	u_l = va_arg(arg, long);
	if (format->type & UNHEXA)
		str = ft_itoa_base(u_l, 16, 'x');
	else if (format->type & UNHEXAUP)
		str = ft_itoa_base(u_l, 16, 'X');
	else if (format->type & OCTAL)
		str = ft_itoa_base(u_l, 8, ' ');
	else if (!(str = ft_itoa_ull(u_l)))
		return (NULL);
	return (str);
}

char *ft_unsigned_int(va_list arg, t_format *format)
{
	char *str;
	unsigned int u_int;

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
	if (!(str = ft_itoa_ull(u_int)))
		return (NULL);
	return (str);
}

char *ft_integer(va_list arg, t_format *format)
{
	char *str;
	int  integer;

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

char *ft_hexadecimal(va_list arg, t_format *format)
{
	char *str;
	unsigned int u_int;

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

char *ft_hexadecimalupper(va_list arg, t_format *format)
{
	char *str;
	unsigned int u_int;

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

char *ft_octal(va_list arg, t_format *format)
{
	char *str;
	unsigned int u_int;

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

char *ft_char(va_list arg, t_format *format)
{
	char c;
	char *str;

	str = NULL;
	c = va_arg(arg, unsigned int);
	if (c == 0)
		format->type |= CHARNULL;
	if (!(str = ft_strnew(1)))
		return (NULL);
	*str = c;
	return (str);
}

char *ft_percent(void)
{
	char *str;

	str = ft_strdup("%");
	return (str);
}

char *ft_ptr_str(va_list arg)
{
	char *str;
	unsigned long u_int;

	str = NULL;
	u_int = va_arg(arg, unsigned long);
	if (!(str = ft_itoa_base(u_int, 16, 'x')))
		return (NULL);
	return (str);
}

char *ft_get_type_string(va_list arg, t_format *format)
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

char  *ft_integer_accurate_str(char *type_str, t_format *format)
{
	char *str;
	int  len;

	str = NULL;
	len = 0;

	if (format->precision > 0)
	{
		len = ft_strlen(type_str);
		if (len < format->precision)
			len = format->precision - len;
		else
			len = 0;
	}
	if (*type_str == '-')
	{
		str = ft_strsub(type_str, 1, ft_strlen(type_str));
		(format->precision > (int)ft_strlen(type_str + 1)) ? len += 1 : 0;
	}
	else
		str = ft_strsub(type_str, 0, ft_strlen(type_str));
	str = ft_cat_at_start(str, len, '0');
	(format->flags & ZERO) ? format->flags ^= ZERO : 0;
	return (str);
}

int ft_get_width_len(t_format *format, char *type_str, char *ref_str)
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


char *ft_zero_width(t_format *format, char *type_str, char *ref_str)
{
	char *tmp;
	int len;

	tmp  = NULL;
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

char *ft_put_hash_flag(t_format *format, char *type_str, char *ref_str)
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

t_format *ft_flags_cancel(t_format *format)
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

char *ft_put_sign(char *type_str, char *ref_str, t_format *format)
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

char *ft_space_width(char *type_str, char *ref_str, t_format *format)
{
	int len;

	len = 0;
	if ((len = format->width - ft_strlen(type_str)) > 0 )
	{
		if (format->type & CHARNULL)
			len -= 1;
		type_str = ft_cat_at_start(type_str, len, ' ');
	}
	return (type_str);
}

char *ft_error_case(char *type_str, char *ref_str)
{
	ft_strdel(&ref_str);
	return (ft_strdup(""));
}

char *ft_format_string(va_list arg, t_format *format)
{
	char *type_str;
	char *ref_str;

	(!(type_str = ft_get_type_string(arg, format)))?type_str = ft_strdup(""):0;
	ref_str = ft_strdup(type_str);
	format = ft_flags_cancel(format);
	if (type_str == NULL)
		return(ft_error_case(type_str, ref_str));
	if (format->precision >= 0 && !(format->type & PERCENT))
		type_str = ft_accurate_string(type_str, format);
	type_str = ft_zero_width(format, type_str, ref_str);
	type_str = ft_put_hash_flag(format, type_str, ref_str);
	type_str = ft_put_sign(type_str, ref_str, format);
	type_str = ft_space_width(type_str, ref_str, format);
	ft_strdel(&ref_str);
	return (type_str);
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
		}
		else if (!(temp = ft_strjoinfree(temp, format_string, 3)))
		{
			free(format);
			return (-1);
		}
	}
	if (format && format->type & CHARNULL)
	{
		ft_strdel(&temp);
		temp = ft_strsub(ref, index, ft_strlen(ref + index));
		len += ft_strlen(temp);
		write(1, temp, ft_strlen(temp));
		free(temp);
		free(format);
		return (len);
	}
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
