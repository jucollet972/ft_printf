#include "ft_printf.h"

char	*ft_unsigned_hh_flag(va_list arg, t_format *format)
{
	char			*str;
	unsigned char	u_char;

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

char	*ft_unsigned_h_flag(va_list arg, t_format *format)
{
	char			*str;
	unsigned short	u_short;

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

char	*ft_unsigned_ll_flag(va_list arg, t_format *format)
{
	unsigned long long	u_ll;
	char				*str;

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

char	*ft_unsigned_l_flag(va_list arg, t_format *format)
{
	unsigned long	u_l;
	char			*str;

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

char	*ft_unsigned_int(va_list arg, t_format *format)
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
	if (!(str = ft_itoa_ull(u_int)))
		return (NULL);
	return (str);
}
