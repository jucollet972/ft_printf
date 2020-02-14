#include "libft.h"

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