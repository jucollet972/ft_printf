#include "ft_printf.h"

char	*ft_dec_hh_flag(va_list arg)
{
	char		*str;
	signed char	signed_c;

	str = NULL;
	signed_c = va_arg(arg, int);
	if (!(str = ft_itoa(signed_c)))
		return (NULL);
	return (str);
}

char	*ft_dec_h_flag(va_list arg)
{
	char		*str;
	short int	short_int;

	str = NULL;
	short_int = va_arg(arg, int);
	if (!(str = ft_itoa(short_int)))
		return (NULL);
	return (str);
}

char	*ft_dec_ll_flag(va_list arg)
{
	unsigned long long	ll;
	char				*str;

	str = NULL;
	ll = va_arg(arg, long long);
	if (!(str = ft_itoa_ll(ll)))
		return (NULL);
	return (str);
}

char	*ft_dec_l_flag(va_list arg)
{
	long	l;
	char	*str;

	str = NULL;
	l = va_arg(arg, long);
	if (!(str = ft_itoa_ll(l)))
		return (NULL);
	return (str);
}
