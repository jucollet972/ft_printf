/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:50:23 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:57:37 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		need_index;
	char	*haystack_temp;

	need_index = 0;
	haystack_temp = (char *)haystack;
	if (!*needle)
		return (haystack_temp);
	while (*haystack_temp)
	{
		need_index = 0;
		while (needle[need_index] == *haystack_temp)
		{
			need_index++;
			haystack_temp++;
			if (!needle[need_index])
				return (haystack_temp - need_index);
		}
		if (needle[need_index])
			haystack_temp -= need_index;
		haystack_temp++;
	}
	return (NULL);
}
