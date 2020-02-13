#include "ft_printf.h"

size_t		ft_count_long_long(long long n)
{
	size_t		counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char     *ft_strrev(char *ref)
{
	char temp;
	int  start;
	int  end;
	char *str;


	if (!(str = ft_strdup(ref)))
		return (NULL);
	start = 0;
	end = 0;
	while (str[end])
		end++;
	while (end > start)
	{
		temp = str[--end];
		str[end] = str[start];
		str[start] = temp;
		start++;
	}
	return (str);
}

char     ft_base_char(int nb, char c)
{
	char ret_c;

	ret_c = 0;
	if (nb <= 9 && nb >= 0)
		ret_c = nb + 48;
	else if (c == 'x')
		ret_c = nb + 97 - 10;
	else if (c == 'X' && nb > 9)
		ret_c = nb + 65 - 10;
	return (ret_c);
}

char     *ft_itoa_base(unsigned long long n, int base, char c)
{
	char         *ret_str;
	unsigned long long     temp;
	int           len;
	int           index;

	index = 0;
	temp = n;
	len = 0;

	if (n == 0)
	  return (ft_strdup("0"));
	while (temp /= base)
		len++;
	if(!(ret_str = ft_strnew(len + 1)))
		return (NULL);
	while (n > 0)
	{
		ret_str[len--] = ft_base_char(n%base, c);
		n /= base;
	}
	return (ret_str);
}

size_t		ft_count_ull(unsigned long long n)
{
	size_t		counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa_ll(long long n)
{
	size_t		index;
	char		*str;
	int			sign;

	sign = 0;
	index = ft_count_long_long(n);
	if ((unsigned long long)n == -9223372036854775808U)
		return (ft_strdup("-9223372036854775808"));
	(n == 0) ? index = 1 : index;
	(n < 0) ? index++ : 0;
	(n < 0) ? sign++ : 0;
	(n < 0) ? n *= -1 : 0;
	if (!(str = ft_strnew(index + 1)))
		return (NULL);
	while (index)
	{
		str[--index] = (n % 10) + 48;
		n /= 10;
	}
	(sign > 0) ? *str = '-' : *str;
	return (str);
}


char	*ft_itoa_ull(unsigned long long n)
{
	size_t		index;
	char		*str;

	index = ft_count_ull(n);
	(n == 0) ? index = 1 : index;
	if (!(str = ft_strnew(index + 1)))
		return (NULL);
	while (index)
	{
		str[--index] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}


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

int ft_isnt_flags(char c)
{
	return (c != '%' && c != 'c' && c != 's' && c != 'p' && c != 'd'
		&& c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'X'
		&& c != '.' && !(c >= '1' && c <= '9')
		&& c != '*' && c != 'l' && c != 'h');
}

int ft_isnt_format(char c)
{
	return (c != '%' && c != 'c' && c != 's' && c != 'p' && c != 'd' &&
		c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'X');
}

void ft_get_format_flags(char **str, int* flags)
{

	if (**str == '0')
	{
		*flags |= ZERO;
		(*str)++;
	}
	else if (**str == ' ')
	{
		*flags |= SPACE;
		(*str)++;
	}
	else if (**str == '+')
	{
		if (*flags & SPACE)
			*flags ^= SPACE;
		*flags |= MORE;
		(*str)++;
	}
	else if (**str == '-')
	{
		*flags |= LESS;
		(*str)++;
	}
	else if (**str == '#')
	{
		*flags |= HASH;
		(*str)++;
	}
}

int      ft_get_format_width(char **str)
{
	int width;

	width = 0;
	if (**str <= '9' && **str >= '0')
	{
		width = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
		return (width);
	}
	return (0);
}

int ft_get_format_precision(char **str)
{
	int precision;

	precision = 0;
	if (**str == '.')
	{
		(*str)++;
		if (*(*str) && *(*str) >= '0' && *(*str) <= '9')
		{
			precision = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
			return (precision);
		}
		else
			return (0);
	}
	return (-1);
}

int ft_get_format_size(char **str)
{
	int size;

	size = 0;
	if (**str == 'h' && *(*str + 1) == 'h')
	{
		size = size | HH;
		(*str)+=2;
	}
	else if (**str == 'h')
	{
	size = size | H;
	(*str)+=1;
	}
	else if (**str == 'l' && *(*str + 1) == 'l')
	{
		size = size | LL;
		(*str)+=2;
	}
	else if (**str == 'l')
	{
		size = size | L;
   	(*str)+=1;
	}
	else
		return (0);
	return (size);
}

int ft_get_format_type(char **str)
{
	int type;

	type = 0;
	(**str == '%') ? type = type | PERCENT : 0;
	(**str == 'c') ? type = type | CHAR : 0;
	(**str == 's') ? type = type | STRING : 0;
	(**str == 'p') ? type = type | POINTER : 0;
	(**str == 'd' || **str == 'i') ? type = type | INTEGER : 0;
	(**str == 'o') ? type = type | OCTAL : 0;
	(**str == 'u') ? type = type | UINT : 0;
	(**str == 'x') ? type = type | UNHEXA : 0;
	(**str == 'X') ? type = type | UNHEXAUP : 0;
	(*str)++;
	return (type);
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

char *ft_get_less_option_str(char *type_str, t_format *format, int len)
{
	char *str;
	char *tmp;

	str = NULL;
	tmp = NULL;
	if (format->flags & ZERO && !(format->type & INTEGER) && !(format->type & OCTAL) && !(format->flags & HASH))
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
		if (format->precision > (int)ft_strlen(type_str + 1))
			len += 1;
	}
	else
		str = ft_strsub(type_str, 0, ft_strlen(type_str));
	str = ft_cat_at_start(str, len, '0');
	if (format->flags & ZERO)
		format->flags ^= ZERO;
	return (str);
}

char *ft_format_string(va_list arg, t_format *format)
{
	char *type_str;
	char *ref_str;
	char *tmp;
	int   len;

	tmp = NULL;
	len = 0;
	if (!(type_str = ft_get_type_string(arg, format)))
	   type_str = ft_strdup("");
	ref_str = ft_strdup(type_str);
	if (format->flags & ZERO && format->flags & LESS)
		format->flags = format->flags ^ ZERO;
	if (format->type & STRING)
	{
		(format->flags & SPACE) ? format->flags ^= SPACE : 0;
		(format->flags & MORE) ? format->flags ^= MORE : 0;
	}
	if (type_str == NULL)
	{
		ft_strdel(&ref_str);
		return (ft_strdup(""));
	}
	if (format->precision >= 0 && !(format->type & PERCENT))
		type_str = ft_accurate_string(type_str, format);
	//protect accurate str free leaks
	len = ft_strlen(type_str);
	if (len < format->width)
		len = format->width - len;
	else
		len = 0;
	(format->type & CHARNULL) ? len -= 1 : 0;
	((format->flags & MORE && *type_str != '-') || (*type_str != '-' && *ref_str == '-') || (format->flags & SPACE && *ref_str != '-')) ? len -= 1 : 0;
	(*ref_str != '0' && format->flags & HASH && format->type & OCTAL) ? len -= 1 : 0;
	((*ref_str != '0' && format->flags & HASH && (format->type & UNHEXA || format->type & UNHEXAUP)) || format->type & POINTER) ? len -= 2 : 0;
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
	if ((format->type & UNHEXA && format->flags & HASH && *ref_str != '0') || format->type & POINTER)
	type_str = ft_strjoinfree("0x", type_str, 2);
	else if (format->type & UNHEXAUP && format->flags & HASH && *ref_str != '0')
	   	type_str = ft_strjoinfree("0X", type_str, 2);
	else if (format->type & OCTAL && format->flags & HASH && *ref_str != '0')
	   	type_str = ft_strjoinfree("0", type_str, 2);
	if (format->type & INTEGER || (format->type & POINTER))
	{
   		if (format->flags & MORE && *ref_str != '-')
		   type_str = ft_cat_at_start(type_str, 1, '+');
		else if (*ref_str == '-' && *type_str != '-')
		   type_str = ft_cat_at_start(type_str, 1, '-');
		else if (format->flags & SPACE && *ref_str != '-')
		   type_str = ft_cat_at_start(type_str, 1, ' ');
	}
	len = 0;
	if ((len = format->width - ft_strlen(type_str)) > 0 )
	{
	 if (format->type & CHARNULL)
		len -= 1;
   	 type_str = ft_cat_at_start(type_str, len, ' ');
	}
	ft_strdel(&ref_str);
	//strdel pas propre
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
