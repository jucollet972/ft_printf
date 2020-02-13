#include "libft.h"

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