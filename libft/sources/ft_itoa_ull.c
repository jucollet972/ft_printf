#include "libft.h"

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