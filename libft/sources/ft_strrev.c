#include "libft.h"

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